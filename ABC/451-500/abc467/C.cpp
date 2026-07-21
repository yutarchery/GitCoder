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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];
int c[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> b[i];
  }

  int ans = n;
  for (int j = 0; j < m; j++) {
    c[1] = j;

    for (int i = 2; i <= n; i++) {
      c[i] = (b[i - 1] - c[i - 1]) % m;
      if (c[i] < 0) {
        c[i] += m;
      }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      int now = (c[i] - a[i]) % m;
      if (now < 0) {
        now += m;
      }
      cnt += now;
    }
    ans = min(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}
