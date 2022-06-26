#include "func.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



PegSolitare::Cell::Cell(CellSit nsit, int nrow, int ncol) {
    sit = nsit;
    row = nrow;
    col = ncol;
}
PegSolitare::PegSolitare(const int mapNum,const char playerCh) {
    if(playerCh == 'u' || playerCh == 'c'){
        playerChoice = playerCh;
    } else{
        cerr << "\nIllegal player choice!!\n";
        exit(1);
    }
    playerChoice = playerCh;
    if(mapNum>0 && mapNum <6){
        string fileName = to_string(mapNum) + ".txt";
        ifstream save(fileName);
        loadMap(save);
    }//checking if chosen map is invalid
    else {
        cerr << "\nMap you chosed is invalid!!\n";
        exit(1);
    }
}
PegSolitare::PegSolitare(const string saveName){
    loadGame(saveName);
}
PegSolitare::PegSolitare(vector<vector<Cell>> map,const char playerCh) {
    if(map.size() > map.at(0).size()){
        mapSize=map.size();
        for(int i=0; i<mapSize; ++i){
            vector<Cell> row;
            for(int j=0; j<mapSize; ++j){
                if(j>=map.at(0).size())
                    row.push_back(Cell(CellSit::o,i,j));
                else
                    row.push_back(map.at(i).at(j));
                }
            map.push_back(row);
        }
    }
    else{
        mapSize = map.at(0).size();
        for(int i=0; i<mapSize; ++i){
            vector<Cell> row;
            for(int j=0; j<mapSize; ++j){
                if(i>=map.size())
                    row.push_back(Cell(CellSit::o,i,j));
                else
                    row.push_back(map.at(i).at(j));
            }
            map.push_back(row);
        }
    }
    playerChoice=playerCh;
}
bool PegSolitare::isWorse(const PegSolitare other) const
{//compare this object and other which given as parameter return true if there is more peg on this game
    if(getScore()>other.getScore())
        return true;
    else
        return false;
}
bool PegSolitare::isMoveLegal(vector<int> loc,Dir x)const
{
    if(loc[0] >= mapSize && loc[1] >= mapSize)
        return false;
    if(map.at(loc[0]).at(loc[1]).getSit()==CellSit::p)//checking is there a peg on the location
        switch (x) {//checking are cells is suitable for move
            case d:
                if(loc[0]<mapSize-2)
                    if(map.at(loc[0]+1).at(loc[1]).getSit()==CellSit::p && map.at(loc[0]+2).at(loc[1]).getSit()==CellSit::e)
                        return true;
                break;
            case u:
                if(loc[0]>1)
                    if(map.at(loc[0]-1).at(loc[1]).getSit()==CellSit::p && map.at(loc[0]-2).at(loc[1]).getSit()==CellSit::e)
                        return true;
                break;
            case r:
                if(loc[1]<mapSize-2)
                    if(map.at(loc[0]).at(loc[1]+1).getSit()==CellSit::p && map.at(loc[0]).at(loc[1]+2).getSit()==CellSit::e)
                        return true;
                break;
            case l:
                if(loc[1]>1)
                    if(map.at(loc[0]).at(loc[1]-1).getSit()==CellSit::p && map.at(loc[0]).at(loc[1]-2).getSit()==CellSit::e)
                        return true;
                break;
        }
    return false;

}
bool PegSolitare::play(vector<int>& loc,Dir x)
{//functions make move according to given parameters
    if(!isMoveLegal(loc,x)){
        return false;
    }
    switch (x) {//updating map according to move
        case d:
            map.at(loc[0]).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]+1).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]+2).at(loc[1]).setSit(CellSit::p);
            break;
        case u:
            map.at(loc[0]).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]-1).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]-2).at(loc[1]).setSit(CellSit::p);
            break;
        case r:
            map.at(loc[0]).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]).at(loc[1]+1).setSit(CellSit::e);
            map.at(loc[0]).at(loc[1]+2).setSit(CellSit::p);
            break;
        case l:
            map.at(loc[0]).at(loc[1]).setSit(CellSit::e);
            map.at(loc[0]).at(loc[1]-1).setSit(CellSit::e);
            map.at(loc[0]).at(loc[1]-2).setSit(CellSit::p);
            break;
    }
    ++numberOfMoves;//increasing move number
    return true;
}
void PegSolitare::play()
{//function plays random from possible moves
    vector<int> loc;
    Dir x;
    vector<vector<int>> posLoc;
    posLoc = possibleLoc();//creating random locations vector
    int size = posLoc.size();
    int randLoc = rand() % size;//for choosing random one creating random index
    loc.push_back(posLoc.at(randLoc).at(0));
    loc.push_back(posLoc.at(randLoc).at(1));//assigning random coordinates
    do{
        int randDir = rand() % 4;//trying random directions until find a valid one
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
    } while (!isMoveLegal(loc,x));
    play(loc,x);
    return;
}
void PegSolitare::playGame(){ //asks user the board type then plays until game finshes
    int mapNum;
    cout << "Enter the map number you wanted to be played";
    cin >> mapNum;
    PegSolitare game(mapNum,'c');
    while(!game.isGameOver()){
        game.printMap();
        game.play();
    }
        game.printMap();
        cout << "Score is " << game.getScore();
}
int PegSolitare::allPegs(vector<PegSolitare> games)
{//counts and returns number of pegs on all games in the given games vector
    int total=0;
        for(int i=0;i<games.size();++i)
        total+=games.at(i).numOfPegs();
    return total;
}
vector<vector<int>> PegSolitare::possibleLoc()const{//checking for possible moves and records locations
    vector<vector<int>> posLoc;
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            vector<int> loc;
            decltype(loc) rowCol;
            loc.push_back(i);
            loc.push_back(j);
            if(isMoveLegal(loc,d)||isMoveLegal(loc,u)||isMoveLegal(loc,r)||isMoveLegal(loc,l)){
                rowCol.push_back(loc[0]);
                rowCol.push_back(loc[1]);
                posLoc.push_back(rowCol);
            }
        }
    }
    return posLoc;
}
bool PegSolitare::isGameOver() const
{//checking if the game is over
    vector<vector<int>> posLoc;
    posLoc = possibleLoc();
    if(posLoc.empty())
        return true;
    return false;
}
void PegSolitare::loadMap(ifstream& save)
{//loading maps from txt files for efficiency
    char pegSit;
    int loadInt;
    save >> loadInt;
    mapSize = loadInt;//loading map size from map file
    for(int i=0; i<mapSize; ++i){
        vector<Cell> row;
        for(int j=0; j<mapSize; ++j){
            save >> pegSit;
            switch (pegSit) {
                case 'p':
                    row.push_back(Cell(CellSit::p,i,j));
                    break;
                case 'o':
                    row.push_back(Cell(CellSit::o,i,j));
                    break;
                case 'e':
                    row.push_back(Cell(CellSit::e,i,j));
                    break;
            }
        }
        map.push_back(row);
    }
    return;
}
void PegSolitare::loadGame(const string& saveName = "save.txt"){
    string loadData;
    int loadInt;
    ifstream save(saveName);
    if(!save.is_open()){
        cerr << "Save you entered couldn't found"<< endl;
        return;
    }
    if(playerChoice=='u'||playerChoice=='c'){
        loadMap(save);
        return;
    }
    save >> loadData;
    playerChoice = loadData[0];
    save >> loadInt;
    numberOfMoves = loadInt;
    loadMap(save);
    save.close();
}
void PegSolitare::saveGame(const string& saveName)const
{//saves the current game to a given file name
    ofstream save(saveName);
    save << playerChoice << endl;
    save << numberOfMoves << endl;
    save << mapSize << endl;
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            switch (map.at(i).at(j).getSit()) {
                case CellSit::p:
                    save << 'p';
                    break;
                case CellSit::o:
                    save << 'o';
                    break;
                case CellSit::e:
                    save << 'e';
                    break;
            }
        }
        save << endl;
    }
    save.close();
}
void PegSolitare::printCell(CellSit x)const{//printing cells to screen
    switch (x) {
        case CellSit::p:
            cout <<"P";
            break;
        case CellSit::e:
            cout <<".";
            break;
        case CellSit::o:
            cout <<" ";
            break;
    }
    return;
}
void PegSolitare::printMap()const{//printing map to screen
    char locId = 'a';
    cout << "\n  ";
    for(int i=0; i<mapSize; ++i){
        cout<<locId;
        ++locId;
    }
    cout << '\n';
    for(int i=0; i<mapSize; i++){
        cout << i << " ";//vertical location identifiers
        for(int j=0; j<mapSize; j++){
            printCell(map.at(i).at(j).getSit());
        }
        cout<< "\n";
    }
    return;
}
int PegSolitare::getScore()const{//getting score from private variable
    int score=0;
    for(int i=0;i<mapSize;++i)
        for (int j = 0; j < mapSize; ++j)
            if(map.at(i).at(j).getSit()==CellSit::p)
                ++score;
    return score;
}
int PegSolitare::numOfPegs() {//returning number of cells with peg on the board
    int pegs=0;
    for(int i=0;i<mapSize;++i)
        for (int j = 0; j < mapSize; ++j)
            if(map.at(i).at(j).getSit()==CellSit::p)
                ++pegs;
    return pegs;
}
int PegSolitare::numOfEmpty() {//returning number of empty cells on the board
    int empty=0;
    for(int i=0;i<mapSize;++i)
        for (int j = 0; j < mapSize; ++j)
            if(map.at(i).at(j).getSit()==CellSit::e)
                ++empty;
    return empty;
}
inline int PegSolitare::numOfPegsTaken() {//returning number of pegs taken from board
    return numOfEmpty()-1;
}


