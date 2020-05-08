/*
The Ruler of HackerLand believes that every citizen of the country should have access to a library. 
Unfortunately, HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads!
As you are the greatest programmer of HackerLand, the ruler wants your help to repair the roads and build some new 
libraries efficiently.

HackerLand has n cities numbered from 1 to n. The cities are connected by m bidirectional roads. 
A citizen has access to a library if:
-> Their city contains a library.
-> They can travel by road from their city to a city containing a library.

You are given  queries, where each query consists of a map of HackerLand and value of c_lib and c_road. 
For each query, find the minimum cost of making libraries accessible to all the citizens and print it on a new line.


Function Description
Complete the function roadsAndLibraries in the editor below. It must return the minimal cost of providing libraries to all,
as an integer.

roadsAndLibraries has the following parameters:

n: integer, the number of cities
c_lib: integer, the cost to build a library
c_road: integer, the cost to repair a road
cities: 2D array of integers where each cities[i] contains two integers that represent cities connected by an obstructed road

1 <= q <= 10
1 <= n <= 10^5
0 <= m <= min( 10^5, (n.(n-1)/2))
1 <= c_road, c_lib <= 10^5
1 <= u[i], v[i] <= n
each road connects two distinct cities


Sample Input
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
Sample Output
4
12

Sample Input
1
6 4 2 3
1 2
1 3
4 5
4 6
Sample Output
12
*/

long cost1, cost2;
long c;
void DFS(int i, vector<vector<int>>& edge, vector<bool>&visited){
    visited[i] = true;
    c++;

    for(int j = 0; j < edge[i].size(); j++){
        if(!visited[edge[i][j]])
            DFS(edge[i][j], edge, visited);
    }
    return;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
     cost1 = (long)c_lib *  (long)n;
     cost2 = 0;
    vector<vector<int>>edge(n, vector<int>());

    for(int i = 0; i < cities.size(); i++){
        edge[cities[i][0] - 1].push_back(cities[i][1] - 1);
        edge[cities[i][1] - 1].push_back(cities[i][0] - 1);
    }

    vector<bool>visited(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            c = 0;
            DFS(i, edge, visited);
            cost2 += (long)c_lib + (c - 1)*(long)c_road;
        }
    }
    return min(cost1, cost2);
}
