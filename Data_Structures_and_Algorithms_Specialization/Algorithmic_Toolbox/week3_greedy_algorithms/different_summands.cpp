#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i=0;
  
  while(n>0){
    i++;      
    n -= i;
    
    if(n<0){
      summands.pop_back();
      summands.push_back(i+n+(i-1));  
    }
    else{
      summands.push_back(i);  
    }
    

  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
