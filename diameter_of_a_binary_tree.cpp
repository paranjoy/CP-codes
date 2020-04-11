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
    int max_dia = -1;
    
    int Height(TreeNode *p){
        if(p==NULL)
            return 0;
        
        int x = Height(p->left);
        int y = Height(p->right);
        
        return x >= y ? x+1 : y+1;
    }
    
    void preorder_traversal(TreeNode *p){
        if(p){
            int ht_r = Height(p->right);
            int ht_l = Height(p->left);
            
            max_dia = max_dia >= (ht_l + ht_r) ? max_dia : (ht_l + ht_r);
            
            preorder_traversal(p->left);
            preorder_traversal(p->right);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        else
            preorder_traversal(root);
        
        
        return max_dia;        
    }
};
