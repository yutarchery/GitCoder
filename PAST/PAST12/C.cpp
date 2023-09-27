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

double p[3][7], dp[20];

void solve(int value, double now, int turn) {
  if (turn == 3) {
    dp[value] += now;
    return;
  }

  for (int j = 1; j <= 6; j++) {
    solve(value + j, now * p[turn][j], turn + 1);
  }

  return;
}

int main() {

  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= 6; j++) {
      cin >> p[i][j];
      p[i][j] /= double(100);
    }
  }

  solve(0, 1, 0);

  for (int i = 1; i <= 18; i++) {
    cout << setprecision(32) << dp[i] << endl;
  }

  return 0;
}