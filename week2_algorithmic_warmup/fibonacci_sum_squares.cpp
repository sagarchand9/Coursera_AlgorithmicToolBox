#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current%10;
        previous = previous%10;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {
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
            sumr += current*current;
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
            current = current%num;
            sumr = sumr%num;  
        }    
    }
    return sumr;

}

int fibonacci_sum_squares_fast1(long long n) {
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
            //sumr += current*current;
            long long tmp_previous = previous;
            previous = current;
            current = tmp_previous + current;
            current = current%num;
            //sumr = sumr%num;  
        }    
    }

    long long ans = (current)*(previous);
    return ans;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
