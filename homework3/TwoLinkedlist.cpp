//
//  TwoDLinkedList.cpp
//  hw3 2022
//
//  Created by Kaan Berk Karabıyık on 1.08.2025.
//
# include <iostream>
# include <string>
#include "TwoDLinkedList.h"
using namespace std;
TwoDLinkedList::TwoDLinkedList(){
    head=nullptr;
}
TwoDLinkedList::~TwoDLinkedList(){
    node* row=head;
        while(row!=nullptr){
            node*col=row;
            node* nextrow=row->down;
            while(col!=nullptr){
                node* nextcol=col->right;
                delete col;
                col=nextcol;
            }
            row=nextrow;
        }
}
void TwoDLinkedList::add_row_sorted(string s){
    node* newrowhead=nullptr;
    node* prev=nullptr;
    for(int i=0;i<s.size();i++){
        node* newNode=new node;
        newNode->data=s[i];
        newNode->right=nullptr;
        newNode->down = nullptr;
        if(prev==nullptr){
            newrowhead=newNode;
        }
        else{
            prev->right=newNode;
        }
        prev=newNode;
    }
    if(head==nullptr||s[0]<head->data){
        newrowhead->down=head;
        head=newrowhead;
    }
    else{
        node* temp=head;
        node* prevRow=nullptr;
        while(temp!=nullptr&&temp->data<s[0]){
            prevRow=temp;
            temp=temp->down;
        }
        prevRow->down=newrowhead;
        newrowhead->down=temp;
    }
    //the new connections will between up and down
    //one up
    node* rowAbove = head;
    //one down
    node* currentRow = head->down;

    while(currentRow != nullptr){
        node* above = rowAbove->right;
        node* below = currentRow->right;

        while(above != nullptr && below != nullptr){
            above->down = below;
            above = above->right;
            below = below->right;
        }
        //update for iteration
        rowAbove = currentRow;
        currentRow = currentRow->down;
    }
}
void TwoDLinkedList::displayFullMatrix(){
    node*row=head;
    while(row!=nullptr){
        node*col=row;
        while(col!=nullptr){
            cout<<col->data;
            col=col->right;
        }
        cout<<endl;
        row=row->down;
    }
}
void TwoDLinkedList::displayFullMatrixReversed(){
    if(head==nullptr){
        return;
    }
    node*row =head;
    head=head->down;
    displayFullMatrixReversed();
    node*col=row;
    while(col!=nullptr){
        cout<<col->data<<" ";
        col=col->right;
    }
    cout<<endl;
    head=row;
}
void TwoDLinkedList::display_rows_starting_with(char c){
    
    node* row=head;
    while(row!=nullptr){
        if(row->data==c){
            node* col=row;
            while(col!=nullptr){
                cout<<col->data;
                col=col->right;
            }
            cout<<endl;
        }
        row=row->down;
    }
}
void TwoDLinkedList::display_cols_starting_with(char c){
    node*col=head;
    while(col!=nullptr){
        if(col->data==c){
            node*next=col;
            while(next!=nullptr){
                cout<<next->data;
                next=next->down;
            }
            cout<<endl;
        }
        col=col->right;
    }
}
int TwoDLinkedList::delete_rows_starting_with(char c){
    node* row=head;
    node* prevRow=nullptr;
    int count=0;
    while(row!=nullptr){
        node*temp=row->down;
        if(row->data==c){
            if(prevRow==nullptr){
                head=temp;
            }
            else{
                prevRow->down=temp;
            }
            node* col=row;
            while(col!=nullptr){
                node*next=col->right;
                delete col;
                col=next;
                count++;
            }
        }
        else{
            prevRow=row;
        }
        row=temp;
    }
    return count;
}
int TwoDLinkedList::delete_cols_starting_with(char c){
    node*col=head;
    node* prev=nullptr;
    int count=0;
    while(col!=nullptr){
        node* temp=col->right;
        if(col->data==c){
            if(prev==nullptr){
                head=temp;
            }
            else{
                prev->right=temp;
            }
            node*row=col;
            while(row!=nullptr){
                node*nextrow=row->down;
                delete row;
                row=nextrow;
                count++;
            }
        }
        else{
            prev=col;
        }
        col=temp;
    }
    return count;
}
void TwoDLinkedList::clear(){
    node* row=head;
        while(row!=nullptr){
            node*col=row;
            node* nextrow=row->down;
            while(col!=nullptr){
                node* nextcol=col->right;
                delete col;
                col=nextcol;
            }
            row=nextrow;
        }
    head=nullptr;
}
