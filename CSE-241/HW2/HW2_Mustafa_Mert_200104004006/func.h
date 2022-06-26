#include <vector>
#include "iostream"
using namespace std;

enum class Cell {p,e,o};
enum Dir {d,u,r,l};
class Game{
private:
    char playerChoice;
    int mapSize;
    int numberOfMoves;
    vector<vector<Cell>> map;

    void loadMap(ifstream& save);
    void printCell(Cell x)const;
    bool isMoveLegal(vector<int> loc,Dir x)const;
    vector<vector<int>> possibleLoc()const;

public:
    void loadGame(const string& saveName);
    void printMap()const;
    bool isGameOver()const;
    void saveGame(const string& saveName)const;
    int getScore() const;
    void computerPlay();
    bool move(vector<int>& loc,Dir x);
    int getMapSize() const {return mapSize;}
    char getPlayerChoice() const {return playerChoice;}
    void setPlayer(char choice){playerChoice=choice;}
};


void getLocDir(string input,vector<int>& loc, Dir& x,Game& game);
void chooseMap(Game& game);
char chooseGame();
char choosePlayer();
void newGame(Game& game);
void play(Game& game);



