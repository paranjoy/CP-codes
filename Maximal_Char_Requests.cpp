/*
In this challenge, a string and a list of intervals are given.
The string consists of English letters only and it can contain both lowercase and uppercase letters.
For two different letters, we say that the first letter is greater than the second letter when the first letter comes later in the 
alphabet than the second letter ignoring the case of the letters. 
For example, the letter 'Z' and 't' are greater than the letters 'b' and 'G', while the letters 'B' andd 'b' are equal
as case is not considered.
The task is the following. For each given interval, you need to find the count of the greatest letter occurring in the string 
in that interval, ignoring the case of the letters, so occurrences of, for example, a  and A are occurrences of the same letter.

Consider, for example, for the string "AbaBacD". In the interval, [0, 4], the greatest letter is 'b' with count 2.

Input Format:
The first line contains integer N, denoting the length of the input string.
The second line contains string S .
The third line contains an integer Q, denoting the number of intervals. 
Each line of the Q subsequent lines contains two space-separated integers x(i) and y(i) , 
denoting the beginning and the end of i th interval.

Constraints:
1 <= N <= 3 x 10^5
1 <= Q <= 10^5
0 <= x(i) <= y(i) < n

Subtasks:
1 <= N <= 2000
1 <= Q <= 2000

for 50% of the maximum score

Output Format:
For each interval, print the count of the greatest letter occurring in the string in that interval.

Sample Input 0
5
ddaaa
1
0 4

Sample Output 0
2

Explanation 0
The string is "ddaaa" and there is only one interval, i.e. the interval [0, 4] denoting the whole string.
The greatest character occuring in that interval is d and its count is 2, therefore, 2 is the answer.

Sample Input 1
8
aAabBcba
5
2 6
1 2
2 2
0 4
0 7

Sample Output 1
1
2
1
2
1

Explanation 1
The input string is "aAabBcba" and there are 5 intervals to check:
 [2,6]-> aA[abBcb]a -> 'c' is the greatest and occurs 1 time
 [1,2]-> a[Aa]bBcba -> 'a' is the greatest and occurs 2 times
 [2,2]-> aA[a]bBcba -> 'a' is the greatest and occurs 1 time
 [0,4]-> [aAabB]cba -> 'b' is the greatest and occurs 2 times
 [0,7]-> [aAabBcba] -> 'c' is the greatest and occurs 1 time
*/

//code snippet
/*
 * Complete the 'getMaxCharCount' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> getMaxCharCount(string s, vector<vector<int>> queries) {
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.
    vector<int> res;
    res.assign(queries.size(),0);
    
    int v[s.size() + 1][26];
    
    for(int i = 0; i < 26; i++)
        v[0][i] = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        char ch = s[i];
        
        int num = (int)ch;
        if(num <= 90)
            num += 32;
    
        for(int  j = 0; j < 26; j++)
            v[i + 1][j] = v[i][j];
        v[i + 1][num - 97] += 1;   
        }
    
    
    for(int  i = 0; i < queries.size(); i++){
        
        int x = queries[i][0];
        int y = queries[i][1];
        
        char ch1 = s[x];
        int num1 = (int)ch1;
        if(num1 <= 90)
            num1 += 32;
        
        if(x == y)
            res[i] = 1;
        
        else
            for(int j = 25; j >= 0; j--){
                if(v[y+1][j] > v[x][j]){
                    res[i] = (v[y+1][j] - v[x][j]);
                    break;
                }
            }
        }
    
    
    return res;
}
