#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;
using std::vector;

bool sortfunc(vector<int> a, vector<int> b){
    return (((double)a[1]/a[0]) > ((double)b[1]/b[0])); 
  }

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector< vector<int> > wv;
  int n = weights.size();
  for(int i=0; i<n;i++){
    vector<int> a;
    a.push_back(weights[i]);
    a.push_back(values[i]);
    wv.push_back(a);
  }

  sort(wv.begin(), wv.end(), sortfunc);

  /*for(int i=0; i != n; i++){
    cout << wv[i][0] <<"   "<<wv[i][1]<<endl;
  }
*/


  for(int i=0; i != n; i++){
    if(capacity>wv[i][0]){
      value += wv[i][1];
      capacity -= wv[i][0];
    }
    else if(capacity >0){
      value += (((double)capacity/wv[i][0]))*wv[i][1];
      break;
    }
  }
  /*for(auto j=wv.begin(); j != wv.end(); j++){
    if(capacity>(*j)[0]){
      value += (*j)[1];
      capacity -= (*j)[0];
    }
    else if(capacity >0){
      value += ((double)(capacity/(*j)[0]))*(*j)[1];
    }
  }*/

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
