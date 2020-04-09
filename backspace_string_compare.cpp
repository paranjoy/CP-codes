/*
Given two strings S and T, return if they are equal when both are typed into empty text editors.# means a backspace character

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/
//CODE SNIPPET

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        int l1 = S.size();
        int l2 = T.size();
        
        string a ="", b ="";
        
        for(int i =0;i<l1;i++){
            if(S[i] == '#' && a.size()>0)
                a = a.substr(0, a.size()-1);
            else if(S[i]!='#')
                a += S[i]; 
        }
        
        for(int i =0;i<l2;i++){
            if(T[i] == '#' && b.size()>0)
                b = b.substr(0, b.size()-1);
            else if(T[i]!='#')
                b += T[i]; 
        }
        
        if(a.compare(b)==0)
            return true;
        
        else
            return false;      
    }
};
