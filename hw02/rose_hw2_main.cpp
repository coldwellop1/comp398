/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Emily Rose - Homework #2

Date last modified: September 1, 2014

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
#include "node.h"

//------------search()-------------
//PRE: the first Node in the linked list
//POST: presents the user with a menu of codes that can be used to search 
//      through the list, accepts 1 code and 1 search term from the user, 
//		and follows the code to either another function or exits the 
//		program (0 or unknown)
//RETURNS: Nothing unless code is '0' or unknown to program. Then a message
//		is printed to the screen and program exits.
//-------------
void search(Node *first_node);

//------------searchRank()-------------
//PRE: the user elected code 1 in the search() function. Assigned first 
//		node of linked list and search term from user
//POST: searches linearly through linked list to find rank requested in 
//		search term.
//RETURNS: complete report of the entry that matches the search term or 
//		error message if term not found.
//-------------
void searchRank(Node *first_node, string choice); 

//------------searchNetwork()-------------
//PRE: the user elected code 2 in the search() function. Assigned first 
//		node of linked list and search term from user
//POST: searches linearly through linked list to find network requested 
//		in search term.
//RETURNS: complete report of the entry that matches the search term or 
//		error message if term not found.
//-------------
void searchNetwork(Node *first_node, string choice);

//------------searchProgram()-------------
//PRE: the user elected code 3 in the search() function. Assigned first 
//		node of linked list and search term from user
//POST: searches linearly through linked list to find program requested
//		in search term.
//RETURNS: complete report of the entry that matches the search term or 
//		error message if term not found.
//-------------
void searchProgram(Node *first_node, string choice);

//------------searchAirings()-------------
//PRE: the user elected code 4 in the search() function. Assigned first 
//		node of linked list and search term from user
//POST: searches linearly through linked list to find airings count 
//		requested in search term.
//RETURNS: complete report of the entry that matches the search term 
//		or error message if term not found.
//-------------
void searchAirings(Node *first_node, string choice);

//------------searchViewers()-------------
//PRE: the user elected code 5 in the search() function. Assigned first 
//		node of linked list and search term from user
//POST: searches linearly through linked list to find viewership requested 
//		in search term.
//RETURNS: complete report of the entry that matches the search term or 
//		error message if term not found.
//-------------
void searchViewers(Node *first_node, string choice);

//------------searchNetwork()-------------
//PRE: the user either elected to print the entire list to stdout OR entered 
//		an unknown term
//POST: entire linked list is printed to the console.  
//RETURNS: none
//-------------
void printList(Node *first_node);

int kMax = 50;
void main()
{
	cout << "~~~~~America's Top 50 TV Shows of 2012-2013~~~~~\n";
	ifstream File("list_of_tv_shows.txt");		//open file

	Node *old_node = new Node;						//initialize

	Node *first_node = new Node;					//initialize
	first_node = old_node;

	//set up variables to be used in while loop
	string new_rank, new_net, new_prog, new_air, new_view;
	
	
	if (File.is_open())						//If the file sucessfully opened...
	{
		
		while (File.good())					//While there are still bits 
												//remaining in the file....
		{

			Node *current_node = new Node; 					//initialize
			old_node->setNext(current_node);

			getline(File, new_rank, ',');	//import rank from list and assign 
												//to current node
			current_node->setRank(new_rank);

			getline(File, new_net, ',');	//import network from list and 
												//assign to current node
			current_node->setNet(new_net);

			getline(File, new_prog, ',');	//import program name from list and 
												//assign to current node
			current_node->setProg(new_prog);

			getline(File, new_air, ',');	//import airing count from list and 
												//assign to current node
			current_node->setAir(new_air);

			getline(File, new_view, ',');	//import viewer count from list and 
												//assign to current node
			current_node->setView(new_view);

			old_node = current_node;		//move old_node one node forward

		}
	}
	else
	{
		cout << string("There has been an error. File did not open correctly \n");
	}

	//// Search for a value ////
	char yes_or_no;			//will hold user's choice
	cout << "Print list before searching? (Y/N) ";
	cin >> yes_or_no;			//take user's choice
	if (yes_or_no == 'Y')
		printList(first_node);	//if user wants to print the list, print the list.
	else
	{
		if (yes_or_no == 'N')
			search(first_node);	//if user does not want to print the list, 
									//continue to search.
		else
		{
			cout << "I don't understand, so I'll print it for you just in case. \n";	
											//user error catcher.
			printList(first_node);		//print the list
		}
	}
	
	
	
	system("PAUSE");
}

