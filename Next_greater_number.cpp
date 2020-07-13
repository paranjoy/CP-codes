/*
Given an array A[] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance 
in the array. If no such element exists, output -1.

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. 
The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting

the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Your Task:
This is a function problem. You only need to complete the function nextLargerElement that takes array and n as parameters and prints the output. 
The newline is automatically appended by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
5
6 8 0 1 3
Output
3 4 4 -1
8 -1 1 3 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
Testcase 2: In the array , the next larger element to 6 is 8 , for 8 there is no larger elements hence it is -1 , for 0 it is 1 , for 1 it is 3 and
then for 3 there is no larger elements and hence -1.
*/

//code snippet

// Function to store Next larger elements
void nextLargerElement(long long arr[], int n){
    // Your code here
    vector<long long> left(n);
    vector<long long> v(n);
    
    v[n - 1] = -1;
    left[n - 1] = -1;
    
    for(int i = n - 2; i >= 0; i--){
        if(arr[i + 1] > arr[i]){
            v[i] = arr[i + 1];
            left[i] = i + 1;
        }
        else{
            int j = left[i + 1];
            while(j != -1){
                if(arr[i] < arr[j]){
                    v[i] = arr[j];
                    left[i] = j;
                    break;
                }
                j = left[j];
            }
            if(j == -1){
                v[i] = -1;
                left[i] = -1;
            }
        }
        
    }
    
    for(int i = 0; i < n; i++)
        cout << v[i] <<" ";
}
