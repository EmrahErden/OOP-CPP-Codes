#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class scoreList
{
private:
	vector<int> _scores;
public:
	void addScore(int a) {_scores.push_back(a);}
	void sortScores(void) {sort(_scores.begin(), _scores.end());}
	void printScores(void);
	bool findScore(int a);
};	//class numbers

void scoreList::printScores(void)
{
	vector<int>::iterator iter;

	cout << "\nListing the scores:\n";
	for(iter=_scores.begin(); iter!=_scores.end(); iter++)
	{
		cout << *iter << "\n";
	}
	cout << "\n";
}

bool scoreList::findScore(int a)
{
	vector<int>::iterator iter;
	iter = find(_scores.begin(), _scores.end(), a);
	if (iter!=_scores.end())
		return true;
	else
		return false;	
}

int main(void)
{
	scoreList a;
	a.addScore(1500);
	a.addScore(2000);
	a.addScore(3);	
	a.printScores();
	a.sortScores();
	a.printScores();
	cout << a.findScore(300) << "\n";
	cout << a.findScore(3) << "\n";
}
