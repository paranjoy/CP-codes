/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

//code snippet
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        1) Find middle point mid = (l + h)/2
        2) If key is present at middle point, return mid.
        3) Else If arr[l..mid] is sorted
            a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
            b) Else recur for arr[mid+1..h]
        4) Else (arr[mid+1..h] must be sorted)
            a) If key to be searched lies in range from arr[mid+1] to arr[h], recur for arr[mid+1..h].
            b) Else recur for arr[l..mid]
            */
        
        return r_search(nums, 0, nums.size() -1, target); 
    }
    
private:
    int r_search(vector<int>& nums, int l, int h, int target){
        
        if(l > h)
            return  -1;
        
        int mid = (l + h)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[l] <= nums[mid]){
            
            if(target >= nums[l] && target <= nums[mid])
                return r_search(nums, l, mid - 1, target);
            
            else
                return r_search(nums, mid + 1, h, target);
        }
        
        if(target >= nums[mid] && target <= nums[h])
            return r_search(nums, mid + 1, h, target);
        
        else
           return r_search(nums, l, mid - 1, target);     
    }
};
