/*
Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

// code snippet
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> v;
        int *a = new int[26];
         for(int j=0;j<26;j++)
             a[j]=0;
        map<string, vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            int l = s.length();
            for(int j=0;j<l;j++){
                a[(int)s[j]-97]++;
            }
            s="";
            for(int j=0;j<26;j++)
            {
                while(a[j]>0){
                    s += (char)(j+97);
                    a[j]--;
                }
            }
            map[s].push_back(strs[i]);
        }
        for(auto it=map.begin();it!=map.end();it++){
            v.push_back(it->second);
        }
        return v;
    
    }
};
