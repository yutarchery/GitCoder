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

int n;
int u[int(2e5 + 5)], v[int(2e5 + 5)];
ll w[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int dist[int(2e5 + 5)], child[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

void calc_dist(int par = 1) {
  visited[par] = true;
  queue<int> que;
  que.push(par);

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        que.push(next);
        dist[next] = dist[q] + 1;
      }
    }
  }

  return;
}

int calc_child(int now) {
  if (visited[now]) {
    return child[now];
  }

  visited[now] = true;

  int ans = 0;
  for (int next : graph[now]) {
    if (dist[now] < dist[next]) {
      ans += calc_child(next);
    }
  }

  return child[now] = ans + 1;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u[i] >> v[i] >> w[i];

    graph[u[i]].emplace_back(v[i]);
    graph[v[i]].emplace_back(u[i]);
  }

  fill(visited + 1, visited + n + 1, false);
  calc_dist();

  ll ans = 0;
  fill(visited + 1, visited + n + 1, false);
  for (int i = 1; i <= n - 1; i++) {
    ll cu = calc_child(u[i]), cv = calc_child(v[i]);

    if ((n - min(cu, cv)) % 2 == 1 && min(cu, cv) % 2 == 1) {
      ans = ans ^ w[i];
    }
  }
  cout << ans << '\n';

  return 0;
}
