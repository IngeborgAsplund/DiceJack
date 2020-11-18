#pragma once
#include<iostream>
#include<string>
#include<vector>

struct Card
{
	std::string suit;
	std::string cardName;
	int value;
	Card(std::string inSuit,std::string name,int invalue)
	{
		suit = inSuit;
		cardName = inSuit+name;
		value = invalue;
	}
};
class DeckOfCard
{
public:
	//reset the deck of cards called in the beginning of the game, fills the deck with cards and shuffles them
	void Reset();
	//draw a card from the deck of cards remove it from the deck and push back a similar card in the back of the deck
	Card DrawNew();
private:
	//vector of struct card. This is used to draw cards in the game
	std::vector<Card>deck;
	//deternie what name a card shall have based on the value we want to assign it 
	std::string SetNewCardName(int cardVal);
};
