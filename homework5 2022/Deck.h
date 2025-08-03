//
//  Deck.h
//  hw5 2022
//
//  Created by Kaan Karabıyık on 3.08.2025.
//

# include <iostream>
# include <string>
# include <fstream>
using namespace std;
struct Card{
    string name;
    int energy;
};
class Deck{
private:
    Card* elements;
    int size;
public:
    Deck();
    Deck(const Deck&copy);
    ~Deck();
    Card* getElements() const;
    int getsize() const;
    Deck operator+(const Card& card);
    Deck operator+(const Deck& deck);
    Deck& operator+=(const Deck& other);
    Deck operator-(int value);
    Deck& operator=(const Deck& copy);
    bool operator==(const Deck&copy);
    bool operator<(const Deck& rhs) const;
    bool operator>(int value)const;
    Card& operator[](int value)const;
};

std::ostream& operator<<(ostream&out,const Deck& deck);
bool operator<=(const Card&card,const Deck&deck);

