/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, 
and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? 
If it is impossible, return -1.

 

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
*/
//code snippet
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<pair<int, int>>> edges(N, vector<pair<int, int>>());
        
        for(vector<int> t : times)
            edges[t[0] - 1].push_back({(t[1] - 1), t[2]});
        
        
        vector<int> t (N, INT_MAX);
        
        queue<int> q;
        
        q.push(K-1);
        t[K-1] = 0;
        
        while(!q.empty()){
            int n = q.front();
            int time = t[n];
            
            q.pop();
            
            for(pair<int, int> p : edges[n]){
                if(time + p.second < t[p.first] ){
                    q.push(p.first);
                    t[p.first] = time + p.second;
                }
            }
 
        }
        
        int max = -1;
        
        for(int  i = 0; i < N; i++){
            if(t[i] == INT_MAX)
                return -1;
            max = t[i] > max ? t[i] : max;
        }
        
        return max;
    }
};
