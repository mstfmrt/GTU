#include <vector>
#include "iostream"
using namespace std;
enum class Cell {p=1,e=0,o=2};
enum Dir {d,u,r,l};
void move(int loc,Dir x, vector<Cell>& map);
bool isMoveLegal(int loc,Dir x, vector<Cell> map);
void mapCreator(int mapNum, vector<Cell>& map);
void chooseMap(vector<Cell>& map);
bool isGameOver(vector<Cell> map);
void getLocDir(string input,int& loc, Dir& x);
void play(vector<Cell>& map);
void printCell(Cell x);
void printMap(vector<Cell> map);
void printScore(vector<Cell> map);
void humanPlay(vector<Cell>& map);
vector<int> possibleLoc(vector<Cell> map);
void computerPlay(vector<Cell>& map);
