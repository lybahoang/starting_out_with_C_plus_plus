/* --- Tic-Tac-Toe Game ---
The program stimulates a Tic-Tac-Toe Game.
*/

#include <iostream>
using namespace std;

// Global constants
const int NUM_ROWS = 3,
          NUM_COLS = 3;

const char PLAYER1_SYM = 'X',
           PLAYER2_SYM = 'O';

// Function prototypes
void displayGameBoard(const char board[][NUM_COLS], int numRows);
bool getPlayerLocation(char board[][NUM_COLS], int numRows, char);
bool checkWin(const char moves[][NUM_COLS], int numRows, char);
void displayMoves(const char moves[][NUM_COLS], int numRows);

// The main Function
int main()
{
    // Array declaration
    char gameBoard[NUM_ROWS][NUM_COLS] = { {'*', '*', '*'},
                                           {'*', '*', '*'},
                                           {'*', '*', '*'} };

//    char moves[NUM_ROWS][NUM_COLS] = { {'*', '*', '*'},
//                                        {'*', '*', '*'},
//                                        {'*', '*', '*'} };


    // Play the game
    bool gameWon = false;
    int numMoves = 0;

    // Display the game board
    displayGameBoard(gameBoard, NUM_ROWS);

    while (numMoves < 9 && !gameWon)
    {
        // Player 1's turn
        cout << "Player 1 turn (X).\n";
        if (getPlayerLocation(gameBoard, NUM_ROWS, PLAYER1_SYM))
        {
            numMoves++;
            displayGameBoard(gameBoard, NUM_ROWS);
            gameWon = checkWin(gameBoard, NUM_ROWS, PLAYER1_SYM);
            if (gameWon)
            {
                cout << "Player 1 wins.\n";
                break;
            }
        }

        // Check if board is full
        if (numMoves >= 9) break;

        // Player 2's turn
        cout << "Player 2 turn (O).\n";
        if (getPlayerLocation(gameBoard, NUM_ROWS, PLAYER2_SYM))
        {
            numMoves++;
            displayGameBoard(gameBoard, NUM_ROWS);
            gameWon = checkWin(gameBoard, NUM_ROWS, PLAYER2_SYM);
            if (gameWon)
            {
                cout << "Player 2 wins.\n";
                break;
            }
        }
    }

    if (!gameWon)
    {
        cout << "Tied.\n";
    }
}

/* --- Function displayGameBoard Definition ---
The function displays the game board of the Tic-Tac-Toe game.
*/
void displayGameBoard(const char board[][NUM_COLS], int numRows)
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

/* --- Function getPlayerLocation Definition ---
The function prompt for a location on the board where the player
wants to mark their symbol 'X' or 'O'
*/
bool getPlayerLocation(char board[][NUM_COLS], int numRows, char symbol)
{
    // Variable declaration
    int row, col;

    // Get the location
    while (true)
    {
        cout << "Enter the row location (0 - 2): ";
        cin >> row;

        cout << "Enter a column location (0 - 2): ";
        cin >> col;

        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS)
        {
            cout << "Invalid location. Please try again.\n\n";
        }
        else if (board[row][col] != '*')
        {
            cout << "Cell already occupied. Choose another.\n\n";
        }
        else
        {
            board[row][col] = symbol;
            return true;
        }
    }
}

/* --- Function checkWin Definition ---
The function checks if a player wins or not.
*/
bool checkWin(const char moves[][NUM_COLS], int numRows, char symbol)
{
    // Check rows
    for (int row = 0; row < numRows; row++)
    {
        if (moves[row][0] == moves[row][1] &&
            moves[row][1] == moves[row][2] &&
            moves[row][2] == symbol)
        {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < NUM_COLS; col++)
    {
        if (moves[0][col] == moves[1][col] &&
            moves[1][col] == moves[2][col] &&
            moves[2][col] == symbol)
        {
            return true;
        }
    }

    // Check diagonals
    if (moves[0][0] == moves[1][1] && moves[1][1] == moves[2][2] && moves[2][2] == symbol)
    {
        return true;
    }
    else if (moves[0][2] == moves[1][1] && moves[1][1] == moves[2][0] && moves[2][0] == symbol)
    {
        return true;
    }

    return false;
}

/* --- Function displayMoves Definition ---
The function displays the moves of each player on the screen.
*/
void displayMoves(const char moves[][NUM_COLS], int numRows)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << moves[row][col] << " ";
        }
        cout << endl;
    }
}
