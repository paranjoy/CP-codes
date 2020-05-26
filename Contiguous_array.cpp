/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/
//code snippet
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int, int> m;
        m[0] = -1;
        
        int count = 0;
        
        int max_len = 0;
        
        for(int  i = 0; i < nums.size(); i++){
            
            if(nums[i] == 1)
                count++;
            else
                count--;
            
            if(m.find(count) != m.end())
                max_len = max(max_len , i - m[count]);
            else
                m[count] = i;                
        }
        return max_len;  
    }
};
