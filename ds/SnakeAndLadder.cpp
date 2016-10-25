#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 8;
const int END_OF_GAME = 100;
const int MAX_SNAKES_LADDER = 10;

enum BoxType
{
    NORMAL,
    SNAKE,
    LADDER,
};

const string BoxTypeStrings[] = {"NORMAL", "SNAKE", "LADDER"};

struct Box
{
    BoxType type;
    int next;
    
    Box() {type = NORMAL; next = -1;}
};

class SnakeAndLadder
{
    private:
        Box board[END_OF_GAME];
        int playerPositions[MAX_PLAYERS];
        bool playing[MAX_PLAYERS];
        string playerNames[MAX_PLAYERS];
        void init();
        int rollDice();
        
    public:
        SnakeAndLadder(int numOfPlayers);
        void startPlay();
        void printBoard();
};

SnakeAndLadder::SnakeAndLadder(int numOfPlayers)
{
    if (numOfPlayers < MIN_PLAYERS || numOfPlayers > MAX_PLAYERS)
    {
        cout << "Number of players should be between " << MIN_PLAYERS << " & " << MAX_PLAYERS << endl; 
    }
    else
    {
        for(int i = 0; i < numOfPlayers; ++i)
        {
            playing[i] = true;
            playerNames[i] = "Player_" + std::to_string(i);
        }  
        for (int i = numOfPlayers; i < MAX_PLAYERS; ++i)
        {
            playing[i] = false;
        }
    }
    init();
}

void SnakeAndLadder::init()
{
    int snakeCount = 0, ladderCount = 0;
    
    srand(time(NULL));
    
    while(1)
    {
        int index1 = rand() % END_OF_GAME;
        int index2 = rand() % END_OF_GAME;
        
        if (snakeCount < MAX_SNAKES_LADDER && index1 > index2 &&
            board[index1].type == NORMAL && index2 != END_OF_GAME - 1)
        {
            snakeCount++;
            board[index1].next = index2;
            board[index1].type = SNAKE;
        }
        if (ladderCount < MAX_SNAKES_LADDER && index1 < index2 &&
            board[index1].type == NORMAL && index2 != END_OF_GAME - 1)
        {
            ladderCount++;
            board[index1].next = index2;
            board[index1].type = LADDER;
        }
        
        if (snakeCount == MAX_SNAKES_LADDER && ladderCount == MAX_SNAKES_LADDER )
            break;
        
        cout << index1 << " " << index2 << " " << snakeCount << " " << ladderCount << endl;
    }
}

void SnakeAndLadder::startPlay()
{
    
}

void SnakeAndLadder::printBoard()
{
    for (int i = 0; i < END_OF_GAME; ++i)
    {
        printf("%3d: %10s, %3d\n", i, BoxTypeStrings[board[i].type].c_str(), board[i].next);
    }
}

int SnakeAndLadder::rollDice()
{
    return (rand() % 6) +1;
}

int main()
{
    SnakeAndLadder s(2);
    s.printBoard();
    //s.startPlay();
}