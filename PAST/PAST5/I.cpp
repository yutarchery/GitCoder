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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, k;
int h[int(2e5 + 5)];

priority_queue<Pii, vector<Pii>, greater<Pii>> que;
vector<int> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
int dist[int(2e5 + 5)];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    que.push({0, c});
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    if (h[a] < h[b]) {
      graph[a].push_back(b);
    } else {
      graph[b].push_back(a);
    }
  }

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    dist[q.second] = q.first;

    for (int next : graph[q.second]) {
      if (!visited[next]) {
        que.push({q.first + 1, next});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      cout << dist[i] << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}