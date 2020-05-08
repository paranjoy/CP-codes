/*
Consider an undirected graph consisting of n nodes where each node is labeled from 1 to n and the edge between any 
two nodes is always of length 6. We define node s to be the starting position for a BFS. 
Given a graph, determine the distances from the start node to each of its descendants and return the list in node number order,
ascending. If a node is disconnected, it's distance should be -1.

For example, there are n = 6 nodes in the graph with a starting node s = 1. The list of edges =[[1,2],[2,3],[3,4],[1,5]] and 
each has a weight of 6.

Starting from node n = 1 and creating a list of distances, for nodes 2 to 6 through  we have[6,12,18,6,-1].

Function Description
Define a Graph class with the required methods to return a list of distances.

Constraints:
1 <= q <= 10
2 <= n <= 1000
1 <= m <= (n.(n-1)/2)
1 <= u,v,s <= n

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output
6 6 -1
-1 6

*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        vector<bool>visited;
        vector<int>distance;
        vector<vector<int>>edge;
        Graph(int n) {
           this->visited.assign(n, false);
           this->distance.assign(n, INT_MAX);
           this->edge.assign(n, vector<int>());
        }
    
        void add_edge(int u, int v) {
           this->edge[u].push_back(v);
           this->edge[v].push_back(u); 
        }
    
        vector<int> shortest_reach(int start) {
            
            vector<int>v;
            this->distance[start] = 0;
            this->visited[start] = true;
            queue<pair<int,int>>q;
            q.push(pair<int,int>(start, 0));

            while(!q.empty()){
                int i = q.front().first;
                int d = q.front().second;
                this->distance[i] = d;
                d = d + 6;
                q.pop();
                for(int  j = 0; j < this->edge[i].size(); j++){
                    if(!this->visited[this->edge[i][j]])
                    {
                    q.push(pair<int,int>(this->edge[i][j], d));
                        this->visited[this->edge[i][j]] = true;
                    }
                }
            }
            for(int i = 0; i < this->edge.size(); i++){
                if(this->distance[i] == INT_MAX)
                    v.push_back(-1);
                else
                    v.push_back(this->distance[i]);
            }
            return v;
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }  
    return 0;
}
