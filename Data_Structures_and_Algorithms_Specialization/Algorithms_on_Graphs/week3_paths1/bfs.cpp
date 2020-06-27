#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

queue<pair<int,int>> Q;
unordered_map<int,bool> visited;

int distance(vector<vector<int> > &adj, int s, int t) {
  Q.push(make_pair(s,0));
  visited[s]=true;
  int top;

  while(!Q.empty()){
    top = Q.front().first;
    for(int i=0; i<adj[top].size(); i++){
      if(adj[top][i] == t)
        return(Q.front().second+1);
      if(visited[adj[top][i]] != true){
        visited[adj[top][i]] = true;
        Q.push(make_pair(adj[top][i], Q.front().second+1));
      }        
    }
    Q.pop();
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
