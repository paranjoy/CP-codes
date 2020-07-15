/*
You are given an integer N. You have to count how many possible combinations of numbers from 1 to N (excluding 1 and N).
which are dividing the number N and after multiplication exactly equal to the value N.
For Example: Let suppose, I have a number 12 and the number that divides 12 between 1 to 12 are 2, 3, 4, 6 we can form N by multiply 2*6, 3*4 and 2*2*3. 
So, there are 3 possible combinations for number 12.

Note: We will not consider 1 and N we will try to find the combinations in between them.

Input:
First-line contains the T number of test cases.
For each test case, there is an integer N.

Output:
Print the number of combinations possible.

Constraints:
1 <= T <= 103
1 <= N <= 106

Example:

Sample Input:
3
12
8
32

Sample Output:

3
2
6

Explanation:
For test case 1:  For value 12 we have 3 combinations in total.
[ [2, 6], [2, 2, 3], [3, 4] ]

For test case 2: For value 8 we have only 2 combinations:
[ [2, 2, 2] , [2, 4] ]

*/

//User function Template for C++

void factorsListFunc (int first, int each_prod, int n, vector<int> single_result_list, vector<vector<int>>& resultant){
    if (first > n || each_prod > n)  
        return;  
        
    if (each_prod == n){
        resultant.push_back(single_result_list);  
        return;  
    }  
    
    for (int i = first; i <= n/2; i++){  
        if (i * each_prod > n)  
            break;  

        if (n % i == 0){  
            single_result_list.push_back(i);  
            
            factorsListFunc(i, i * each_prod, n, single_result_list, resultant); 
            
            single_result_list.pop_back();  
        }
    }
}

int getFactors(int n){
    // Code here
    vector<vector<int>> resultant; 
    vector<int>single_result_list; 
    factorsListFunc(2, 1, n, single_result_list, resultant);
    
    /*for (int i = 0; i < resultant.size(); i++){  
        for (int j = 0; j < resultant[i].size(); j++)  
            cout << resultant[i][j] << " ";  
        cout << endl; 
    } */
    
    return resultant.size();
}
