#include <vector>
#include "func.h"
//maps are loading from a file for efficient memory usage


int main() {
    string input;
    string saveName;
    vector<int> loc;
    Dir x;
    loc.push_back(0);
    loc.push_back(0);
    vector<PegSolitare> games;

    games.push_back(createGame());

    cout << "When you wanted to make a move in an user game enter a move in format \"b3-r\" " << endl;
    cout << "When you wanted to make a move in a computer game enter random input then press enter " << endl;
    cout << "When you wanted to save the game enter the \"save\" command." << endl;
    cout << "When you wanted to create a new game enter the \"new\" command." << endl;
//you are playing last game added when the last game ends or closed some way you will continue with games added last before this game
    while(!isAllGamesOver(games)){
        int lastGame = games.size() -1;
        games.at(lastGame).printMap();
        cout << "Enter command => ";
        cin >> input;

        if(input == "save"){//if user wants to save current game this part will work
            cout << "Give a name to your save with extension => ";
            cin >> saveName;
            games.at(lastGame).saveGame(saveName);
            games.pop_back();
            continue;
        }
        else if(input == "new"){//if user wants to create a new game this part will work
            games.push_back(createGame());
            continue;
        }
        else if(games.at(lastGame).getPlayerChoice()=='u'){
            getLocDir(input,loc,x,games.at(lastGame));
            if(!games.at(lastGame).play(loc,x))
                cerr<<"\nMove is invalid!"<<endl;
        }
        else{
            games.at(lastGame).play();
        }
        if(games.at(lastGame).isGameOver()){
            games.at(lastGame).printMap();
            cout << "Your score is " << games.at(lastGame).getScore()<< endl;
            games.pop_back();
            if(games.size()!=0){
                if(games.at(lastGame-1).getPlayerChoice()=='u')
                    cout << "\nThis game is an user game";
                else
                    cout << "\nThis game is a computer game";

            }
        }

    }
    cout << "There is no more playable game";
    return 0;
}

