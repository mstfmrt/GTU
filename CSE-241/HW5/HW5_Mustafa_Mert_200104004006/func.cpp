#include "iostream"
#include "vector"
#include "func.h"

using namespace bg2;


void PegSolitare::play(vector<int> loc, char dir) {//makes the move according to given location and direction

    switch (dir) {//updating map according to move
        case 'd':
            map.at(loc[0]).at(loc[1]) = 'e';
            map.at(loc[0]+1).at(loc[1]) = 'e';
            map.at(loc[0]+2).at(loc[1]) = 'p';
            break;
        case 'u':
            map.at(loc[0]).at(loc[1]) = 'e';
            map.at(loc[0]-1).at(loc[1]) = 'e';
            map.at(loc[0]-2).at(loc[1]) = 'p';
            break;
        case 'r':
            map.at(loc[0]).at(loc[1]) = 'e';
            map.at(loc[0]).at(loc[1]+1) = 'e';
            map.at(loc[0]).at(loc[1]+2) = 'p';
            break;
        case 'l':
            map.at(loc[0]).at(loc[1]) = 'e';
            map.at(loc[0]).at(loc[1]-1) = 'e';
            map.at(loc[0]).at(loc[1]-2) = 'p';
            break;
    }
}
void PegSolitare::playUser(string input) {//makes the move according to user input if it is valid
    vector<int> loc;
    loc.push_back(0);
    loc.push_back(0);
    char dir;
    if(input.length()==4){
        if((input[0]-'a')>=9||(input[0]-'a')<0||(input[1]-'0')>=9||(input[1]-'0')<0||
           !(input[3]=='u'||input[3]=='d'||input[3]=='r'||input[3]=='l')){//checking if the input outside the map or direction is invalid
            loc[0] = 8;
            loc[1] = 8;
            dir = 'u';//assigning invalid move
        }
        loc[0] = input[1] - '0';
        loc[1] = input[0] - 'a';
        dir = input[3];
    }
    else{
        loc[0] = 8;
        loc[1] = 8;
        dir = 'u';//assigning invalid move
    }

    if(!isMoveLegal(loc,dir)){
        cerr << "Move is illegal" << endl;
        return ;
    }
    play(loc,dir);
}
void PegSolitare::playUser() {//asks input to user until the game ends
    while(!endGame()){
        string input;
        cout << "Enter a move (c4-r): ";
        cin >> input;
        playUser(input);
        print();
    }
}
void PegSolitare::playAuto() {//plays a random move
    vector<int> loc;
    char dir;
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
                dir = 'd';
                break;
            case 1:
                dir = 'u';
                break;
            case 2:
                dir = 'r';
                break;
            case 3:
                dir = 'l';
                break;
        }
    } while (!isMoveLegal(loc,dir));
    play(loc,dir);
    return;
}
void PegSolitare::playAutoAll() {//plays the random moves until the game ends
    while(!endGame()){
        playAuto();
    }
}
bool PegSolitare::endGame() {//checking if the game is over
    vector<vector<int>> posLoc;
    posLoc = possibleLoc();
    if(posLoc.empty())
        return true;
    return false;
}
int PegSolitare::boardScore() {//gives the score of the board
    int score=0;
    for(int i=0;i<9;++i)
        for (int j = 0; j < 9; ++j)
            if(map.at(i).at(j) == 'p')
                ++score;
    return score;
}
void PegSolitare::initialize() {//initialized the board for the game
    map = {
            {'o','o','o','p','p','p','o','o','o'},
            {'o','o','o','p','p','p','o','o','o'},
            {'o','o','o','p','p','p','o','o','o'},
            {'p','p','p','p','p','p','p','p','p'},
            {'p','p','p','p','e','p','p','p','p'},
            {'p','p','p','p','p','p','p','p','p'},
            {'o','o','o','p','p','p','o','o','o'},
            {'o','o','o','p','p','p','o','o','o'},
            {'o','o','o','p','p','p','o','o','o'}
    };
    return ;
}
bool PegSolitare::isMoveLegal(vector<int> loc,char x)const{// checks if the move is legal
    if(loc[0] >= 9 && loc[1] >= 9)
        return false;
    if(map.at(loc[0]).at(loc[1]) =='p')//checking is there a peg on the location
        switch (x) {//checking are cells is suitable for move
            case 'd':
                if(loc[0]<7)
                    if(map.at(loc[0]+1).at(loc[1])=='p' && map.at(loc[0]+2).at(loc[1])=='e')
                        return true;
                break;
            case 'u':
                if(loc[0]>1)
                    if(map.at(loc[0]-1).at(loc[1])=='p' && map.at(loc[0]-2).at(loc[1])=='e')
                        return true;
                break;
            case 'r':
                if(loc[1]<7)
                    if(map.at(loc[0]).at(loc[1]+1)=='p' && map.at(loc[0]).at(loc[1]+2)=='e')
                        return true;
                break;
            case 'l':
                if(loc[1]>1)
                    if(map.at(loc[0]).at(loc[1]-1)=='p' && map.at(loc[0]).at(loc[1]-2)=='e')
                        return true;
                break;
        }
    return false;
}
vector<vector<int>>  PegSolitare::possibleLoc()const{//checking for possible moves and records locations
    vector<vector<int>> posLoc;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            vector<int> loc;
            decltype(loc) rowCol;
            loc.push_back(i);
            loc.push_back(j);
            if(isMoveLegal(loc,'d')||isMoveLegal(loc,'u')||isMoveLegal(loc,'r')||isMoveLegal(loc,'l')){
                rowCol.push_back(loc[0]);
                rowCol.push_back(loc[1]);
                posLoc.push_back(rowCol);
            }
        }
    }
    return posLoc;
}
void PegSolitare::print() {//prints the map
    char locId = 'a';
    cout << "\n  ";
    for(int i=0; i<9; ++i){
        cout<<locId;
        ++locId;
    }
    cout << '\n';
    for(int i=0; i<9; i++){
        cout << i << " ";//vertical location identifiers
        for(int j=0; j<9; j++){
            switch (map.at(i).at(j)) {
                case 'p':
                    cout <<"P";
                    break;
                case 'e':
                    cout <<".";
                    break;
                case 'o':
                    cout <<" ";
                    break;
            }
        }
        cout<< "\n";
    }
    cout << endl;
}


