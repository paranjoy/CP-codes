/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's,
then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?Given an array with n objects colored 
red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order 
red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
//code snippet
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c_0 = 0;
        int c_1 = 0;
        int c_2 = 0;
        
        int i;
        
        for(i = 0; i < nums.size(); i++)
            if(nums[i] == 0)
                c_0++;
            else if(nums[i] == 1)
                c_1++;
            else
                c_2++;
        
        
        i = 0;
        
        while(c_0--)
            nums[i++] = 0;
        while(c_1--)
            nums[i++] = 1;
        while(c_2--)
            nums[i++] = 2;
        
        return;
        
    }
};
