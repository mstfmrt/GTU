#include <vector>
#include "iostream"
using namespace std;

enum class CellSit{p,e,o};
enum Dir {d,u,r,l};
class PegSolitare{
private:
    class Cell{
    private:
        CellSit sit;
        int row;
        int col;
    public:
        Cell(CellSit nsit,int nrow, int ncol);
        int getRow()const{return row;}
        int getCol()const{return col;}
        CellSit getSit()const{return sit;}
        void setRow(int nrow){row=nrow;}
        void setCol(int ncol){col=ncol;}
        void setSit(CellSit nsit){sit=nsit;}

    };
    char playerChoice;
    int mapSize;
    int numberOfMoves;
    vector<vector<Cell>> map;

    void loadMap(ifstream& save);
    void printCell(CellSit x)const;
    bool isMoveLegal(vector<int> loc,Dir x)const;
    vector<vector<int>> possibleLoc()const;

public:
    PegSolitare(int mapNum, char playerCh);
    PegSolitare(vector<vector<Cell>> map,char playerCh);
    PegSolitare(string saveName);
    PegSolitare(){}
    bool isWorse(PegSolitare other)const;
    void loadGame(const string& saveName);
    void printMap()const;
    bool isGameOver()const;
    void saveGame(const string& saveName)const;
    int getScore() const;
    void play();
    bool play(vector<int>& loc,Dir x);
    void playGame();
    int getMapSize() const {return mapSize;}
    char getPlayerChoice() const {return playerChoice;}
    void setPlayer(char choice){playerChoice=choice;}
    int numOfPegs();
    int numOfEmpty();
    int numOfPegsTaken();
    static int allPegs(vector<PegSolitare> games);
};


void getLocDir(string input,vector<int>& loc, Dir& x,PegSolitare& game);
int chooseMap();
char chooseGame();
char choosePlayer();
PegSolitare createGame();
bool isAllGamesOver(vector<PegSolitare> games);


