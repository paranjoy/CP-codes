/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

Hint #1  
Will Brute force work here? Try to optimize it.

Hint #2  
Can we optimize it by using some extra space?

Hint #3  
What about storing sum frequencies in a hash table? Will it be useful?

Hint #4  
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. 
Can we use this property to optimize it.
*/
/*
The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i] for sum upto ith index)
upto two indices is the same, the sum of the elements lying in between those indices is zero. 
Extending the same thought further, if the cumulative sum upto two indices, say i and j is at a difference of k 
i.e. if sum[i] - sum[j] = k, the sum of elements lying between indices i and j is k.

Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum upto all the 
indices possible along with the number of times the same sum occurs. 
We store the data in the form: (sum_i, no. of occurences of sum_i).
We traverse over the array numsnums and keep on finding the cumulative sum.
Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. 
If the same sum occurs again, we increment the count corresponding to that sum in the hashmap.
Further, for every sum encountered, we also determine the number of times the sum − k has occured already,
since it will determine the number of times a subarray with sum kk has occured upto the current index. 
We increment the countcount by the same amount.
After the complete array has been traversed, the countcount gives the required result.
*/

//code snippet

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> prev_sum;
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum += nums[i];
                
            if(sum == k)
                count++;
            
            if(prev_sum.find(sum - k) != prev_sum.end())
                count += prev_sum[sum - k];
            
            prev_sum[sum]++;   
        }
        
        return count;
         
    }
};
