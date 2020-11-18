#include<algorithm>
#include"cardGameData.h"

void DeckOfCard::Reset()
{
	deck.clear();
	for(int i = 1; i <=13; i++)
	{
		deck.push_back(Card("Club", SetNewCardName(i), i));
		deck.push_back(Card("Heart", SetNewCardName(i), i));
		deck.push_back(Card("Spade", SetNewCardName(i), i));
		deck.push_back(Card("Diamond", SetNewCardName(i), i));
	}
	//shuffle the cards in the vector deck
	std::random_shuffle(deck.begin(), deck.end());
}
Card DeckOfCard::DrawNew()
{
	Card drawn = deck.front();//pick the first element of the array
	deck.erase(deck.begin());// erase the card drawn
	deck.push_back(drawn);// add card back in 
	return drawn;// return the drawn card
}
//this function assigns names to a specific card based on the value we want to assign said card ranging from low values 1(2) and high ones 13(ace).
// It uses a switch statement to do this and will be called everytime we want to create a new struct of type card.
std::string DeckOfCard::SetNewCardName(int cardVal)
{
	std::string name;
	switch (cardVal)
	{
	case 1:
		name = "2";
		break;
	case 2:
		name = "3";
		break;
	case 3:
		name = "4";
		break;
	case 4:
		name = "5";
		break;
	case 5:
		name = "6";
		break;
	case 6:
		name = "7";
		break;
	case 7:
		name = "8";
		break;
	case 8:
		name = "9";
		break;
	case 9:
		name = "10";
		break;
	case 10:
		name = "Jack";
		break;
	case 11:
		name = "Queen";
		break;
	case 12:
		name = "King";
		break;
	case 13:
		name = "Ace";// the reason Ace is value 13 is that Ace is always the highest card of any suit so it would be strange to 
		break;		//give it a low value.
	}
	return name;
}