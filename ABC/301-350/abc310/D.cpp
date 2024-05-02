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

int n, t, m, a, b, ans = 0;
int team[15];
bool out[15][15];

void dfs(int now, int num_team) {
  if (now == n + 1) {
    if (num_team == t) {
      ans++;
    }
    return;
  }

  for (int i = 1; i <= num_team + 1; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      if (out[now][j] && (team[i] & (1 << (j - 1))) != 0) {
        flag = false;
      }
    }

    if (!flag) {
      continue;
    }

    team[i] += (1 << (now - 1));
    dfs(now + 1, max(num_team, i));
    team[i] -= (1 << (now - 1));
  }
  return;
}

int main() {
  cin >> n >> t >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    out[a][b] = true;
    out[b][a] = true;
  }
  dfs(1, 0);

  cout << ans << endl;

  return 0;
}
