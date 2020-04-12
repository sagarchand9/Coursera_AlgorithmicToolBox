#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int n = a.size();
  int m = b.size();
  vector<int> M2(m+1,0);
  vector< vector<int> > M;
  M.push_back(M2);
  int val;

  for(int i=1; i<=n; i++){
    vector<int> M2;
    M2.push_back(0);
    for(int j=1; j<=m; j++){
      if(a[i-1]==b[j-1]){
        val = max(M[i-1][j-1]+1, max(M[i-1][j], M2[j-1]));
      }
      else{
        val = max(M[i-1][j-1], max(M[i-1][j], M2[j-1]));
      }
      M2.push_back(val);
    }
    M.push_back(M2);
  }

  return M[n][m];
  //write your code here
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
