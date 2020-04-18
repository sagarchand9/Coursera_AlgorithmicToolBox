#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool desc(int i, int j){return(i>j);}

int partition3(vector<int> &w) {
	int total = accumulate(w.begin(), w.end(),0);

	sort(w.begin(), w.end(), desc);
	if(total%3 != 0)
		return 0;

	int W = total/3;

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

  	if(A[m][W] != W)
  		return 0;

  	vector<int> w1;
  	int i=m;
  	int j=W;

  	while((i>0)||(j>0)){
  		if(A[i-1][j] == A[i][j]){
  			w1.push_back(w[i-1]);  			
  		}
  		else{
  			j = j-w[i-1];
  		}
  		i--;
  	}


	int m1 = w1.size();
  	vector<int> B1(W+1,0);
  	vector< vector <int> > A1(m1+1,B1);

  	for(int i=1; i<=m1; i++){
    	for(int j=1; j<=W; j++){
      		if(j>=w1[i-1]){
        		A1[i][j] = max(A1[i-1][j], A1[i-1][j-w1[i-1]]+w1[i-1]);
      		}
      		else{
        		A1[i][j] = A1[i-1][j];
      		}  
    	}
  	}

  	if(A1[m1][W] != W)
  		return 0;


  	//write your code here
  	return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
