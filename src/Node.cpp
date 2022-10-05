#include "Node.hpp"
#include <string>
#include <cmath>
Node::Node(int veri)
{
	sol = NULL;
	sag = NULL;
	soy_sayisi = 0;
	this->veri = veri;
}
void Node::setSoy_sayisi(int soy_sayisi)
{
	this->soy_sayisi = soy_sayisi;
}
int Node::getSoy_sayisi()
{
	return soy_sayisi;
}
void Node::setVeri(int veri)
{
	this->veri = veri;
}
int Node::getVeri()
{
	return veri;
}
Node*&Node::getSol()
{
	return sol;
}
Node*& Node::getSag()
{
	return sag;
}
void Node::setSag(Node*sag)
{
	this->sag = sag;
}
void Node::setSol(Node*sol)
{
	this->sol = sol;
}
