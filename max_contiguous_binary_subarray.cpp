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
// code snippet
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
            
        map<int, int> m;
        pair<int , int> p;
        p = make_pair(0, 0);
        m.insert(p);
        int max1 = -1;
        int count = 0;
                
        for(int i = 0; i < nums.size(); i++){
            count = count + ((nums[i] == 1) ? 1 : -1);
            m.insert(pair<int , int>(count, i + 1));
            
            max1 = max(max1 , i + 1 - m[count]);
        }
        
        return max1;
    }
};
