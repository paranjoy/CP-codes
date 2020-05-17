/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".



Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

//code snippet
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        
        if(p.size() > s.size())
            return res;
        
        vector<int> s_map(26, 0);
        vector<int> p_map(26, 0);
       
        int i;
        
        for(i = 0; i < p.size(); i++){
            s_map[s[i] - 'a']++;
            p_map[p[i] - 'a']++;
        }
        
        if(s_map == p_map)
            res.push_back(0);
        
        while(i < s.size()){
            
            s_map[s[i] - 'a']++;
            s_map[s[i - p.size()] - 'a']--;
            
            if(s_map == p_map)
                res.push_back(i - p.size() + 1);
            
            i++;
        }
        
        return res;
    }
};
