//
//  Deck.cpp
//  hw5 2022
//
//  Created by Kaan Karabıyık on 3.08.2025.
//
#include "Deck.h"
std::ostream& operator<<(ostream&out,const Deck& deck){
    for(int i=0;i<deck.getsize();i++){
        out<<i<<": "<<deck.getElements()[i].name<<" - "<<deck.getElements()[i].energy;
        out<<endl;
    }
    return out;
}
Deck::Deck(){
    elements=nullptr;
    size=0;
}
Deck::Deck(const Deck&copy){
    size=copy.size;
    elements=new Card[size];
    for(int i=0;i<size;i++){
        elements[i]=copy.elements[i];
    }
}
Deck::~Deck(){
    delete[]elements;
}
Card* Deck::getElements() const{
    return elements;
}
int Deck::getsize() const{
    return size;
}
Deck Deck::operator+(const Card&card){
    Deck result(*this);
    Card* newArray=new Card[size+1];
    for(int i=0;i<size;i++){
        newArray[i]=elements[i];
    }
    newArray[size]=card;
    delete[] result.elements;
    result.elements=newArray;
    result.size++;
    return result;
}
Deck Deck::operator+(const Deck&deck){
    Deck result(*this);
    int newSize=this->size+deck.size;
    Card* newArray=new Card[newSize];
    for(int i=0;i<size;i++){
        newArray[i]=elements[i];
    }
    for(int i=0;i<deck.size;i++){
        newArray[i+size]=deck.elements[i];
    }
    delete[]result.elements;
    result.elements=newArray;
    result.size=newSize;
    return result;
}
Deck& Deck::operator+=(const Deck& other){
    int newSize=this->size+other.size;
    Card* newArray=new Card[newSize];
    for(int i=0;i<size;i++){
        newArray[i]=elements[i];
    }
    for(int i=0;i<other.size;i++){
        newArray[i+size]=other.elements[i];
    }
    delete[]elements;
    elements=newArray;
    size=newSize;
    return *this;
}
Deck Deck::operator-(int value){
    Deck result0(*this);
    if(value>size){
        Card* emptyArray=nullptr;
        delete[]result0.elements;
        result0.elements=emptyArray;
        return result0;
    }
    Deck result(*this);
    int newSize=size-value;
    Card* newArray=new Card[newSize];
    for(int i=0;i<newSize;i++){
        newArray[i]=elements[value+i];
    }
    delete[]result.elements;
    result.elements=newArray;
    result.size=newSize;
    return result;
}
Deck& Deck::operator=(const Deck& copy){
    int newSize=copy.size;
    Card* newArray=new Card[newSize];
    for(int i=0;i<newSize;i++){
        newArray[i]=copy.elements[i];
    }
    delete[]elements;
    elements=newArray;
    size=newSize;
    return *this;
}
bool Deck::operator==(const Deck& rhs){
    int count1=0;
    int count2=0;
    for(int i=0;i<size;i++){
        count1+=elements[i].energy;
    }
    for(int i=0;i<rhs.size;i++){
        count2+=rhs.elements[i].energy;
    }
    if(count1==count2){
        return true;
    }
    return false;
}
bool Deck::operator<(const Deck&rhs)const{
    int count1=0;
    int count2=0;
    for(int i=0;i<size;i++){
        count1+=elements[i].energy;
    }
    for(int i=0;i<rhs.size;i++){
        count2+=rhs.elements[i].energy;
    }
    if(count1<count2){
        return true;
    }
    return false;
}
bool Deck::operator>(int value)const{
    if(size>value){
        return true;
    }
    return false;
}
bool operator<=(const Card&card,const Deck&deck){
    for(int i=0;i<deck.getsize();i++){
        if(deck.getElements()[i].name==card.name&&deck.getElements()[i].energy==card.energy){
            return true;
        }
    }
    return false;
}
Card& Deck::operator[](int value)const{
    return elements[value];
}


