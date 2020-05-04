/*
In this challenge, you must implement a simple text editor. 
Initially, your editor contains an empty string, S. You must perform Q operations of the following 4 types:

append(W) - Append string W to the end of S.
delete(k) - Delete the last K characters of S.
print(k) - Print the k'th character of S.
undo() - Undo the last (not previously undone) operation of type 1 or 2, reverting S to the state it was in 
prior to that operation.

Constraints
1 <= Q <= 10^6
1 <= k <= |S|

The sum of the lengths of all W in the input <= 10^6 .
The sum of k over all delete operations <= 2*10^6.
All input characters are lowercase English letters.
It is guaranteed that the sequence of operations given as input is possible to perform.


Sample Input
8
1 abc
3 3
2 3
1 xy
3 2
4 
4 
3 1
Sample Output
c
y
a

*/

#include <bits/stdc++.h>
using namespace std;
stack<string>s;
string str = "\0";
void app(){
    string s1;
    cin>>s1;
    str += s1;
    s.push(str);
}
void del(){
    int k;
    cin>>k;
    if(str.size() - k == 0)
        str = "\0";
    else{
        string s1 = str.substr(0, str.size() - k);
        str = s1;
    }
    s.push(str);
}
void pr(){
    int k;
    cin>>k;
    cout<<str[k-1]<<endl;
}
void undo(){
    s.pop();
    str = s.top();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    s.push("\0");
    int n;
    cin>>n;
    while(n--){
        int q;
        cin>>q;

        if(q == 1)
            app();
        else if(q == 2)
            del();
        else if(q == 3)
            pr();
        else
            undo();
    }
    return 0;
}
