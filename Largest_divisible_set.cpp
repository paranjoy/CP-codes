/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in 
this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/
//code snippet
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        
        int max = 1;
        int pos = 0;
        
        for(int  i = 1; i < nums.size(); i++)
            for(int  j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if(dp[i] > max){
                    max = dp[i];
                    pos = i;
                }
            }
        
        vector<int> res;
        
        if(nums.size() == 0)
            return res;
        
        do{
            res.insert(res.begin(), nums[pos]);
            
            pos = prev[pos];
        }while(pos != -1);
        
        return res;
    }
};
