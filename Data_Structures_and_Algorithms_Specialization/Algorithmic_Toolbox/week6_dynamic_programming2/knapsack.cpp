#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int m = w.size();
  vector<int> B(W+1,0);
  vector< vector <int> > A(m+1,B);

  for(int i=1; i<=m; i++){
    for(int j=1; j<=W; j++){
      if(j>=w[i-1]){
        A[i][j] = max(A[i-1][j], A[i-1][j-w[i-1]]+w[i-1]);
      }
      else{
        A[i][j] = A[i-1][j];
      }  
    }
  }
  return A[m][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
