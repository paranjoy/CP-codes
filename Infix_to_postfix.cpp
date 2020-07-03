/*
Given an infix expression exp in the form of a string. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
  ​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 

Input:
The first line of input contains an integer T denoting the number of test cases. 
The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-. 

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes string as parameter and returns the postfix expression. 
The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= |exp| <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D
Output:
abcd^e-fgh*+^*+i-
ABC+*D/

Explanation:
Testcase 1: After converting the infix expression into postfix expression , the resultant expression will be abcd^e-fgh*+^*+i-
Testcase 2: After converting the infix expression into postfix expression , the resultant expression will be ABC+*D/

*/
/*
The postfix expressions can be evaluated easily using a stack.

Scan the infix expression from left to right.
If the scanned character is an operand, output it.
Else,
If the precedence of the scanned operator is greater than the precedence of the operator in the stack push it.
Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
If the scanned character is an ‘(‘, push it to the stack.
If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
Repeat steps 2-6 until infix expression is scanned.
Print the output
Pop and output from the stack until it is not empty.
*/


//Function to return precedence of operators
int prec(char c){
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string exp){
    stack<char> st;
    st.push('N');
    int l = exp.length();
    string ns;
    for(int i = 0; i < l; i++){
        // If the scanned character is an operand, add it to output string.
        if((exp[i] >= 'a' && exp[i] <= 'z')||(exp[i] >= 'A' && exp[i] <= 'Z'))
          ns+=exp[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(exp[i] == '(')
          st.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(exp[i] == ')'){
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
        }

        // If an operator is scanned
        else{
            while(st.top() != 'N' && prec(exp[i]) <= prec(st.top())){
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(exp[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(st.top() != 'N'){
        char c = st.top();
        st.pop();
        ns += c;
    }
    return ns;
}
