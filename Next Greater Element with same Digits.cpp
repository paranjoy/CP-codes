/*
Given an integer N, the task is to find the next greater element with the same digits. If no such number exists the return -1.
Note: If the next greater element is greater than 32-bit integer then return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a 32-bit integer N.

Output:
For each testcase, in a new line, the next greater number is printed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function nextPermutation() which takes an integer N and returns the next greater element with the same digits. If no such number exists the return -1.

Expected Auxiliary Space: O(M), where M is the number of digits of N
Expected Time Complexity: O(M), where M is the number of digits of N

Constraints:
1 ≤ T ≤ 10000
1 ≤ N ≤ 2147483647

Example:
Input:
2
513
10000

Output:
531
-1

Explanation:
Testcase 1: 531 is the smallest number which is greater than 513 and having same digits.
Testcase 2: It is not possible to form a number greater than 10000 using digits of 10000.
*/


int nextPermutation(int n)
{
    int sz = (int)ceil(log10(n));
    vector<int> num;
    int copy = n;
    int prev = copy%10;
    num.push_back(prev);
    int pos;
    sz--;
    sz--;
    copy = copy/10;
    bool flag = true;
    
    while(copy > 0){
        int d = copy%10;
        if(d < prev && flag == true){
            flag = false;
            pos = sz;
        }
        prev = d;
        num.insert(num.begin(), prev);
        copy = copy/10;
        sz--;
    }
    
    if(flag)
        return -1;
        
   
    int j;
    for(int i = num.size() - 1; i >= pos; i--){
        if(num[i] > num[pos]){
            j = i;
            break;
        }
    }
    
    int temp = num[j];
    num[j] = num[pos];
    num[pos] = temp;
    pos = pos + 1;
    sort(num.begin()+pos, num.end());

    long long res = 0;

    for(int i = 0; i < num.size(); i++){
        res = res*10 + num[i];
    }
    
    if(res >  2147483647)
        return -1;
    return res;
}
