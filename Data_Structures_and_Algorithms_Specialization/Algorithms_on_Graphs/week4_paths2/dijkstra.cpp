#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, vector<vector<int> > &c, int s, int t) {
  vector<int> vis(adj.size(),-1);
  vector<int> cost(adj.size(),-1);
  vis[s] = 1;
  cost[s] = 0;
  int curr = s;

  /*for(int i=0; i<adj.size(); i++){
    for(int j=0; )
  }*/
  while(vis[t]==-1){
    for(int i=0; i<adj[curr].size(); i++){
      if(cost[adj[curr][i]]==-1){
        //cout<<curr<<" "<<adj[curr][i]<<" "<<c[curr][i]<<" "<<cost[curr]<<"\n";
        cost[adj[curr][i]] = c[curr][i] + cost[curr];
      }
      else{
        cost[adj[curr][i]] = min(cost[adj[curr][i]], c[curr][i] + cost[curr]); 
      }
    }
    curr=-1;

    /*for(int i=0; i<adj.size(); i++){
      cout<<cost[i]<<" ";
    }
    cout<<"\n";*/

    for(int i=0; i<adj.size(); i++){
      if(cost[i]>0){
        if(vis[i]==-1){
          if(curr==-1)
            curr = i;
          else{
            if(cost[curr]>cost[i]){
              curr = i;
            }
          }
        }
      }
    }
    if(curr==-1)
      return -1;
    vis[curr]=1;
  }


  return cost[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
