/*
Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a 
given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes
along a path results in a sequence in the given binary tree.

 

Example 1:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true

Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0

Example 2:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false 

Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

Example 3:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false

Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
 

Constraints:

1 <= arr.length <= 5000
0 <= arr[i] <= 9
Each node's value is between [0 - 9].



Hint #1  
Depth-first search (DFS) with the parameters: current node in the binary tree and current position in the array of integers.

Hint #2  
When reaching at final position check if it is a leaf node.
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
    bool isValidSequence(TreeNode* root, vector<int>& arr){
        
        if(root == NULL || root->val != arr[0])
            return false;
        stack<pair<TreeNode*,  int>> s;
        s.push(pair<TreeNode*,  int>(root,0));
        int i;
        
        TreeNode *p = s.top().first;
        i = s.top().second;
        s.pop();
        
        while(1){
            
            if(p->val == arr[i++]){
                if(i == arr.size() && p->left == NULL && p->right == NULL)
                    return true;
                if(i == arr.size() && (p->left != NULL || p->right != NULL))
                    return false;
                
                if(p->left && p->left->val == arr[i]){
                    
                    if(p->right && p->right->val == arr[i])
                        s.push(pair<TreeNode*,  int>(p->right,i));
                        
                    
                    p = p->left;
                    
                }
                else if(p->right && p->right->val == arr[i]){
                    
                    p = p->right;
                }
                else{
                    
                    if(s.empty()){
                        return false;
                    }
                    
                    p = s.top().first;
                    i = s.top().second;
                    s.pop();
                }
            }
            else{
                
                if(s.empty())
                    return false;
                
                p = s.top().first;
                i = s.top().second;
                s.pop();                   
            }           
            
        }
        
        return false;     
    }
};
