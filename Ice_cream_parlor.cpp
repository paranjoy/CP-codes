/*
Sunny and Johnny like to pool their money and go to the ice cream parlor. 
Johnny never buys the same flavor that Sunny does. The only other rule they have is that they spend all of their money.

Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.

For example, they have m = 6 to spend and there are flavors costing [1,3,4,5,6] . 
The two flavors costing 1 and 5 meet the criteria. Using 1-based indexing, they are at indices 1 and 4.

Function Description
Complete the icecreamParlor function in the editor below. It should return an array containing the indices of the prices 
of the two flavors they buy, sorted ascending.

icecreamParlor has the following parameter(s):

m: an integer denoting the amount of money they have to spend
cost: an integer array denoting the cost of each flavor of ice cream

Constraints
1 <= t <= 50
2 <= m, n <= 10^4
1 <= cost[i] <= 10^4, ∀ i in [1,n] 
There will always be a unique solution.

Sample Input
2
4
5
1 4 5 3 2
4
4
2 2 4 3
Sample Output
1 4
1 2

*/

// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) {

    vector<int> v;
    map<int, vector<int>>m1;
    for(int  i = 0; i < arr.size(); i++){
        m1[arr[i]].push_back(i+1);
    }

    for(int  i = 0; i < arr.size(); i++){
        int j = m - arr[i];

        if(j != arr[i]){
            if(m1.find(j) != m1.end()){
                v.push_back(i+1);
                v.push_back((m1[j])[0]);
                break;
            }
        }
        else{
            if(m1[j].size() >= 2)
                {
                    v.push_back(m1[j][0]);
                    v.push_back(m1[j][1]);
                    break;
                }
        }
    }
    return v;
}
