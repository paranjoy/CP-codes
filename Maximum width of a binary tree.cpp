/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. 
The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null 
nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:   
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int mod = 1000000007;
        map<long long, long long> left;
        map<long long, long long> right;
        
        queue<tuple<TreeNode*, long long, long long>> q;
        q.push({root, 0, 1});
        left[0] = 1;
        right[0] = 1;
        
        while(!q.empty()){
            TreeNode* temp = get<0>(q.front());
            long level = get<1>(q.front());
            long num = get<2>(q.front());
            
            q.pop();
            
            long long l = (2*num) % mod;
            if(temp->left){
                
                if(left.find(level + 1) == left.end())
                    left[level + 1] = l ;
                else
                    left[level + 1] = left[level + 1] < l ? left[level + 1] : l ;
                
                if(right.find(level + 1) == right.end())
                    right[level + 1] = l;
                else
                    right[level + 1] = right[level + 1] > l ? right[level + 1] : l;
                
                q.push({temp->left, level + 1, l});
            }
            
            long long r = (2*num + 1) % mod;
            if(temp->right){
                
                if(left.find(level + 1) == left.end())
                    left[level + 1] = r;
                else
                    left[level + 1] = left[level + 1] < r ? left[level + 1] : r ;
                
                if(right.find(level + 1) == right.end())
                    right[level + 1] = r;
                else
                    right[level + 1] = right[level + 1] > r ? right[level + 1] : r;
                
                q.push({temp->right, level + 1, r});
            } 
        }
        
        int count = INT_MIN;
        
        for(auto itr = left.begin(); itr != left.end(); itr++){
            int  i = itr->first;
            cout << i <<" "<< right[i] <<" "<<left[i] << endl;
            count = count > (right[i] - left[i] + 1) ? count : (right[i] - left[i] + 1) ;
        }
        cout << endl;
        return count;
    }
};
