/*
You are given an integer num. You will apply the following steps exactly two times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
The new integer cannot have any leading zeros, also the new integer cannot be 0.
Let a and b be the results of applying the operations to num the first and second times, respectively.

Return the max difference between a and b.

 

Example 1:
Input: num = 555
Output: 888

Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888


Example 2:
Input: num = 9
Output: 8

Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8


Example 3:
Input: num = 123456
Output: 820000


Example 4:
Input: num = 10000
Output: 80000


Example 5:
Input: num = 9288
Output: 8700
 

Constraints:

1 <= num <= 10^8

*/

//code snippet

class Solution {
public:
    int maxDiff(int num) {
        
        int c = length(num);
        int max, min;
        
        int f = int(pow(10, c-1));
        f = num/f;
        
        if(f != 1 && f != 9){
            
            max = replace(f,9, num);
            min = replace(f,1, num);
            
            return (max - min);
        }
        
        if(f == 1){
            max = replace(f,9, num);
            
            string s = to_string(num);            
            
            for(int i = 0; i < s.size(); i++){
                
                if(s[i] != '1' && s[i] != '0' ){
                    c = int(s[i]) - 48;
                    break;
                }
            }
            
            min = replace(c, 0, num);
            
            return (max - min);
        }
        
        if(f == 9){
            min = replace(9, 1, num);
            
            string s = to_string(num);
            
            for(int i = 0; i < s.size(); i++){
                
                if(s[i] != '9'){
                    c = int(s[i]) - 48;
                    break;
                }
            }
            
            max = replace(c, 9, num);
            
            return (max - min);
            
        }
        
        return 0;
    }
private:
    int length(int n){
        int c = 0;
        while(n > 0){
            c++;
            n = n/10;
        }
        return c;
    }
    
    int replace(int n1, int n2, int n){
        int c = 1;
        int sum = 0;
        while(n>0){
            int d = n %10;
            if(d == n1){
                d = n2;
            }
            sum += d*c;
            c = c*10;
            n = n/10;
        }
        return sum;
    }
};
