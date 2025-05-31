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
ll c[15];
int k[105], a[105][15];
bool is_able[15][105];

ll ans = 1e18;
void solve(int idx) {
  int cnt[105] = {};
  ll cost = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (is_able[i][j]) {
        cnt[j] += idx % 3;
      }
    }

    cost += c[i] * (idx % 3);
    idx /= 3;
  }

  for (int i = 1; i <= m; i++) {
    if (cnt[i] < 2) {
      return;
    }
  }

  ans = min(ans, cost);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> k[i];
    for (int j = 1; j <= k[i]; j++) {
      cin >> a[i][j];
      is_able[a[i][j]][i] = true;
    }
  }

  for (int i = 0; i < pow(3, n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
