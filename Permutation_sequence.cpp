/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the kth permutation sequence.

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/
//code snippet
class Solution {
public:
    string getPermutation(int n, int k) {
       
        vector<int> nums;
        int fact[n];
        fact[0] = 1;
        nums.push_back(1);
        
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i + 1);
        }
        
        k--;
        
        string s = "";
        for (int i = n - 1; i >= 0; i--) {
            int idx = k/fact[i];
            k = k % fact[i];

            cout << idx << " ";
            s += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return s;
    }
};
