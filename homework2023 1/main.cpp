//
//  main.cpp
//  hw1 2023
//
//  Created by Kaan Karabıyık on 30.07.2025.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct cell{
    int row;
    int col;
};
vector<vector<char>> shapeParser(const string& input) {
    vector<vector<char>> shape;
    vector<char> row;
    int i = 0;

    while (i < input.size()) {
        if (isdigit(input[i])) {
            int count = input[i] - '0';
            i++;
            char letter = input[i];
            i++;
            for (int k = 0; k < count; k++)
                row.push_back(letter);
        }
        else if (input[i] == '/') {
            // one slash = one new row
            shape.push_back(row);
            row.clear();
            i++;
        }
    }

    // push whatever is left in the last row
    shape.push_back(row);
    return shape;
}

vector<vector<cell>> findPlacements(vector<vector<char>> matrix,vector<vector<char>> shape){
    int R=matrix.size();
    int C=matrix[0].size();
    int rS=shape.size();
    int cS = 0;
    for(int i=0; i<shape.size(); i++){
        if(shape[i].size() > cS){
            cS = shape[i].size();
        }
    }
    vector<vector<cell>> all;
    for(int r0=0;r0+rS<=R;r0++){
        for(int c0=0;c0+cS<=C;c0++){
            bool valid=true;
            vector<cell> stars;
            for(int i=0;i<rS&&valid;i++){
                for(int j=0;j<shape[i].size();j++){
                    if(shape[i][j]=='s'){
                        if(matrix[r0+i][c0+j]!='-'){
                            valid=false;
                        }
                        cell Cell;
                        Cell.row=r0+i;
                        Cell.col=c0+j;
                        stars.push_back(Cell);
                    }
                }
            }
            if(valid){
                all.push_back(stars);
            }
        }
    }
    return all;
}
int main() {
    string filename;
    cout<<"please enter the filename: ";
    cin>>filename;
    ifstream input;
    input.open(filename.c_str());
    while(!input){
        cout << "Couldn't find the file!" << endl;
        cout << "Please enter the file name: ";
        cin >> filename;
        input.open(filename.c_str()); // try to open again
    }
    string line;
    bool valid=true;
    int expectedlength=-1;
    vector<vector<char>> matrix;
    int linenumber=0;
    while(getline(input,line)){
        linenumber++;
        for(int i=0;i<line.length();i++){
            if(line[i]!='-'&&line[i]!='#'){
                cout<<"Erroneous file content. Program terminates.";
                valid=false;
            }
        }
        int currentlength=line.length();
        if(expectedlength==-1){
            expectedlength=currentlength;
        }
        else if(expectedlength!=currentlength){
            cout<<"Erroneous file content. Program terminates.";
            valid=false;
        }
        if(valid){
            vector<char> row;
            for(int i=0;i<line.length();i++){
                row.push_back(line[i]);
            }
            matrix.push_back(row);
        }
    }
    if(valid){
        cout<<"matrix content: "<<endl;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        string choice;
        cout<<"Enter the string query for a shape, or Quit to terminate the program: ";
        cin>>choice;
        while(choice!="quit"){
            vector<vector<char>> shape=shapeParser(choice);
            vector<vector<cell>> placements=findPlacements(matrix,shape);
            if(placements.empty()){
                cout<<"no placements found"<<endl;
            }
            else{
                for(int i=0;i<placements.size();i++){
                    cout << "Placement number " << i+1 << ":" << endl;
                    for(int j=0;j<placements[i].size();j++){
                        cout<<"("<<placements[i][j].row<<","<<placements[i][j].col<<") ";
                    }
                    cout<<endl;
                }
            }
            cout<<"Enter the string query for a shape, or Quit to terminate the program: ";
            cin>>choice;
        }
        }

    return 0;
}
