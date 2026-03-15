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

int n, m, a[int(3e5 + 5)], b[int(3e5 + 5)];
map<int, int> a_idx;
int loc[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a_idx[a[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    loc[i] = a_idx[b[i]];
  }

  ll ans = 0;
  for (int i = 2; i <= m; i++) {
    ans += abs(loc[i] - loc[i - 1]);
  }
  cout << ans << '\n';

  return 0;
}
