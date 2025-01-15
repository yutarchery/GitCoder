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

int n, m;
string s[1005];
ll c[1005];

ll ans[(1 << 10)];

int main() {
  cin >> n >> m;
  fill(ans, ans + (1 << n), 1e16);
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> c[i];

    int idx = 0;
    for (int j = 0; j < n; j++) {
      idx *= 2;
      if (s[i][j] == 'Y') {
        idx++;
      }
    }
    ans[idx] = min(ans[idx], c[i]);
  }

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      ans[(i | j)] = min(ans[(i | j)], ans[i] + ans[j]);
    }
  }

  if (ans[(1 << n) - 1] == 1e16) {
    cout << -1 << endl;
  } else {
    cout << ans[(1 << n) - 1] << endl;
  }

  return 0;
}
