#include <bits/stdc++.h>

using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree, long long high=2147483657, long long low=-2147483657, int i=0) {
  bool ans = true;
  if(tree.size()==0)
    return(true);
  if((tree[i].key<high)&&(tree[i].key>=low)){
    if(tree[i].left != -1)
      ans = IsBinarySearchTree(tree, tree[i].key, low, tree[i].left);
    if((tree[i].right != -1)&&(ans == true))
      ans = IsBinarySearchTree(tree, high, tree[i].key, tree[i].right);     
  }
  else
    return(false);
  return ans;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
