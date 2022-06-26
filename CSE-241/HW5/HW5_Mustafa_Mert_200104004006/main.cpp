#include <iostream>
#include "vector"
#include "func.h"



using namespace std;




int main() {
    string input;
    cout << "Peg Solitare Game" << endl << endl;

    bg2::PegSolitare game1;
    game1.initialize();
    game1.print();
    cout << "Enter a move (c4-r): ";
    cin >> input;
    game1.playUser(input);
    game1.print();


    cout << "Eight Puzzle Game" << endl << endl;

    bg2::EightPuzzle game2;
    game2.initialize();
    game2.print();
    cout << "Enter a move (8-r): ";
    cin >> input;
    game2.playUser(input);
    game2.print(); 


    cout << "Klotski Game" << endl << endl;  

    bg2::Klotski game3;
    game3.initialize();
    game3.print();
    cout << "Enter a move (G-d): ";
    cin >> input;
    game3.playUser(input);
    game3.print();  




    vector<bg2::BoardGame2D *> games;
    bg2::PegSolitare peg1;
    peg1.initialize();
    bg2::PegSolitare peg2;
    peg2.initialize();
    bg2::EightPuzzle ep1;
    ep1.initialize();
    bg2::EightPuzzle ep2;
    ep2.initialize();
    bg2::Klotski kl1;
    kl1.initialize();
    bg2::Klotski kl2;
    kl2.initialize();

    games.push_back(&peg1);
    games.push_back(&peg2);
    games.push_back(&ep1);
    games.push_back(&ep2);
    games.push_back(&kl1);
    games.push_back(&kl2);
    
    //playVector(games);


    

    return 0;
}