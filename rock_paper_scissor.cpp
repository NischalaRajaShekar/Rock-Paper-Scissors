/*
 * rock_paper_scissor.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: nisch
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses

int computer_wins=0;
int human_wins = 0;
int tie = 0;


//Reads value of human_input
char human_choice()
{
	char human_input;
	cout << "Your choice? ";
	cin >> human_input;
	return human_input;
}

// Generates random value for computer_input
char computer_choice()
{
	int iRan;
	char comp_input;
	srand(time(NULL));
	iRan = rand() % 3;

	switch(iRan)
	{
	case 0 : comp_input = 'r';
		cout<< "The computer chose ROCK"<< endl;
		break;
	case 1 : comp_input = 'p';
		cout<< "The computer chose PAPER"<< endl;
		break;
	case 2 : comp_input = 's';
		cout<< "The computer chose SCISSORS"<< endl;
		break;
	}return comp_input;
}

//Computes the total number of Human wins, computer wins and ties
void record_win(char human_input, char comp_input)
{
	switch(human_input)
	{
		case 'r':
			if(comp_input == 'p')
			{
				computer_wins++;
				cout << "The winner is computer"<< endl;
			}
			else if (comp_input == 's')
			{
				human_wins++;
				cout<< "The winner is you" << endl;
			}
			else
			{
				tie++;
				cout<< "Its a tie!" << endl;
			}
			break;

		case 'p':
			if(comp_input == 's')
			{
				computer_wins++;
				cout << "The winner is computer"<< endl;
			}
			else if (comp_input == 'r')
			{
				human_wins++;
				cout<< "The winner is you" << endl;
			}
			else
			{
				tie++;
				cout<< "Its a tie!" << endl;
			}
				break;

		case 's':
			if(comp_input == 'r')
			{
				computer_wins++;
				cout << "The winner is computer"<< endl;
			}
			else if (comp_input == 'p')
			{
				human_wins++;
				cout<< "The winner is you" << endl;
			}
			else
			{
				tie++;
				cout<< "Its a tie!" << endl;
			}
				break;
	}
}

int main()
{
    char human_input, comp_input;

    for(int i = 0; i < MAX_ROUNDS; i++)
    {
    	cout << "Round "<< i+1 << endl;
    	human_input = human_choice();

    	while(human_input != 'r' && human_input != 'R' && human_input != 'p' && human_input != 'P' && human_input != 's' && human_input != 'S')
    		{
    		cout<< "***ERROR: Valid choices are R, P or S "<< endl;
    		human_input = human_choice();
    		}

    	if(human_input =='r' || human_input =='R')
    		cout<< "You chose ROCK"<<endl;
    	else if(human_input =='p' || human_input =='P')
    	cout<< "You chose PAPER" << endl;
    	else
    		cout << "You chose SCISSORS" << endl;

    	comp_input = computer_choice();
    	human_input = tolower(human_input);
    	record_win(human_input, comp_input);
    }
    cout << "Summary" << endl;
    cout << "Human wins: "<< human_wins << endl;
    cout << "Computer wins: "<< computer_wins << endl;
    cout << "Ties: "<< tie << endl;

    return 0;
}
