//
//  main.cpp
//  hw2022 1
//
//  Created by Kaan Karabıyık on 29.07.2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct cell
{
char letter; // letter inside the cell
char color; // color of the cell
};
bool isLower(string word){
    for(int i=0;i<word.length();i++){
        if(word[i]<'a'||word[i]>'z'){
           return false;
    }
    
}
    return true;
    }
bool uniqueW(string word){
    for(int i=0;i<word.length();i++){
        for(int j=i+1;j<word.length();j++){
            if(word[i]==word[j]){
                return false;
            }
        }
    }
    return true;
}
bool seenbefore(string word,vector<string>&v){
    for(int i=0;i<v.size();i++){
        if(v[i]==word){
            return false;
        }
    }
    return true;
}
bool greencheck(string word,string green){
    for(int i=0;i<word.length();i++){
        if(green[i]!='-'&&word[i]!=green[i]){
            return false;
        }
    }
    return true;
}

int main() {
    string filename;
    cout << "Please enter the file name: ";
    cin >> filename;

    ifstream input;
    input.open(filename.c_str());

    while (!input) {
        cout << "Couldn't find the file!" << endl;
        cout << "Please enter the file name: ";
        cin >> filename;
        input.open(filename.c_str()); // try to open again
    }

    string word;
    int attempt;
    input>>attempt;
    input.ignore();
    getline(input,word);
    int Wlength=word.length();
    cout<<"The word that you will guess has "<<Wlength<<" letters and you have "<<attempt<<" attempts.";
    vector<vector<cell>> matrix(attempt,vector<cell>(Wlength));
    for(int i=0;i<attempt;i++){
        for(int j=0;j<Wlength;j++){
            matrix[i][j].letter='-';
            matrix[i][j].color='-';
        }
    }
    string greenstring(Wlength,'-');
    string guess;
    int guesscount=0;
    bool wordfound=false;
    vector<string> prev;
    while(guesscount<attempt&&!wordfound){
        cout<<"What's your guess? ";
        cin>>guess;
        bool valid=true;
        if(guess.length()!=Wlength){
            cout << "Invalid input. The word must be " << Wlength << " letters long." << endl;
            valid=false;
        }
        if(valid && !isLower(guess)){
            cout << "Invalid input. Only lowercase letters are allowed." << endl;
            valid=false;
        }
        if(valid && !uniqueW(guess)){
            cout << "Invalid input. The word must not have repeated letters." << endl;
            valid=false;
        }
        if(valid && !seenbefore(guess,prev)){
            cout << "You have already tried this word." << endl;
            valid=false;
        }
        if(valid && !greencheck(guess,greenstring)){
            cout << "You must keep the correct letters in the same position as before." << endl;
            valid=false;
        }
        if(valid){
            prev.push_back(guess);
            for(int i=0;i<Wlength;i++){
                matrix[guesscount][i].letter=guess[i];
                if(guess[i]==word[i]){
                    matrix[guesscount][i].color='G';
                    greenstring[i] = guess[i];
                }
                else{
                    bool found=false;
                    for(int j=0;j<Wlength;j++){
                        if(guess[i]==word[j]&&!found){
                            found=true;
                        }
                    }
                    if(found){
                        matrix[guesscount][i].color='Y';
                    }
                    else{
                        matrix[guesscount][i].color='B';
                    }
                }
            }
            if(guess==word){
                wordfound=true;
                cout << "You guessed the word!" << endl;
            }
            guesscount++;
            for(int i=0;i<attempt;i++){
                for(int j=0;j<Wlength;j++){
                    cout<<matrix[i][j].letter<<", "<<matrix[i][j].color<<endl;
                }
            }
            
        }
    }
    return 0;
}
