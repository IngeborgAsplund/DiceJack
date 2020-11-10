// Project1_DiceJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <random>
//variables
bool gameOver = false;
int userInput = 0;
int credits = 100;
std::vector<int> cards;


// this function clears the array cards of any elements then fills it with the 52 cards usually found in a deck of cards
// called at the start of every round this function will technically refill 
void ResetAndFillArray()
{
    //check if we have more than zero elements in the array and if so we want to clear the array of its elemets
    if(cards.size()>0)
       cards.clear();
    //for loop that adds for cards for each iteration of the loop.
    for(int i = 1;i<=13;i ++)
    {
        cards.push_back(i);
        cards.push_back(i);
        cards.push_back(i);
        cards.push_back(i);
    }
}
//return the value of a card randomly drawn from the deck of cards, this are added instead of the combination of two dice
// each time a player or ai takes a card. The cards is then added to the total score
int DrawNewcard()
{
    std::random_device random;
    std::mt19937 gen = std::mt19937(random());
    std::uniform_int_distribution<int>drawCard(0,cards.size());    
    int cardId = drawCard(random);//get the index of the card we want to draw from the array

    int cardvalue = cards[cardId];//picking a card on the earlier generated position.
    cards.pop_back[cardId];// remove the actual card from the array
    return cardvalue;// return the value of the drawn card
}
//The computer will use this to take the its turn instead of rolling four dice automatically. As A player
//who plays this game would consider his/her own current score when deciding if they should take the risk to reroll
// the dice I think the computer should take the same precursion. Therefore if the current score of the computer is
// bigger than or equal to 17 the computer will exit its turn. Returns a vaule of type int for the computer score.
int AIRound()
{
    int currentScore = 0;
    //generating random seed
    std::random_device random;
    std::mt19937 compGen = std::mt19937(random());
    //define our dice
    std::uniform_int_distribution<int> compDice(1, 6);
    while(currentScore<17)
    {
        for(int i = 0; i<2;i++)
        {
            currentScore += compDice(compGen);
        }
    }
    return currentScore;
}
//the main functionality for playing a round of dice jack it takes a bet from the player and start a playing rond given the input taken is
//correct it continue to play a round
void PlayRound()
{
    //refill the array
    ResetAndFillArray();
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
                    int computerscore = AIRound();
                    
                    if (playerTotal > computerscore || computerscore >= 21)
                    {
                        credits += bet;
                        std::cout << "\nYou won this rond remaining credits are " << credits;
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
                std::cout<<"\nCongratulations you won";
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

