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
ll a[25][25], ans = 0;
bool used[25][25];

void solve(int now_i, int now_j, ll val) {
  ans = max(ans, val);

  if (!(1 <= now_i && now_i <= h && 1 <= now_j && now_j <= w)) {
    return;
  }

  int next_i = now_i, next_j = now_j + 1;
  if (next_j > w) {
    next_i = now_i + 1;
    next_j = 1;
  }

  solve(next_i, next_j, val);

  if (now_i + 1 <= h && !used[now_i][now_j] && !used[now_i + 1][now_j]) {
    used[now_i][now_j] = true;
    used[now_i + 1][now_j] = true;
    solve(next_i, next_j, val ^ (a[now_i][now_j] ^ a[now_i + 1][now_j]));
    used[now_i][now_j] = false;
    used[now_i + 1][now_j] = false;
  }

  if (now_j + 1 <= w && !used[now_i][now_j] && !used[now_i][now_j + 1]) {
    used[now_i][now_j] = true;
    used[now_i][now_j + 1] = true;
    solve(next_i, next_j, val ^ (a[now_i][now_j] ^ a[now_i][now_j + 1]));
    used[now_i][now_j] = false;
    used[now_i][now_j + 1] = false;
  }

  return;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
      ans ^= a[i][j];
    }
  }
  solve(1, 1, ans);
  cout << ans << endl;

  return 0;
}
