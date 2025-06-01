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

ll is_prime(ll num) {
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return i;
    }
  }

  return 1;
}

bool solve(ll num) {
  ll p = is_prime(num);
  if (p == 1) {
    return false;
  }

  while (num % p == 0) {
    num /= p;
  }

  return num > 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    solve(n) ? Yes() : No();
  }

  return 0;
}
