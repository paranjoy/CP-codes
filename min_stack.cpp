/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

HINT 1
Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)
*/
//code snippet

class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int data;
        Node *next;
        Node *prev;
        int min_till;
    } *top_pointer;
    
    MinStack() {
        top_pointer = NULL;
    }
    
    void push(int x) {
      
        if( top_pointer == NULL){
          Node *p = new Node();
          p->data = x;
          p->next = NULL;
          p->prev = NULL;
          p->min_till = x;
          
          top_pointer = p;
      }  
     else{
         Node *p = new Node();
         p->data = x;
         p->next = NULL;
         p->prev = top_pointer;
         p->min_till = (top_pointer->min_till) <= x ? (top_pointer->min_till) : x;
          
         top_pointer = p;
     }
        
   }
    
    void pop() {
        
        if(top_pointer == NULL){}
        else{
            Node *old = top_pointer;
            top_pointer = top_pointer->prev;
            if(top_pointer != NULL)
                top_pointer->next = NULL;
            delete(old);
        }
    }
    
    int top() {
        return top_pointer->data;
        
    }
    
    int getMin() {
        
        
        return top_pointer->min_till;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
