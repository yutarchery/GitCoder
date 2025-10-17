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

int n, m, u, v;
bool graph[15][15];

bool now[15];

void prepare(int idx) {
  for (int i = 1; i <= n; i++) {
    now[i] = idx % 2;
    idx /= 2;
  }
  return;
}

int solve(int idx) {
  prepare(idx);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (graph[i][j] && now[i] == now[j]) {
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u][v] = true;
    graph[v][u] = true;
  }

  int ans = 1e9;
  for (int i = 0; i < (1 << n); i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
