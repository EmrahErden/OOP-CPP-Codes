#include <iostream>

using namespace std;

class critters
{
private:
	string* _name;
	int _age;
	critters();
public:
	critters(const string &n, int a);	//standard constructor
	critters(const critters &crit);	//copy constructor
	void announce(void) {cout << "I'm a critter named as " << *_name << 
	" and at the age of " << _age << "\n";}
	~critters(); //deconstructor
};//class critters

critters::critters(const string &n, int a)
{
	_name = new string(n);	//_name is pointing to heap memory
	_age = a;
}

critters::~critters(void)
{
	cout << "Destructor for a critters object was called\n";
	delete _name;	//delete the pointer, pointing to heap
}

//copy constructor
critters::critters(const critters &crit)
{
	_name = new string("coppied-"+*(crit._name));
	_age = crit._age;
}

int main(void)
{
	critters s1("Simon", 43);
	s1.announce();
	critters s2 = s1;
	s2.announce();
}
