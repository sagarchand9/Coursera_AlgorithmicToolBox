#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void siftDown(int currP, int n, int lastP){
    if(2*currP+2>n)
      return;
    if(data_[currP]>data_[2*currP + 1]){
      if(((2*currP + 2)<=(n-1))&&(data_[currP]>data_[2*currP + 2])){
        if(data_[2*currP + 2]<data_[2*currP + 1]){
          swap(data_[2*currP + 2], data_[currP]);
          swaps_.push_back(make_pair(currP, 2*currP + 2));  
          siftDown(2*currP + 2, n, lastP);
        }
        else{
          swap(data_[2*currP + 1], data_[currP]);
          swaps_.push_back(make_pair(currP, 2*currP + 1));      
          siftDown(2*currP + 1, n, lastP);
        }
      }
      else{
        swap(data_[2*currP + 1], data_[currP]);
        swaps_.push_back(make_pair(currP, 2*currP + 1));      
        siftDown(2*currP + 1, n, lastP);
      }   
    }
    else if(((2*currP + 2)<=(n-1))&&(data_[currP]>data_[2*currP + 2])){
      swap(data_[2*currP + 2], data_[currP]);
      swaps_.push_back(make_pair(currP, 2*currP + 2));  
      siftDown(2*currP + 2, n, lastP);
    }
  }

  void GenerateSwapsNew() {
    swaps_.clear();
    
    int n = data_.size();
    int lastP = (n-2)/2;
    int currP = lastP;

    while(currP>=0){
      siftDown(currP, n, lastP);
      currP--;
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwapsNew();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
