/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
//code snippet

class Solution {
public:    
    static bool compare(pair <int, char> a, pair <int, char> b){
      return a.first < b.first;
   }
    
    string frequencySort(string s) {
        
        vector <pair <int, char>> v;
        map <char, int> m;
        string ans = "";
      
        for(int i = 0; i < s.size(); i++)
            m[s[i]]++;
      
        for(auto itr = m.begin(); itr != m.end(); itr++)
            v.push_back({itr->second, itr->first});
        
        sort(v.rbegin(), v.rend(), compare);
        
        for(int i = 0; i < v.size(); i++){
            int t = v[i].first;
            
            while(t--)
                ans += v[i].second;
        } 
        return ans;
   }   
};
