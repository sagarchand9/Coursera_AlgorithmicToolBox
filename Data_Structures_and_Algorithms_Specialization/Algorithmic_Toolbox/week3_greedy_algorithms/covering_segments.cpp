#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool sort_segment(Segment a, Segment b){
  return(a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), sort_segment);

  int n = segments.size();
  int t = segments[0].end;
  points.push_back(t);

  for(int i=0; i < n; i++){
    if(t < segments[i].start){
      t = segments[i].end;
      points.push_back(t);  
    }
  }

  //write your code here
  /*for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
