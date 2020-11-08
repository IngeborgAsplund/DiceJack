// Project1_DiceJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <random>
bool gameOver = false;
int userInput = 0;
int credits = 100;
//the main functionality for playing a round of dice jack it takes a bet from the player and start a playing rond given the input taken is
//correct it continue to play a round
void PlayRound()
{
    //set the bet to 0
    int bet = 0;
    //ask user for input and present conditions
    std::cout <<"\n"<<"Place your bet for this round of diceJack."<<"\n"<< "\n" << "Credits: " << credits << "\n" 
        <<"Remember that your bet cannot exceed the amound of credits you have"<<"\n";
    //read input
    std::cin >> bet;
    //check if bet is valid
    if (bet > 0 && bet <= credits)
    {
        int playerTotal = 0;
        bool playing = true;
        //generating random seed
        std::random_device random;
        std::mt19937 gen = std::mt19937(random());
        //define our dice
        std::uniform_int_distribution<int> dice(1, 6);
        //debug line
        std::cout << "Play round with a bet of " << bet << "\n";
        while(playing)
        {
            
            //roll dice two times
            for(int i = 0; i<2; i ++)
            {
                playerTotal +=dice(gen);
            }
           
            if(playerTotal>=21)
            {
                std::cout <<"\n"<<"You went bust, your current score is "<<playerTotal;
                credits -= bet;
                playing = false;
            }
            else
            {
                std::cout << "\n" << "Your total score is currently " << playerTotal <<"\nType 0 to roll another time and 1 to end"<<"\n";
                int answer = 0;
                std::cin >> answer;
                if (answer == 1)
                {
                    int computerscore = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        computerscore += dice(gen);
                    }
                    if (playerTotal > computerscore || computerscore >= 21)
                    {
                        credits += bet;
                        std::cout << "You won this rond remaining credits are " << credits;
                        playing = false;
                    }
                    else if (computerscore > playerTotal)
                    {
                    credits -= bet;
                    std::cout << "You lost this rond\n" << "remaining credits are " << credits;
                    playing = false;
                    }

                }
            }
            

        }
    }
    else
        std::cout << "Invalid input, bet cannot exeed your total credits nor can it be a negative value" << "\n";
   
}
//While bool gameover is false we want to run the main gameloop
void GameLoop()
{
    while (!gameOver)
    {
        std::cout <<"\n"<<"Welcome to the game of dice jack.\nPlease input 1 to play a round and 2 to quit.\n";
        std::cin >> userInput;

        if (userInput == 1)
        {
            PlayRound();
            if (credits <= 0)
            {
                std::cout << "\n"<<"Game over";
                credits = 100;
                gameOver = true;
            }
            else if (credits >= 300)
            {
                std::cout<<"Congratulations you won";
                credits = 100;
                gameOver = true;
            }
        }
        else if (userInput == 2)
        {
            std::cout<< "\n";
            gameOver = true;
        }
    }
}
//main function
int main()
{
    GameLoop();
}

