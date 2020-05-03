/*
You will be given a n X n square chess board with one queen and a number of obstacles placed on it. 
Determine how many squares the queen can attack.

A queen is standing on an n X n chessboard. The chess board's rows are numbered from 1 to n, going from bottom to top.
Its columns are numbered from 1 to n, going from left to right. Each square is referenced by a tuple,(r, c), 
describing the row, r, and column, c, where the square is located.

The queen is standing at position (r_q, c_q). In a single move, she can attack any square in any of 
the eight directions (left, right, up, down, and the four diagonals). 

There are obstacles on the chessboard, each preventing the queen from attacking any square beyond it on that path.

Given the queen's position and the locations of all the obstacles, find and print the number of squares the queen can 
attack from her position 

Function Description

Complete the queensAttack function in the editor below. It should return an integer that describes the number of squares
the queen can attack.

queensAttack has the following parameters:
- n: an integer, the number of rows and columns in the board
- k: an integer, the number of obstacles on the board
- r_q: integer, the row number of the queen's position
- c_q: integer, the column number of the queen's position
- obstacles: a two dimensional array of integers where each element is an array of 2 integers, the row and column of
an obstacle

Constraints
0 < n <= 10^5
0 <= k <= 10^5
A single cell may contain more than one obstacle.
There will never be an obstacle at the position where the queen is located.

Sample Input 0
4 0
4 4
Sample Output 0
9


Sample Input 1
5 3
4 3
5 5
4 2
2 3
Sample Output 1
10


Sample Input 2
1 0
1 1
Sample Output 2
0

*/

//code snippet
// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int m1 = n - r_q;
    int m2 = min((n - c_q),(n - r_q));
    int m3 = n - c_q;
    int m4 = min((n - c_q), (r_q - 1));
    int m5 = r_q - 1;
    int m6 = min((c_q - 1), (r_q - 1));
    int m7 = c_q - 1;
    int m8 = min((n - r_q), (c_q - 1));

    for(int  i = 0; i < obstacles.size(); i++){

        int r = obstacles[i][0];
        int c = obstacles[i][1];

        if(c == c_q){
            if(r > r_q)
                m1 = min(m1, (r - r_q - 1));
            if(r < r_q)
                m5 = min(m5, (r_q - r - 1));
        } 

        if(r == r_q){
            if(c > c_q)
                m3 = min(m3, (c - c_q - 1));
            if(c < c_q)
                m7 = min(m7, (c_q - c - 1));
        }

        double slope = (1.0*r_q - 1.0*r)/(1.0*c_q - 1.0*c);

        if(slope == 1.0){
            if(r > r_q)
                m2 = min(m2, (r - r_q - 1));
            if( r < r_q)
                m6 = min(m6, (r_q - r - 1));
        }

        if(slope == -1.0){
            if(c > c_q)
                m4 = min(m4, (c - c_q - 1));
            if(c < c_q)
                m8 = min(m8, (c_q - c - 1));
        }
    }

    return (m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8);
}