void EightPuzzle::play(int tile, char x) {//makes the move according to given tile and direction
    vector<int> loc;
    int temp;
    int a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.at(i).at(j) == tile){
                loc.push_back(i);
                loc.push_back(j);
            }

        }
    }
    switch (x) {
        case 'd':
            a=1;
            while(1){
                if(board.at(loc.at(0)+a).at(loc.at(1))==0)
                    break;
                ++a;
            }
            while(board.at(loc.at(0)+a).at(loc.at(1)) != tile){
                board.at(loc.at(0)+a).at(loc.at(1)) = board.at(loc.at(0)+a-1).at(loc.at(1));
                --a;
            }
            board.at(loc.at(0)).at(loc.at(1)) = 0;
            break;
        case 'u':
            a=-1;
            while(1){
                if(board.at(loc.at(0)+a).at(loc.at(1))==0)
                    break;
                --a;
            }
            while(board.at(loc.at(0)+a).at(loc.at(1)) != tile){
                board.at(loc.at(0)+a).at(loc.at(1)) = board.at(loc.at(0)+a+1).at(loc.at(1));
                ++a;
            }
            board.at(loc.at(0)).at(loc.at(1)) = 0;
            break;
        case 'r':
            a=1;
            while(1){
                if(board.at(loc.at(0)).at(loc.at(1)+a)==0)
                    break;
                ++a;
            }
            while(board.at(loc.at(0)).at(loc.at(1)+a) != tile){
                board.at(loc.at(0)).at(loc.at(1)+a) = board.at(loc.at(0)).at(loc.at(1)+a-1);
                --a;
            }
            board.at(loc.at(0)).at(loc.at(1)) = 0;
            break;
        case 'l':
            a=-1;
            while(1){
                if(board.at(loc.at(0)).at(loc.at(1)+a)==0)
                    break;
                --a;
            }
            while(board.at(loc.at(0)).at(loc.at(1)+a) != tile){
                board.at(loc.at(0)).at(loc.at(1)+a) = board.at(loc.at(0)).at(loc.at(1)+a+1);
                ++a;
            }
            board.at(loc.at(0)).at(loc.at(1)) = 0;
            break;
    }
}
void EightPuzzle::playUser(string input) {//makes the move according to given input if the move is valid
    int tile;
    char dir;
    if (input.length()==3){
        if((input[0]-'0')>8||(input[0]-'0')<1||
           !(input[2]=='u'||input[2]=='d'||input[2]=='r'||input[2]=='l')){
            cerr << "Move is illegal" << endl;
            return ;
        }
        tile = input[0]-'0';
        dir = input[2];
    }
    else{
        cerr << "Move is illegal" << endl;
        return ;
    }
    if(!isMoveLegal(tile,dir)){
        cerr << "Move is illegal" << endl;
        return ;
    }
    play(tile,dir);
}
void EightPuzzle::playUser() {//asks user for input until the game ends
    while(!endGame()){
        string input;
        cout << "Enter a move (8-d): ";
        cin >> input;
        playUser(input);
        print();
    }
}
void EightPuzzle::playAuto(){//makes a random move
    vector<int> posTile;
    char dir;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(isMoveLegal(board.at(i).at(j),'d')||isMoveLegal(board.at(i).at(j),'u')||isMoveLegal(board.at(i).at(j),'r')||isMoveLegal(board.at(i).at(j),'l')){
                posTile.push_back(board.at(i).at(j));
            }
        }
    }
    int randomTile = posTile.at( rand() % (posTile.size()));
    do{
        int randDir = rand() % 4;//trying random directions until find a valid one
        switch (randDir) {
            case 0:
                dir = 'd';
                break;
            case 1:
                dir = 'u';
                break;
            case 2:
                dir = 'r';
                break;
            case 3:
                dir = 'l';
                break;
        }
    } while (!isMoveLegal(randomTile,dir));
    play(randomTile,dir);
}
void EightPuzzle::playAutoAll(){//makes random moves until the game ends
    while(!endGame()){
        playAuto();
    }
    cout << "Game is over";
}
bool EightPuzzle::endGame() {//checks if the game ends
    int n = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(n==9 && board.at(i).at(j)==0);
            else if(board.at(i).at(j) != n )
                return false;
            ++n;
        }
    }
    return true;
}
int EightPuzzle::boardScore() {//returns the score of the board
    int score;
    if (endGame())
        return 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.at(i).at(j) == i*3+j+1)
                ++score;
        }
    }
    score = 10-score;
    return score;
}
void EightPuzzle::initialize() {//initialized the board for the game
    int x1,y1,x2,y2,temp;
    vector<int> row;
    for(int i = 0;i<3;++i){
        row.clear();
        for (int j = 0; j < 3; ++j) {
            row.push_back(3*i+j);
        }
        board.push_back(row);
    }//filled the board with numbers

    for (int i = 0; i < 100; ++i) {//shuffles the board
        int x1 = rand()%3;
        int y1 = rand()%3;
        int x2 = rand()%3;
        int y2 = rand()%3;
        temp = board.at(x1).at(y1);
        board.at(x1).at(y1) = board.at(x2).at(y2);
        board.at(x2).at(y2) = temp;
    }
}
void EightPuzzle::print() {//prints the board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board.at(i).at(j) << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
bool EightPuzzle::isMoveLegal(int tile ,char x)const {//checks if the move is legal for given parameters
    vector<int> loc;
    if(tile==0)
        return false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.at(i).at(j) == tile) {
                loc.push_back(i);
                loc.push_back(j);
            }
        }
    }
    switch (x) {
        case 'd':
            while (1) {
                if (board.at(loc.at(0)).at(loc.at(1)) == 0)
                    return true;
                ++loc.at(0);
                if (loc.at(0) >= 3)
                    return false;
            }
            break;
        case 'u':
            while (1) {
                if (board.at(loc.at(0)).at(loc.at(1)) == 0)
                    return true;
                --loc.at(0);
                if (loc.at(0) < 0)
                    return false;
            }
            break;
        case 'r':
            while (1) {
                if (board.at(loc.at(0)).at(loc.at(1)) == 0)
                    return true;
                ++loc.at(1);
                if (loc.at(1) >= 3)
                    return false;
            }
            break;
        case 'l':
            while (1) {
                if (board.at(loc.at(0)).at(loc.at(1)) == 0)
                    return true;
                --loc.at(1);
                if (loc.at(1) < 0)
                    return false;
            }
            break;
        default:
            return false;
    }
    return false;
}



