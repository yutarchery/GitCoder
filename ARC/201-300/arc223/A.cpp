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

int n;
ll sum_w, w[65], v[65];

ll sum_v[65];

ll calc(int idx, ll rest) {
  if (idx == 0) {
    return 0;
  }

  if (rest < w[idx]) {
    return calc(idx - 1, rest);
  }

  ll res = sum_v[idx - 1];
  res = max(res, v[idx] + calc(idx - 1, rest - w[idx]));
  return res;
}

ll solve() {
  cin >> n >> sum_w;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    sum_v[i] = sum_v[i - 1] + v[i];
  }

  return calc(n, sum_w);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
