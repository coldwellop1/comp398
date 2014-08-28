//Node.cpp
//Emily Rose
#include "stdafx.h"
#include "Node.h"
#include <string>

using namespace std;


// ======================================================================
Node::Node()					// Default CTOR
{
	string nothing = " ";
	this->rank = nothing;
	this->network = nothing;
	this->program = nothing;
	this->airings = nothing;
	this->viewers = nothing;

}// CTOR

// ======================================================================

// ======================================================================
Node::Node(string rank, string network, string program, string airings, string viewers)					// Default CTOR
{
	this->rank = rank;
	this->network = network;
	this->program = program;
	this->airings = airings;
	this->viewers = viewers;

}// CTOR
// ======================================================================