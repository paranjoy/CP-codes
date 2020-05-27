/*
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 
Explanation
Rotate the array 90 degrees anticlockwise.
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;

	int mat[N][N];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> mat[i][j];
	
	// Consider all squares one by one
	// for a 2D matrix of NxN there are N/2 squares 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    }

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout << mat[i][j] <<" ";
		cout << endl;
	}

	return 0;
}
