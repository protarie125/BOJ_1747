#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

constexpr auto kMaxN = ll{2000000};

ll n;
vb sieve;
vl primes;

bool IsPalin(ll x) {
  vl vec{};
  while (x > 0) {
    vec.push_back(x % 10);
    x /= 10;
  }

  const auto& l = vec.size();
  for (auto i = 0; i < l; ++i) {
    if (vec[i] != vec[l - 1 - i]) return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sieve = vb(kMaxN + 1, true);
  sieve[0] = false;
  sieve[1] = false;

  for (auto i = 2; i <= kMaxN; ++i) {
    if (!sieve[i]) continue;

    primes.push_back(i);

    for (auto j = i + i; j <= kMaxN; j += i) {
      sieve[j] = false;
    }
  }

  cin >> n;

  for (const auto& p : primes) {
    if (p < n) continue;

    if (IsPalin(p)) {
      cout << p;
      return 0;
    }
  }

  return 0;
}