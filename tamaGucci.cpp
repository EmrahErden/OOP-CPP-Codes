#include <iostream>

#define foodEffect 4
#define playEffect 4
#define aliveTreshold 25
#define lifeLimit 23

using namespace std;

class tamaGucci
{
private:
	int _boredom, _hunger, _lifeTime;
	tamaGucci();
public:
	tamaGucci(int b, int h) : _boredom(b), _hunger(h), _lifeTime(0) {}
	int getHunger(void) {return _hunger;}
	int getBoredom(void) {return _boredom;}
	int getHealth(void) {return _hunger+_boredom;}
	void feed(void) {_hunger -= foodEffect; if(_hunger<0) {_hunger=0;}}
	void play(void) {_boredom -= playEffect; if(_boredom<0) {_boredom=0;}}
	bool alive(void) {if(getHealth()<25) {return true;} else {return false;}}
	bool nirvana(void) {if (_lifeTime>=lifeLimit) {return true;} else {return false;}}
	void passTime(void) {_boredom++; _hunger++; _lifeTime++;}
	void display(void);
	void promptCommand(void);
}; //class tamaGucci

void tamaGucci::display(void)
{
	cout << "--------------------\n";
	cout << "| boredom = " << _boredom << "\n";
	cout << "| hunger  = " << _hunger << "\n";
	cout << "| lifeTime = " << _lifeTime << "\n";
	cout << "| health = " << getHealth() << "\n";
	cout << "| " << aliveTreshold << " is the critical value \n";
	cout << "--------------------\n";
}

void tamaGucci::promptCommand(void)
{
	static int choice;
	cout << "\nTamaGucci Caretaker\n\n";
	cout << "Please select a number: \n";
	cout << "1 - Play with TamaGucci\n";
	cout << "2 - Feed your TamaGucci\n";
	cout << "3 - Do nothing\n\n";
	cin >> choice;

	switch (choice)
	{
		case 1:
		play();
		break;

		case 2:
		feed();
		break;

		case 3:
		//do nothing;
		break;
		default:
		cout << "\nSorry, but " << choice << " isn’t a valid choice.\n";
	}

}

int main(void)
{
	tamaGucci memduh(3,4);
	while(memduh.alive() && !memduh.nirvana())
	{
		memduh.passTime();
		memduh.promptCommand();
		memduh.display();
	}

	if(memduh.nirvana())
	{
		cout << "\n\n\nYOUR PET HAS REACHED TO NIRVANA!!\n\n\n";
	}else
	{
		cout << "\n\n\nSORRY YOUR PET HAS JUST DIED...\n\n\n";
	}

}
