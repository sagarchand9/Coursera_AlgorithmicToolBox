#include <iostream>
#include <vector>

using std::vector;
using namespace std;
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);

  b=a;
  int b_i = left, b_j = ave;
  int a_i = left;
  int count = 0;

  /*for(int i=left; i<right; i++){
    cout<<a[i]<<" ";
  }
  cout<<"\n";
  cout<<"left: "<<left<<"  ave: "<<ave<<"  right: "<<right<<"\n";
  */while((b_i<ave)||(b_j<right)){
    if(b_i>=ave){
      a[a_i] = b[b_j];
      a_i++;
      b_j++;
    }
    else if(b_j>=right){
      a[a_i] = b[b_i];
      a_i++;
      b_i++;
      //count++;
    }
    else{
      if(b[b_i]>b[b_j]){        
        a[a_i] = b[b_j];        
        a_i++;
        b_j++;
        count += ave - b_i;
      }
      else{
        a[a_i] = b[b_i];        
        a_i++;
        b_i++;
      }
      
    }
  }


  /*for(int i=left; i<right; i++){
    cout<<a[i]<<" ";
  }
  cout<<"\n"<<count<<"\n\n";
*/
  number_of_inversions +=count;
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
