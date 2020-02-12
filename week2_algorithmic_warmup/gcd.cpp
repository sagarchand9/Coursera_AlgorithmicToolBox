#include <iostream>
using namespace std; 

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int rem = b%a;

  if(rem == 0)
    return a;

  return gcd_fast(rem, a);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  int big = max(a,b);
  int small = min(a,b);
  std::cout << gcd_fast(small, big) << std::endl;
  return 0;
}
