/*
There is a Giant who is exhausted. To gain strength he will go through a N*M integer grid Arr[N][M] which contains food packets. 
Arr[i][j] is the amount of strength he gains after eating the food packet. Strength gained by eating a food packet can also be negative( i.e. Arr[i][j]<0). 
From row r and column c, he can go to any of the following three indices:

I.                Arr[ r+1 ][ c-1 ] (valid only if c-1>=0)
II.               Arr[ r+1 ][ c ]
III.              Arr[ r+1 ][ c+1 ] (valid only if c+1<=N-1)

So if he start at any column on row 0, what is the maximum strength he can earn till row N-1. 
If the strength earned is negative print 0, because in that case he will not enter the grid.

Note: If Giant is standing at Arr[i][j] he has to eat that food packet .

Input:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two integers N and M, 
denoting the number of rows and columns. 
Next N lines of each test case contains M space seperated integers denoting amount of strength he gains after eating the food packet .

Output:
Print the maximum strength the giant can gain.

Constraints:
1<=T<=10
1<=N,M<=1000
0<=| Arr[i][j] |<=105
Sum of N*M over all test cases doesn't exceed 106

Your Task:​
This is a functional problem . You don't need to take input just complete the function strength() which accpets 2d vector grid and two integers N , M 
as parameters and return the maximum strength giant can gain.

Example:
Input:
2
2 2
10 4
3 5
2 2
5 -1
-2 -1
Output:
15
4

Explanation:
Testcase 1: He will eat 10 in 1st row and 5 in second row.
Testcase 2: He will eat 5 in 1st row and -1 in second row.

*/

/*
for a particular cell Grid[i][j] , check from which position of i-1 it is possible to reach at Grid[i][j].
Take the one which contributes the maximum energy to that cell.
*/

//User function Template for C++

int strength(vector<vector<int>> &mat, int N, int M){
    
    for (int i = 1; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
            op1 = mat[i - 1][j];
            if(j - 1 >= 0)  // upper left diagonal
                op2 = mat[i - 1][j - 1];
            if(j + 1 < M)   // upper right diagonal
                op3 = mat[i - 1][j + 1];
                
            mat[i][j] += max(op1, max(op2, op3));
        } 
    } 
    
    int res = 0; 
    for (int j = 0; j < M; j++)  
        res = max(mat[N - 1][j], res); 
    
    return res; 
}
