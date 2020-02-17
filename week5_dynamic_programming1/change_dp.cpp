#include <iostream>
#include <vector>
using namespace std;
int get_change(int m) {
	vector <int> A(m+1,0);
	
	for(int i=1; i<=m; i++){
		if(i<3)
			A[i] = A[i-1]+1;
		else if(i<4)
			A[i] = min(A[i-1], A[i-3])+1;
		else
			A[i] = min(min(A[i-1], A[i-3]), A[i-4])+1;

	}
  //write your code here
  return A[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
