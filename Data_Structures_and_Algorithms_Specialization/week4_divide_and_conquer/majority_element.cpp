#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  //if (left + 1 == right) return a[left];

  sort(a.begin(), a.end());
  int n = a.size();
  int count=1, ans=1;
  for(int i=1; i<n; i++){
    if(a[i] == a[i-1])
      count++;
    else{
      ans = max(count, ans);
      count = 1;
    }
  }

  ans = max(count, ans);

  if(ans>(n/2))    
    return 1;
  
 
  

  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
