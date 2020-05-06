/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

//code snippet

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        int n = nums.size()/2;
        
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->second > n)
                return itr->first;
        }
       return 0; //because we can assume that this step will never arrive
    }
};
//Boyer-Moore Voting Algorithm will give result in O(n) time and consume O(1) space
