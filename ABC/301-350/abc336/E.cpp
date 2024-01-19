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

ll n, dp1[20][150][150], dp2[20][150][150];

void reset() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 150; j++) {
      for (int k = 0; k < 150; k++) {
        dp1[i][j][k] = 0;
        dp2[i][j][k] = 0;
      }
    }
  }
  return;
}

ll solve(int sum) {
  ll rest = n, digit = 1, digit_cnt = 1;
  while (digit * 10 <= n) {
    digit *= 10;
    digit_cnt++;
  }

  dp2[0][0][0] = 1;
  for (int i = 1; i <= digit_cnt; i++) {
    for (int j = 0; j < 150; j++) {
      for (int k = 0; k < 150; k++) {
        for (int l = 0; l <= 9; l++) {
          dp1[i][j + l][(10 * k + l) % sum] += dp1[i - 1][j][k];
        }
      }
    }

    int l_max = rest / digit;
    for (int j = 0; j < 150; j++) {
      for (int k = 0; k < 150; k++) {
        for (int l = 0; l < l_max; l++) {
          dp1[i][j + l][(10 * k + l) % sum] += dp2[i - 1][j][k];
        }
        dp2[i][j + l_max][(10 * k + l_max) % sum] += dp2[i - 1][j][k];
      }
    }

    rest %= digit;
    digit /= 10;
  }

  return dp1[digit_cnt][sum][0] + dp2[digit_cnt][sum][0];
}

int main() {
  cin >> n;

  ll ans = 0;
  for (int i = 1; i < 150; i++) {
    reset();
    ans += solve(i);
  }
  cout << ans << endl;

  return 0;
}
