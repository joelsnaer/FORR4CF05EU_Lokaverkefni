#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>#include <ctime>
#include <time.h>;

/*
Jóel Snær Garcia
3.5.2018
Lokaverkefni - Leikjaklasi
*/
using namespace std;

//Base class leikir
class Leikir {
private:
	int wins = 0;
	int losses = 0;
public:
	int getWins(){ return this->wins; };
	int getLosses(){ return this->losses; };
	void setWin(){ wins++; };
	void setLoss() { losses++; };

};
//Hengimaður
class Hengimann : Leikir {
private:
	int max = 5;
	char letter;
	int guess = 0;
	string word;
public:
	void play();
	void score();
	int giskaStaf(char guess, string secretword, string &guessword);
};
void Hengimann::play(){
	string words[] =
	{
		"iceland",
		"america",
		"russia",
		"malaysia",
		"philippines",
		"australia",
		"china",
		"ethiopia",
		"nigeria",
		"indonesia"
	};
	guess = 0;
	system("cls");
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];
	string giskuord(word.length(), '*'); // Búið til streng jafn langan og word sem er bara stjarna
	cout << "Welcome to hangman, you have " << max << " number of guesses" << endl;
	while (guess < max)
	{
		cout << giskuord << endl;
		cout << "Guess a letter: " << endl;
		cin >> letter;
		if (giskaStaf(letter, word, giskuord) == 0)
		{
			cout << "That letter isn't part of the word" << endl;
			guess++;
		}
		else
		{
			cout << "That letter is in the word" << endl;
		}
		cout << "You have " << max - guess << " many guesses left" << endl;
		if (word == giskuord)
		{
			cout << word << endl;
			cout << "Congratulations you guessed the word correctly" << endl;
			Hengimann::setWin();
			break;
		}
	}
	if (guess == max)
	{
		cout << "You lost, better luck next time" << endl;
		cout << "The word was: " << word << endl;
		Hengimann::setLoss();
	}
}
int Hengimann::giskaStaf(char gisk, string ord, string &guessword)
{
	int i;
	int matches = 0;
	int len = ord.length();
	for (i = 0; i< len; i++){
		if (gisk == guessword[i]) {
			return 0;
		}
		if (gisk == ord[i]){
			guessword[i] = gisk;
			matches++;
		}
	}
	return matches;
}
void Hengimann::score(){
	cout << "Hangman: Wins: " << Hengimann::getWins() << " Losses: " << Hengimann::getLosses() << "\n";
}
//Skæri blað steinn
class SkBlSt : Leikir {
private:
	int val;
	int valTolvu;
public:
	void play();
	void score();
};
void SkBlSt::play(){
	system("CLS");
	int playing = 0;
	srand(time(NULL));
	while(playing == 0){
		valTolvu = rand() % 3 + 1; //1 = Rock, 2 = Paper, 3 = Scissors
		cout << "Choose what you are going to do, Rock(1), Paper(2), Scissors(3)" << endl;
		cin >> val;
		if (val == valTolvu){
			cout << "There was a tie, keep playing" << endl;
		}
		else if ((val == 1 && valTolvu == 3) || (val == 2 && valTolvu == 1) || (val == 3 && valTolvu == 2)){
			playing++;
			cout << "You won this round" << endl;
			SkBlSt::setWin();
		}
		else if ((val == 1 && valTolvu == 2) || (val == 2 && valTolvu == 3) || (val == 3 && valTolvu == 1)){
			playing++;
			cout << "You lost this round" << endl;
			SkBlSt::setLoss();
		}
		else{
			cout << "Wrong input" << endl;
		}
	}
}
void SkBlSt::score(){
	cout << "Rock, paper, scissors: Wins: " << SkBlSt::getWins() << " Losses: " << SkBlSt::getLosses() << "\n";
}
//Giskaðu tölu milli 1-1000 leikur
class Gisk : Leikir {
private:
	int tala;
	int gisk;
	int max = 10;
	int fjoldi = 0;
public:
	void score();
	void play();
};
void Gisk::play(){
	system("CLS");
	int fjoldi = 0; //Reset fjolda
	bool victory = false;
	srand(time(NULL));
	tala = rand() % 1000 + 1;
	while (fjoldi < max && victory == false){
		std::cout << "Enter guess " << (fjoldi + 1) << " of " << max << endl;
		cin >> gisk;
		if (gisk == tala)
		{
			cout << "You guessed the correct number with " << (fjoldi + 1) << " number of guesses" << endl;
			Gisk::setWin();
			victory = true;
		}
		else if (gisk > tala)
		{
			cout << "You guessed a number bigger than the number you are looking for\n" << endl;
		}
		else
		{
			cout << "You guessed a number smaller than the number you are looking for\n" << endl;
		}
		fjoldi++;
	}
	if (victory == false)
	{
		cout << "You didn't correct the correct number in time" << endl;
		Gisk::setLoss();
	}
}
void Gisk::score(){
	cout << "Guess a number between 1 and 1000: Wins: " << Gisk::getWins() << " Losses: " << Gisk::getLosses() << "\n";
}

//Val
void val(){
	system("CLS");
	cout << "============================================= \n"
		<< "Select a game: \n"
		<< "1. Hangman \n"
		<< "2. Rock, paper, scissors \n"
		<< "3. Guess a number between 1 and 1000 \n"
		<< "4. Birta niðirstöður \n"
		<< "============================================= \n"
		<< endl;
}
//Main
int main(void) {
	system("chcp 1250");
	//Leikja breytur
	Hengimann hengimann;
	SkBlSt skblst;
	Gisk gisk;
	int input = 0;
	val();
	while (cin >> input){
		val();
		switch (input)
		{
		case 1:
			hengimann.play();
			system("pause");
			val();
			break;
		case 2:
			skblst.play();
			system("pause");
			val();
			break;
		case 3:
			gisk.play();
			system("pause");
			val();
			break;
		case 4:
			system("cls");
			cout << "============================================= \n" << "Birtir hversu oft þú hefur unnið og tapað \n";
			hengimann.score();
			skblst.score();
			gisk.score();
			cout << "============================================= \n" << endl;
			system("pause");
			val();
			break;
		default:
			cout << input << " is not a valid input" << endl;
			break;
		}
	}
	return 0;
}

