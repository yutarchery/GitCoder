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

ll l, r;

vector<ll> primes;
map<ll, ll> rest;

bool visited[int(1e7 + 5)], prime_visited[int(2e7 + 5)];

void make_primes(ll m) {
  for (ll i = 2; i * i <= m; i++) {
    if (prime_visited[i]) {
      continue;
    }

    primes.push_back(i);
    for (ll j = i; j * j <= m; j += i) {
      prime_visited[j] = true;
    }
  }
  return;
}

int main() {
  cin >> l >> r;
  make_primes(r + 100);

  int ans = 1;
  visited[0] = true;
  for (ll p : primes) {
    ll m = l / p;
    for (ll i = (l / p) * p; i <= r; i += p) {
      if (i < l) {
        continue;
      }
      if (visited[i - l]) {
        continue;
      }

      visited[i - l] = true;
      ll rest = i;
      while (rest % p == 0) {
        rest /= p;
      }
      if (rest == 1) {
        ans++;
      }
    }
  }

  for (ll i = l; i <= r; i++) {
    if (!visited[i - l]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