void getLocDir(string input,vector<int>& loc, Dir& x,PegSolitare& game){// getting location and direction from user input

    if(input.length()==4){
        if((input[0]-'a')>=game.getMapSize()||(input[0]-'a')<0||(input[1]-'0')>=game.getMapSize()||(input[1]-'0')<0||
           !(input[3]=='u'||input[3]=='d'||input[3]=='r'||input[3]=='l')){//checking if the input outside the map or direction is invalid
            loc[0] = game.getMapSize()-1;
            loc[1] = game.getMapSize()-1;
            x = d;//assigning invalid move
            return;
        }
        loc[0] = input[1] - '0';
        loc[1] = input[0] - 'a';
    }
    else if(input.length()==5){
        if((input[0]-'a')>=game.getMapSize()||(input[0]-'a')<0||(input[1]-'0')>9||(input[1]-'0')<0||(input[2]-'0')>9||(input[2]-'0')<0||
           !(input[4]=='u'||input[4]=='d'||input[4]=='r'||input[4]=='l')){//checking if the input outside the map or direction is invalid
            loc[0] = game.getMapSize()-1;
            loc[1] = game.getMapSize()-1;
            x = d;//assigning invalid move
            return;
        }
        loc[0] = 10 * (input[1] - '0') + (input[2] - '0');
        loc[1] = input[0] - 'a';
    }
    else{
        loc[0] = game.getMapSize()-1;
        loc[1] = game.getMapSize()-1;
        x = d;//assigning invalid move
        return;
    }

    //calculating the location according to input
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
char chooseGame(){
    char choice;//choosing game type if a new one or load from saves
    cout << "Do you want to start a new game(n) or load game(l)?  ";
    cin >> choice;
    switch (choice) {
        case 'n':
            return 'n';
        case 'N':
            return 'n';
        case 'l':
            return 'l';
        case 'L':
            return 'l';
        default:
            cerr << "Invalid choice!" << endl;
            return chooseGame();
    }
}
char choosePlayer(){
    char choice;// choosing player type
    cout << "\nDo you want a game of user(u) or computer(c)?";
    cin >> choice;
    switch (choice) {
        case 'u':
            return 'u';
        case 'U':
            return 'u';
        case 'c':
            return 'c';
        case 'C':
            return 'c';
        default:
            cerr << "Invalid player choice!" << endl;
            return choosePlayer();
    }
}
int chooseMap()
{
    int mapNum;
    cout << "\nWhich map do you want to play? (1-5)  ";
    cin >> mapNum;

    if(mapNum>0 && mapNum <6){
        return mapNum;
    }//checking if chosed map is invalid
    else {
        cerr << "\nMap you chosed is invalid!!\n";
        return chooseMap();
    }

}
PegSolitare createGame(){
    string saveName;
    if(chooseGame()=='n'){
        PegSolitare x(chooseMap(),choosePlayer());
        return x;
    }
    else{
        cout<<"\nEnter the save name with .txt extension";
        cin >> saveName;
        PegSolitare y(saveName);
        return y;
    }
}
bool isAllGamesOver(vector<PegSolitare> games){//checking if the all games over
    int numOfGames = games.size();
    for (int i = 0; i < numOfGames; ++i) {
        if (!games.at(i).isGameOver())
            return false;
    }
    return true;
}