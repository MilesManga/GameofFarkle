#include "pch.h"
#include "stdafx.h";
#include<iostream>
#include<ctime>     
#include <conio.h>
#include <random>
#include <string>
#include <fstream>
#include "scoreDice.h"


using namespace std;
using namespace System;
using namespace System::IO;

int userInput;
int numPlayers;
int playersNames; 
int die1 = 0;
int die2 = 0;
int die3 = 0;
int die4 = 0;
int die5 = 0;
int die6 = 0;
int scoreDice = 0;

int dieSideCount = 0;

class dieRoll {

    void Dice()
    {
        die1 = (rand() % 6) + 1;
        die2 = (rand() % 6) + 1;
        die3 = (rand() % 6) + 1;
        die4 = (rand() % 6) + 1;
        die5 = (rand() % 6) + 1;
        die6 = (rand() % 6) + 1;
    }
};

int userGame()
{
    cout << "\nPress 1 to roll the dice." << endl;
    cin >> userInput;
    if (userInput == 1)
    {
        void Dice();
        cout << "\nYou rolled" << endl;
        cout << "Die 1 = " << die1 << endl;
        cout << "Die 2 = " << die2 << endl;
        cout << "Die 3 = " << die3 << endl;
        cout << "Die 4 = " << die4 << endl;
        cout << "Die 5 = " << die5 << endl;
        cout << "Die 6 = " << die6 << endl;
    }
    else if (dieSideCount >= 3)
    {
        {
            String^ Score = "textfile.txt";
            try
            {
                Console::WriteLine("trying to open file {0}...", Score);
                StreamReader^ din = File::OpenText(Score);

                String^ str;
                int count = 0;
                while ((str = din->ReadLine()) != nullptr)
                {
                    count++;
                    Console::WriteLine("line {0}: {1}", count, str);
                }
            }
            catch (Exception^ e)
            {
                if (dynamic_cast<FileNotFoundException^>(e))
                    Console::WriteLine("file '{0}' not found", Score);
                else
                    Console::WriteLine("problem reading file '{0}'", Score);
            }
        }
    }
    else {
        cout << "You did not enter the proper number to roll the dice. Please press 1 to roll the dice.";
        
    }
    return (die1, die2, die3, die4, die5, die6) << scoreDice;
}





void checkForWin()
{
    while (true)
    {
        int result = userGame();
        if (userGame)
        {
            scoreDice = result;
            continue;
        }
        // int finalResult = dieTotal;
        if (result == scoreDice)
        {
            cout << "\nPlayer 1 wins." << endl;
            break;
        }
        else if (result == 2)
        {
            cout << "\nPlayer 2 wins" << endl;
            break;
        }
        else if (result == 3)
        {
            cout << "\nPlayer 3 wins" << endl;
        }
        else if (result == 4)
        {
            cout << "\nPlayer 4 wins" << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    ifstream infile("Rules.txt");
    if (infile.fail())
    {
        cout << "Could not open file";
    }
    else {
        string farkle;
        while (getline(infile, farkle))
        {
            cout << farkle << endl;
        }
        infile.close();
    }

    cout << "Welcome to Farkle! " << endl << endl;
    cout << "The minimum number of players is 4." << endl << endl;
    cout << "Please enter the number of players: " << endl << endl;
    cin >> numPlayers;
    cout << "Please enter the the player's names?" << endl << endl;
    cin >> playersNames;
    if (numPlayers < 2)
    {
        cout << "Farkle needs a minimum of 4 players, please enter 2 more players." << endl << endl;
        cin >> numPlayers;
        cout << "Please also enter the two player's names as well." << endl << endl;
        cin >> playersNames;
    }
    else {
        return userGame();

    }
    return 0;
};
