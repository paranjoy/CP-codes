/*
There are N Algorithm Experts and N-1 Software Developers. You as Project manager will exclude an Algorithm Expert and form N-1 teams each consist of a 
software developer and an algorithm expert such that the efficiency of the whole project is maximised, but the problem is you can't jumble the ordering as 
the employees won't be happy.
There is an array algoExperts[] which denotes the skill of ith algorithm expert and an array Developers[] which denotes the skill of ith software developer.
Efficency of a team is given by the product of the skill of software developer and the algorithm expert, 
and total efficiency is the sum of the efficiencies of N-1 teams.

Input:
First line will contain an integer T denoting the number of testcases. First line of each testcase contains a single integer N, denoting the size of the array. 
Next line conatains N space separated integers denoting the skill of the Algorithm Experts and last line of each teastcases contains N-1 elements denoting the skills of N-1 Software Developers.

Output:
Print the maximum total efficiency of the team formed.

Your Task:
You don't need to take input. Complete the function project() which takes algoExperts[], Developers[] and size n as input and return the maximum efficiency
of the formed team. Printing is done by the driver code only.

Constraints:
1<=T<=30
2<=N<=105
0<=algoExperts[i]<=106
0<=Developers[i]<=106

Example:
Input:
2
5
4 1 5 2 9
1 2 1 1
2
4 1
1
Output:
25
4

Explanation:
Testcase 1: 2nd Algorithm Expert is excluded and the maximum efficiency will be 4*1 + 5*2 + 2*1 + 9*1 = 25.
Testcase 2: 2nd  Algorithm Expert is excluded and the maximum efficiency will be 4*1 = 4.
*/

//First we have to find the presum of product and postsum of product. 
long long int project(long long int algoExperts[], long long int Developers[], int n){

    long long int dpf[n + 5] = {0}, dpb[n + 5] = {0};
    long long int a[n + 5] = {0}, b[n + 5] = {0};
    long long int ans = 0;
        
    // Making the array 1 indexed.
    for(int i = 0; i < n; i++)
    a[i + 1] = algoExperts[i];
    for(int i = 0; i < n - 1; i++)
    b[i + 1]=Developers[i];
    
    // Calculating the product sum from front
    for(int i = 1; i <= n; i++)
        dpf[i] = dpf[i - 1] + a[i]*b[i];
    // Calculating the product sum from back
    for(int i = n; i > 0; i--)
        dpb[i] = dpb[i + 1] + a[i]*b[i - 1];

    // placing zero at (i+1)th index and storing the maximum answer
    for(int i = 0; i < n; i++)
        ans = max(dpf[i] + dpb[i + 2], ans);
        
    return ans;
}
