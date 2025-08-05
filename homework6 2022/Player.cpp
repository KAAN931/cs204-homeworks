//
//  Player.cpp
//  hw6 2022
//
//  Created by Kaan Karabıyık on 4.08.2025.
//
#include <iostream>
#include "Player.h"
template<typename T>
int Player<T>::nextID = 1;
template<typename T>
Player<T>::Player(Board<T>& board):board(board){
    ID=nextID;
    nextID++;
}
template<typename T>
bool Player<T>::updateCell(int r,int c,T setvalue){
    if(!board.is_claimed(r,c)){
        board.setCell(r,c,setvalue);
        board.setOwner(r,c,ID);
        return true;
    }
    return false;
}
template<typename T>
void Player<T>::updateMyCells(T setvalue){
    for(int i=0;i<board.getNumRows();i++){
        for(int j=0;j<board.getNumCols();j++){
            if(board.is_claimed_by(i,j,ID)){
                board.setCell(i,j,setvalue);
            }
        }
    }
}
template<typename T>
bool Player<T>::unclaimOwnership(int r,int c){
    if(board.is_claimed_by(r,c,ID)){
        board.setOwner(r,c,0);
        return true;
    }
    return false;
}
template<typename T>
void Player<T>::unclaimOwnerships(){
    for(int i=0;i<board.getNumRows();i++){
        for(int j=0;j<board.getNumCols();j++){
                unclaimOwnership(i,j);
        }
    }
}

