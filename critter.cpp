#include <iostream>

using namespace std;

class critter
{
private:
	int _hunger;
public:
	void greet(void) {cout << "Hello! I'm a critter and my hunger level is: " << _hunger << "\n";}
	void setHunger(int a) {_hunger=a;}
	critter(int hunger);
};	//critter class

critter::critter(int hunger)
{
	_hunger = hunger;
	cout << "A new critter has been born!!\n";
}

int main(void)
{
	critter a, b;
	a.setHunger(3);
	b.setHunger(9);
	a.greet();
	b.greet();
}
