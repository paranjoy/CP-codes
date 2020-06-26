/*
Given an array arr[] of N non-negative integers representing the height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
The structure is like below:
| |
|_|
We can trap 2 units of water in the middle gap.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. 
Each test case contains an integer N denoting the size of the array, followed by N space-separated numbers to be stored in the array.

Output:
Output the total unit of water trapped in between the blocks.

User Task:
The task is to complete the function trappingWater() which returns the total amount of water that can be trapped.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by the block of height 4 is 3 units, block of height 0 is 7 units. So, the total unit of water trapped is 10 units.
Testcase 2: Water cannot be trapped here.
*/
//idea : To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. 
//Then use these pre-computed values to find the amount of water in every array element.


// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    int left[n]; 
    int right[n]; 
 
    int water = 0; 
  
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        left[i] = max(left[i - 1], arr[i]); 
  
    right[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 
  
    for (int i = 0; i < n; i++) 
        water += min(left[i], right[i]) - arr[i]; 
  
    return water;
}
