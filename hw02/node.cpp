//node.cpp
//Emily Rose
#include "stdafx.h"
#include <string>
#include "node.h"

using namespace std;


// ======================================================================
Node::Node()					// Default CTOR
{
	string nothing = " ";
	this->rank_ = nothing;
	this->network_ = nothing;
	this->program_ = nothing;
	this->airings_ = nothing;
	this->viewers_ = nothing;

}// CTOR

// ======================================================================

// ======================================================================
Node::Node(string rank, string network, string program, string airings, string viewers)// Default CTOR
{
	this->rank_ = rank;
	this->network_ = network;
	this->program_ = program;
	this->airings_ = airings;
	this->viewers_ = viewers;

}// CTOR
// ======================================================================

void Node::setNext(Node* new_next)
{
	this->next_ = new_next;
}
void Node::setRank(string new_rank)
{
	this->rank_ = new_rank;
}
void Node::setNet(string new_net)
{
	this->network_ = new_net;
}
void Node::setProg(string new_prog)
{
	this->program_ = new_prog;
}
void Node::setAir(string new_air)
{
	this->airings_ = new_air;
}
void Node::setView(string new_view)
{
	this->viewers_ = new_view;
}

Node* Node::getNext()
{
	return this->next_;
}
string Node::getRank()
{
	return this->rank_;
}
string Node::getNet()
{
	return this->network_;
}
string Node::getProg()
{
	return this->program_;
}
string Node::getAir()
{
	return this->airings_;
}
string Node::getView()
{
	return this->viewers_;
}