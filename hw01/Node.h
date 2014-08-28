/* node.h */
/* last modified: 8/27/14 */
/*Emily Rose*/

#ifndef NODE
#define NODE
//----------------------------------------------------------------------
//  SPECIFICATION FILE (Node.h)
//  This module declares a new type for one Node
//----------------------------------------------------------------------

#include <string>

using namespace std;


class Node
{
public:
	Node();// Default constructor
	//------------Node()-------------
	//PRE: a declared Node object
	//POST: A Node object with assigned blank values (spaces hold the place of what will be there)
	//RETURNS: --
	//------------------------------

	Node(string rank, string network, string program, string airings, string viewers);// Constructor
	//------------Node()-------------
	//PRE: a declared Node object and assigned rank, network, program, airings, and viewers.
	//POST: A Node object with assigned values for all elements except next
	//RETURNS: --
	//-------------

	Node* next;	// pointer to the next node in list

	//the following are the elements contained in each column of the list.
	string rank; 
	string network;
	string program;
	string airings;
	string viewers;

}; // class Node


#endif






