#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main()
{
	string treeType;
	
	cout << "What type of tree do you have? ";
	cin >> treeType;

	Tree myTree(treeType);

	float height;
	cout << "How tall is your tree? ";
	cin >> height;

	myTree.setHeight(height);

	int age;
	cout << "How old is your tree? ";
	cin >> age;

	myTree.setAge(age);

	cout << "Tree type: " << myTree.getType();
	cout << " Height:" << myTree.getHeight();
	cout << " Age: " << myTree.getAge();
	cout << endl;

	cout << myTree.getString() << endl;

	cout << myTree << endl;

	Tree mapleTree("Maple");
	mapleTree.setAge(50);
	mapleTree.setHeight(40.0);

	if (myTree.isTallerThan(mapleTree))
	{
		cout << "My tree is taller than yours!" << endl;
	}
	else
	{
		cout << "The maple tree is king!" << endl;
	}

	system("pause");
	return 0;
}