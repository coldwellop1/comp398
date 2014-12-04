#include "constants.h"
#include <string.h>
using namespace std;

//check if the line begins with a character that does not have special meaning in markdown
//input: string containing the current line of code
//output: a boolean stating if the current line begins with a meaningless character
bool beginsWithText(currentLine){
	for (int i = 0; i < ALPHEBET_LENGTH; i++){
		if (currentLine[0] == ALPHEBET[i])
			return true;
		if (currentLine[0] == NUMBERS[i])
			return true;
		if (currentLine[0] == SYMBOLS[i])
			return true;
	}
	return false;
}

//check if a character (key) exists within the current line
//input: a key to search for and a line to search within
//output: an integer: -1 if the key is not found in the string, else returns the index of the key.
int existsIn(char key, string currentLine){
	for(int i = 0; i < currentLine.length(); i++){
		if (currentLine[i] == key)
			return i;
	}
	return -1;
}

bool blankLine(string currentLine){
	if (currentLine.empty())
		return true;
	if (currentLine.find_first_not_of(" 	") == -1)
		return true;
	else
		return false;
}