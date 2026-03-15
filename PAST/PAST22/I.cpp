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

int n, a, b, c, d;
ll p[int(2e5 + 5)], q[int(2e5 + 5)];
set<ll> sum, diff;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b >> c >> d;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> q[i];
    sum.insert(p[i] + q[i]);
    diff.insert(p[i] - q[i]);
  }

  sum.insert(-1e16);
  sum.insert(1e16);

  diff.insert(-1e16);
  diff.insert(1e16);

  for (ll i = a; i <= b; i++) {
    for (ll j = c; j <= d; j++) {
      auto sum_i = sum.lower_bound(i + j);
      auto diff_i = diff.lower_bound(i - j);

      if (*sum_i == i + j) {
        cout << '#';
      } else if (*diff_i == i - j) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }

  return 0;
}
