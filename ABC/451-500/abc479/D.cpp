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

int n, q, s, t;
ll l[int(3e5 + 5)], r[int(3e5 + 5)];

ll min_l[int(3e5 + 5)], min_r[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;

  for (int i = 2; i <= n; i++) {
    cin >> l[i];
  }

  min_l[n] = l[n];
  for (int i = n - 1; i >= 1; i--) {
    min_l[i] = min(min_l[i + 1], l[i]);
  }

  for (int i = 1; i <= n - 1; i++) {
    cin >> r[i];
  }

  min_r[1] = r[1];
  for (int i = 2; i <= n; i++) {
    min_r[i] = min(min_r[i - 1], r[i]);
  }

  while (q--) {
    cin >> s >> t;
    if (s < t) {
      cout << min(r[s], l[s] + min_r[s]) << '\n';
    } else {
      cout << min(l[s], r[s] + min_l[s]) << '\n';
    }
  }

  return 0;
}
