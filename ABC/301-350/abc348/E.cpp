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
vector<int> graph[int(1e5 + 5)];
ll c[int(1e5 + 5)], sum;

ll dist[int(1e5 + 5)];
bool visited[int(1e5 + 5)];
ll ans[int(1e5 + 5)], val[int(1e5 + 5)];

void prepare(int root) {
  queue<int> que;
  que.push(root);
  visited[root] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int next : graph[now]) {
      if (visited[next]) {
        continue;
      }
      visited[next] = true;
      dist[next] = dist[now] + 1;
      que.push(next);
    }
  }

  return;
}

ll prepare_minus(int node) {
  ll res = c[node];
  for (int next : graph[node]) {
    if (dist[next] < dist[node]) {
      continue;
    }
    res += prepare_minus(next);
  }

  return val[node] = res;
}

void solve(int root) {
  for (int i = 1; i <= n; i++) {
    ans[root] += dist[i] * c[i];
  }

  queue<int> que;
  que.push(root);

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      if (dist[now] > dist[next]) {
        continue;
      }

      ans[next] = ans[now] + sum - 2 * val[next];
      que.push(next);
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  fill(visited + 1, visited + n + 1, false);
  prepare(1);
  prepare_minus(1);
  solve(1);
  sort(ans + 1, ans + n + 1);
  cout << ans[1] << endl;

  return 0;
}
