/*

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, 
and any descendant of node.right has a value > node.val.Also recall that a preorder traversal displays the value of
the node first, then traverses node.left, then traverses node.right.)

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size() == 0)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < preorder.size(); i++)
            r_insert(root, preorder[i]);
        
        return root;
        
        
    }
private:
    TreeNode* r_insert(TreeNode* p, int key){
        
        if(p == NULL)
            p = new TreeNode(key);
        else if(key > p->val)
            p->right = r_insert(p->right, key);
        else if(key < p->val)
            p->left = r_insert(p->left, key);
        
        return p;
    }
};

