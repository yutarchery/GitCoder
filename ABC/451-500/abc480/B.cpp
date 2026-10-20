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

int n, m;
string s[105], t[105];
int ans[105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i];
  }

  for (int i = 1; i <= m; i++) {
    bool flag = false;
    int cnt = 0, target = 0;

    for (int j = 1; j <= n; j++) {
      if (s[j] == t[i]) {
        flag = true;
        ans[j]++;
        break;
      }
      if (s[j].length() != t[i].length()) {
        continue;
      }

      int now = 0;
      for (int k = 0; k < s[j].length(); k++) {
        if (s[j][k] != t[i][k]) {
          now++;
        }
      }

      if (now == 1) {
        cnt++;
        target = j;
      }
    }

    if (flag) {
      continue;
    } else if (cnt == 1) {
      ans[target]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
