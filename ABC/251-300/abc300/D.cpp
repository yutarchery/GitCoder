#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll n;

vector<ll> primes;
bool prime[int(1e6 + 5)];
int prime_index[int(1e6 + 5)];

void prepare() {
  bool visited[int(1e6 + 5)] = {};
  for (ll i = 2; i * i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    primes.push_back(i);
    prime[i] = true;
    for (ll j = i; j * j <= n; j += i) {
      visited[j] = true;
    }
  }

  for (ll i = 2; i * i <= n; i++) {
    prime_index[i] = prime_index[i - 1];
    if (prime[i]) {
      prime_index[i]++;
    }
  }

  return;
}

int main() {
  cin >> n;
  prepare();

  ll ans = 0;
  for (int i = 0; i < primes.size(); i++) {
    for (int j = i + 1; j < primes.size(); j++) {
      if (primes[i] * primes[i] * primes[j] * primes[j] > n) {
        break;
      }

      ll m = min(primes[j] - 1,
                 n / (primes[i] * primes[i] * primes[j] * primes[j]));

      ans += max(0, prime_index[m] - prime_index[primes[i]]);
    }
  }

  cout << ans << endl;

  return 0;
}
