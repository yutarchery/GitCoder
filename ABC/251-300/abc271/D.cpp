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

int n, s, a[105], b[105];
bool dp[105][10005];
string ans;

int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (dp[i - 1][j]) {
        dp[i][j + a[i]] = true;
        dp[i][j + b[i]] = true;
      }
    }
  }

  if (!dp[n][s]) {
    No();
    return 0;
  }

  Yes();
  int now = s;
  for (int i = n; i >= 1; i--) {
    if (now - a[i] >= 0 && dp[i - 1][now - a[i]]) {
      now -= a[i];
      ans += 'H';
    } else {
      now -= b[i];
      ans += 'T';
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}