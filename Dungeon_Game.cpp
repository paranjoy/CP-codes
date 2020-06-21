/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left 
room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. 
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 
if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	  3
-5	    -10	  1
10	     30	  -5 (P)
 

Note:
The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right 
room where the princess is imprisoned.
*/

//code snippet
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        
        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
        
        dp[r - 1][c - 1] = dungeon[r - 1][c - 1] > 0 ? 1 : (1 + abs(dungeon[r - 1][c - 1])); 
        
        for(int  i = r - 2; i >= 0; i--)
            dp[i][c - 1] = max((dp[i + 1][c - 1] - dungeon[i][c - 1]), 1);
        
        for(int j = c - 2; j >= 0; j--)
            dp[r - 1][j] = max((dp[r - 1][j + 1] - dungeon[r - 1][j]), 1);
        
        for(int  i = r - 2; i >= 0; i--)
            for(int j = c - 2; j >= 0; j--)
                dp[i][j] = max((min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]), 1);
        
        
        //path
        int  i = 0, j = 0;
        
        while(i < r - 1 && j < c - 1){
            if(dp[i][j + 1] < dp[i + 1][j]){
                cout <<"R ";
                j++;
            }
            else{
                cout <<"D ";
                i++;
            }
        }
        while(i < r - 1){
            cout <<"D ";
            i++;
        }
        while(j < c - 1){
            cout <<"R ";
            j++;
        }
        cout << endl;
        
        return dp[0][0];
    }
};
