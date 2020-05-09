/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

//code snippet
class Solution {
public:
    bool isPerfectSquare(int num) {
     
        if(num == 1)
            return true;
        
        int l = 0, r = num / 2;
        
        while(l <= r){
            
            long mid = l + (r - l) / 2;
            
            if(mid*mid == num)
                return true;
            
            if(mid> num/mid)
                r = mid - 1;
            
            else l = mid + 1;
        }
        
        return false;
    }
}
