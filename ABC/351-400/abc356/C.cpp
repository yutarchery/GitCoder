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

int n, m, k, c[105], a;
bool visited[105][20], now[20];
char r[105];

int ans = 0;

void solve(int idx) {
  fill(now, now + n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (idx % 2 == 1) {
      now[i] = true;
    }
    idx /= 2;
  }

  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (visited[i][j] && now[j]) {
        cnt++;
      }
    }

    if (cnt >= k && r[i] == 'x') {
      return;
    }
    if (cnt < k && r[i] == 'o') {
      return;
    }
  }

  ans++;
  return;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    for (int j = 0; j < c[i]; j++) {
      cin >> a;
      visited[i][a] = true;
    }
    cin >> r[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
