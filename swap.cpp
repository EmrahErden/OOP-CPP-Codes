#include <iostream>

using namespace std;

void badSwap(int a, int b);
void goodSwap(int &a, int &b);
void displayScore(int myScore, int yourScore);
int main(void)
{
	int myScore = 500;
	int yourScore = 1000;

	displayScore(myScore, yourScore);
	cout << "\nCalling badSwap: \n";
	badSwap(myScore, yourScore);
	displayScore(myScore, yourScore);
	cout << "\nCalling goodSwap: \n";
	goodSwap(myScore, yourScore);
	displayScore(myScore, yourScore);
}

void badSwap(int a, int b)
{
	int c;
	c = b;
	b = a;
	a = c;
}

void goodSwap(int &a, int &b)
{
	int c;
	c = b;
	b = a;
	a = c;
}

void displayScore(int myScore, int yourScore)
{
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n";	
}
