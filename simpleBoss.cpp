#include <iostream>

using namespace std;

class enemy
{
public:
	int _baseDamage;
	enemy(int bd) : _baseDamage(bd) {}
	void attack(void) const;
};//base class enemy

class boss:public enemy
{
public:
	int _damageMultiplier;
	//CHECK THIS OUT!!!
	//http://stackoverflow.com/questions/3319892/c-why-does-my-derivedclasss-constructor-not-have-access-to-the-baseclasss-p
	boss(int bd, int dm) : enemy(bd), _damageMultiplier(dm) {}
	//CHECK THIS OUT!!!
	void specialAttack(void) const;
};//boss class

void enemy::attack(void) const
{
	cout << "Attack inflicts " << _baseDamage << " damage!\n";
}

void boss::specialAttack(void) const
{
	cout << "Special attack inflicts " << _damageMultiplier*_baseDamage 
	<< " damage!\n";
}

int main(void)
{
	enemy simpleMonster(10);
	simpleMonster.attack();
	boss bigGuy(11,3);
	bigGuy.attack();
	bigGuy.specialAttack();
}

