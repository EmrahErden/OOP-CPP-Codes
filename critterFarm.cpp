#include <iostream>
#include <vector>

using namespace std;

class critter
{
private:
	string _name;
public:
	critter(const string &name) : _name(name) {}
	string getName(void) const {return _name;}
	friend void peek(const critter &aCritter);
};//class critter

class farm
{
private:
	vector<critter> _critters;
public:
	farm(int maxSize=1) {_critters.reserve(maxSize);}
	void addCritter(const string &name) {_critters.push_back(critter(name));}
	void rollCall(void);
};//class farm

void peek(const critter &aCritter)
{
	cout << aCritter._name << "\n";
}

void farm::rollCall(void)
{
	for(vector<critter>::const_iterator iter = _critters.begin(); iter !=_critters.end(); iter++)
	{
		cout << "Calling " << iter->getName() << "\n";
	}
}

int main(void)
{
	farm myFarm(5);
	myFarm.addCritter("Feyzullah");
	myFarm.addCritter("Emrullah");
	myFarm.addCritter("Saadettin");
	myFarm.addCritter("Baattin");
	myFarm.addCritter("Ulvi");
	myFarm.addCritter("Kemalettin");
	myFarm.rollCall();
	critter hamza("Hamza");	//accessing to private member with a helper function
	peek(hamza);
}
