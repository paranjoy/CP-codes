/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6


Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

//code snippet

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
    int maxPathSum(TreeNode* root) {
        
        int res = INT_MIN;
        
        recur_find_max_path(root, res);
        
        return res;
    }
private:
    int recur_find_max_path(TreeNode* root, int& res){
        
        if(root == NULL)
            return 0;
        
        int r = recur_find_max_path(root->right, res);
        int l = recur_find_max_path(root->left, res);
        
        int max1 = max(max(l, r) + root->val, root->val);
        
        int max2 = max(max1, l + r + root->val);
        
        res = max(res, max2);
        
        return max1;
    }
};