void search(Node *first_node)
{
	cout << "\nSearch Codes: " << "\n" << "Ranking: 1" << "\n";
	cout << "Network: 2" << "\n" << "Program: 3" << "\n" << "Airings: 4";
	cout << "\n" << "Viewers: 5" << "\n" << "Exit: 0" << "\n" << "Please ";
	cout << "enter the code for the search method you would like to use : ";
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
			cout << "\nPlease enter the rank you would like to see";
			cout << "the entry for: ";
			cin >> choice;	//get user's choice
			searchRank(first_node, choice);	//start search
		}

		else
		{
			if (code == 2)	//if user chose network
			{
				cout << "\nPlease enter the three letter network code";
				cout << " you would like to see the top entry for: ";
				cin >> choice;	// get user's choice
				searchNetwork(first_node, choice); //start search
			}
			else
			{
				if (code == 3)	//if user chose program
				{
					cout << "\nPlease enter the full name of the program ";
					cout << "you would like to see the entry for: ";
					cin >> choice;	// get user's choice
					searchProgram(first_node, choice);	//start search
				}
				else
				{
					if (code == 4)	//if user chose airings
					{
						cout << "\nPlease enter the number of airings you ";
						cout << "would like to see the top entry for: ";
						cin >> choice;	//get user's choice
						searchAirings(first_node, choice);	//start search
					}
					else
					{
						if (code == 5)	//if user chose viewers
						{
							cout << "\nPlease enter the number of viewers you ";
							cout << "would like to see top the entry for: ";
							cin >> choice;				//get user's choice
							searchViewers(first_node, choice);	//start search
						}
						else
							cout << "Sorry, I don't understand your input.\n";	
											//if user entered something incorrect
						}

				}
			}
		}
	}
}

