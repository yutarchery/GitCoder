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

int n;
ll d[20][20];

ll dp[(1 << 20)];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> d[i][j];
    }
  }

  ll ans = 0;
  for (int k = 0; k < (1 << n); k++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((k & (1 << i)) == 0 && (k & (1 << j)) == 0) {
          int next = k + (1 << i) + (1 << j);
          dp[next] = max(dp[next], dp[k] + d[i][j]);
          ans = max(ans, dp[next]);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
