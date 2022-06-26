#include <vector>
#include "func.h"
//maps are loading from a file for efficient memory usage


int main() {
    vector<Cell> map;
    Game game;
    string input;
    string saveName;
    vector<int> loc;
    Dir x;
    loc.push_back(0);
    loc.push_back(0);


    play(game);
    cout << "When you wanted to save the game enter the \"save\" command." << endl;
    game.printMap();
    while(!game.isGameOver()){
        if(game.getPlayerChoice()=='u'){
            cout << "\n=>";
            cin >> input;
            if(input == "save"){
                cout << "Give a name to your save with extension => ";
                cin >> saveName;
                game.saveGame(saveName);
                break;
            }
            getLocDir(input,loc,x,game);
            if(!game.move(loc,x))
                cerr<<"\nMove is invalid!"<<endl;
        }
        else{
            cout << "Press any key then enter to let computer play => ";
            cin >> input;
            if(input == "save"){
                cout << "Give a name to your save with extension => ";
                cin >> saveName;
                game.saveGame(saveName);
                break;
            }
            game.computerPlay();
        }
        game.printMap();
    }
    cout << "Your score is " << game.getScore();

    return 0;
}

