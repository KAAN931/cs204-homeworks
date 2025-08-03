//
//  TwoDLinkedList.h
//  hw3 2022
//
//  Created by Kaan Karabıyık on 1.08.2025.
//
# include <iostream>
# include <string>
# include <fstream>
using namespace std;
struct node
{
char data;
node *right;
node *down;
};
class TwoDLinkedList{
private:
    node* head;
public:
    TwoDLinkedList();
    ~TwoDLinkedList();
    void add_row_sorted(string s);
    void displayFullMatrix();
    void displayFullMatrixReversed();
    void display_rows_starting_with(char c);
    void display_cols_starting_with(char c);
    int delete_rows_starting_with(char c);
    int delete_cols_starting_with(char c);
    void clear();
};
