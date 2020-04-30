/*
Given two integers, l and r, find the maximal value of a xor b, where a and b satisfy the following condition:

l <= a <= b <= r

Function Description

Complete the maximizingXor function in the editor below. It must return an integer representing the maximum value calculated.

maximizingXor has the following parameter(s):

l: an integer, the lower bound, inclusive
r: an integer, the upper bound, inclusive

Input Format

The first line contains the integer l.
The second line contains the integer r.

Constraints

1 <= l <= r <= 10^3

Output Format

Return the maximal value of the xor operations for all permutations of the integers from l to r , inclusive.

Sample Input 0
10
15
Sample Output 0
7

Sample Input 1
11
100
Sample Output 1
127
*/
// code snippet
//complexity (O(1))

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {

    int sum = 0;
    int res = 0; 
    int i = 0;
    while(l | r){
        
        sum += pow(2, i);

        if((l & 1) != (r & 1))
            res = sum;

        i++;
        l = l >> 1;
        r = r >> 1;
    }

    return res;
}
