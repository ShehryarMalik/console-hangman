#include <iostream>
#include <cstdlib>
using namespace std;

//This function centers and prints a message and print top and bottom borders if needed.
void displayMessage(string message, bool printTop = true, bool printBottom = true)
{
    if(printTop)
    {
        cout<<"+--------------------------+"<<endl;
        cout<<"|";
    }
    else
    {
        cout<<"|";
    }

    bool ft = true;


    for(int i = message.length() ; i<=25 ; i++)
    {
        if(ft)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        ft = !ft;
    }

    cout<<message;

    if(printBottom)
    {
        cout<<"|"<<endl;
        cout<<"+--------------------------+"<<endl;
    }
    else
    {
        cout<<"|"<<endl;
    }
}
//end of display function

//draws the hangman depending on the number of tries.
void drawHangman(int tries)
{
    if(tries >= 1)
        displayMessage("|",false,false);
    else
        displayMessage("",false,false);

    if(tries >= 2)
        displayMessage("|",false,false);
    else
        displayMessage("",false,false);
    if(tries >= 3)
        displayMessage("0",false,false);
    else
        displayMessage("",false,false);
    if(tries == 4)
        displayMessage("/  ",false,false);

    if(tries == 5)
        displayMessage("/| ",false,false);

    if(tries >= 6)
        displayMessage("/|\\",false,false);
    else
        displayMessage("",false, false);

    if(tries == 7)
        displayMessage("/ ",false,false);

    if(tries >= 8)
        displayMessage("/ \\",false,false);
    else
        displayMessage("",false, false);
}
//end of drawHangman function.

//Loops Main menu until user decides to play or exit
char mainMenu()
{
    int choice;
    do
    {
        system("cls");
        cout<<"\t\tWelcome to HangMan!"<<endl;
        cout<<"1.Play\n2.Instructions\n3.About\n4.Exit\n";
        cin>>choice;
        switch(choice)
        {

        case 1:
            return 'y';
            break;
        case 2:
            system("cls");
            cout<<"Welcome to hangman!\nThis game will randomly choose a country.\nYou have to guess which country it is by\ntyping its name, before you run out of tries.\nGoodLuck!\n\n";
            system("PAUSE");
            break;
        case 3:
            system("cls");
            cout<<"This project was made for semester's final project.\n\t\tGroupMembers:\n\t>Shehryar Malik\n\t>Ali Omar\n\t>Raja Hamza\n\t>Bilal Ahmed Jadoon\n\n";
            system("pause");
            break;
        case 4:
            return 'n';
            break;
        default:
            cout<<"Wrong input"<<endl<<endl;
            system("PAUSE");
            break;
        }
    }
    while(true);
}
//end of main menu


int main()
{
    string words[20] =
    {
        "Pakistan",
        "India",
        "China",
    };

    char c;

    c = mainMenu();
    while(c != 'n')
    {
        system("cls");
        string TheWord;
        TheWord = words[rand() % 3];
        string guess;
        int tries = 0;
        bool win = false;
        string currentStatus = "Guess the Country.";
        while(tries <= 8 )
        {

            displayMessage("Hang Man");
            drawHangman(tries);

            displayMessage(currentStatus);

            for(int i = 1; i <= TheWord.length(); i++)
                cout<<" _ ";

            cout<<endl<<endl;
            cin>>guess;

            if(guess != TheWord)
            {
                currentStatus = "Wrong! try again.";
                tries++;
                system("cls");
            }
            else
            {
                win = true;
                break;
            }
        }

        system("cls");
        if(win)
            displayMessage("YOU WIN!");
        else
        {
            displayMessage("You Lose!");
            drawHangman(tries);
        }

        cout<<"Do you want to play again (y/n)?"<<endl;
        cin>>c;
        system("cls");

    }

    return 0;
}
