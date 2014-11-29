/* Markdown must handle: 
		paragraphs, 
		headers, 
		block quotes, 
		emphasis, 
		lists, 
		links, 
		images,
		code. 
		*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string appendToCode(string code, string lineToAppend){
	code = code + lineToAppend;
	return lineToAppend;
}


bool isNewPar(string lastLine, string currentLine){
	if (((lastLine.find_first_not_of(' ') == -1) || (lastLine.find_first_not_of('\t') == -1)) && (lastLine.find_first_not_of('\n') != -1))
		//if the last line we searched had (only) spaces or tabs...
		return true;	//this is the beginning of a paragraph
	else
		return false;	//this is not the beginning of a paragraph
}
bool endOfPar(string currentLine, string nextLine){
	if (((nextLine.find_first_not_of(' ') == -1) || (nextLine.find_first_not_of('\t') == -1)) && (nextLine.find_first_not_of('\n') != -1))
		//if the next line we'll search has (only) spaces or tabs...
		return true;	//this is the end of the paragraph
	else
		return false;	//this is not the end of the paragraph
}
/*A paragraph is simply one or more consecutive lines of 
text, separated by one or more blank lines. (A blank line
is any line that looks like a blank line — a line containing 
nothing but spaces or tabs is considered blank.) Normal 
paragraphs should not be indented with spaces or tabs.*/
string paragraph(string lastLine, string currentLine, string nextLine){
	if ((isNewPar(lastLine, currentLine) == true) && (currentLine[0] != '>'))
		currentLine = "<p>" + currentLine;
	if (endOfPar(currentLine, nextLine) == true)
		currentLine = currentLine + "</p>";
	return currentLine;
}

bool isFirstLevHead(string currentLine, string nextLine){
	if (nextLine.find_first_not_of('=') == -1 || currentLine.find_first_not_of('#') == 1)
		return true;	//if the next line is strictly ='s or the current line starts with ONE #, line is a first level header.
	else
		return false;	//this is not a first level header.
}
bool isSecLevHead(string currentLine, string nextLine){
	if (nextLine.find_first_not_of('-') == -1 || currentLine.find_first_not_of('#') == 2)
		return true;	//if the next line is strictly -'s or the current line starts with TWO #, line is a second level header.
	else
		return false;	//this is not a second level header.
}
bool isThirdLevHead(string currentLine){
	if (currentLine.find_first_not_of('#') == 3)
		return true;	//if the current line starts with THREE #, line is a third level header.
	else
		return false;	//this is not a third level header.
}
bool isFourthLevHead(string currentLine){
	if (currentLine.find_first_not_of('#') == 4)
		return true;	//if the current line starts with FOUR #, line is a fourth level header.
	else
		return false;	//this is not a fourth level header.
}
bool isFifthLevHead(string currentLine){
	if (currentLine.find_first_not_of('#') == 5)
		return true;	//if the current line starts with FIVE #, line is a fifth level header.
	else
		return false;	//this is not a fifth level header.
}
bool isSixthLevHead(string currentLine){
	if (currentLine.find_first_not_of('#') == 6)
		return true;	//if the current line starts with SIX #, line is a sixth level header.
	else
		return false;	//this is not a sixth level header.
}
/*Markdown offers two styles of headers: Setext and atx. 
Setext-style headers for <h1> and <h2> are created by “underlining” 
with equal signs (=) and hyphens (-), respectively. To create an 
atx-style header, you put 1-6 hash marks (#) at the beginning of the 
line — the number of hashes equals the resulting HTML header level.*/
/*Markdown:					Output:
A First Level Header			<h1>A First Level Header</h1>
====================

A Second Level Header			<h2>A Second Level Header</h2>
---------------------

### Header 3					<h3>Header 3</h3>
*/
string header(string currentLine, string nextLine){
	if (isFirstLevHead(currentLine, nextLine) == true)
		currentLine = "<h1>" + currentLine + "</h1>";
	if (isSecLevHead(currentLine, nextLine) == true)
		currentLine = "<h2>" + currentLine + "</h2>";
	if (isThirdLevHead(currentLine) == true)
		currentLine = "<h3>" + currentLine + "</h3>";
	if (isFourthLevHead(currentLine) == true)
		currentLine = "<h4>" + currentLine + "</h4>";
	if (isFifthLevHead(currentLine) == true)
		currentLine = "<h5>" + currentLine + "</h5>";
	if (isSixthLevHead(currentLine) == true)
		currentLine = "<h6>" + currentLine + "</h6>";
	return currentLine;
}

