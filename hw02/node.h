/* node.h */
/* last modified: 8/27/14 */
/*Emily Rose*/

#ifndef NODE_H_
#define NODE_H_
//----------------------------------------------------------------------
//  SPECIFICATION FILE (node.h)
//  This module declares a new type for one Node.
//  This file declares all members of the new Node class.  The functions 
//		within the class allow the user to assign and retreive assigned 
//      values of the different members of the class.
//----------------------------------------------------------------------

#include <string>

using namespace std;

//The Node class is to be used to make a linked list with each entry 
//	containing five string values: a rank, a network, a program name, 
//	an airings count, and a viewers count.  The sixth value is a 
//	pointer to the next entry in the list.
class Node
{
 public:
	// Default constructor
	//------------Node()-------------
	//PRE: the name of the new Node object
	//POST: A Node object with assigned blank values (spaces hold the place of what will be there)
	//RETURNS: --
	//------------------------------
	Node();


	//------------Node()-------------
	//PRE: a declared Node object and assigned rank, network, program, airings, and viewers.
	//POST: A Node object with assigned values for all elements except next
	//RETURNS: --
	//-------------
	Node(string rank, string network, string program, string airings, string viewers);// Constructor


	//------------setNext()-------------
	//PRE: a declared Node and a declared pointer to another Node.
	//POST: pointer is assigned to the 'next_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setNext(Node *new_next);


	//------------setRank()-------------
	//PRE: a declared Node and a declared string that represents the ranking of this node
	//POST: string is assigned to the 'rank_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setRank(string new_rank);


	//------------setNet()-------------
	//PRE: a declared Node and a declared string that represents the network of this node
	//POST: string is assigned to the 'network_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setNet(string new_net);


	//------------setProg()-------------
	//PRE: a declared Node and a declared string that represents the program name of this node
	//POST: string is assigned to the 'program_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setProg(string new_prog);


	//------------setAir()-------------
	//PRE: a declared Node and a declared string that represents the airing count of this node
	//POST: string is assigned to the 'airings_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setAir(string new_air);


	//------------setView()-------------
	//PRE: a declared Node and a declared string that represents the viewer number of this node
	//POST: string is assigned to the 'viewers_' member of the declared Node.
	//RETURNS: --
	//-------------
	void setView(string new_view);


	//------------getNext()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the pointer located in the 'next_' member of the declared Node.
	//-------------
	Node* getNext();


	//------------getRank()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the string located in the 'rank_' member of the declared Node.
	//-------------
	string getRank();


	//------------getNet()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the string located in the 'network_' member of the declared Node.
	//-------------
	string getNet();


	//------------getProg()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the string located in the 'program_' member of the declared Node.
	//-------------
	string getProg();


	//------------getAir()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the string located in the 'airings_' member of the declared Node.
	//-------------
	string getAir();


	//------------getView()-------------
	//PRE: a declared Node
	//POST: --
	//RETURNS: the string located in the 'viewers_' member of the declared Node.
	//-------------
	string getView();

 private:

	Node* next_;	// pointer to the next node in list

	//the following are the elements contained in each column of the list.
	string rank_;			// ranking of the program
	string network_;		// network that the program airs on
	string program_;		// name of the program
	string airings_;		// times the program has aired
	string viewers_;		// number of viewers of the program
	
}; // class Node


#endif // NODE_H_






