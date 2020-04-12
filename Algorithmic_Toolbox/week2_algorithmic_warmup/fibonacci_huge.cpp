#include <iostream>
#include <math.h> 

using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current % m;
    }

    return current % m;
}

long long pisano_period(long long m){
    long long p=0,c=1,temp;
    for(long long i=0; i<=m*m; i++){
        temp = p;
        p = c;
        c = (c+temp)%m;

        if((p==0)&&(c==1)){
            return i+1;
        }
    }


}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long period = pisano_period(m);
    long long n1 = n % period;
    long long ans = get_fibonacci_huge_naive(n1,m);
    return ans;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
