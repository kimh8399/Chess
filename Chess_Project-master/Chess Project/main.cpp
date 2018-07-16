// Chess Final Project
// Huck Kim and Tim Zwart
//
// Single player chess
// 2017

#include <iostream>
#include "bitboards.h"
#include "movegen.h"

using namespace std;

int main()
{
    // Declare chessboard
    Board b;
    b.reset();
    vector<move_history> history;

    cout << "Which side should the computer play as? 0 for white, 1 for black" << endl;
    colour side;

    do
    {
        int num;
        cin >> num;

        if(cin.fail() || (num != 0 && num != 1))
        {
            cout << "Invalid input Try again" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        else
        {
            side = (colour)num;
            break;
        }
    }
    while(true);

    colour turn = white;
    cout << endl;
    while(true)
    {
        // Output board
        cout << b << endl;

        gameState currState;

        // If it is the computer's turn, make it move
        if(turn == side)
            currState = compMove(turn, b, history);

        // If it is the user's turn, let them move
        else
            currState = getMove(turn, b, history);

        switch (currState)
        {
        case whiteWins:
            cout << "Checkmate! White wins!" << endl;
            return 0;
        case blackWins:
            cout << "Checkmate! Black wins!" << endl;
            return 0;
        case draw:
            cout << "It's a draw!" << endl;
            return 0;
        case end_game:
            cout << "Aborting" << endl;
            return 0;
        default:
            break;
        }

        // Change who's turn it is to move
        turn = colour(!bool(turn));
    }

    return 0;
}
