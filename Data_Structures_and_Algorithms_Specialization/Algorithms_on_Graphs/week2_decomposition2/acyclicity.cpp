#include <iostream>
#include <vector>

using namespace std;

int flag=0;
void dfs(vector<vector<int> > &adj, vector<int> &visited, int curr){
  if(visited[curr]==2)
    return;

  for(int i=0; i<adj[curr].size(); i++){
    if(visited[adj[curr][i]]==2)
      continue;
    if(visited[adj[curr][i]]==1){
      flag=1;
      return;
    }
    visited[adj[curr][i]] = 1;
    dfs(adj, visited, adj[curr][i]);
  }
  visited[curr]=2;
}
int acyclic(vector<vector<int> > &adj) {
  int res = 1;
  int n = adj.size();
  
  vector<int> visited(n,0); //0->not visited, 1->transition, 2-> visited all neighbours  
  int curr;

  for(int k=0; k<n; k++){
    if(visited[k]==2)
      continue;
    visited[k]=1;
    dfs(adj, visited, k);
  }
  
  return flag;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
