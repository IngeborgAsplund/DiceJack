// Project1_DiceJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool gameOver = false;
int userInput = 0;
//While bool gameover is false we want to run the main gameloop
void GameLoop()
{
    while (!gameOver)
    {
        std::cout << "Welcome to the game of dice jack\n Please input 1 to play and 2 to quit.\n\n";
        std::cin >> userInput;

        if (userInput == 1)
        {
            std::cout << "You entered a new round of dice jack\n";
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

