/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

//code snipppet

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> edge(numCourses, vector<int>());
        
        for(int i = 0; i < prerequisites.size(); i++){
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]]++; // no of requirements
        }
        
        queue<int> q;
        
        int n = 0; // no of courses completed
        
        for(int i = 0; i < numCourses; i++)
            if(in_degree[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            
            int i = q.front();
            q.pop();
            
            n++;
            
            for(int  j = 0; j < edge[i].size(); j++){
                in_degree[edge[i][j]]--;
                
                if(in_degree[edge[i][j]] == 0)
                    q.push(edge[i][j]);
            }
        }
        
        return n == numCourses ;
    }
};
