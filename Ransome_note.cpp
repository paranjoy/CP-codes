/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

//code snippet

class Solution {
public:
    bool canConstruct(string rn, string mg) {
        
        vector<int>v(26, 0);
        
        for(int i = 0; i < mg.size(); i++)
            v[mg[i]-'a']++;
        
        for(int i = 0; i < rn.size(); i++)
            if(--v[rn[i]-'a'] < 0)
                return false;
        
        return true;        
    }
};
