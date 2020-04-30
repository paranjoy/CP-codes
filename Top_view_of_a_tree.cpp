/*
You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. 
See the example below.

You only have to complete the function.

For example :

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Top View : 1 -> 2 -> 5 -> 6

Input Format
You are given a function,
void topView(node * root) {

}

Constraints

1 <= Nodes in the tree <= 500

Output Format
Print the values on a single line separated by space.

Sample Input

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Sample Output

1 2 5 6

Explanation

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
From the top only nodes 1,2,5,6 will be visible.
*/

//code snippet

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {

        if(root == NULL)
            return;

        map<int, int> m;
        m[0] = root->data;

        queue<pair<int, Node*>> q;

        q.push(pair<int, Node*>(0, root));

        while( q.empty() == false){

            int n = (q.front()).first;
            Node * p = (q.front()).second;

            q.pop();

            if(m.find(n) == m.end()){
                m[n] = p->data;
            }

            if(p->left != NULL)
                q.push(pair<int, Node*>(n-1, p->left));
            if(p->right != NULL)
                q.push(pair<int, Node*>(n+1, p->right));
        }

        for(auto itr = m.begin(); itr != m.end(); itr++){
            cout<<itr->second<<" ";
        }
    }

}; //End of Solution
