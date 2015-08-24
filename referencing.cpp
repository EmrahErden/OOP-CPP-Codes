#include <iostream>

using namespace std;

int main(void)
{
	int myScore;
	int& emrahScore = myScore;
	cout << "myScore is: ";
	cin >> myScore;
	cout << "emrahScore is: " << emrahScore << "\n";
	cout << "\n";
	myScore += 500;
	cout << "Adding 500 to myScore: " << myScore << "\n";
	cout << "emrahScore is : " << emrahScore << "\n";	
}
