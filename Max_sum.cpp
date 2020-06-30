/*
Given an array arr[] of positive integers of size N . You need to find maximum sum that can be formed from the integers of the array under the constraint that no three consecutive elements can be used .
Input:
First line of input contains number of test cases T. For each test case , first line contains N denoting size of the array and Next line contains N space seperated integers .
Output:
For each test case , Print maximum sum.
Your Task:
You have to complete the function MaxSum() which accpets given array and it's size as parameter and returns the value of maximum sum.
Constraints:
1<= T <=100
1<= N <=105
1<= arr[i] <=103
Example:
Input:
2
5
1 2 3 4 5
4
9 2 1 3
Output:
12
14
Explanation: 
Test Case 1: 1 + 2 + 4 + 5 = 12
*/
/*
 We have three cases
 1) Exclude arr[i]
 2) Exclude arr[i-1]
 3) Exclude arr[i-2]
 */
 
 //C++

int MaxSum(int arr[], int n) 
{ 
    // Stores result for subarray arr[0..i], i.e., 
    // maximum possible sum in subarray arr[0..i] 
    // such that no three elements are consecutive. 
    int sum[n]; 
  
    // Base cases (process first three elements) 
    if (n >= 1) 
        sum[0] = arr[0]; 
  
    if (n >= 2) 
        sum[1] = arr[0] + arr[1]; 
  
    if (n > 2) 
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2])); 
  
    // Process rest of the elements 
    // We have three cases 
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1] 
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i] 
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
    for (int i = 3; i < n; i++) 
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]); 
  
    return sum[n - 1]; 
} 
