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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

string k;
int d;

ll dp[int(1e4 + 5)][105][2];

int main() {
  cin >> k >> d;
  int n = k.length();
  int border = 0;

  for (int i = 0; i < 10; i++) {
    if ('0' + i < k[0]) {
      dp[0][i % d][0]++;
    } else if ('0' + i == k[0]) {
      dp[0][i % d][1]++;
      border += i % d;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < d; j++) {
      for (int l = 0; l < 10; l++) {
        dp[i][(j + l) % d][0] += dp[i - 1][j][0];
        dp[i][(j + l) % d][0] %= mod;

        if ('0' + l < k[i]) {
          dp[i][(j + l) % d][0] += dp[i - 1][j][1];
          dp[i][(j + l) % d][0] %= mod;
        }
      }
    }

    int num = k[i] - '0';
    dp[i][(border + num) % d][1] += dp[i - 1][border][1];
    border += num;
    border %= d;
  }

  ll ans = dp[n - 1][0][0] + dp[n - 1][0][1] - 1;
  if (ans < 0) {
    ans += mod;
  }
  cout << ans % mod << endl;

  return 0;
}