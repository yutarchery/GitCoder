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

int n, c[int(3e5 + 5)];
int l[int(3e5 + 5)], r[int(3e5 + 5)], ans[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  l[1] = -1e9;
  for (int i = 2; i <= n; i++) {
    if (c[i] == c[i - 1]) {
      l[i] = l[i - 1];
    } else {
      l[i] = i;
    }
  }

  r[n] = 1e9;
  for (int i = n - 1; i >= 1; i--) {
    if (c[i] == c[i + 1]) {
      r[i] = r[i + 1];
    } else {
      r[i] = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = min(i - (l[i] - 1), (r[i] + 1) - i);
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
