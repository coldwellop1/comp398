// hw04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "markdown_hw04.cpp"
using namespace std;

const string newLine = "/n";
void main()
{
	cout << "Please enter the pathway to the markdown file: ";
	string filePathway;
	cin >> filePathway;
	cout << newLine;

	ifstream File
	File.open(filePathway, in);
	if (File.is_open())
	{
		string code = "<html>"; // variable will hold the html code that we convert. Begins by just holding <html>.
		if (File.good()){
			string lastLine = "";
			string currentLine, nextLine;	//variable holds current & next line from .md file.
			getline(File, currentLine);	//put the first line of the file in currentLine.
			getline(File, nextLine); //put the second line of the file in nextLine.
			while (File.good())
			{
				string followingLine;	//variable to hold the line after the next line in the .md file that we will look at.
				getline(File, followingLine);
				string lineToAppend = translateLine(lastLine, currentLine, nextLine, followingLine);	//translate the line to html
				code = appendToCode(code, lineToAppend);
				lastLine = currentLine;	//make the last line be the one we just did.
				currentLine = nextLine;	//make the next line be the one we're now looking at.
				nextLine = followingLine;	//make the following line be the next line we'll look at.
			}
			//NEED TO DO SOMETHING OUT HERE FOR WHEN NEXTLINE AND FOLLOWINGLINE WILL NOT EXIST IN THE FILE.
		}
		code = code + "</html>";
	}
	else
		cout << "There was an error opening the file." << newLine;
}




