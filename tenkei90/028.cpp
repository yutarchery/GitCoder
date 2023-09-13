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

int n, lx, ly, rx, ry;
int a[1005][1005], sum[1005][1005], ans[int(1e5 + 5)];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> lx >> ly >> rx >> ry;
    lx++;
    ly++;
    rx++;
    ry++;
    a[lx][ly]++;
    a[rx][ly]--;
    a[lx][ry]--;
    a[rx][ry]++;
  }

  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      a[i][j] += a[i][j - 1];
    }
  }

  for (int j = 1; j <= 1000; j++) {
    for (int i = 1; i <= 1000; i++) {
      a[i][j] += a[i - 1][j];
      ans[a[i][j]]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}