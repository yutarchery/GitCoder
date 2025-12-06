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

int n, u[int(2e5 + 5)], d[int(2e5 + 5)], l[int(2e5 + 5)], r[int(2e5 + 5)];

const int m = 2000;
int zero = 0;
int cnt[2005][2005], sum[2005][2005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u[i] >> d[i] >> l[i] >> r[i];

    cnt[u[i]][l[i]]++;
    cnt[d[i] + 1][l[i]]--;
    cnt[u[i]][r[i] + 1]--;
    cnt[d[i] + 1][r[i] + 1]++;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[i][j] += cnt[i][j - 1];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= m; i++) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (cnt[i][j] == 0) {
        zero++;
      }

      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (cnt[i][j] == 1) {
        sum[i][j]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << zero + (sum[d[i]][r[i]] - sum[u[i] - 1][r[i]] -
                    sum[d[i]][l[i] - 1] + sum[u[i] - 1][l[i] - 1])
         << endl;
  }

  return 0;
}
