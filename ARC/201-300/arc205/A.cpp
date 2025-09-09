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

int n, q;
char s[505][505];
int u[int(2e5 + 5)], d[int(2e5 + 5)], l[int(2e5 + 5)], r[int(2e5 + 5)];

int cnt[505][505], sum[505][505];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 1; i <= q; i++) {
    cin >> u[i] >> d[i] >> l[i] >> r[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      bool flag = true;
      for (int di = -1; di <= 0; di++) {
        for (int dj = -1; dj <= 0; dj++) {
          if (s[i + di][j + dj] != '.') {
            flag = false;
          }
        }
      }

      if (flag) {
        cnt[i][j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cnt[i][j];
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << sum[d[i]][r[i]] - sum[u[i]][r[i]] - sum[d[i]][l[i]] +
                sum[u[i]][l[i]]
         << endl;
  }

  return 0;
}
