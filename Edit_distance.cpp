/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
//code snippet

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        int dp[m + 1][n + 1];
        
        for(int i = 0; i < m + 1; i++)
            for(int j = 0; j < n + 1; j++){
                if(i == 0)
                    dp[i][j] = j;
                
                else if(j == 0)
                    dp[i][j] = i;
                
                else if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                else{
                    int modify = 1 + dp[i - 1][j - 1];
                    int insert = 1 + dp[i - 1][j];
                    int del = 1 + dp[i][j - 1];
                    
                    dp[i][j] = min(modify, min(insert, del));
                }
            }
        
        return dp[m][n];      
    }
};
