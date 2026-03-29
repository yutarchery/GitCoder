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

int n, m, a[1005], b[1005], c[1005];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (c[a[i]] <= b[i]) {
      ans += c[a[i]];
      c[a[i]] = 0;
    } else {
      ans += b[i];
      c[a[i]] -= b[i];
    }
  }
  cout << ans << "\n";

  return 0;
}
