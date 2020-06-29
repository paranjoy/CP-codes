/*
Given a binary tree of size N . We install bulb on the nodes of the tree . A bulb at a node can light it's parent , itself and it's immediate children . Y
ou have to find minimum number of bulbs required to light all the nodes of the tree.

You have to complete function minBulb() which accepts root node of the tree as parameter and returns the minimum number of light bulbs 
required to light up the whole tree.

Constraints:
1<=T<=103
1<=N<=103
Example:

Input:
2
1 2 3
1 N 2 N 3 N 4 N 5 N
Output:
1
2

Explanation:
Test Case 2:
Given tree is: 
                       1
                          \
                            2
                               \
                                 3
                                    \
                                       4
                                           \
                                             5
On placing bulbs at node 2 and 4 we can light all the nodes of the tree.
*/
/*
Structure of Node is as follows:
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
int ans = 0;
int post(Node* node){
    bool zero = false , two = false;
    
    if(node->left==NULL && node->right==NULL)
        return 0;
    
    if(node->left){
        int get = post(node->left);
        if(get==0)
            zero = true;
        if(get==2)
            two = true;
    }
    
    if(node->right){
        int get = post(node->right);
        if(get==0)
            zero = true;
        if(get==2)
            two = true;
    }
    
    if(zero==true){
        ans++;
        return 2;
    }
    
    if(two==true)
        return 1;
    
   return 0; 
}

int minBulb(Node* root){
   ans = 0;    
   //greedy
   int result = post(root);
    if(result==0)
        return ans + 1;
    return ans;
}
