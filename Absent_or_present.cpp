/*
You are given a string representing an attendance record for a student. 
The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or 
more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False
*/
//code snippet
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        int l = 0;
        
        for(int  i = 0; i < s.size(); i++){
            if(s[i] == 'A')
                a++;
            
            if(s[i] == 'L'){
                if(i + 1 < s.size() && s[i + 1] == 'L'){
                    i++;
                    if(i + 1 < s.size() && s[i + 1] == 'L'){
                        l++;
                        i++;
                    }
                }                
            }
        }
        
        cout << a <<" "<<l<<endl;
        
        return !((a > 1) || (l > 0));
    }
};
