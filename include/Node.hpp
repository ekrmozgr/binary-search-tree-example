#ifndef Node_HPP
#define Node_HPP
class Node
{
public:
	Node(int);
	int getVeri();
	void setVeri(int);
	int getSoy_sayisi();
	void setSoy_sayisi(int);
	Node*& getSol();
	Node*& getSag();
	void setSag(Node*);
	void setSol(Node*);
private:
	int veri;
	Node * sol;
	Node * sag;
	int soy_sayisi;
};
#endif

