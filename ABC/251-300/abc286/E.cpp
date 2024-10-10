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

int n, q, u, v;
ll a[305];
char s[305][305];

vector<int> graph[305];
bool visited[305][305];
int dist[305][305];
ll val[305][305];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

void solve(int u) {
  val[u][u] = a[u];
  que.push({0, u});
  visited[u][u] = true;

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();
    dist[u][q.second] = q.first;

    for (int next : graph[q.second]) {
      if (!visited[u][next]) {
        dist[u][next] = q.first + 1;
        visited[u][next] = true;
        que.push({q.first + 1, next});
      }

      if (dist[u][next] == q.first + 1) {
        val[u][next] = max(val[u][next], val[u][q.second] + a[next]);
      }
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'Y') {
        graph[i].push_back(j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    solve(i);
  }

  cin >> q;
  while (q--) {
    cin >> u >> v;
    if (visited[u][v]) {
      cout << dist[u][v] << " " << val[u][v] << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}
