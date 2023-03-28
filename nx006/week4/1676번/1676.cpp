#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <utility>
#include <tuple>

std::vector<int> primeFactorization(int N) {
  std::vector<int> factors;

  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      factors.emplace_back(i);
      N /= i;
    }
  }

  if (N > 1) {
    factors.emplace_back(N);
  }

  return std::move(factors);
}

auto countHowMany2and5(const int N) {
  if (N < 2) return std::make_pair(0, 0);
  const auto primes = primeFactorization(N);

  auto sumOf2 = 0;
  auto sumOf5 = 0;
  for (const auto prime : primes) {
    if (prime == 2) {
      sumOf2++;
    }
    else if (prime == 5) {
      sumOf5++;
    }
    else if (prime > 5) break;
  }


  return std::make_pair(sumOf2, sumOf5);
}

int main()
{
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  auto num = 0;
  std::cin >> num;

  auto sumOf2 = 0;
  auto sumOf5 = 0;

  for (int N = 0; N <= num; N++) {
    auto [partialSum2, partialSum5] = countHowMany2and5(N);
    sumOf2 += partialSum2;
    sumOf5 += partialSum5;
  }

  const auto numberOfZeros = std::min(sumOf2, sumOf5);

  std::cout << numberOfZeros << std::endl;

  return 0;
}