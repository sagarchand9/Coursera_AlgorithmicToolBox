#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n<=0)
        return 0;
    if (n <= 1)
        return n;
    int num = 10;
    long long period = 60;
    long long previous = 0;
    long long current  = 1;
    long long sumr=0;      
    long long nr = n%period;

    if(nr == 0)
        sumr = 0;
    else if(nr ==1)
        sumr = 1;
    else{
        for (int i = 1; i <= nr ; ++i) {
            sumr += current;
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
            current = current%num;
            sumr = sumr%num;  
        }    
    }
    return sumr;

}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int sum1 = fibonacci_sum_fast(to);
    int sum2 = fibonacci_sum_fast(from-1);

    return (sum1-sum2+10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