/*Blockquotes are indicated using email-style ‘>’ angle brackets.*/
/*Markdown:										Output:
													<blockquote>
> This is a blockquote.									<p>This is a blockquote.</p>
>
> This is the 2nd par. in the blockquote.				<p>This is the 2nd par. in the blockquote.</p>
>
> ## This is an H2 in a blockquote						<h2>This is an H2 in a blockquote</h2>
													</blockquote>
*/
string blockQuote(string lastLine, string currentLine, string nextLine){
	if ((lastLine.find("<blockquote>\n    <p>") == -1) && (currentLine[0] == '>'))
		currentLine = "<blockquote>\n    <p>" + currentLine;
	if ((nextLine[0] != '>') && (currentLine[0] == '>'))
		currentLine = currentLine + "\n<blockquote>";
	return currentLine;
}

string strongEmph(string currentLine, int oddOrEven){

	string strong = "**";
	int position = currentLine.find(strong);
	if ((position != -1) && (oddOrEven%2 == 1)){
		currentLine.replace(position, 2, "<strong>");
		++oddOrEven;
	}
	if ((position != -1) && (oddOrEven%2 == 0)){
		currentLine.replace(position, 2, "</strong>");
		++oddOrEven;
	}
	if (currentLine.find(strong) != -1)
		strongEmph(currentLine, oddOrEven);
	return currentLine;
}

string weakEmph(string currentLine, int oddOrEven){
	string weak = "**";
	int position = currentLine.find(weak);
	if ((position != -1) && (oddOrEven % 2 == 1)){
		currentLine.replace(position, 1, "<weak>");
		++oddOrEven;
	}
	if ((position != -1) && (oddOrEven % 2 == 0)){
		currentLine.replace(position, 1, "</weak>");
		++oddOrEven;
	}
	if (currentLine.find(weak) != -1)
		weakEmph(currentLine, oddOrEven);
	return currentLine;
}


/*Markdown uses asterisks and underscores to indicate spans of 
emphasis.*/

/*Markdown:										Output:
These words *are emphasized*.						<p>These words <em>are emphasized</em>.
These words _are emphasized also_.					These words <em>are emphasized also</em>.</p>

Use 2 asterisks for **strong emphasis**.			<p>Use 2 asterisks for <strong>strong emphasis</strong>.
Or, you can __use two underscores instead__.		Or, you can <strong>use two underscores instead</strong>.</p>
*/
string emphasis(string currentLine){
	int oddOrEven = 1;
	currentLine = strongEmph(currentLine, oddOrEven);
	currentLine = weakEmph(currentLine, oddOrEven);
	return currentLine;
}

/*Unordered (bulleted) lists use asterisks, pluses, and hyphens 
(*, +, and -) as list markers. These three markers are interchangable*/
/*Markdown:				Output:
								//(They all produce the following:)
* Candy.					<ul>
* Gum.						<li>Candy.</li>
	Popcorn.				<li><p>Gum.</p>
							<p>Popcorn.</p></li>
+ Candy.					</ul>
+ Gum.
	Popcorn.

- Candy.
- Gum.
	Popcorn.
*/
string checkIfUnordered(string lastLine, string currentLine, string nextLine, string followingLine, char symbol){

	if (currentLine[0] == symbol){
		if ((endOfPar(currentLine, nextLine) == true) && (followingLine[0] != ' ') && (followingLine[0] != '\t'))
			currentLine = "<li>" + currentLine + "</li> \n </ul>";
		else{
			if ((nextLine[0] != symbol) && (followingLine[0] == ' ') || (followingLine[0] == '\t')){
				currentLine.replace(0, 1, "<li> <p>");
				currentLine = currentLine + "</p>";
				followingLine.replace(0, 4, "<p>");
				followingLine = followingLine + "</p></li>";
			}
			else
				currentLine = "<li>" + currentLine + "</li>";
		if (lastLine.find("<li>") == -1)
			currentLine = "<ul> \n" + currentLine;
		}
	}
	return currentLine;
}
string unorderedList(string lastLine, string currentLine, string nextLine, string followingLine){
	char ast = '*';
	char plus = '+';
	char hyph = '-';
	currentLine = checkIfUnordered(lastLine, currentLine, nextLine, followingLine, ast);
	currentLine = checkIfUnordered(lastLine, currentLine, nextLine, followingLine, plus);
	currentLine = checkIfUnordered(lastLine, currentLine, nextLine, followingLine, hyph);

	return currentLine;
}

/*Ordered (numbered) lists use regular numbers, followed by periods, 
as list markers*/
/*Markdown:				Output:
							<ol>
1.  Red						<li>Red</li>
2.  Green					<li>Green</li>
3.  Blue					<li><p>Blue</p>
							<p>Orange</p></li>
	Orange					</ol>
*/
string orderedList(string lastLine, string currentLine, string nextLine, string followingLine){

	return currentLine;
}

