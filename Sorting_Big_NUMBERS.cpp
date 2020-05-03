/*
Consider an array of numeric strings where each string is a positive number with anywhere from 1 to 10^6  digits. 
Sort the array's elements in non-decreasing, or ascending order of their integer values and print each element 
of the sorted array on a new line.

Function Description
Complete the bigSorting function in the editor below. It should return the sorted string array.

bigSorting has the following parameter(s):
unsorted: an unsorted array of integers as strings

Constraints
1 <= n <= 2*10^5
Each string is guaranteed to represent a positive integer without leading zeros.
The total number of digits across all strings in unsorted is between 1 and 10^6 (inclusive).



Sample Input 0
6
31415926535897932384626433832795
1
3
10
3
5
Sample Output 0
1
3
3
5
10
31415926535897932384626433832795


Sample Input 1
8
1
2
100
12303479849857341718340192371
3084193741082937
3084193741082938
111
200
Sample Output 1
1
2
100
111
200
3084193741082937
3084193741082938
12303479849857341718340192371
*/
//code snippet
// Complete the bigSorting function below.
bool compare(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
       return true; 
    if (n2 < n1) 
       return false; 
  
    // If lengths are same 
    for (int i=0; i<n1; i++) 
    { 
       if (str1[i] < str2[i]) 
          return true; 
       if (str1[i] > str2[i]) 
          return false; 
    } 
  
    return false; 
} 
vector<string> bigSorting(vector<string> unsorted) {

    sort(unsorted.begin(), unsorted.end(), compare);

    return unsorted;
}
