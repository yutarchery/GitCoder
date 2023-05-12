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

int n, x, dist[3005][3005];
vector<Pii> graph[3005];
bool visited[3005][3005];

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
  cin >> n >> x;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  for (int i = 1; i <= n; i++) {
    calc_dist(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == x) {
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}