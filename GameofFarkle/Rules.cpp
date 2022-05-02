#include "pch.h"
#using<system.dll>
using namespace System;
using namespace System::IO;


int main()
{
    String^ Rules = "textfile.txt";

    StreamWriter^ sw = gcnew StreamWriter(Rules);
    sw->WriteLine("In Farkle, each player begins their turn by rolling six dice.");
    sw->WriteLine("After the player rolls, they find the dice combinations from that roll.");
    sw->WriteLine("Each die combination contains different point values.");
    sw->WriteLine("The player earns points by rolling a 1, 5, or die combination.");
    sw->WriteLine("Ones are worth 100 points while fives are worth 50 points.");
    sw->WriteLine("Three die or higher with any identical number is multiplied by 100.");
    sw->WriteLine("For example, if a player rolls three 4s, the total would be 400 points.");
    sw->WriteLine("Rolling a die combination allows the player to roll again.");
    sw->WriteLine("A Farkle happens when the player rolls the die and no points occur.");
    sw->WriteLine("They lose all of their points for that turn.");
    sw->WriteLine("If the player stops their turn, they pass it on to the next player from the left side.");
    sw->WriteLine("If any player reaches 10,000 points, he or she won the game.");
    sw->Close();
    Console::WriteLine("a new file  has been written", Rules);

    return 0;
}