#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int count=0;
    int n = stops.size();

    for(int i=1; i<n; i++){
        if((stops[i]-stops[i-1]) > tank)
            return -1;
    }
    if((stops[n-1]+tank)<dist)
        return -1;

    if(tank<stops[0])
        return -1;

    int achievable = tank;

    for(int i=0; i<n; i++){
        if(achievable < stops[i]){
            achievable = stops[i-1] + tank; 
            count++;
        }
    }


    if(achievable < dist)
        return count+1;
    return count;

        
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
