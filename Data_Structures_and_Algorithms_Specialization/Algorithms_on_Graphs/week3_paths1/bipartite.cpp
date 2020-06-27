#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

queue<pair<int,int>> Q;
unordered_map<int,int> team;

int bipartite(vector<vector<int> > &adj) {
  team[0]=1;
  int flag;
  int top;
  Q.push(make_pair(0,1));
  while(!Q.empty()){
    top = Q.front().first;
    flag = Q.front().second;
    for(int j=0; j<adj[top].size(); j++){
      if(team[adj[top][j]]==flag)
        return(0);
      if(team[adj[top][j]] == 0){
        if(flag == 1){
          team[adj[top][j]] = 2;
          Q.push(make_pair(adj[top][j],2));
        }
        else{
          team[adj[top][j]] = 1;  
          Q.push(make_pair(adj[top][j],1));
        }
          
      }
    }
    Q.pop();
  }
  return 1;
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
  std::cout << bipartite(adj);
}
