#include "constants.h"
#include "functions.cpp"
#include "helper_functions.cpp"
#include <string.h>
using namespace std;

void main(){
	
	//Step 1: Replace all &'s and <'s with their escape characters
	currentLine = replaceAmp(currentLine);
	currentLine = replaceLeftAngle(currentLine);
}