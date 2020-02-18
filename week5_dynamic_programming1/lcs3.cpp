#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std; 

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int aa = a.size(), bb = b.size(), cc = c.size();
  vector <vector <vector <int> > > Longest(aa + 1,vector <vector<int> >(bb + 1,vector<int>(cc + 1)));

  for (int i = 0; i <= aa; i++) {
    for (int j = 0; j <= bb; j++) {
      for (int k = 0; k <= cc; k++) {
        if (i == 0 || j == 0 || k == 0) {
          Longest[i][j][k] = 0;
          continue;
        }
        else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
          Longest[i][j][k] = Longest[i - 1][j - 1][k - 1] + 1;
          continue;
        }
        else {
          Longest[i][j][k] =
            max( max(Longest[i - 1][j][k], Longest[i][j - 1][k]),
              Longest[i][j][k - 1]);
        }
      }

    }
  }
  return Longest[aa][bb][cc];
}



int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
