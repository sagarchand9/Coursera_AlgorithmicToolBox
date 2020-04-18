#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> B;
  B.push_back(0);
  B.push_back(0);
  vector< vector<int> > A;
  A.push_back(B);
  vector<int> sequence;
  int mi, prev;

  for(int i=1; i<=n; i++){
    mi = A[i-1][0];
    prev = i-1;
    if (i % 3 == 0) {
      if(A[i/3][0]<mi){
        mi = A[i/3][0];
        prev = i/3;
      }
    }  
    if (i % 2 == 0) {
      if(A[i/2][0]<mi){
        mi = A[i/2][0];
        prev = i/2;
      }
    }  
    vector<int> temp;
    temp.push_back(mi+1);
    temp.push_back(prev);
    A.push_back(temp);
  }

  int index = A.size()-1;
  while(index>0){
    sequence.push_back(index);
    index = A[index][1];
  }
 

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
