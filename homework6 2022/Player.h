//
//  Untitled.h
//  hw6 2022
//
//  Created by Kaan Karabıyık on 4.08.2025.
//
#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
template<typename T>
class Player{
private:
    Board<T>& board;
    int ID;
    static int nextID;
public:
    Player(Board<T>& board);
    bool updateCell(int r,int c,T value);
    void updateMyCells(T value);
    bool unclaimOwnership(int r,int c);
    void unclaimOwnerships();
};
#include "Player.cpp"
#endif
