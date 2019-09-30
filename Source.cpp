#include <iostream>
#include <time.h>
#include <stdlib.h>   

using namespace std;
class Car { //Class nfor car
public:
	string name, make, model; //String for car name, make and model
	double quarterTime, maxSpeed; //Double data type for quarter mile time and max speed
	void input() //Function to input car details by user
	{
		cout << "Enter car name:";
		cin >> name;
		cout << "Enter car make:";
		cin >> make;
		cout << "Enter car model:";
		cin >> model;
		cout << "Enter quarter mile time:";
		cin >> quarterTime;
		cout << "Enter max speed:";
		cin >> maxSpeed;
	}
	void display() //Function to diplay car details
	{
		cout << "Name:" << name;
		cout << " Make:" << make;
		cout << " Model:" << model; 
		cout << " Quarter mile time:" << quarterTime << " Max speed:" << maxSpeed << "\n";
	}
	int race(Car b) //Function to race the cars
	{
		srand(time(NULL)); //Seeding the random number generator
		//The below two lines of code add or remove some random time
		//between -1 to 1 to the quarter mile time of both cars.
		double one_red = ((double(rand()) / double(RAND_MAX)) * (1 + 1)) + 1;
		double two_red = ((double(rand()) / double(RAND_MAX)) * (1 + 1)) + 1;
		quarterTime += one_red;
		b.quarterTime += two_red;
		if (quarterTime < b.quarterTime) //If car 1 has lower quarter mile time, it wins
		{
			cout << name << " won by " << b.quarterTime - quarterTime;
			return 1;
		}
		if (quarterTime > b.quarterTime) //If car 2 has lower quarter mile time, it wins
		{
			cout << b.name << " won by " << quarterTime - b.quarterTime;
			return -1;
		}
		if (quarterTime == b.quarterTime) //If both cars win
		{
			cout << "No body won";
			return 0;
		}

	}
};

//Main function
int main() 
{
	int bal = 100; //Starting balance is 100 for the user

	while (bal > 0) //While user balance is greater than 0, he can play the game
	{
		int car_select;
		int result;
		int bet = 1;
		Car c1, c2; //Below lines of codes are for entering car details
		cout << "Enter Car 1 details" << endl;
		c1.input();
		cout << "Enter Car 2 details" << endl;
		c2.input();
		cout << " The details of the cars are:\n";
		//Displaying the details of the car for the user to choose
		cout << "1.";
		c1.display();
		cout << "2.";
		c2.display();
		cout << "Select which car to bet on(Press 1 or 2):";//Selecting which car to bet on
		cin >> car_select;
		cout << "Select the amount you want to bet:";
		while (1)//This would only take bet value which is between 1 and balance of user
		{
			cin >> bet;
			if (bet >= 1 && bet <= bal)
				break;
		}

		if (car_select) //Based on the car selection, race fucntion would be called
			result = c1.race(c2);
		else
			result = c2.race(c1);
		if (result) //If your car wins, result is 1
		{
			cout << "You won the bet. Your new balance is:";
			bal += bet;
			cout << bal << "\n";
		}
		else if (result == -1) //If your car looses, result is -1
		{
			cout << "You lost the bet. Your new balance is:";
			bal -= bet;
			cout << bal << "\n";
		}
		else //If race is draw
		{
			cout << "It was a draw. Your balance is:" << bal << "\n";
		}
	}

	return 0;
}