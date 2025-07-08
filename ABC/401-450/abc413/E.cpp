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

int n, p[int(1 << 18)];
vector<vector<int>> ans[20];

void solve() {
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    cin >> p[i];
    ans[0].push_back({p[i]});
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ans[i - 1].size(); j += 2) {
      vector<int> now;
      if (ans[i - 1][j] < ans[i - 1][j + 1]) {
        for (int k : ans[i - 1][j]) {
          now.push_back(k);
        }
        for (int k : ans[i - 1][j + 1]) {
          now.push_back(k);
        }
      } else {
        for (int k : ans[i - 1][j + 1]) {
          now.push_back(k);
        }
        for (int k : ans[i - 1][j]) {
          now.push_back(k);
        }
      }

      ans[i].push_back(now);
    }
  }

  for (int j = 0; j < (1 << n); j++) {
    cout << ans[n][0][j] << (j == (1 << n) - 1 ? '\n' : ' ');
  }

  for (int i = 0; i <= n; i++) {
    ans[i].resize(0);
  }

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
