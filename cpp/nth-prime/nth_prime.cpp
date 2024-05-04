#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <stdexcept>
#include "nth_prime.h"

namespace nth_prime {
  int sieve_of_eratosthenes(const int n, std::vector<int> range) {
    int prime_count = 0;

    for (std::vector<int>::iterator prime_iterator = range.begin(); prime_iterator < range.end(); std::advance(prime_iterator, 1)) {
      if (++prime_count == n) {
        return *prime_iterator;
      }

      for (std::vector<int>::iterator multiple_iterator = std::next(prime_iterator, 1); multiple_iterator < range.end(); std::advance(multiple_iterator, 1)) {
        if (*multiple_iterator % *prime_iterator == 0) {
          range.erase(multiple_iterator);
        }
      }
    }

    return 0;
  }

  int nth(int n) {
    if (n < 1) {
      throw std::domain_error("Error");
    }

    std::vector<int> range(105000);
    std::iota(std::begin(range), std::end(range), 2);

    return sieve_of_eratosthenes(n, range);
  }
}  // namespace nth_prime
