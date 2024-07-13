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

int n, k;
string s;

ll dp[1005][1050];

bool judge(int num) {
  vector<int> now;
  for (int i = 0; i < k; i++) {
    now.push_back(num % 2);
    num /= 2;
  }

  for (int i = 0; i < k; i++) {
    if (now[i] == now[k - 1 - i]) {
      continue;
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  cin >> n >> k;
  cin >> s;

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << k); j++) {
      int next = (j * 2) % (1 << k);
      if (s[i - 1] == 'A' || s[i - 1] == '?') {
        if (i < k || judge(next)) {
          dp[i][next] += dp[i - 1][j];
          dp[i][next] %= MOD2;
        }
      }
      if (s[i - 1] == 'B' || s[i - 1] == '?') {
        if (i < k || judge(next + 1)) {
          dp[i][next + 1] += dp[i - 1][j];
          dp[i][next + 1] %= MOD2;
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < (1 << k); j++) {
    ans += dp[n][j];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
