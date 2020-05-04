/*
Consider an array of  distinct integers, arr = [arr[0], arr[1],....arr[n-1]].
George can swap any two elements of the array any number of times. An array is beautiful if the 
sum of |arr[i] - arr[i - 1]| among ( 1 <= i <= n-1 ) is minimal.

Given the array arr, determine and return the minimum number of swaps that should be performed in order to make the 
array beautiful.

For example, arr = [7, 15, 12, 3] . One minimal array is [3, 7, 12, 15].
To get there, George performed the following swaps:
Swap      Result
      [7, 15, 12, 3]
3 7   [3, 15, 12, 7]
7 15  [3, 7, 12, 15]

It took 2 swaps to make the array beautiful. This is minimal among the choice of beautiful arrays possible.

Function Description
Complete the lilysHomework function in the editor below. It should return an integer that represents the minimum number
of swaps required.

lilysHomework has the following parameter(s):
arr: an integer array

Constraints
1 <= n <= 10^5
1 <= arr[i] <= 2*10^9


Sample Input
4
2 5 3 1
Sample Output
2

*/

bool compare(int a , int b){

    if(a > b)
        return true;
    
    return false;
}

int no_swaps(vector<int> v1, vector<int> v, map<int, int> m){
    
    int c = 0;

    for(int  i = 0; i < v1.size(); i++){
        if(v[i] != v1[i]){
            c++;
            
            int j = m[v[i]];
            m[v1[i]] = m[v[i]];
            int temp = v1[i];
            v1[i] = v[i];
            v1[j] = temp;
        }
    }

    return c;
}
// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {

    map<int, int> m;

    vector<int> v;
    vector<int> v1;
    
    int min1, min2;
    
    for(int  i = 0; i < arr.size(); i++){
        m[arr[i]] = i;
        v.push_back(arr[i]);
        v1.push_back(arr[i]);
    }

    sort(v.begin(), v.end()); // sort in ascending order
    
    min1 = no_swaps(v1, v, m);
    
    for(int  i = 0; i < arr.size(); i++){
        m[arr[i]] = i;
        v1[i] = arr[i];
        v[i] = arr[i];
    }
    
    sort(v.begin(), v.end(), compare); //sort in descending order
    
    min2 = no_swaps(v1, v, m);

    return min(min1, min2);
}
