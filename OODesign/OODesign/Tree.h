#pragma once
#include <string>
#include <ostream>

using namespace std;

class Tree
{
private:
	string type;
	float height;
	int age;
public:
	Tree(string type);
	string getType();
	
	float getHeight();
	void setHeight(float height);

	int getAge();
	void setAge(int age);

	string getString();

	bool isTallerThan(Tree& other);

	//https://stackoverflow.com/questions/22274115/overloading-left-shift-operator
	friend ostream& operator<<(ostream& os, const Tree& tree);
};