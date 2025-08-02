//
//  main.cpp
//  hw4 2022
//
//  Created by Kaan Karabıyık on 3.08.2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include "DynStackHW4.h"
using namespace std;
int main() {
    string filename;
    ifstream input;
    input.open(filename.c_str());
    while(!input.fail()){
        cout<<"file not found"<<endl;
        cout<<"please enter the filename: ";
        cin>>filename;
        input.open(filename.c_str());
    }
    DynStack stack;
    string line;
    int linenumber=0;
    bool error=false;
    while(getline(input,line)){
        linenumber++;
        for(int i=0;i<line.size();i++){
            char c=line[i];
            if(c=='('||c=='}'||c=='['){
                cout<<"found the opening symbol "<<c<<" at line "<<linenumber<<endl;
                stack.push(c,linenumber);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(stack.isEmpty()){
                    cout << "ERROR!!! Found the closing symbol " << c
                         << " at line " << linenumber
                         << " but there are no unclosed opening symbols!" << endl;
                    error=true;
                }
                else{
                    char lastsymbol;
                    int lastline;
                    stack.pop(lastsymbol,lastline);
                    char expected;
                    if(c==')'){
                        expected='(';
                    }
                    else if(c=='}'){
                        expected='{';
                    }
                    else if(c==']'){
                        expected='[';
                    }
                    if(expected==lastsymbol){
                        cout << "Found the closing symbol " << c << " at line " << linenumber
                             << " which closes the opening symbol " << lastsymbol
                             << " at line " << lastline << endl;
                    }
                    else{
                        cout << "ERROR!!! Found the closing symbol " << c << " at line " << linenumber
                             << " but the last unclosed opening symbol is " << lastsymbol
                             << " at line " << lastline << endl;
                            error = true;
                    }
                }
            }
            if(!error){
                if(!stack.isEmpty()){
                    cout << "ERROR!!! The following opening symbols were not closed:" << endl;
                    while(stack.isEmpty()){
                        char symbol;
                        int line;
                        stack.pop(symbol,line);
                        cout << "  Symbol " << symbol << " at line " << line << endl;
                    }
                }
                else{
                    cout << "File processed successfully. No errors were found." << endl;
                }
            }
        }
    }
    return 0;
}
