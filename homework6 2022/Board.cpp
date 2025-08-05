//
//  Board.cpp
//  hw6 2022
//
//  Created by Kaan Karabıyık on 4.08.2025.
//
#include <iostream>
#include "Board.h"
using namespace std;
template<typename T>
Board<T>::Board(int r,int c){
    matrix=new Info<T>*[r];
    for(int i=0;i<r;i++){
        matrix[i]=new Info<T>[c];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matrix[i][j].owner=0;
        }
    }
    numRows=r;
    numCols=c;
}
template<typename T>
Board<T>::Board(const Board&copy){
    numRows=copy.numRows;
    numCols=copy.numCols;
    matrix=new Info<T>*[numRows];
    for(int i=0;i<numRows;i++){
        matrix[i]=new Info<T>[numCols];
    }
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            matrix[i][j]=copy.matrix[i][j];
        }
    }
}
template<typename T>
Board<T>::~Board(){
    for(int i=0;i<numRows;i++){
        delete[]matrix[i];
    }
    delete[] matrix;
}
template<typename T>
void Board<T>::displayBoard(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            cout<<"("<<matrix[i][j].value<<","<<matrix[i][j].owner<<")   ";
        }
        cout<<endl;
    }
}
template<typename T>
void Board<T>::updateBoardCells(int ID,T setvalue){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            if(matrix[i][j].owner==ID){
                matrix[i][j].value=setvalue;
            }
        }
    }
}
template<typename T>
int Board<T>::getPlayerCellsCount(int ID){
    int count=0;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            if(matrix[i][j].owner==ID){
                count++;
            }
        }
    }
    return count;
}
template<typename T>
int Board<T>::knowTheOwner(int r,int c){
    return matrix[r][c].owner;
}
template<typename T>
bool Board<T>::is_claimed_by(int r,int c,int ID){
    if(matrix[r][c].owner==ID){
        return true;
        }
    return false;
}
template<typename T>
bool Board<T>::is_claimed(int r,int c){
    if(matrix[r][c].owner!=0){
        return true;
        }
    return false;
}
template<typename T>
void Board<T>::setOwner(int r,int c,int setowner){
    matrix[r][c].owner=setowner;
}
template<typename T>
int Board<T>::getNumRows(){
    return numRows;
}
template<typename T>
int Board<T>::getNumCols(){
    return numCols;
}
template<typename T>
void Board<T>::setCell(int r, int c, int value) {
    matrix[r][c].value = value;
}