void Klotski::play(char block, char dir) {//makes the move for given block and direction
    switch (dir) {
        case 'd':
            for (int i = 0; i < blocks.at(block-'A').getWidth(); ++i) {
                board.at(blocks.at(block-'A').getLocr()).at(blocks.at(block-'A').getLocc()+i)='X';
            }
            blocks.at(block-'A').moveDown();
            break;
        case 'u':
            for (int i = 0; i < blocks.at(block-'A').getWidth(); ++i) {
                board.at(blocks.at(block-'A').getLocr()+blocks.at(block-'A').getLength()-1).at(blocks.at(block-'A').getLocc()+i)='X';
            }
            blocks.at(block-'A').moveUp();
            break;
        case 'r':
            for (int i = 0; i < blocks.at(block-'A').getLength(); ++i) {
                board.at(blocks.at(block-'A').getLocr()+i).at(blocks.at(block-'A').getLocc())='X';
            }
            blocks.at(block-'A').moveRight();
            break;
        case 'l':
            for (int i = 0; i < blocks.at(block-'A').getLength(); ++i) {
                board.at(blocks.at(block-'A').getLocr()+i).at(blocks.at(block-'A').getLocc()+blocks.at(block-'A').getWidth()-1)='X';
            }
            blocks.at(block-'A').moveLeft();
            break;
    }
    for (int i = 0; i < blocks.at(block-'A').getWidth(); ++i) {
        for (int j = 0; j < blocks.at(block - 'A').getLength(); ++j) {
            board.at(blocks.at(block - 'A').getLocr() + j).at(blocks.at(block - 'A').getLocc() + i) = block;
        }
    }

}
void Klotski::playUser(string input) {//makes the move according to input if it is valid
    char block;
    char dir;
    if (input.length()==3){
        if((input[0]-'A')>9||(input[0]-'A')<0||
           !(input[2]=='u'||input[2]=='d'||input[2]=='r'||input[2]=='l')){
            cerr << "Move is illegal" << endl;
            return ;
        }
        block = input[0];
        dir = input[2];
    }
    if(!isMoveLegal(block,dir)){
        cerr << "Move is illegal" << endl;
        return ;
    }
    play(block,dir);

}
void Klotski::playUser(){//asks user for move until game ends
    while(!endGame()){
        string input;
        cout << "Enter a move (A-d): ";
        cin >> input;
        playUser(input);
        print();
    }
}
void Klotski::playAuto(){//makes a random move
    char randomBlock;
    char randomDir;
    do {
        randomBlock = 'A' + rand()%10;
        int randDir = rand() % 4;//trying random directions until find a valid one
        switch (randDir) {
            case 0:
                randomDir = 'd';
                break;
            case 1:
                randomDir = 'u';
                break;
            case 2:
                randomDir = 'r';
                break;
            case 3:
                randomDir = 'l';
                break;
        }
    } while (!isMoveLegal(randomBlock,randomDir));
    play(randomBlock,randomDir);
    return;
}
void Klotski::playAutoAll(){//makes random moves until the game ends
    while(!endGame()){
        playAuto();
    }
    cout << "Game is over";
}
bool Klotski::endGame(){//checks if the game ends
    if(blocks.at(1).getLocr()==3 && blocks.at(1).getLocc()==1)
        return true;
    else
        return false;
}
int Klotski::boardScore(){//returns the score of the board
    if (endGame())
        return 0;
    int score;
    score = blocks.at(1).getLocr()-3 * blocks.at(1).getLocc()-1;
    return score;
}
void Klotski::initialize() {//initialized the board for the game
    board = {
            {'A','B','B','C'},
            {'A','B','B','C'},
            {'D','E','E','F'},
            {'D','G','H','F'},
            {'I','X','X','J'}
    };

    Block A(2,1,0,0);
    Block B(2,2,0,1);
    Block C(2,1,0,3);
    Block D(2,1,2,0);
    Block E(1,2,2,1);
    Block F(2,1,2,3);
    Block G(1,1,3,1);
    Block H(1,1,3,2);
    Block I(1,1,4,0);
    Block J(1,1,4,3);

    blocks.push_back(A);
    blocks.push_back(B);
    blocks.push_back(C);
    blocks.push_back(D);
    blocks.push_back(E);
    blocks.push_back(F);
    blocks.push_back(G);
    blocks.push_back(H);
    blocks.push_back(I);
    blocks.push_back(J);
}
void Klotski::print() {//prints the map
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(board.at(i).at(j)=='X')
                cout << " ";
            else
                cout << board.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;
}
bool Klotski::isMoveLegal(char block, char dir) const {//checks if the move is valid for given input
    switch (dir) {
        case 'd':
            if (blocks.at(block-'A').getLocr()+blocks.at(block-'A').getLength()-1>3)
                return false;
            for (int i = 0; i < blocks.at(block-'A').getWidth(); ++i) {
                if(board.at(blocks.at(block-'A').getLocr()+blocks.at(block-'A').getLength()).at(blocks.at(block-'A').getLocc()+i)!='X')
                    return false;
            }
            return true;
            break;
        case 'u':
            if (blocks.at(block-'A').getLocr()<1)
                return false;
            for (int i = 0; i < blocks.at(block-'A').getWidth(); ++i) {
                if(board.at(blocks.at(block-'A').getLocr()-1).at(blocks.at(block-'A').getLocc()+i)!='X')
                    return false;
            }
            return true;
            break;
        case 'r':
            if (blocks.at(block-'A').getLocc()+blocks.at(block-'A').getWidth()-1>2)
                return false;
            for (int i = 0; i < blocks.at(block-'A').getLength(); ++i) {
                if(board.at(blocks.at(block-'A').getLocr()+i).at(blocks.at(block-'A').getLocc()+blocks.at(block-'A').getWidth())!='X')
                    return false;
            }
            return true;
            break;
        case 'l':
            if (blocks.at(block-'A').getLocc()<1)
                return false;
            for (int i = 0; i < blocks.at(block-'A').getLength(); ++i) {
                if(board.at(blocks.at(block-'A').getLocr()+i).at(blocks.at(block-'A').getLocc()-1)!='X')
                    return false;
            }
            return true;
            break;
    }
    return false;
}

void playVector(vector<BoardGame2D *> games){
    while(games.size()!=0){
        games.at(games.size()-1)->playAutoAll();
        games.pop_back();
    }
}