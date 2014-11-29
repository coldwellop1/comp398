#include "helper_functions.cpp"
#include "constants.h"
#include <string.h>
using namespace std;

string Headers(string currentLine, string nextline){
	//check for header 1 underlining
	if ((nextline.find_first_not_of('= ') == -1){
		currentLine = "<h1>" + currentLine + "</h1>";
	}

	//check for header 2 underlining
	if ((nextline.find_first_not_of('- ') == -1){
		currentLine = "<h2>" + currentLine + "</h2>";
	}

	//for '#' header symbols
	//erase unneccessary ending #'s
	for(int i = 0; i < 6; i++){
		if (currentLine.back() == '#')
			currentLine.pop_back;
	}

	//check for #'s at front of string
	if (currentLine[0] == '#'){	//if line starts with 1 '#'
		if (currentLine[1] == '#'){	//if line starts with 2 '#'s
			if (currentLine[2] == '#'){	//if line starts with 3 '#'s
				if (currentLine[3] == '#'){	//if line starts with 4 '#'s
					if (currentLine[4] == '#'){	//if line starts with 5 '#'s
						if (currentLine[5] == '#'){		//if line starts with 6 '#'s
							currentLine = currentLine.erase(0, 6);	//remove #'s
							currentLine = "<h6>" + currentLine + "</h6>";	//add html tag
						}
						else{
							currentLine = currentLine.erase(0, 5);	//remove #'s
							currentLine = "<h5>" + currentLine + "</h5>";	//add html tag
						}}
					else{
						currentLine = currentLine.erase(0, 4);	//remove #'s
						currentLine = "<h4>" + currentLine + "</h4>";	//add html tag
					}}
				else{
					currentLine = currentLine.erase(0, 3);	//remove #'s
					currentLine = "<h3>" + currentLine + "</h3>";	//add html tag
				}}
			else{
				currentLine = currentLine.erase(0, 2);	//remove #'s
				currentLine = "<h2>" + currentLine + "</h2>";	//add html tag
			}}
		else{
			currentLine = currentLine.erase(0, 1);	//remove #'s
			currentLine = "<h1>" + currentLine + "</h1>";	//add html tag
		}}
	return currentLine;
}

string replaceAmp(string currentLine){
	int where = existsIn(AMP, currentLine);
	if ( where != -1){
		currentLine = currentLine.replace(where, 1, NEW_AMP);
	}
	return currentLine;
}

string replaceLeftAngle(string currentLine){
	int where = existsIn(LEFT_ANGLE, currentLine);
	if ((where != -1) && (currentLine[where+1] == ' ')) {
		currentLine = currentLine.replace(where, 1, NEW_LEFT_ANGLE);
	}
	return currentLine;
}

string paragraph(string lastLine, string currentLine, string nextLine){
	if (blankLine(lastLine))
		currentLine = "<p>" + currentLine;
	if (blankLine(nextLine))
		currentLine = currentLine + "</p>";
	return currentLine;
}

string addBreak(string currentLine){
	int breakSymLen = BREAK.length();
	int where = currentLine.find("  \n");

	if (currentLine.length() == (breakSymLen + where))
		currentLine = currentLine.replace(where, breakSymLen, NEW_BREAK);
}