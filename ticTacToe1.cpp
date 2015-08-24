//g++ -std=c++11 ticTacToe1.cpp -o ticTacToe1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define X 0	//X is the human player
#define O 1	//O is the computer

class ttt
{
private:
	int _whoseMove;
	vector <int> _board = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
	const int WINNING_ROWS[8][3] = {{0,1,2},
				 	{3,4,5},
				 	{6,7,8},
				 	{0,3,6},
				 	{1,4,7},
				 	{2,5,8},
				 	{0,4,8},
				 	{2,4,6}};
public:
	void displayInstructions(void);
	void displayBoard(void);	//display the current situation on the board
	void askHumanStartsFirst(void);
	int getMove(void) {return _whoseMove;} 
	bool validMove(int loc);
	void makeMove(int loc);
	bool checkWin(void);
	bool checkDraw(void);

};// the tic tac toe class

bool ttt::checkDraw(void)
{
	if (count(_board.begin(), _board.end(), -1) == 0)
		return true;
	else
		return false;
}

bool ttt::checkWin(void)
{
	for(int j=0; j<8; j++)
	{
		if((_board[WINNING_ROWS[j][0]]==_board[WINNING_ROWS[j][1]])&&
		(_board[WINNING_ROWS[j][0]]==_board[WINNING_ROWS[j][2]])
		&&(_board[WINNING_ROWS[j][0]]!=-1))
			return true;
			
	}
	return false;
}

void ttt::makeMove(int loc)
{
	_board[loc] = _whoseMove;
	_whoseMove = (_whoseMove+1)%2;
}

bool ttt::validMove(int loc)
{
	if((loc>=0)&&(loc<9)&&(_board[loc]==-1))
		return true;
	else
		return false;
}

void ttt::askHumanStartsFirst(void)
{
	char start;
	cout << "Do you want to start first? (y/n) : ";
	cin >> start;

	if ((start=='y')||(start=='Y'))
		_whoseMove = X;
	else if ((start=='n')||(start=='N'))
		_whoseMove = O;
	else
		askHumanStartsFirst();
}

void ttt::displayInstructions(void)
{
cout << "\nWelcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
cout << "--where human brain is pit against silicon processor\n\n";
cout << "Make your move known by entering a number, 0 - 8. The number\n";
cout << "corresponds to the desired board position, as illustrated:\n\n";
cout << "0 | 1 | 2\n";
cout << "—————————\n";
cout << "3 | 4 | 5\n";
cout << "—————————\n";
cout << "6 | 7 | 8\n\n";
cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char showIt(int a)
{
	if (a==-1)
		return ' ';
	else if (a==0)
		return 'X';
	else if (a==1)
		return 'O';
}
void ttt::displayBoard(void)
{
	cout << "\n";
	for(int i=0; i<3; i++)
	{
		cout << showIt(_board[i*3]) << " | " << showIt(_board[i*3+1]) 
		<< " | " << showIt(_board[i*3+2]) << "\n";
		
		if(i<2)
			cout << "————————— \n";
	}
	cout << "\n";
}

int main(void)
{
	int theMove;
	ttt board;

	board.displayInstructions();
	board.askHumanStartsFirst();

	while(!(board.checkWin() || board.checkDraw()))
	{
		if(board.getMove()==0)	//if it's player's move
		{
			//ask player for move
			do
			{
				cout << "Please enter a valid move: ";
				cin >> theMove;
			}while(!board.validMove(theMove)); //try till get a valid move
			board.makeMove(theMove);

		}else	//if it is computer's move
		{
			do
			{
				theMove = rand()%9;
			}while(!board.validMove(theMove));
			board.makeMove(theMove);
		}
		board.displayBoard();
	}

	//displaying the result
	if(board.checkWin())
	{
		if(board.getMove()==1)	//remember, move changes after the play!!
		{
			cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
			cout << "But never again! I, the computer, so swear it!\n\n";
		}
		else
		{
			cout << "As I predicted, human, I am triumphant once more -- proof\n";
			cout << "that computers are superior to humans in all regards.\n\n";
		}
		return 0;
			
	}
	
	if(board.checkDraw())
	{
		cout << "You were most lucky, human, and somehow managed to tie me.\n";
		cout << "Celebrate. . . for this is the best you will ever achieve.\n\n";
		return 0;
	}

}
