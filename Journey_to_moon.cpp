/*
The member states of the UN are planning to send 2 people to the moon. 
They want them to be from different countries. You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. 
Determine how many pairs of astronauts from different countries they can choose from.

For example, we have the following data on 2 pairs of astronauts, and 4 astronauts total, numbered 0 through 3.

1   2
2   3
Astronauts by country are [0] and [1,2,3]. There are  pairs to choose from: [0,1], [0,2] and [0,3].

Function Description
Complete the journeyToMoon function in the editor below. It should return an integer that represents the number of valid pairs 
that can be formed.

journeyToMoon has the following parameter(s):
n: an integer that denotes the number of astronauts
astronaut: a 2D array where each element astronauts[i] is a 2 element integer array that represents the ID's of 
two astronauts from the same country

1 <= n <= 10^5
1 <= p <= 10^4

Sample Input 0
5 3
0 1
2 3
0 4
Sample Output 0
6

Sample Input 1
4 1
0 2
Sample Output 1
5
*/

// Complete the journeyToMoon function below.
int bfs(int i , vector<bool>& visited, vector<vector<int>>& edge){
  int c = 0;
  queue<int>q;
  q.push(i);
  visited[i] = true;
  c++;
  while(!q.empty()){
      int  j = q.front();
      q.pop() ;
      for(int k = 0; k < edge[j].size(); k++){
        if(!visited[edge[j][k]])
        {
          c++;
          q.push(edge[j][k]);
          visited[edge[j][k]] = true;
        }
      }
  }
  return c;
}

long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int>components;

    vector<vector<int>>edge(n, vector<int>());
    for(int i = 0; i < astronaut.size(); i++){
      edge[astronaut[i][0]].push_back(astronaut[i][1]);
      edge[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    vector<bool>visited(n, false);
    for(int  i = 0; i < n ; i++){
      if(!visited[i]){
        int count;
        if(edge[i].size() == 0)
          count = 1;
        else
          count = bfs(i, visited, edge);
        components.push_back(count);
        //cout<<count<<" ";
      }
    }
    long sum = 0;
    long sum1 = 0;
    for(int  i = 1; i < components.size(); i++){
      sum1 += components[i-1];
      sum += sum1 * components[i];
    }
    return sum;
}
