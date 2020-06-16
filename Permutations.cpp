/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//code snippet
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0) 
            return vector<vector<int>>();
        
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        vector<int>res;
        vector<bool> used(num.size(),false);
        
        dfs(result,res,num,used,num.size());
        
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &res, vector<int> num, vector<bool> &used, int n){
        if(n==0){
            result.push_back(res);
            return;
        }
        
        for(int i=0;i<num.size();i++){
            if(used[i]==false){
                used[i]=true;
                res.push_back(num[i]);
                
                dfs(result,res,num,used,n-1);
                
                res.pop_back();
                used[i]=false;
            }
        }
    }
};
