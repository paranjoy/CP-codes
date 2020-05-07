/*
You will be given a list of integers, arr, and a single integer k. You must create an array of length k from elements of arr
such that its unfairness is minimized. Call that array subarr. Unfairness of an array is calculated as
max(subarr) - min(subarr)

Where:
- max denotes the largest integer in subarr 
- min denotes the smallest integer in subarr

As an example, consider the array [1,4,7,2] with a k of 2. Pick any two elements, test subarr = [4,7] .
unfairness = 7 - 4 = 3
Testing for all pairs, the solution [1,2] provides the minimum unfairness.

Note: Integers in arr may not be unique.

Function Description

Complete the maxMin function in the editor below. 
It must return an integer that denotes the minimum possible value of unfairness.

maxMin has the following parameter(s):
k: an integer, the number of elements in the array to create
arr: an array of integers .

constraints:
2 <= n <= 10^5
2 <= k <= n

Sample Input 0
7
3
10
100
300
200
1000
20
30
Sample Output 0
20

Sample Input 1
10
4
1
2
3
4
10
20
30
40
100
200
Sample Output 1
3

Sample Input 2
5
2
1
2
1
2
1
Sample Output 2
0
*/

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {

  sort(arr.begin(), arr.end());
  int mini = INT_MAX;
  for(int i = 0; i <= arr.size() - k; i++)
    mini = min(mini, (arr[i+k-1] - arr[i]));

  return mini;
}
