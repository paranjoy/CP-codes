/*
Given a number N, find the smallest number K, such that product of digits of K is equal to N.

Input: First line of input contains number of testcases T. For each testcase, there will be a single line containing N.

Output: For each testcase, output single integer. If K is not possible, print "-1" (without quotes).

Your task: Your task is to complete the function smallestK() which takes the value N as parameter and return the value K.

Constraints:
1 <= T <= 105
1 <= N <= 1015

Example:
Input:
2
12
5

Output:
26
5

Explanation:
Testcase 1: 26 is the smallest number, and product of 2 and 6 is 12.
Testcase 2: 5 is the smallest number which is itself equal to 5.
*/

/*
idea is to Check if numbers 9 to 2 are divisors of N. If yes divide it by the numbers and keep count of how many times it was divided. 
If N has prime factors greater than 9, return -1. Else, arrange the divisors in ascending order.
*/

string smallestK(long long n)
{
    if(n == 1)
        return "1";
    map<int, int> m;
    
    for(int i = 9; i >= 2; i--){
        while(n % i == 0){
            m[i]++;
            n = n /i;
        }
    }
    
    if(n > 9)
        return "-1";
    else{
        string str = "";
        
        for(auto itr = m.begin(); itr != m.end(); itr++){
            while(itr->second --){
                str += to_string(itr->first);
            }
        }
        
        return str;
    }
    
}
