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
char s[105][105];
int x[105], y[105], sum[105];

int val = 0;
vector<int> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];

      if (s[i][j] == '0') {
        x[j]++;
      } else {
        y[j]++;
      }
    }
  }

  for (int j = 1; j <= m; j++) {
    if (x[j] == 0 || y[j] == 0) {
      for (int i = 1; i <= n; i++) {
        sum[i]++;
      }
    } else if (x[j] < y[j]) {
      for (int i = 1; i <= n; i++) {
        if (s[i][j] == '0') {
          sum[i]++;
        }
      }
    } else {
      for (int i = 1; i <= n; i++) {
        if (s[i][j] == '1') {
          sum[i]++;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      val = max(val, sum[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (sum[i] == val) {
      ans.push_back(i);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
