/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Emily Rose - Homework #1

Date last modified: August 28, 2014

Summary: This program imports a list of the top 50 television shows in the United States from a 
			.txt file and provides the user with the option of searching through and viewing the
			list.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
INPUT:	(from .txt file): a csv list containing the ranking, network name, program name, number 
			of airings, and number of viewers for the top 50 shows in the U.S.A.
		(from stdin): User must enter codes when prompted into stdin in order to navigate through
			the program.  

OUTPUT: (to console, stdout): Title of the program, prompts for user input to navigate program, 
			the list if user requests it, and the search results of user's search. Appropriate 
			error messages will appear based on the user's input.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

const int MAX = 50;
void search(Node *firstNode);
void searchRank(Node *firstNode, string choice); 
void searchNetwork(Node *firstNode, string choice);
void searchProgram(Node *firstNode, string choice);
void searchAirings(Node *firstNode, string choice);
void searchViewers(Node *firstNode, string choice);
void printList(Node *firstNode);

void main()
{
	cout << "~~~~~America's Top 50 TV Shows of 2012-2013~~~~~\n";
	ifstream File("ListofTVShows.txt");		//open file

	Node *oldNode;							//Node
	oldNode = new Node;						//initialize

	Node *firstNode;						//Beginning Node (copy of oldNode)
	firstNode = new Node;					//initialize
	firstNode = oldNode;
		
	
	if (File.is_open())						//If the file sucessfully opened...
	{
		
		while (File.good())					//While there are still bits remaining in the file....
		{

			Node *currNode;							//Will be the node which the program is working with at a specific moment.
			currNode = new Node; 					//initialize

			oldNode->next = currNode;		//Assign oldNode to be the node preceeding the current node.


			getline(File, currNode->rank, ',');	//import rank from list and assign to current node


			getline(File, currNode->network, ',');	//import network from list and assign to current node

			getline(File, currNode->program, ',');	//import program name from list and assign to current node

			getline(File, currNode->airings, ',');	//import airing count from list and assign to current node
			getline(File, currNode->viewers, ',');	//import viewer count from list and assign to current node

			oldNode = currNode;						//move oldNode one node forward

		}
	}
	else
	{
		cout << string("There has been an error. File did not open correctly \n");
	}

	//// Search for a value ////
	char yesOrNo;			//will hold user's choice
	cout << "Print list before searching? (Y/N) ";
	cin >> yesOrNo;			//take user's choice
	if (yesOrNo == 'Y')
		printList(firstNode);	//if user wants to print the list, print the list.
	else
	{
		if (yesOrNo == 'N')
			search(firstNode);	//if user does not want to print the list, continue to search.
		else
		{
			cout << "I don't understand, so I'll print it for you just in case. \n";	//user error catcher.
			printList(firstNode);		//print the list
		}
	}
	
	
	
	system("PAUSE");
}

void search(Node *firstNode)
{
	cout << "\nSearch Codes: " << "\n" << "Ranking: 1" << "\n" << "Network: 2" << "\n" << "Program: 3" << "\n" << "Airings: 4" << "\n" << "Viewers: 5" << "\n" << "Exit: 0" << "\n" << "Please enter the code for the search method you would like to use: ";
				//present user with search codes
	int code;	//create variable to hold user's code choice
	string choice;
	cin >> code;	// get user's code.


	if (code == 0)
	{
		cout << "\nThanks! Bye!\n";
	}
	else
	{
		if (code == 1)	//if user chose ranking
		{
			cout << "\nPlease enter the rank you would like to see the entry for: ";
			cin >> choice;	//get user's choice
			searchRank(firstNode, choice);	//start search
		}

		else
		{
			if (code == 2)	//if user chose network
			{
				cout << "\nPlease enter the three letter network code you would like to see the top entry for: ";
				cin >> choice;	// get user's choice
				searchNetwork(firstNode, choice); //start search
			}
			else
			{
				if (code == 3)	//if user chose program
				{
					cout << "\nPlease enter the full name of the program you would like to see the entry for: ";
					cin >> choice;	// get user's choice
					searchProgram(firstNode, choice);	//start search
				}
				else
				{
					if (code == 4)	//if user chose airings
					{
						cout << "\nPlease enter the number of airings you would like to see the top entry for: ";
						cin >> choice;	//get user's choice
						searchAirings(firstNode, choice);	//start search
					}
					else
					{
						if (code == 5)	//if user chose viewers
						{
							cout << "\nPlease enter the number of viewers you would like to see top the entry for: ";
							cin >> choice;				//get user's choice
							searchViewers(firstNode, choice);	//start search
						}
						else
							cout << "Sorry, I don't understand your input.\n";	//if user entered something incorrect
						}

				}
			}
		}
	}
}


