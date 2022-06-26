#include "string"
#include "vector"

using namespace std;

namespace bg2{
    class BoardGame2D{
    public:
        virtual void playUser(string input) = 0;
        virtual void playUser() = 0;
        virtual void playAuto() = 0;
        virtual void playAutoAll() = 0;
        virtual bool endGame() = 0;
        virtual int boardScore() = 0;
        virtual void initialize() = 0;
    };

    class PegSolitare: public BoardGame2D {
    public:
        void playUser(string input);
        void playUser();
        void playAuto();
        void playAutoAll();
        bool endGame();
        int boardScore();
        void initialize();
        bool isMoveLegal(vector<int> loc,char x)const;
        vector<vector<int>> possibleLoc()const;
        void play(vector<int> loc, char x);
        void print();
    private:
        vector<vector<char>> map;
    };

    class EightPuzzle: public BoardGame2D {
    public:
        void playUser(string input);
        void playUser();
        void playAuto();
        void playAutoAll();
        bool endGame();
        int boardScore();
        void initialize();
        bool isMoveLegal(int tile ,char x)const;
        void play(int tile, char x);
        void print();
    private:
        vector<vector<int>> board;
    };

    class Klotski: public BoardGame2D {
    public:
        void playUser(string input);
        void playUser();
        void playAuto();
        void playAutoAll();
        bool endGame();
        int boardScore();
        void initialize();
        bool isMoveLegal(char block ,char dir)const;
        void play(char block, char dir);
        void print();
        class Block{
            int length;
            int width;
            int locr;
            int locc;
        public:
            Block(int l,int w, int lr, int lc){
                length = l;
                width = w;
                locr = lr;
                locc = lc;
            }
            void setLocr(int n){locr = n;}
            void setLocc(int n){locc = n;}
            int getLocr()const{return locr;}
            int getLocc()const{return locc;}
            int getLength()const{return length;}
            int getWidth()const{return width;}
            void moveDown(){++locr;}
            void moveUp(){--locr;}
            void moveRight(){++locc;}
            void moveLeft(){--locc;}
        };
    private:
        vector<Block> blocks;
        vector<vector<char>> board;
    };

    void playVector(vector<BoardGame2D *> games);
}