string checkIfOrdered(string lastLine, string currentLine, string nextLine, string followingLine, char symbol){

	if (isdigit(currentLine[0]) && (currentLine.find_first_of('.') == 1)){
		if ((endOfPar(currentLine, nextLine) == true) && (followingLine[0] != ' ') && (followingLine[0] != '\t'))
			currentLine = "<li>" + currentLine + "</li> \n </ol>";
		else{
			if ((nextLine[0] != symbol) && (followingLine[0] == ' ') || (followingLine[0] == '\t')){
				currentLine.replace(0, 1, "<li> <p>");
				currentLine = currentLine + "</p>";
				followingLine.replace(0, 4, "<p>");
				followingLine = followingLine + "</p></li>";
			}
			else
				currentLine = "<li>" + currentLine + "</li>";
		if (lastLine.find("<li>") == -1)
			currentLine = "<ol> \n" + currentLine;
		}
	}
	return currentLine;
}

/*Markdown supports two styles for creating links: inline and reference.
With both styles, you use square brackets to delimit the text you want 
to turn into a link.*/
/*Markdown:
	This is an [example link](http://example.com/).
	This is an[example link](http://example.com/ "With a Title").

  Output:
	<p>This is an <a href="http://example.com/"> example link</a>.</p>
	<p>This is an <a href="http://example.com/" title="With a Title"> example link</a>.</p>
	*/

/*Reference-style links allow you to refer to your links by names, which 
you define elsewhere in your document:
Markdown:
I get 10 times more traffic from [Google][1] than from
[Yahoo][2] or [MSN][3].

[1]: http://google.com/        "Google"
[2]: http://search.yahoo.com/  "Yahoo Search"
[3]: http://search.msn.com/    "MSN Search"

Output:
<p>I get 10 times more traffic from <a href="http://google.com/"
title="Google">Google</a> than from <a href="http://search.yahoo.com/"
title="Yahoo Search">Yahoo</a> or <a href="http://search.msn.com/"
title="MSN Search">MSN</a>.</p>
*/
/* The title attribute is optional. Link names may contain letters, 
numbers and spaces, but are not case sensitive:
Markdown:
I start my morning with a cup of coffee and
[The New York Times][NY Times].

[ny times]: http://www.nytimes.com/

Output:

<p>I start my morning with a cup of coffee and
<a href="http://www.nytimes.com/">The New York Times</a>.</p>

*/
string link(string lastLine, string currentLine, string nextLine){

	return currentLine;
}

/*Image syntax is very much like link syntax.*/
/* 
						Markdown:
Inline (titles opt):	![alt text](/path/to/img.jpg "Title")
Reference-style:		![alt text][id]
						[id]: /path/to/img.jpg "Title"

						Output: (both produce the same)
						<img src="/path/to/img.jpg" alt="alt text" title="Title" />
*/
string image(string lastLine, string currentLine, string nextLine){

	return currentLine;
}

/*In a regular paragraph, you can create code span by wrapping text 
in backtick quotes. Any ampersands (&) and angle brackets (< or >) 
will automatically be translated into HTML entities. This makes it 
easy to use Markdown to write about HTML example code*/

/*Markdown:
I strongly recommend against using any `<blink>` tags.

I wish SmartyPants used named entities like `&mdash;`
instead of decimal-encoded entites like `&#8212;`.

Output:
<p>I strongly recommend against using any
<code>&lt;blink&gt;</code> tags.</p>

<p>I wish SmartyPants used named entities like
<code>&amp;mdash;</code> instead of decimal-encoded
entites like <code>&amp;#8212;</code>.</p>
*/

/*To specify an entire block of pre-formatted code, indent every line of the block by 4 spaces or 1 tab. Just like with code spans, &, <, and > characters will be escaped automatically.

Markdown:

If you want your page to validate under XHTML 1.0 Strict,
you've got to put paragraph tags in your blockquotes:

    <blockquote>
        <p>For example.</p>
    </blockquote>

Output:

<p>If you want your page to validate under XHTML 1.0 Strict,
you've got to put paragraph tags in your blockquotes:</p>

<pre><code>&lt;blockquote&gt;
    &lt;p&gt;For example.&lt;/p&gt;
&lt;/blockquote&gt;
</code></pre>
*/
string code(string currentLine, string nextLine){

	return currentLine;
}

string translateLine(string lastLine, string currentLine, string nextLine, string followingLine){
	currentLine = paragraph(lastLine, currentLine, nextLine);
	currentLine = header(currentLine, nextLine);
	currentLine = blockQuote(lastLine, currentLine, nextLine);
	currentLine = emphasis(currentLine);
	currentLine = unorderedList(lastLine, currentLine, nextLine, followingLine);
	currentLine = orderedList(lastLine, currentLine, nextLine, followingLine);
	currentLine = link(lastLine, currentLine, nextLine);
	currentLine = image(lastLine, currentLine, nextLine);
	currentLine = code(currentLine, nextLine);
	return currentLine;
}