void searchRank(Node *firstNode, string choice)
{
	int count = 0;
	Node *nextNode;
	nextNode = new Node;
	nextNode = firstNode;
	string currentRank = "start";
	while ((currentRank.compare(choice) != 0) && (count < MAX))
	{
		count = count + 1;
		nextNode = nextNode->next;
		currentRank = nextNode->rank;
	}
	if (currentRank.compare(choice) == 0)
		cout << "Rank:" << nextNode->rank << "  Network:" << nextNode->network << "  Program:" << nextNode->program << "  Airings:" << nextNode->airings << "  Viewers:" << nextNode->viewers << "\n\n\n";
	else
	{
		cout << "No such rank found. Please try again.";
		search(firstNode);
	}
		
}
void searchNetwork(Node *firstNode, string choice)
{
	int count = 0;
	Node *nextNode;
	nextNode = new Node;
	nextNode = firstNode;
	string currentNetwork = "~";
	while ((currentNetwork.compare(choice) != 0) && (count < MAX))
	{
		count = count + 1;
		nextNode = nextNode->next;
		currentNetwork = nextNode->network;
	}
	if (currentNetwork.compare(choice) == 0)
		cout << "Rank:" << nextNode->rank << "  Network:" << nextNode->network << "  Program:" << nextNode->program << "  Airings:" << nextNode->airings << "  Viewers:" << nextNode->viewers << "\n\n\n";
	else
	{
		cout << "No such network found. Please try again.";
		search(firstNode);
	}

}

void searchProgram(Node *firstNode, string choice)
{
	int count = 0;
	Node *nextNode;
	nextNode = new Node;
	nextNode = firstNode;
	string currentProgram = "~";
	while ((currentProgram.compare(choice) != 0) && (count < MAX))
	{
		count = count + 1;
		nextNode = nextNode->next;
		currentProgram = nextNode->program;
	}
	if (currentProgram.compare(choice) == 0)
		cout << "Rank:" << nextNode->rank << "  Network:" << nextNode->network << "  Program:" << nextNode->program << "  Airings:" << nextNode->airings << "  Viewers:" << nextNode->viewers << "\n\n\n";
	else {
		cout << "No such program found. Please try again.";
		search(firstNode);
	}

}

void searchAirings(Node *firstNode, string choice)
{
	int count = 0;
	Node *nextNode;
	nextNode = new Node;
	nextNode = firstNode;
	string currentAirings = "start";
	while ((currentAirings.compare(choice) != 0) && (count < MAX))
	{
		count = count + 1;
		nextNode = nextNode->next;
		currentAirings = nextNode->airings;
	}
	if (currentAirings.compare(choice) == 0)
		cout << "Rank:" << nextNode->rank << "  Network:" << nextNode->network << "  Program:" << nextNode->program << "  Airings:" << nextNode->airings << "  Viewers:" << nextNode->viewers << "\n\n\n";
	else
	{
		cout << "No such airing found. Please try again.";
		search(firstNode);
	}

}
void searchViewers(Node *firstNode, string choice)
{
	int count = 0;
	Node *nextNode;
	nextNode = new Node;
	nextNode = firstNode;
	string currentViewers = "start";
	while ((currentViewers.compare(choice) != 0) && (count < MAX))
	{
		count = count + 1;
		nextNode = nextNode->next;
		currentViewers = nextNode->viewers;
	}
	if (currentViewers.compare(choice) == 0)
		cout << "Rank:" << nextNode->rank << "  Network:" << nextNode->network << "  Program:" << nextNode->program << "  Airings:" << nextNode->airings << "  Viewers:" << nextNode->viewers << "\n\n\n";
	else
	{
		cout << "No such viewer number found. Please try again.";
		search(firstNode);
	}

}
void printList(Node *firstNode)
{
	int count = 0;
	Node *currNode;
	currNode = firstNode->next; //node we are currently looking at (start at first)
	while (count < MAX)
	{
		cout << "Rank:" << currNode->rank << "  Network:" << currNode->network << "  Program:" << currNode->program << "  Airings:" << currNode->airings << "  Viewers:" << currNode->viewers << "\n";
		currNode = currNode->next;
		count = count + 1;
	}
	search(firstNode);
}