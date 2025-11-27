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

int n, m, q, k, a[25], u, v, s[int(2e5 + 5)], t[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int dist[25][int(2e5 + 5)];
bool visited[25][int(2e5 + 5)];

void prepare(int idx, int start) {
  visited[idx][start] = true;
  queue<int> que;
  que.push(start);
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[idx][next]) {
        visited[idx][next] = true;
        dist[idx][next] = dist[idx][q] + 1;
        que.push(next);
      }
    }
  }

  return;
}

int main() {
  cin >> n >> m >> q >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= q; i++) {
    cin >> s[i] >> t[i];
  }

  for (int i = 1; i <= k; i++) {
    prepare(i, a[i]);
  }

  for (int i = 1; i <= q; i++) {
    int ans = 1e9;
    for (int j = 1; j <= k; j++) {
      ans = min(ans, dist[j][s[i]] + dist[j][t[i]]);
    }
    cout << ans << endl;
  }

  return 0;
}
