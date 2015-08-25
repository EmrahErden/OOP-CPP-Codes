#include <iostream>

using namespace std;

class critter
{
private:
	int _hunger;
public:
	static int _total;
	//static member variable declaration
	//total number of critter objects in existence
	void greet(void) const {cout << "Hello! I'm a critter and my hunger level is: " << _hunger << "\n";}
	void setHunger(int hunger);
	int getHunger(void) const {return _hunger;}
	critter(int hunger);
	static int getTotal(void) {return _total;}	//returns total number of critters
};	//critter class

/*
The major difference is that a static member function cannot access non-static data members. 
This is because a static member function exists for the entire class and is not associated with any
particular instance of the class.

You can also access a static member function through any object of the class.
*/

/*
As you can see from the declaration, the constructor has no return type. It can’t—
it’s illegal to specify a return type for a constructor.
*/
critter::critter(int hunger)
{
	_hunger = hunger;
	cout << "A new critter has been born!!\n";
	_total += 1;
}

void critter::setHunger(int hunger)
{
	if (hunger<0)
	{
		cout << "You can’t set a critter’s hunger to a negative number.\n";
	}else
	{
		_hunger = hunger;
	}
}

int critter::_total = 0;

int main(void)
{
	critter a(3), b(9);
	cout << critter::getTotal() << "\n";
	a.greet();
	b.greet();
	a.setHunger(-1);
	a.setHunger(300);
	a.greet();
	critter c(32);
	cout << critter::getTotal() << "\n";
}
