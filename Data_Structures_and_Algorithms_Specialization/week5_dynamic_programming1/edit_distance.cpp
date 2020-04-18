#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
	vector<int> M2;
	vector< vector<int> > M;
	int n = str1.size();
	int m = str2.size();
	int val;

	for(int i=0; i<=m; i++)
		M2.push_back(i);
	M.push_back(M2);

	for(int i=1; i<=n; i++){
		vector<int> M2;
		M2.push_back(i);

		for(int j=1; j<=m; j++){
			if(str1[i-1]==str2[j-1]){
				val = min(M[i-1][j-1], min(M2[j-1]+1, M[i-1][j]+1));
			}
			else{
				val = min(M[i-1][j-1]+1, min(M2[j-1]+1, M[i-1][j]+1));
			}
			M2.push_back(val);
		}
		M.push_back(M2);
	}
	
  //write your code here
  return M[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
