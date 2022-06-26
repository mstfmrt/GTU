#include "func.h"
#include <iostream>
#include <vector>
using namespace std;
void mapCreator(int mapNum, vector<Cell>& map){
    switch (mapNum) {//creating map according to chosed one
        case 1:
            map = {Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::e,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o};
            break;
        case 2:
            map = {Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::e,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o};
            break;
        case 3:
            map = {Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::e,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o};
            break;
        case 4:
            map = {Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::e,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o};
            break;
        case 5:
            map = {Cell::o,Cell::o,Cell::o,Cell::o,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,
                   Cell::p,Cell::p,Cell::p,Cell::p,Cell::e,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,
                   Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::p,Cell::p,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::p,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,
                   Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o,Cell::o};
            break;
        case 6:
            map = {Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o,
                   Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o, Cell::o};
            break;
    }
}
void chooseMap(vector<Cell>& map)
{
    int mapNum;
    cout << "Which map do you want to play? (1-6)  ";
    cin >> mapNum;
    if(mapNum>0 && mapNum <7)//checking if chosed map is invalid
        mapCreator(mapNum,map);
    else {
        cout << "\nMap you chosed is invalid!!\n";
        chooseMap(map);
    }
    return;
}
bool isMoveLegal(int loc,Dir x,vector<Cell> map)
{
    if(map.at(loc)==Cell::p)//checking is there a peg on the location
        switch (x) {//checking is the cells is suitable for move
            case d:
                if(loc<80)
                    if(map.at(loc+10)== Cell::p && map.at(loc+20) == Cell::e)
                        return true;
                break;
            case u:
                if(loc>19)
                    if(map.at(loc-10) == Cell::p && map.at(loc-20) == Cell::e)
                        return true;
                break;
            case r:
                if(loc<98)
                    if(map.at(loc+1) == Cell::p && map.at(loc+2) == Cell::e)
                        return true;
                break;
            case l:
                if(loc>2)
                    if(map.at(loc-1) == Cell::p && map.at(loc-2) == Cell::e)
                        return true;
                break;
        }
    return false;

}
void move(int loc,Dir x, vector<Cell>& map)
{
    switch (x) {//updating map according to move
        case d:
            map[loc]=Cell::e;
            map[loc+10]=Cell::e;
            map[loc+20]=Cell::p;
            break;
        case u:
            map[loc]=Cell::e;
            map[loc-10]=Cell::e;
            map[loc-20]=Cell::p;
            break;
        case r:
            map[loc]=Cell::e;
            map[loc+1]=Cell::e;
            map[loc+2]=Cell::p;
            break;
        case l:
            map[loc]=Cell::e;
            map[loc-1]=Cell::e;
            map[loc-2]=Cell::p;
            break;
    }


}
vector<int> possibleLoc(vector<Cell> map){
    vector<int> posLoc;
    for(int i=0;i<100;++i){
        if(isMoveLegal(i,d,map)||isMoveLegal(i,u,map)||isMoveLegal(i,r,map)||isMoveLegal(i,l,map))
            posLoc.push_back(i);
    }
    return posLoc;
}
bool isGameOver(vector<Cell> map){
    vector<int> posLoc;
    posLoc = possibleLoc(map);
    if(posLoc.size()==0)
        return true;
    return false;
}
void getLocDir(string input,int& loc, Dir& x){
    if(input.length()!=4||(input[0]-'a')>9||(input[0]-'a')<0||(input[1]-'0')>8||(input[1]-'0')<0||
       !(input[3]=='u'||input[3]=='d'||input[3]=='r'||input[3]=='l')){//checking if the input outside the map or direction is invalid
        loc = 99;
        x = u;//assigning invalid move
        return;
    }

    loc = 10 * (input[1] - '0') + (input[0]-'a');//calculating the location according to input
    switch (input[3]) {//assigning direction according to input
        case 'u':
            x = u;
            break;
        case 'd':
            x=d;
            break;
        case 'r':
            x = r;
            break;
        case 'l':
            x=l;
            break;
    }
    return;
}
void play(vector<Cell>& map)
{
    char playerChoice;
    cout << "If you want to play press (y) otherwise it will be a computer game.";
    cin >> playerChoice;

    if(playerChoice == 'y')//according to choice starting game
        humanPlay(map);
    else
        computerPlay(map);
    return;
}
void printCell(Cell x){//printing cells to screen
    switch (x) {
        case Cell::p:
            cout <<"P";
            break;
        case Cell::e:
            cout <<".";
            break;
        case Cell::o:
            cout <<" ";
            break;
    }
    return;
}
void printMap(vector<Cell> map){//printing map to screen
    cout << "  abcdefghi\n";//horizontal location identifiers
    int k = 0;
    for(int i=0; i<10; i++){
        cout << i << " ";//vertical location identifiers
        for(int j=0; j<10; j++){
            printCell(map[k]);
            k++;
        }
        cout<< "\n";
    }
    return;
}
void printScore(vector<Cell> map){
    int score=0;
    for(Cell i: map)
        if(i == Cell::p)
            ++score;
    cout << "\nYour score is " << score;
}
void humanPlay(vector<Cell>& map){
    string input;
    int loc;
    Dir x;
    printMap(map);
    do{
        //asking user for move
        cout<< "Enter the move you wanted to make (b4-r)";
        cin>> input;
        getLocDir(input,loc, x);
        if(isMoveLegal(loc,x,map)){
            move(loc,x,map);
            printMap(map);
        }
        else
            cout<<"\nMove is invalid!";

    }while(!isGameOver(map));
    printScore(map);
    return;
}
void computerPlay(vector<Cell>& map)
{
    printMap(map);
    int loc;
    Dir x;
    do{
        //asking user for move
        cout<< "\nplease press enter for the computer to play";
        getchar();

        vector<int> posLoc;
        posLoc = possibleLoc(map);
        int size = posLoc.size();
        int randLoc = rand() % size;
        loc = posLoc[randLoc];
        do{
            int randDir = rand() % 4;
            switch (randDir) {
                case 0:
                    x = d;
                    break;
                case 1:
                    x = u;
                    break;
                case 2:
                    x = r;
                    break;
                case 3:
                    x = l;
                    break;
            }
        } while (!isMoveLegal(loc,x,map));
        move(loc,x,map);
        printMap(map);
    }while(!isGameOver(map));
    printScore(map);
}