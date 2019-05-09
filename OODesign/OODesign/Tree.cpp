#include "Tree.h"

Tree::Tree(string typeOfTree)
{
	this->type = typeOfTree;
}

string Tree::getType()
{
	return this->type;
}

float Tree::getHeight()
{
	return this->height;
}

void Tree::setHeight(float height)
{
	this->height = height;
}

int Tree::getAge()
{
	return this->age;
}

void Tree::setAge(int age)
{
	this->age = age;
}

string Tree::getString()
{
	return "Type: " + type + " Height: " + to_string(height) + " Age: " + to_string(age);
}

bool Tree::isTallerThan(Tree & other)
{
	return height > other.height;
}

ostream & operator<<(ostream & os, const Tree & tree)
{
	os << "Type: " + tree.type + " Height: ";
	os << to_string(tree.height);
	os << " Age: " + to_string(tree.age);

	return os;
}
