// Program: game called "Connect- 4 game." 
//  The game is played on a 7x7 board where each player, in their turn, chooses three coordinates (matrix) to place their symbol ('X' or 'O'). 
//  The goal is to be the last player to place symbols on the board, and the player who successfully places the last three symbols wins. 
//  The program ensures that players make valid moves, such as choosing empty squares within the board's bounds. 
//  The game continues until a player wins by placing the last three symbols or until the board is full, resulting in a tie.
// Author:Nasr EL_dein Ali Hassan, ID : 20220781.s3
// Version:3.0
// Date:29/2/2024
    #include <iostream>
    #include <vector>
    using namespace std ;

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3 4 5 6 7 " << endl;
    for (int i = 0; i < 7; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 7; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the move is valid
bool isValidMove(const vector<vector<char>>& board, int row1, int col1, int row2, int col2 , int row3, int col3) {
    // Check if the coordinates are within the board's bounds
    if (row1 < 0 || row1 >= 7 || col1 < 0 || col1 >= 7 || row2 < 0 || row2 >= 7|| col2 < 0 || col2 >= 7|| row3 < 0 || row3>= 7|| col3< 0 || col3 >= 7) 
        {
        return false;
        }
    // Check if the squares are empty
    if (board[row1][col1] != ' ' || board[row2][col2] != ' ' || board[row3][col3] != ' ' ) {
        return false;
    }
    return true;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board) {
    return isBoardFull(board);
}

int main() {
    vector<vector<char>> board(7, vector<char>(7, ' ')); 
    // Initialize an empty 4x4 board
    char currentPlayer = 'X'; // Player X goes first

    while (true) {
       
        displayBoard(board);

        // Get the player's move
        int row1, col1, row2, col2 ,row3 , col3;
        cout << "Player " << currentPlayer << ", enter your move (row1  col1 ) ( row2  col2) ( row3 col3): ";
        cin >> row1 >> col1 >> row2 >> col2 >> row3 >> col3;

        //   عشان Check if the move is valid
        if (!isValidMove(board, row1 - 1, col1 - 1, row2 - 1, col2 - 1, row3 - 1, col3-1)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row1 - 1][col1 - 1] = currentPlayer;
        board[row2 - 1][col2 - 1] = currentPlayer;
        board[row3 - 1][col3 - 1] = currentPlayer;  
        // بتحدد  Check if the current player has won
        if (checkWin(board)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // to looping the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}


