/*
Given a sorted array of distinct integers of size N which is rotated X number of times, the task is to find the value of X.
Note: Array is sorted in increasing order

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a single integer N, size of the array. 
The second line of each test case contains N space-separated values of the array arr[].

Output:
For each testcase, in a new line, the value of X gets printed.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function NumberOfRotations() which takes the array arr[] and the size of the array (N) as inputs and returns values of X.

Expected Auxiliary Space: O(1)
Expected Time Complexity: O(log(N))

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
3
3
1 2 3
5
5 1 2 3 4
4
3 4 1 2

Output:
0
1
2

Explanation:
Testcase1: The array is not rotated hence answer is 0.
Testcase 2: Sorted array will look like {1, 2, 3, 4, 5}, and rotated once.
Testcase 3: Sorted array will look like {1, 2, 3, 4}, and it has been rotated 2 times.
*/

int NumberOfRotations(int arr[], int n){

    int l = 0, r = n - 1;
    if (arr[l] < arr[r]) 
        return 0; 
  
    if (arr[r] == arr[l]) 
        return l; 
  
    while(l <= r){
        int mid = l + (r - l)/2;
        
        if(mid < r && arr[mid + 1] < arr[mid])
            return (mid + 1);
        
        if(mid > l && arr[mid] < arr[mid - 1])
            return mid;
        
        if(arr[r] > arr[mid])
            r = mid - 1;
        else
            l = mid + 1;       
    }   
    
    return 0;
}
