/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000

Output: 1

Example 2:
Input:
11000
11000
00100
00011

Output: 3
*/

//code snippet

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        int count = 0;
        
        int r = grid.size(); // no of rows
        int c = grid[0].size(); // no of colums
        
        
        /* iterate through the 2d array, while encountering a '1' increment count and also the same time make all the 
        adjacent '1's as '0's recursively(do the same thing repeatedly). This means that once we encounter a piece of land,         we make the whole island as water( but not the other disjoint island). In this way we count the no of island. 
        */
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    count++;
                    make_surrounding_zero(grid, i, j, r, c);   
                }   
            }
        return count;
    }
private:
    void make_surrounding_zero(vector<vector<char>>& grid, int i, int j, int r, int c){
        
        if( i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        make_surrounding_zero(grid, i + 1, j, r, c);
        make_surrounding_zero(grid, i - 1, j, r, c);
        make_surrounding_zero(grid, i, j + 1, r, c);
        make_surrounding_zero(grid, i, j - 1, r, c);
        
        
    }
};
