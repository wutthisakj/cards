#include <iostream>
#include <stdlib.h>
#include "apvector.h"
#include "apstring.h"

using namespace std;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES, JOKER};
enum Rank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK, QUEEN, KING, NORANK};

struct Card
{
    Suit suit;
    Rank rank;

    Card ();
    Card (Suit s, Rank r);
    void print () const;
    bool equals (const Card& c2) const;
    bool isGreater (const Card& c2) const;
};

Card::Card (void) {
    suit = JOKER; rank = NORANK;
}

Card::Card (Suit s, Rank r) {
    suit = s; rank = r;
}

void Card::print () const {
    apvector<apstring> suits (5);
    suits[0] = "Clubs";
    suits[1] = "Diamonds";
    suits[2] = "Hearts";
    suits[3] = "Spades";
    suits[4] = "Joker";

    apvector<apstring> ranks (15);
    ranks[1] = "Ace";
    ranks[2] = "2";
    ranks[3] = "3";
    ranks[4] = "4";
    ranks[5] = "5";
    ranks[6] = "6";
    ranks[7] = "7";
    ranks[8] = "8";
    ranks[9] = "9";
    ranks[10] = "10";
    ranks[11] = "Jack";
    ranks[12] = "Queen";
    ranks[13] = "King";
    ranks[14] = ";)";
    cout << ranks[rank] << " of " << suits[suit] << endl;
}

bool Card::equals (const Card& c2) const {
    return (rank == c2.rank && suit == c2.suit);
}

bool equals (const Card& c1, const Card& c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}

bool Card::isGreater (const Card& c2) const {
        if (suit > c2.suit) return true;
        if (suit < c2.suit) return false;

        if (rank > c2.rank) return true;
        if (rank < c2.rank) return false;
    return false;
}

apvector<Card> buildDeck(void) {
    apvector<Card> deck (52);

    int index = 0;
    for (Suit suit=CLUBS; suit<=SPADES; suit=Suit(suit+1)) {
        for (Rank rank=ACE; rank<=KING; rank=Rank(rank+1)) {
            deck[index].suit = suit;
            deck[index].rank = rank;
            index++;
        }
    }
 return deck;
};

void printDeck (const apvector<Card>& deck) {
    for (int i = 0; i< deck.length(); i++) {
        deck[i].print();
    }
}

int find (const Card& card, const apvector<Card>& deck) {
    for (int i = 0; i < deck.length(); i++) {
        if (equals (deck[i], card)) return i;
    }
    return -1;
}

// Decks

struct Deck {
    apvector<Card> cards;

    Deck (int n);
    Deck ();
    void print () const;
    int find (const Card& card) const;
};

Deck::Deck (int size) {
    apvector<Card> temp (size);
    cards = temp;
}

Deck::Deck () {
    apvector<Card> temp (52);
    cards = temp;

    int i = 0;
    for (Suit suit=CLUBS; suit<=SPADES; suit=Suit(suit+1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

void Deck::print () const {
    for (int i = 0; i< cards.length(); i++) {
        cards[i].print();
    }
}

int Deck::find (const Card& card) const {
    for (int i = 0; i < cards.length(); i++) {
        if (equals (cards[i], card)) return i;
    }
    return -1;
}


int main()
{
    //Card TheJoker = Card ();
    //Card TheJoker(void);
    Card JackOfDiamons (DIAMONDS, JACK);
    //apvector<Card> deck = buildDeck ();
    //printDeck (deck);
    //TheJoker.print();
    //int index = find (JackOfDiamons, deck);
    //cout << "I found the card at index = " << index <<  endl;

    Deck deck = Deck ();
    //for (int i = 0; i<52; i++) {
    //    deck.cards[i].print();
    //}
    deck.print();
    int index = deck.find(JackOfDiamons);
    if (index != -1)
        cout << "Found the card at index no.:" << index << endl;
    else
        cout << "not found the card!" << endl;

    return 0;
}
