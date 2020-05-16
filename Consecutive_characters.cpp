/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one 
unique character.

Return the power of the string.

 
Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Example 3
Input: s = "triplepillooooow"
Output: 5

Example 4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

Example 5:
Input: s = "tourist"
Output: 1
 

Constraints:
1 <= s.length <= 500
s contains only lowercase English letters.

*/
//code snippet

class Solution {
public:
    int maxPower(string s) {
        
        int max = 1;
        
        int c = 1;
        
        for(int  i =  0; i < s.size(); i++){
            c = 1;
            
            for(int j = i + 1; j < s.size(); j++){
                
                if(s[i] == s[j])
                    c++;
                else
                    break;
            }
            max = max > c ? max : c;
        }
        return max;
    }
};
