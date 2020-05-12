/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element
which appears exactly once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

//code snippet

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        
        if(nums.size() == 1)
            return nums[0];
        
        if(nums[0] != nums[1])
            return nums[0];
        
        if(nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            
            int mid = l + (r - l)/2;
            
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            
            int n_l = (mid - l);
            int n_r = (r - mid);
            
            if(n_l % 2 == 0 && nums[mid] == nums[mid - 1])
                r = mid - 2;
           
            else if(n_r % 2 == 0 && nums[mid] == nums[mid + 1])
                l = mid + 2;
            
            else if(n_l % 2 != 0 && nums[mid] == nums[mid + 1])
                r = mid - 1;
            
            else  if(n_r % 2 != 0 && nums[mid] == nums[mid - 1])
                l = mid + 1;
        }        
        
        return -1;   
    }
};
