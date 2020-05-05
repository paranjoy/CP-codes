/*
You are given  queries. Each query is of the form two integers described below:
-1 x  : Insert x in your data structure.
-2 y  : Delete one occurence of y from your data structure, if present.
-3 z  : Check if any integer is present whose frequency is exactly . If yes, print 1 else 0.

The queries are given in the form of a 2-D array queries of size q where queries[i][0] contains the operation,
and queries[i][0] contains the data element.


Function Description
Complete the freqQuery function in the editor below. It must return an array of integers where each element is a 1 
if there is at least one element value with the queried number of occurrences in the current array, or 0 if there is not.

freqQuery has the following parameter(s):
queries: a 2-d array of integers

Constraints:
1 <= q <= 10^5
1 <= x,y,z <= 10^9


Sample Input 0
8
1 5
1 6
3 2
1 10
1 10
1 6
2 5
3 2
Sample Output 0
0
1


Sample Input 1
4
3 4
2 1003
1 16
3 1
Sample Output 1
0
1


Sample Input 2
10
1 3
2 3
3 2
1 4
1 5
1 5
1 4
3 2
2 4
3 2
Sample Output 2
0
1
1
*/

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> q) {
    map<int, int>m;
    map<int, int> m2;
    vector<int>v;
    for(int  i = 0; i < q.size(); i++)
    {
        int op = q[i][0];
        int  p = q[i][1];

        if(op == 1){
            m2[m[p]]--;
            m[p]++;
            m2[m[p]]++;
        }
        else if(op == 2){
            if(m.find(p) != m.end()){
                m2[m[p]]--;
                m[p]--;

                if(m[p] == 0)
                    m.erase(p);
                else
                    m2[m[p]]++;
            }
        }
        else{
            if(m2.find(p) != m2.end() && m2[p] != 0)
                v.push_back(1);
            else
                v.push_back(0);
        }
    }

    return v;

}
