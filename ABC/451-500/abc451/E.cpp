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

int n, a[3005][3005];
priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

int group[3005];
vector<Pii> graph[3005];
int dist[3005][3005];
bool visited[3005][3005];

int calc_group(int u) {
  if (u == group[u]) {
    return u;
  } else {
    int gu = group[u];
    int res = calc_group(gu);
    return group[u] = res;
  }
}

void unite(int u, int v) {
  int gu = calc_group(u), gv = calc_group(v);
  group[u] = min(gu, gv);
  group[v] = min(gu, gv);
  group[max(gu, gv)] = min(gu, gv);

  return;
}

void calc_dist(int start) {
  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.push({0, start});

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();

    if (visited[start][q.second]) {
      continue;
    }

    visited[start][q.second] = true;
    dist[start][q.second] = q.first;

    for (Pii next : graph[q.second]) {
      if (!visited[start][next.second]) {
        que.push({q.first + next.first, next.second});
      }
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
      que.push({a[i][j], {i, j}});
    }
  }

  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();
    int val = q.first, u = q.second.first, v = q.second.second;
    int gu = calc_group(u), gv = calc_group(v);
    if (gu == gv) {
      continue;
    } else {
      graph[u].push_back({val, v});
      graph[v].push_back({val, u});
      unite(u, v);
    }
  }

  for (int i = 1; i <= n; i++) {
    calc_dist(i);
  }

  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dist[i][j] != a[i][j]) {
        No();
        return 0;
      }
    }
  }
  Yes();

  return 0;
}
