/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 
Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/
/*
Intuition

It's natural to try to assign everyone to a group. Let's say people in the first group are red, and people in the second group are blue.

If the first person is red, anyone disliked by this person must be blue. Then, anyone disliked by a blue person is red, then anyone disliked by a red person is blue, and so on.

If at any point there is a conflict, the task is impossible, as every step logically follows from the first step.

*/

class Solution {
public:
   bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       
       arr.assign(N, 0);
       enemy_edge.assign(N, vector<int>());
       visited.assign(N, false);
       
       for(int i = 0; i < dislikes.size(); i++){
           enemy_edge[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
           enemy_edge[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
       }
       
       for(int i = 0; i < N; i++){
           if(enemy_edge[i].size() != 0 && arr[i] == 0)
               bfs(i);
           if(!flag)
               return false;
       }
       
       return true;
   }
private:
    bool flag = true;
    vector<int> arr;
    vector<vector<int>> enemy_edge;
    vector<bool>visited;
    
    void bfs(int i){
        
        queue<int>q;
        q.push(i);
        arr[i] = 1;
        visited[i] = true;
        
        while(!q.empty()){
            int j = q.front();
            q.pop();
            
            for(int k = 0; k < enemy_edge[j].size(); k++){
                
                if(arr[enemy_edge[j][k]] == 0){
                    arr[enemy_edge[j][k]] = arr[j] * (-1);
                }
                
                else if(arr[enemy_edge[j][k]] == arr[j]){
                    flag = false;
                    break;
                }
                
                
                if(!visited[enemy_edge[j][k]]){
                    q.push(enemy_edge[j][k]);
                    visited[enemy_edge[j][k]] = true;
                }    
            }
            
            if(!flag)
                break;
        }
    }
};
