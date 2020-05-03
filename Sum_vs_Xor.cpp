/*
Given an integer n, find each x such that:

0 <= x <= n

n + x = n ^ x
(^ indicates bitwise xor)

Function Description
Complete the sumXor function in the editor below. It should return the number of values determined, as an integer.

sumXor has the following parameter(s):
- n: an integer

Input Format
A single integer, n.

Constraints
0 <= n <= 10 ^ 15

Subtasks
0 <= n <= 100
 for 60% of the maximum score.

Output Format
Print the total number of integers  satisfying the criteria.


Sample Input 0
5
Sample Output 0
2

Sample Input 1
10
Sample Output 1
4

Sample Input 2
4
Sample Output 2
4
*/
//code snippet

// Complete the sumXor function below.
long sumXor(long n) {

    long res = 0;
    // just couunt the no. of zeroes in the binary representation of n
    while(n > 0){

        if((n & 1) == 0)
            res++;
        n = n >> 1;
    }
    return long(pow(2, res)); // answer// Complete the sumXor function below.
}
