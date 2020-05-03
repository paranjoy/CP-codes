/*
You are given a 2D matrix of dimension m X n and a positive integer r. 
You have to rotate the matrix r times and print the resultant matrix. Rotation should be in anti-clockwise direction.
Note that in one rotation, you have to shift elements by one step only.

It is guaranteed that the minimum of m and n will be even.

As an example rotate the Start matrix by 2:

Start         First           Second
 1 2 3 4        2  3  4  5      3  4  5  6
12 1 2 5  ->   1  2  3  6 ->   2  3  4  7
11 4 3 6      12  1  4  7       1  2  1  8
10 9 8 7      11 10  9  8     12 11 10  9

Function Description
Complete the matrixRotation function in the editor below. It should print the resultant 2D integer array and return nothing.

matrixRotation has the following parameter(s):
matrix: a 2D array of integers
r: an integer that represents the rotation factor

Constraints
2 <= m, n <= 300
1 <= r <= 10^9
min(m,n) % 2 = 0
1 <= a[i][j] <= 10^8

Sample Input #01
4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output #01
3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14
Explanation #01
The matrix is rotated through two rotations.
 1  2  3  4      2  3  4  8      3  4  8 12
 5  6  7  8      1  7 11 12      2 11 10 16
 9 10 11 12  ->  5  6 10 16  ->  1  7  6 15
13 14 15 16      9 13 14 15      5  9 13 14


Sample Input #02
5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28
Sample Output #02
28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1
Explanation 02
The various states through 7 rotations:
1  2  3  4      2  3  4 10    3  4 10 16    4 10 16 22
7  8  9 10      1  9 15 16    2 15 21 22    3 21 20 28
13 14 15 16 ->  7  8 21 22 -> 1  9 20 28 -> 2 15 14 27 ->
19 20 21 22    13 14 20 28    7  8 14 27    1  9  8 26
25 26 27 28    19 25 26 27    13 19 25 26   7 13 19 25

10 16 22 28    16 22 28 27    22 28 27 26    28 27 26 25
 4 20 14 27    10 14  8 26    16  8  9 25    22  9 15 19
 3 21  8 26 ->  4 20  9 25 -> 10 14 15 19 -> 16  8 21 13
 2 15  9 25     3 21 15 19     4 20 21 13    10 14 20  7
 1  7 13 19     2  1  7 13     3  2  1  7     4  3  2  1


Sample Input #03
2 2 3
1 1
1 1
Sample Output #03
1 1
1 1
Explanation #03
All of the elements are the same, so any rotation will repeat the same matrix.

*/

// Complete the matrixRotation function below.

void rotate(int m , int m2, int n , int n2, vector<vector<int>>& matrix){

    int r  = 0 , c = 0;
    int prev = matrix[m][n] , curr;

    for(int  i = m+1; i <= m2; i++){

        curr = matrix[i][n];
        matrix[i][n] = prev;
        prev = curr;
    }

    for(int  i = n+1; i <= n2; i++){

        curr = matrix[m2][i];
        matrix[m2][i] = prev; 
        prev = curr;
    }

    for(int i = m2-1; i>=m; i--){
       
        curr = matrix[i][n2];
        matrix[i][n2] = prev;
        prev = curr;
    }

    for(int i = n2-1; i >=n ; i--){
        
        curr = matrix[m][i];
        matrix[m][i] = prev;
        prev = curr;
    }
}


void matrixRotation(vector<vector<int>> matrix, int r) {

    int m2 = matrix.size()-1;
    int n2 = matrix[0].size()-1;
    int m = 0, n = 0;

    while(m2-m>=0 && n2-n>=0){

        int sum = 2*(m2 - m + n2 - n);
        sum = r % sum;
        
        while(sum > 0){
            rotate(m,m2,n,n2,matrix);
            sum--;
        }

        m++;
        m2--;
        n++;
        n2--;
    }

    for (int i = 0; i < matrix.size(); i++) 
    { 
        for (int j = 0; j < matrix[0].size(); j++) 
          cout << matrix[i][j] << " "; 
        cout << endl; 
    }

}
