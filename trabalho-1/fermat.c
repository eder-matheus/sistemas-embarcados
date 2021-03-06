#include <stdio.h>
#include <stdlib.h>

/* Iterative Function to calculate (a^n)%p in O(logy) */
int power(int a, unsigned int n, int p) {
  int res = 1; // Initialize result
  a = a % p;   // Update 'a' if 'a' >= p

  while (n > 0) {
    // If n is odd, multiply 'a' with result
    if (n & 1)
      res = (res * a) % p;

    // n must be even now
    n = n >> 1; // n = n/2
    a = (a * a) % p;
  }
  return res;
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(int a, int b) {
  if (a < b)
    return gcd(b, a);
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
int isPrime(unsigned int n, int k) {
  // Corner cases
  if (n <= 1 || n == 4)
    return 0;
  if (n <= 3)
    return 1;

  // Try k times
  while (k > 0) {
    // Pick a random number in [2..n-2]
    // Above corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);

    // Checking if a and n are co-prime
    if (gcd(n, a) != 1)
      return 0;

    // Fermat's little theorem
    if (power(a, n - 1, n) != 1)
      return 0;

    k--;
  }

  return 1;
}

// Driver Program to test above function
int main() {
  int i;
  int k = 3;
  for (i = 1000; i < 10000; i++) {
    isPrime(i, k);
  }
  return 0;
}
