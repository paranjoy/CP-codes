/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

//code snippet

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        
        for(int  i = 0; i < s.size(); i++)
            m[s[i]]++;
        
        for(int  i = 0; i < s.size(); i++)
            if(m[s[i]] == 1)
                return i;
        
        return -1;
        
        
    }
};
