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

int n, m;
ll x[40], y[40], c[40];

typedef pair<double, int> Pdi;
vector<Pdi> graph[40];
priority_queue<Pdi, vector<Pdi>, greater<Pdi>> que;

ll dist[40];
double ans = 1e18;
bool visited[40], ok[40];

void solve(int num) {
  fill(visited, visited + n + m + 1, false);
  fill(ok + n + 1, ok + n + m + 1, false);

  for (int i = n + 1; i <= n + m; i++) {
    if (num % 2 == 1) {
      ok[i] = true;
    }
    num /= 2;
  }

  que.push({0, 1});
  double now = 0;
  while (!que.empty()) {
    Pdi q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    now += q.first;

    for (Pdi next : graph[q.second]) {
      if (ok[next.second] && !visited[next.second]) {
        que.push(next);
      }
    }
  }

  ans = min(ans, now);

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n + m; i++) {
    cin >> x[i] >> y[i] >> c[i];
  }
  for (int i = 1; i <= n + m; i++) {
    for (int j = i + 1; j <= n + m; j++) {
      ll dist2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      double dist = sqrt(dist2);

      if (c[i] == c[j]) {
        graph[i].push_back({dist, j});
        graph[j].push_back({dist, i});
      } else {
        graph[i].push_back({dist * 10, j});
        graph[j].push_back({dist * 10, i});
      }
    }
  }

  fill(ok + 1, ok + n + 1, true);
  for (int i = 0; i < (1 << m); i++) {
    solve(i);
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
