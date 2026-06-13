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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int h, w, k;
char s[505][505];
int sum[505][505];

int my_count(int start_i, int goal_i, int start_j, int goal_j) {
  return sum[goal_i][goal_j] - sum[start_i - 1][goal_j] -
         sum[goal_i][start_j - 1] + sum[start_i - 1][start_j - 1];
}

ll solve(int start_i, int goal_i) {
  ll ans = 0, sj = 1, tj = 1;
  for (ll j = 1; j <= w; j++) {
    sj = max(sj, j);
    tj = max(tj, j);

    if (my_count(start_i, goal_i, j, w) < k) {
      break;
    }

    while (sj <= w && my_count(start_i, goal_i, j, sj) <= k - 1) {
      sj++;
    }
    while (tj <= w && my_count(start_i, goal_i, j, tj) <= k) {
      tj++;
    }
    ans += tj - sj;
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> k;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      sum[i][j] =
          sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] - '0');
    }
  }

  ll ans = 0;
  for (int start_i = 1; start_i <= h; start_i++) {
    for (int goal_i = start_i; goal_i <= h; goal_i++) {
      ans += solve(start_i, goal_i);
    }
  }
  cout << ans << '\n';

  return 0;
}
