#include <iostream>
#include <vector>

using namespace std;

void max_sliding_window(vector<int> const & A, int w) {
    vector<pair<int,int>> q;
    q.push_back(make_pair(A[0], 0));
    int temp;

    for(int i=1; i<w; i++){        
        if((A[i]<q.back().first)){
            q.push_back(make_pair(A[i], i));
        }
        else{

            while((!q.empty())&&(q.back().first <= A[i])){
                q.pop_back();
            }
            q.push_back(make_pair(A[i], i));
        }
    }    
    cout<<q.front().first;
    int f=0;

    for(int i=w; i<A.size(); i++){ 
        cout<<" ";
        if(i == (w+q[f].second)){
            //q.erase(q.begin());
            f++;
        }

        if((q.size()<=f)||(A[i]<q.back().first)){
            q.push_back(make_pair(A[i], i));
        }
        else{
            while((q.size()>f)&&(q.back().first <= A[i])){
                q.pop_back();
            }
            q.push_back(make_pair(A[i], i));
        }
        
        cout<<q[f].first;
    }

    return;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
