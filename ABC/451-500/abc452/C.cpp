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

int n, m, a[15], b[15];
string s[int(2e5 + 5)];

bool ok[15][26];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  cin >> m;
  for (int j = 1; j <= m; j++) {
    cin >> s[j];

    for (int i = 1; i <= n; i++) {
      if (s[j].length() == a[i]) {
        ok[i][s[j][b[i] - 1] - 'a'] = true;
      }
    }
  }

  for (int j = 1; j <= m; j++) {
    if (s[j].length() != n) {
      No();
      continue;
    }

    bool flag = true;
    for (int k = 1; k <= n; k++) {
      if (!ok[k][s[j][k - 1] - 'a']) {
        flag = false;
      }
    }

    flag ? Yes() : No();
  }

  return 0;
}
