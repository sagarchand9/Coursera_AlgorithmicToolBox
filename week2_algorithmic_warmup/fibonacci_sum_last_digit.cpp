#include <iostream>
#include <math.h>
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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


int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;
    int num = 10;
    long long period = pisano_period(num);
    long long previous = 0;
    long long current  = 1;
    long long sum      = 0;
    long long sumr=0,sumw=0;      
    //int nw = int(n)/int(period);
    long long nr = n%period;

    /*for (int i = 1; i <= period ; ++i) {
        sum += current;
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current%num;
        sum = sum%num;        
    }*/

    previous = 0;
    current  = 1;

    if(nr == 0)
        sumr = 0;
    else if(nr ==1)
        sumr = 1;
    else{
        for (int i = 1; i <= nr ; ++i) {
            //cout<<i<<" "<<previous<<" "<<current<<" "<<sumr<<"\n" ;
            sumr += current;
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
            current = current%num;
            sumr = sumr%num;  
        }    
    }
    //cout<<previous<<" "<<current<<" "<<sumr<<"\n" ;
    
//    cout<<sum<<"  "<<sumr<<"\n";

  //  sumw = sum*nw + sumr;
    //cout<<nr<<" "<<"sagar"<<"\n";
    return sumr;
    //return period;
    //return sumw%num;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
