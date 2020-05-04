/*
Consider a matrix where each cell contains either a 0 or a 1. 

Any cell containing a 1 is called a filled cell. 
Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. 
Note that each cell in a region is connected to zero or more cells in the region but is not necessarily directly 
connected to all the other cells in the region.

Given an m X n matrix, find and print the number of cells in the largest region in the matrix. 
Note that there may be more than one region in the matrix.

For example, there are two regions in the following 3 X 3 matrix. The larger region at the top left contains 3 cells.
The smaller one at the bottom right contains 1.

110
100
001

Function Description
Complete the connectedCell function in the editor below. 
It should return an integer that denotes the area of the largest region.

connectedCell has the following parameter(s):
- matrix: a 2D array of integers where matrix[i] represents the i'th row of the matrix

Sample Input
4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
Sample Output
5

Explanation
The diagram below depicts two regions of the matrix; for each region, the component cells forming the region are
marked with an X:

X X 0 0     1 1 0 0
0 X X 0     0 1 1 0
0 0 X 0     0 0 1 0
1 0 0 0     X 0 0 0
The first region has five cells and the second region has one cell. We print the size of the largest region.

*/

int m;
int maxi;

void count_cells(vector<vector<int>>& matrix, int i, int j){
    m++;
    matrix[i][j] = 0;

    if(((i-1)>=0 && ((i-1) <= matrix.size()-1)) && (matrix[i-1][j] == 1) )
        count_cells(matrix, i-1, j);
    if(((i-1)>=0 && ((i-1) <= matrix.size()-1)) && ((j+1)>=0 && ((j+1) <= matrix[0].size()-1)) && (matrix[i-1][j+1] == 1) )
        count_cells(matrix, i-1, j+1);
    if(((j+1)>=0 && ((j+1) <= matrix[0].size()-1)) && (matrix[i][j+1] == 1))
        count_cells(matrix, i, j+1);
    if(((i+1)>=0 && ((i+1) <= matrix.size()-1)) && ((j+1)>=0 && ((j+1) <= matrix[0].size()-1)) && (matrix[i+1][j+1] == 1) )
        count_cells(matrix, i+1, j+1);
    if(((i+1)>=0 && ((i+1) <= matrix.size()-1)) && (matrix[i+1][j] == 1) )
        count_cells(matrix, i+1, j);
    if(((i+1)>=0 && ((i+1) <= matrix.size()-1)) && ((j-1)>=0 && ((j-1) <= matrix[0].size()-1)) && (matrix[i+1][j-1] == 1) )
        count_cells(matrix, i+1, j-1);
    if(((j-1)>=0 && ((j-1) <= matrix[0].size()-1)) && (matrix[i][j-1] == 1))
        count_cells(matrix, i, j-1);
    if(((i-1)>=0 && ((i-1) <= matrix.size()-1)) && ((j-1)>=0 && ((j-1) <= matrix[0].size()-1)) && (matrix[i-1][j-1] == 1) )
        count_cells(matrix, i-1, j-1);
}
// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {

    maxi = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int  j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 1){
                m = 0;
                count_cells(matrix, i, j);

                maxi = max(maxi, m);
            }

        }
    }
    return maxi;
}
