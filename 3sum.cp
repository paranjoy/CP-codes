/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Hint #1  
So, we essentially need to find three numbers x, y, and z such that they add up to the given value. 
If we fix one of the numbers say x, we are left with the two-sum problem at hand!

Hint #2  
For the two-sum problem, if we fix one of the numbers, say x, we have to scan the entire array to find the next number y which is value - x where value is the 
input parameter. Can we change our array somehow so that this search becomes faster?

Hint #3  
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?
*/

//code snippet
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        cout << nums.size() << endl;
        
        if(nums.size() <= 2)
            return {};
      
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++){
           //Declare and intialize two indexes
           int start = i + 1;
           int end = nums.size() - 1;
           
           /* To ignore duplicates, Never consider consecutive indices with same value.*/
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
 
            while(start < end){
 
                //Ignore duplicates
                if(end < nums.size() - 1 && nums[end] == nums[end + 1]){
                    end--;
                    continue;
                }
 
                //If triplets is found then put them in a list
                 if(nums[i] + nums[start] + nums[end] == 0){
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(nums[i] + nums[start] + nums[end] < 0)
                    start++;
                else
                    end--;
            }
        }
        
        return res;
    }
};
