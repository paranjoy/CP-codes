/*
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/

//code snippet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int res = INT_MIN;
        
        height(root, res);
        
        return res - 1;
    }
private:
    int height(TreeNode* root, int& res){
        if(root == NULL)
            return 0;
        
        int l_h = height(root->left, res);
        int r_h = height(root->right, res);
        
        res = max(res, l_h + r_h + 1);
        
        
        return 1 + max(l_h, r_h);
    }
};
