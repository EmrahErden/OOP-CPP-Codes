/* 
Because pointers work in such a unique way, programmers often prefix pointer
variable names with the letter “p” to remind them that the variable is indeed a
pointer.

Assigning 0 to a pointer has special meaning. Loosely translated, it means,
“Point to nothing.”

*/

#include <iostream>

using namespace std;

int main(void)
{
	int* pscore1;
	int* pscore2 = 0;
	int score1 = 1000;
	int score2 = 3;

	cout << "pscore1: " << pscore1 << "\n";
	cout << "pscore2: " << pscore2 << "\n";
	pscore1 = &score1;
	pscore2 = &score2;	
	cout << "\n";
	cout << "&score1: " << &score1 << "\n";
	cout << "&score2: " << &score2 << "\n";
	cout << "pscore1: " << pscore1 << "\n";
	cout << "pscore2: " << pscore2 << "\n";
	cout << "*pscore1: " << *pscore1 << "\n";
	cout << "*pscore2: " << *pscore2 << "\n";
	*pscore2 = 300500;
	cout << "score2: " << score2 << "\n"; 
}
