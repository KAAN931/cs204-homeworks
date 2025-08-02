//
//  main.cpp
//  hw2 2022
//
//  Created by Kaan Karabıyık on 31.07.2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct node{
    char ch;
    node * next;
};
bool isLower(char word){
        if(word<'a'||word>'z'){
           return false;
    }
    return true;
    }
void add(node*&head,char ch){
    node* newNode=new node;
    newNode->ch=ch;
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
    }
    else{
        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void printList(node*head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->ch;
        temp=temp->next;
    }
    cout<<endl;
}
bool deleteCh(node*& head, char target) {
    // Delete from the head if needed
    bool found=false;
    while (head != nullptr && head->ch == target) {
        node* temp = head;
        head = head->next;
        delete temp;
        found=true;
    }

    // Now delete from the rest of the list
    node* current = head;
    while (current->next) {
        if (current->next->ch == target) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            found=true;

        } else {
            current = current->next;
        }
    }
    return found;
}
void insert(node*&head,char inserted,char letter){
    node* newNode=new node;
    newNode->ch=inserted;
    newNode->next=nullptr;
    node* temp=head;
    if(head == nullptr){
        // List is empty, insert at beginning
        head = newNode;
        return;
    }
    while(temp->next!=nullptr&&temp->ch!=letter){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        newNode->next=head;
        head=newNode;
    }
    else{
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
int compare(node* head1,node*head2){
    int sim=0;
    node* temp1=head1;
    node* temp2=head2;
        while(temp1!=nullptr&&temp2!=nullptr){
            if(temp1->ch==temp2->ch){
                sim++;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    return sim;
}
int main() {
    node* head1=nullptr;
    node*head2=nullptr;
    string filename;
    cout<<"Please enter the file 1 name: ";
    cin>>filename;
    ifstream input;
    input.open(filename.c_str());
    while(!input){
        cout<<"Please enter the file 1 name: ";
        cin>>filename;
        input.open(filename.c_str());
    }
    char ch;
    while(input.get(ch)){
        if (isLower(ch)) {
            add(head1, ch);
        }
    }
    string filename2;
    cout<<"Please enter the file 2 name: ";
    cin>>filename2;
    ifstream input2;
    input2.open(filename2.c_str());
    while(!input2){
        cout<<"Please enter the file 2 name: ";
        cin>>filename;
        input2.open(filename2.c_str());
    }
    char ch2;
    while(input2.get(ch2)){
        if (isLower(ch2)) {
            add(head2, ch2);
        }
    }
    printList(head1);
    printList(head2);
    cout<<"Enter a command and its corresponding argument(s), if any: ";
    string line;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line); // e.g., "delete2 x"
    istringstream ss(line);
    string command;
    char letter1, letter2;
    ss >> command >> letter1 >> letter2;
    while(command!="exit"){
        while(command!="sim"&&command!="insert1"&&command!="insert2"&&command!="delete1"&&command!="delete2"&&command!="exit"){
            cout<<"invalid command."<<endl;
            cout<<"Enter a command and its corresponding argument(s), if any: ";
            getline(cin, line);
            istringstream ss2(line);
            ss2 >> command>>letter1 >> letter2;
        }
        if(command != "sim"&&!isLower(letter1)&&isLower(letter2)){
            cout<<"invalid argument";
        }
        else{
            if(command=="delete1"){
                bool found=deleteCh(head1,letter1);
                if(found){
                    cout<<"Deleting all occurrences of "<<letter1<<" in List1"<<endl;
                    cout<<"The current content of List1 is:";
                    printList(head1);
                }
                else{
                    cout<<"No deletion as the value "<<letter1<<" was not found in the list";
                }
            }
            if(command=="delete2"){
                bool found=deleteCh(head2,letter1);
                if(found){
                    cout<<"Deleting all occurrences of "<<letter1<<" in List2"<<endl;
                    cout<<"The current content of List2 is:";
                    printList(head2);
                }
                else{
                    cout<<"No deletion as the value "<<letter1<<" was not found in the list";
                }
            }
            if(command=="insert1"){
                insert(head1,letter1,letter2);
                cout<<"The node with "<<letter1<<" has been inserted after the first occurrence of a node with "<<letter2<<" value.";
                printList(head1);
            }
            if(command=="insert2"){
                insert(head2,letter1,letter2);
                cout<<"The node with "<<letter1<<" has been inserted after the first occurrence of a node with "<<letter2<<" value.";
                printList(head2);
            }
            if(command=="sim"){
                int count=compare(head1,head2);
                cout<<"There is/are "<<count<<" letter(s) matched in the same positions in both lists.";
            }
        }
        cout<<"Enter a command and its corresponding argument(s), if any: ";
        getline(cin, line);
        istringstream ss3(line);
        ss3 >> command>>letter1>>letter2;
    }

    return 0;
}
