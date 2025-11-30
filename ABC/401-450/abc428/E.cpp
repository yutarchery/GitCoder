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

int n, a, b;
vector<Pli> graph[int(1e6 + 5)];

bool visited[2][int(1e6 + 5)] = {};
ll dist[2][int(1e6 + 5)] = {};

int farthest(int start) {
  ll now_dist[2 * n + 5] = {};
  bool now_visited[2 * n + 5] = {};

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, start});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (now_visited[q.second]) {
      continue;
    }
    now_dist[q.second] = q.first;
    now_visited[q.second] = true;

    for (Pli next : graph[q.second]) {
      if (!now_visited[next.second]) {
        que.push({q.first + next.first, next.second});
      }
    }
  }

  int ans = 0;
  ll max_dist = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (max_dist < now_dist[i]) {
      ans = i;
      max_dist = now_dist[i];
    }
  }
  return ans;
}

void calc_dist(int start, int idx) {
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, start});

  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited[idx][q.second]) {
      continue;
    }
    visited[idx][q.second] = true;
    dist[idx][q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (!visited[idx][next.second]) {
        que.push({next.first + q.first, next.second});
      }
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back({ll(1e9), b});
    graph[b].push_back({ll(1e9), a});
  }

  for (int i = 1; i <= n; i++) {
    graph[i].push_back({i, i + n});
    graph[i + n].push_back({i, i});
  }

  int f1 = farthest(1);
  calc_dist(f1, 0);
  int f2 = farthest(f1);
  calc_dist(f2, 1);

  for (int i = 1; i <= n; i++) {
    if (dist[0][i] < dist[1][i]) {
      cout << f2 - n << endl;
    } else if (dist[0][i] == dist[1][i]) {
      cout << max(f1 - n, f2 - n) << endl;
    } else {
      cout << f1 - n << endl;
    }
  }

  return 0;
}
