//game lobby with dynamic memory implementation
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class player
{
private:
	string _name;
	player* _nextPlayer;
public:
	player(const string &n) : _name(n), _nextPlayer(0) {};
	player *getNextPlayer(void) {return _nextPlayer;}
    void setNextPlayer(player* b) {_nextPlayer = b;}
	string getName(void){return _name;}
};//class player

class lobby
{
public:
	void addPlayer(string a);
    void removePlayer(void);
	void display(void);
private:
	player* _firstPlayer = 0;
};//class lobby


//member function removes the player at the head of the line
void lobby::removePlayer(void)
{
    if(_firstPlayer==0)
    {
        cout << "Lobby is empty. There is no one to remove!!\n";
    }else
    {
            cout << "Removing the first player in the que...\n";
            player* temp = _firstPlayer;
            _firstPlayer = temp->getNextPlayer();
            delete temp;
    }
}

void lobby::addPlayer(string a)
{
    player *newPlayer = new player(a);//creating the player on heap

    if (_firstPlayer==0)
    {
        _firstPlayer = newPlayer;
        return;
    }else
    {
    	player* temp = _firstPlayer;
        while(temp->getNextPlayer()!=0)
        {
            temp = temp->getNextPlayer();
        }
        temp->setNextPlayer(newPlayer);
    }
}

void lobby::display(void)
{
    cout << "Displaying the players in the lobby:\n";
	player* temp = _firstPlayer;
	int counter = 0;
	while(temp->getNextPlayer()!=0)
	{
		counter++;
		cout << counter << "- " << temp->getName() << "\n";
		temp = temp->getNextPlayer();
	}
    counter++;
    cout << counter << "- " << temp->getName() << "\n\n";
}

int main(void)
{
	lobby kurbaga;
	kurbaga.addPlayer("mahmood");
	kurbaga.addPlayer("zekai");
	kurbaga.addPlayer("hamidoo");
    kurbaga.addPlayer("tuncay");
	kurbaga.display();
	kurbaga.removePlayer();
    cout << "\n";
	kurbaga.display();
}

