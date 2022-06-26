#include "func.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool Game::isMoveLegal(vector<int> loc,Dir x)const
{
    if(loc[0] >= mapSize && loc[1] >= mapSize)
        return false;
    if(map.at(loc[0]).at(loc[1])==Cell::p)//checking is there a peg on the location
        switch (x) {//checking are cells is suitable for move
            case d:
                if(loc[0]<mapSize-2)
                    if(map.at(loc[0]+1).at(loc[1])== Cell::p && map.at(loc[0]+2).at(loc[1])== Cell::e)
                        return true;
                break;
            case u:
                if(loc[0]>1)
                    if(map.at(loc[0]-1).at(loc[1])== Cell::p && map.at(loc[0]-2).at(loc[1])== Cell::e)
                        return true;
                break;
            case r:
                if(loc[1]<mapSize-2)
                    if(map.at(loc[0]).at(loc[1]+1)== Cell::p && map.at(loc[0]).at(loc[1]+2)== Cell::e)
                        return true;
                break;
            case l:
                if(loc[1]>1)
                    if(map.at(loc[0]).at(loc[1]-1)== Cell::p && map.at(loc[0]).at(loc[1]-2)== Cell::e)
                        return true;
                break;
        }
    return false;

}
bool Game::move(vector<int>& loc,Dir x)
{
    if(!isMoveLegal(loc,x)){
       return false;
    }
    switch (x) {//updating map according to move
        case d:
            map.at(loc[0]).at(loc[1])=Cell::e;
            map.at(loc[0]+1).at(loc[1])=Cell::e;
            map.at(loc[0]+2).at(loc[1])=Cell::p;
            break;
        case u:
            map.at(loc[0]).at(loc[1])=Cell::e;
            map.at(loc[0]-1).at(loc[1])=Cell::e;
            map.at(loc[0]-2).at(loc[1])=Cell::p;
            break;
        case r:
            map.at(loc[0]).at(loc[1])=Cell::e;
            map.at(loc[0]).at(loc[1]+1)=Cell::e;
            map.at(loc[0]).at(loc[1]+2)=Cell::p;
            break;
        case l:
            map.at(loc[0]).at(loc[1])=Cell::e;
            map.at(loc[0]).at(loc[1]-1)=Cell::e;
            map.at(loc[0]).at(loc[1]-2)=Cell::p;
            break;
    }
    ++numberOfMoves;//increasing move number
    return true;
}
vector<vector<int>> Game::possibleLoc()const{//checking for possible moves and records locations
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
bool Game::isGameOver() const{//checking
    vector<vector<int>> posLoc;
    posLoc = possibleLoc();
    if(posLoc.empty())
        return true;
    return false;
}
void Game::loadMap(ifstream& save){
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
                    row.push_back(Cell::p);
                    break;
                case 'o':
                    row.push_back(Cell::o);
                    break;
                case 'e':
                    row.push_back(Cell::e);
                    break;
            }
        }
        map.push_back(row);
    }
    return;
}
void Game::loadGame(const string& saveName = "save.txt"){
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
void Game::saveGame(const string& saveName)const{
    ofstream save(saveName);
    save << playerChoice << endl;
    save << numberOfMoves << endl;
    save << mapSize << endl;
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            switch (map.at(i).at(j)) {
                case Cell::p:
                    save << 'p';
                    break;
                case Cell::o:
                    save << 'o';
                    break;
                case Cell::e:
                    save << 'e';
                    break;
            }
        }
        save << endl;
    }
    save.close();
}
void Game::printCell(Cell x)const{//printing cells to screen
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
void Game::printMap()const{//printing map to screen
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
            printCell(map.at(i).at(j));
        }
        cout<< "\n";
    }
    return;
}
int Game::getScore()const{//getting score from private variable
    int score=0;
    for(int i=0;i<mapSize;++i)
        for (int j = 0; j < mapSize; ++j)
            if(map.at(i).at(j)==Cell::p)
                ++score;
    return score;
}
void Game::computerPlay()
{
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
    move(loc,x);
    return;
}
void play(Game& game)
{
    string saveName;
    auto gameChoice = chooseGame();//choosing game type new or load
    if(gameChoice=='n')//if a new game will start choosing who will play
        newGame(game);
    else{
        cout<<"\nEnter the save name with .txt extension";
        cin >> saveName;
        game.loadGame(saveName);
    }
    return;
}
void newGame(Game& game){
    game.setPlayer(choosePlayer());//setting who will play
    chooseMap(game);
    return;
}
void getLocDir(string input,vector<int>& loc, Dir& x,Game& game){// getting location and direction from user input

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
void chooseMap(Game& game)
{
    int mapNum;
    cout << "\nWhich map do you want to play? (1-5)  ";
    cin >> mapNum;

    if(mapNum>0 && mapNum <8){
        string fileName = to_string(mapNum) + ".txt";
        game.loadGame(fileName);
    }//checking if chosed map is invalid
    else {
        cerr << "\nMap you chosed is invalid!!\n";
        chooseMap(game);
    }

}

