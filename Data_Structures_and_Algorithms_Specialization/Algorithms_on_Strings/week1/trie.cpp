#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  int count=1, curr, match=0;

  for(int p=0; p<patterns.size(); p++){    
    curr=0;
    for(int i=0; i<patterns[p].size(); i++){      
      edges e;
      while(t.size()<curr){
        t.push_back(e);
      }
      if(t.size()==curr){
        e.insert({patterns[p][i], count});        
        curr=count;
        count++;
        t.push_back(e);    
      }
      else{
        e = t[curr];
        for(auto it=e.begin(); it != e.end(); it++){
          if((*it).first==patterns[p][i]){
            match =1;
            curr = (*it).second;
            break;            
          }
        }
        if(match==1){
          match=0;
          continue;
        }
        e.insert({patterns[p][i], count});        
        t[curr] = e;
        curr = count;        
        count++;        
      }  
      match=0;
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}