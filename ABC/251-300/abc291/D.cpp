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

int n, card[int(2e5 + 5)][2];
ll dp[int(2e5 + 5)][2];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> card[i][0] >> card[i][1];
  }
  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (card[i][j] != card[i - 1][k]) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= MOD2;
        }
      }
    }
  }

  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD2 << endl;
  return 0;
}