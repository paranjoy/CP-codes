/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

//code snippet


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int max = 0;
        
        for(int  i = 0; i < matrix[0].size(); i++)
        {
            if(matrix[0][i] == '1')
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
            
            max = max >= dp[0][i] ? max : dp[0][i];
        }
        for(int  i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == '1')
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
            
            max = max >= dp[i][0] ? max : dp[i][0];
        }
        
        
        for(int  i = 1; i < matrix.size(); i++){
            
            for(int j = 1; j < matrix[0].size(); j++){
                
                if(matrix[i][j] == '1')
                    dp[i][j] = min( dp[i - 1][j], min( dp[i - 1][j - 1], dp[i][j - 1] )) + 1;
                else
                    dp[i][j] = 0;
                
                max = max >= dp[i][j] ? max : dp[i][j];
            }
        }
        
        return max*max;
    }
};
