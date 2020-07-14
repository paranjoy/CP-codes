/*
Given a string S, find length of the longest substring with all distinct characters.
For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input Format:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is String S.

Output Format:
For each testcase, in a new line, the length of the longest substring with all distinct characters gets printed.

Your Task:
This is a function problem. You only need to complete the function longestUniqueSubstr that takes S string as argument and returns the length.

Constraints:
1 ≤ T ≤ 100
1 ≤ |S| ≤ 104

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7

Explanation:
Testcase1: abababcdefababcdab. The substring marked in red is the answer and it has a length of 6.
Testcase2: geeksforgeeks. The substring marked in red is the answer and it has a length of 7.
*/

bool counter_check(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 1)
            return false;
    }
    
    return true;
}
bool check(string str, int window_size){
    vector<int> v(128, 0);
    int j = 0;
    
    for(j = 0; j < window_size; j++){
        v[str[j]]++;
    }
    
    if(counter_check(v))
        return true;
    
    for(j = window_size; j < str.size(); j++){
        v[str[j]]++;
        v[str[j - window_size]]--;
        
        if(counter_check(v))
            return true;
    }
    
    return false;
}

int longestUniqueSubstr(string s){
    int l = 0, r = s.size();
    int count = 0;
    
    while(l <= r){
        int mid = (l + r)/2;
        
        if(check(s, mid)){
            count = max(count, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    return count;
    //Your code here
}
