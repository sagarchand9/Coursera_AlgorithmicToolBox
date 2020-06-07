#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int n = adj.size();
  
  vector<int> visited(n,0);
  vector<int> stack;
  int curr;

  for(int k=0; k<n; k++){
    if(visited[k]>0)
      continue;
    res++;
    stack = adj[k];    
    visited[k]=1;  

    for(int i=0; i<stack.size(); i++){
      visited[stack[i]]=1;
    }

    while(!stack.empty()){
      curr = stack.back();
      stack.pop_back();
      for(int i=0; i<adj[curr].size(); i++){
        if(visited[adj[curr][i]]==0){
          visited[adj[curr][i]]=1;
          stack.push_back(adj[curr][i]);
        }
      }
    }
  
  }

  return res;
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
  std::cout << number_of_components(adj);
}
