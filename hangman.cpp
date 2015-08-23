#include <string>
#include <iostream>
#include <cctype>	//used for lower case conversion
#include <cstdio>	//used for exit
using namespace std;

#define MAX_NUM_WRONG 3

class guesser
{
private:
	string _secretWord;
	int _numWrongGuesses;
	int _secretWordLength;
	char _currentLetter;
	string _guessedLetters;
	string _currentGuess;
	guesser();
public:
	guesser(string theWord);
	void displayCurrentGuess(void) {cout << "The Current Guess: " << _currentGuess << "\n";}
	void guessedLetters(void) {cout << "Guessed Letters Up to Now: " << _guessedLetters << "\n";}
	void guessOne(char c);
	void displaySecret(void){cout << _secretWord << "\n";}
	int getNumWrongGuesses(void) {return _numWrongGuesses;}
	int getWordLength(void) {return _secretWordLength;}
	bool statusCheck(void);
};	//class guesser

bool guesser::statusCheck(void)
{
	if(!_secretWord.compare(_currentGuess))
	{
		cout << "\n\nBINGO, YOU WON THE INTERNET !!!\n\n\n";
		return true;
	}else
	{
		return false;
	}
}

guesser::guesser(string theWord)
{
	_numWrongGuesses = 0;
	_secretWord = theWord;
	_secretWordLength = theWord.size();
	_currentLetter = ' ';
	for(int i=0; i<_secretWordLength;i++)
	{
		_currentGuess+='-';
	}
}

void guesser::guessOne(char c)
{
	char theLetter;

	cout << "Please guess a letter : ";
	cin >> theLetter;

	_currentLetter = tolower(theLetter);
	_guessedLetters += _currentLetter;

	if(_secretWord.find(_currentLetter) != std::string::npos)
	{
		cout << "\nGZ!, You made a nice guess !! \n";

		for(int i=0; i < _secretWordLength; i++)
		{ 
			if (_secretWord[i]==_currentLetter)
				_currentGuess[i]=_currentLetter;
		}	
	}else
	{
		_numWrongGuesses+=1;
		cout << "\nYou made a wrong guess!!\n";	
	}	


}

int main(void)
{
	char theLetter;
	guesser w("hakmund");

	cout << "\nThe Game Hangman Initiated \n";
	cout << "Guess the word with " << w.getWordLength() << " letters: \n";
	w.displayCurrentGuess();

	while(w.getNumWrongGuesses()<MAX_NUM_WRONG)
	{
		cout << "********************************\n";
		w.guessOne(theLetter);
		w.displayCurrentGuess();
		w.guessedLetters();
		cout << "You have " << MAX_NUM_WRONG - w. getNumWrongGuesses() 
		<< " guesses left...\n";
		if(w.statusCheck())
		{
			return 0;
		}
	}
	cout << "\n\nSORRY, YOU LOST THE GAME!! LOSER!!!\n\n\n";
	return 0;
}
	

