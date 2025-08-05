//
//  Board.h
//  hw6 2022
//
//  Created by Kaan Karabıyık on 4.08.2025.
//

#ifndef BOARD_H
#define BOARD_H
template<typename T>
struct Info{
    int owner;
    T value;
};
template<typename T>
class Board{
private:
   Info<T>** matrix;
    int numRows;
    int numCols;
public:
    Board();
    Board(int r,int c);
    ~Board();
    Board(const Board& copy);
    void displayBoard();
    void updateBoardCells(int ID,T value);
    int getPlayerCellsCount(int ID);
    int knowTheOwner(int r,int c);
    bool is_claimed_by(int r,int c,int ID);
    int getNumRows();
    int getNumCols();
    void setCell(int r, int c, int value);
    bool is_claimed(int r,int c);
    void setOwner(int r,int c,int owner);
};
#include "Board.cpp"
#endif
