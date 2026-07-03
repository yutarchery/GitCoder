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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

ll bits[61];

ll solve() {
  ll n;
  cin >> n;

  for (int i = 60; i - 1 >= 0; i--) {
    if (bits[i] > n) {
      continue;
    }

    for (int j = i - 1; j - 1 >= 0; j--) {
      if (bits[i] + bits[j] > n) {
        continue;
      }

      for (int k = j - 1; k >= 0; k--) {
        if (bits[i] + bits[j] + bits[k] <= n) {
          return bits[i] + bits[j] + bits[k];
        }
      }
    }
  }

  return -1;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  bits[0] = 1;
  for (int i = 1; i <= 60; i++) {
    bits[i] = bits[i - 1] * 2;
  }

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
