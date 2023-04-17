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

int h, w;
ll c, a[1005][1005];

ll cost1[1005][1005], cost2[1005][1005];
ll ans = 1e16;

void solve() {
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cost1[i][j] = min(cost1[i - 1][j] + c, cost1[i][j - 1] + c);
      cost1[i][j] = min(cost1[i][j], a[i][j]);
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cost2[i][j] = min(cost1[i - 1][j], cost1[i][j - 1]) + c + a[i][j];
      ans = min(ans, cost2[i][j]);
    }
  }
}

int main() {
  cin >> h >> w >> c;
  for (int i = 0; i <= h; i++) {
    cost1[i][0] = 1e16;
    cost2[i][0] = 1e16;
  }
  for (int j = 0; j <= w; j++) {
    cost1[0][j] = 1e16;
    cost2[0][j] = 1e16;
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  solve();
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w - j + 1; j++) {
      swap(a[i][j], a[i][w - j + 1]);
    }
  }
  solve();

  cout << ans << endl;

  return 0;
}