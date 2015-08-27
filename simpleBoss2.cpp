#include<iostream>
#include<string>

using namespace std;

class enemy
{
protected:
	int _baseDamage; 
	string _name;
public:
	int getBaseDamage(void) const {return _baseDamage;}
	enemy(string n, int bd) : _name(n), _baseDamage(bd) {}
	void attack(void) const {cout << _name << "'s attack inflicted " 
	<< _baseDamage << " damage!\n";}
	void virtual taunt(void) {cout << _name << ": Swshhhh!!\n";}
};//class enemy

class boss : public enemy
{
private:
	int _damageMultiplier;
public:
	boss(string n, int bd, int m) : enemy(n, bd), _damageMultiplier(m) {}
	void specialAttack(void) const {cout << _name<< "'s special attack inflicted " 
	<<  _damageMultiplier * _baseDamage  
	<< " damage, and laughs heartily at you! \n";}
	void taunt(void) {cout << _name << ": Grosshwhswshs!!\n";}
};//boss class derived from enemy

int main(void)
{
	enemy b("Bogstrok", 19);
	b.taunt();
	b.attack();
	boss q("Quagmirran",29, 3);
	q.taunt();
	q.attack();
	q.specialAttack();
}
