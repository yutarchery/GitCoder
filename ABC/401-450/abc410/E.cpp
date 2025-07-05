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

int n, h, m, a[3005], b[3005];

bool visited[3005][3005];
int ans[3005][3005];

priority_queue<Pii> que;

int main() {
  cin >> n >> h >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  que.push({h, m});
  while (!que.empty()) {
    Pii q = que.top();
    que.pop();

    int i = q.first, j = q.second;
    if (ans[i][j] == n) {
      break;
    }

    int k = ans[i][j];
    if (i - a[k + 1] >= 0) {
      ans[i - a[k + 1]][j] = max(ans[i - a[k + 1]][j], k + 1);
      if (!visited[i - a[k + 1]][j]) {
        visited[i - a[k + 1]][j] = true;
        que.push({i - a[k + 1], j});
      }
    }

    if (j - b[k + 1] >= 0) {
      ans[i][j - b[k + 1]] = max(ans[i][j - b[k + 1]], k + 1);
      if (!visited[i][j - b[k + 1]]) {
        visited[i][j - b[k + 1]] = true;
        que.push({i, j - b[k + 1]});
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= m; j++) {
      res = max(ans[i][j], res);
    }
  }
  cout << res << endl;

  return 0;
}