void searchRank(Node *first_node, string choice)
{
	int count = 0;
	Node *next_node = new Node;
	next_node = first_node;				//start searching at the beginning of the 
											//linked list.
	string current_rank = "start";
	while ((current_rank.compare(choice) != 0) && (count < kMax))	
					//while the entry of the current node isn't what we're looking for 
									//AND we haven't reached the end of the list...
	{
		++count;
		next_node = next_node->getNext();					//move to next node
		current_rank = next_node->getRank();			//load next entry to evaluate
	}
	if (current_rank.compare(choice) == 0)			// if the program finds it, 
		//it is printed to console.
	{
		cout << "Rank:" << next_node->getRank() << "  Network:" << next_node->getNet();
		cout << "  Program:" << next_node->getProg() << "  Airings:" << next_node->getAir();
		cout << "  Viewers:" << next_node->getView() << "\n\n\n";
	}
	else
	{			//otherwise an error message is displayed.
		cout << "No such rank found. Please try again.";
		search(first_node);
	}
		
}
void searchNetwork(Node *first_node, string choice)
{
	int count = 0;
	Node *next_node = new Node;
	next_node = first_node;				//start searching at the beginning of the linked list.
	string currentNetwork = "~";
	while ((currentNetwork.compare(choice) != 0) && (count < kMax))	
							//while the entry of the current node isn't what we're looking for 
												//AND we haven't reached the end of the list...
	{
		++count;
		next_node = next_node->getNext();						//move to next node
		currentNetwork = next_node->getNet();					//load next entry to evaluate
	}
	if (currentNetwork.compare(choice) == 0)
		// if the program finds it, it is printed to console.
	{
		cout << "Rank:" << next_node->getRank() << "  Network:";
		cout << next_node->getNet() << "  Program:" << next_node->getProg();
		cout << "  Airings:" << next_node->getAir() << "  Viewers:";
		cout << next_node->getView() << "\n\n\n";
	}
	else
	{			//otherwise an error message is displayed.
		cout << "No such network found. Please try again.";
		search(first_node);
	}

}
void searchProgram(Node *first_node, string choice)
{
	int count = 0;
	Node *next_node = new Node;
	next_node = first_node;				
			//start searching at the beginning of the linked list.
	string current_program = "~";
	while ((current_program.compare(choice) != 0) && (count < kMax))	
						//while the entry of the current node isn't what we're looking for 
												//AND we haven't reached the end of the list...
	{
		++count;
		next_node = next_node->getNext();						//move to next node
		current_program = next_node->getProg();					//load next entry to evaluate
	}
	if (current_program.compare(choice) == 0)
		// if the program finds it, it is printed to console.
	{
		cout << "Rank:" << next_node->getRank() << "  Network:" << next_node->getNet();
		cout << "  Program:" << next_node->getProg() << "  Airings:" << next_node->getAir();
		cout << "  Viewers:" << next_node->getView() << "\n\n\n";
	}
	else 
	{			//otherwise an error message is displayed.
		cout << "No such program found. Please try again.";
		search(first_node);
	}

}
void searchAirings(Node *first_node, string choice)
{
	int count = 0;
	Node *next_node = new Node;
	next_node = first_node;				
							//start searching at the beginning of the linked list.
	string current_airings = "start";
	while ((current_airings.compare(choice) != 0) && (count < kMax))	
							//while the entry of the current node isn't what we're looking for 
													//AND we haven't reached the end of the list...
	{
		++count;
		next_node = next_node->getNext();						//move to next node
		current_airings = next_node->getAir();					//load next entry to evaluate
	}
	if (current_airings.compare(choice) == 0)			// if the program finds it, it is printed to console.
	{
		cout << "Rank:" << next_node->getRank() << "  Network:" << next_node->getNet();
		cout << "  Program:" << next_node->getProg() << "  Airings:" << next_node->getAir();
		cout << "  Viewers:" << next_node->getView() << "\n\n\n";
	}
	else
	{			//otherwise an error message is displayed.
		cout << "No such airing found. Please try again.";
		search(first_node);
	}
}
void searchViewers(Node *first_node, string choice)
{
	int count = 0;
	Node *next_node = new Node;
	next_node = first_node;				
							//start searching at the beginning of the linked list.
	string current_viewers = "start";
	while ((current_viewers.compare(choice) != 0) && (count < kMax))	
							//while the entry of the current node isn't what we're looking for 
												//AND we haven't reached the end of the list...
	{
		++count;
		next_node = next_node->getNext();					//move to next node
		current_viewers = next_node->getView();				//load next entry to evaluate
	}
	if (current_viewers.compare(choice) == 0)
		// if the program finds it, it is printed to console.
	{
		cout << "Rank:" << next_node->getRank() << "  Network:" << next_node->getNet();
		cout << "  Program:" << next_node->getProg() << "  Airings:" << next_node->getAir();
		cout << "  Viewers:" << next_node->getView() << "\n\n\n";
	}
	else
	{			//otherwise an error message is displayed.
		cout << "No such viewer number found. Please try again.";
		search(first_node);
	}

}
void printList(Node *first_node)
{
	int count = 0;
	Node *current_node = first_node->getNext(); 
				//node we are currently looking at (start at first)
	while (count < kMax)
	{
		++count;
		cout << "Rank:" << current_node->getRank() << "  Network:" << current_node->getNet();
		cout << "  Program:" << current_node->getProg() << "  Airings:" << current_node->getAir();
		cout << "  Viewers:" << current_node->getView() << "\n\n\n";
		current_node = current_node->getNext();						//load next entry to output to console
	}
	search(first_node);
}