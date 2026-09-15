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

int n, m, x[int(2e5 + 5)], y[int(2e5 + 5)];
ll c[int(2e5 + 5)];

const int offset = int(2e5);
vector<Pli> graph[int(6e5 + 5)];
bool visited[int(6e5 + 5)];
ll dist[int(6e5 + 5)];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> c[i];

    graph[i].push_back({c[i], offset + x[i]});
    graph[2 * offset + y[i]].push_back({0, i});
  }

  for (int i = 1; i <= n; i++) {
    graph[offset + i].push_back({0, 2 * offset + i});
    graph[2 * offset + i].push_back({0, offset + i});
  }

  ll ans = INF;

  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    dist[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      que.push({q.first + next.first, next.second});
      if (next.second == 1) {
        ans = min(ans, q.first + next.first);
      }
    }
  }

  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}
