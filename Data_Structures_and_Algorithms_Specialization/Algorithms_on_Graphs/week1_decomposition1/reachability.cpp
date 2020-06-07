#include <iostream>
#include <vector>

using namespace std;

int reach(vector<vector<int> > &adj, int x, int y) {
  int n = adj.size();
  vector<int> visited(n,0);
  visited[x]=1;
  vector<int> stack;
  stack = adj[x];
  for(int i=0; i<stack.size(); i++){
    visited[stack[i]]=1;
  }

  int curr;
  while((!stack.empty())&&(visited[y]==0)){
    curr = stack.back();
    stack.pop_back();
    for(int i=0; i<adj[curr].size(); i++){
      if(visited[adj[curr][i]]==0){
        visited[adj[curr][i]]=1;
        stack.push_back(adj[curr][i]);
      }
    }
  }

  return visited[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
