/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

//code snippet
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 0)
           return;
        
        
        for(int  i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')
                flood_fill(board, i, 0);
            
            if(board[i][board[0].size() - 1] == 'O')
                flood_fill(board, i, board[0].size() - 1);
        }
        
        for(int j = 1; j < board[0].size() - 1; j++){
            if(board[0][j] == 'O')
                flood_fill(board, 0, j);
            
            if(board[board.size() - 1][j] == 'O')
                flood_fill(board, board.size() - 1, j);
        }
        
        
        
        for(int  i = 0; i < board.size(); i++)
            for(int  j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'B')
                    board[i][j] = 'O';
            }
    }
private:
    void flood_fill(vector<vector<char>>& board, int  i, int j){
        if(board[i][j] != 'O')
            return;
        
        board[i][j] = 'B';
        
        
        if(i - 1 >= 0)
            flood_fill(board, i - 1, j);
        
        if(j - 1 >= 0)
            flood_fill(board, i, j - 1);
        
        if(i + 1 < board.size())
            flood_fill(board, i + 1, j);
        
        if(j + 1 < board[0].size())
            flood_fill(board, i, j + 1);
            
    }
};
