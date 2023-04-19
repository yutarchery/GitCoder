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

int n, m;
ll x_ab, x_ac, x_bc;
string s;

vector<Pli> graph[int(1e5 + 5)];
bool visited[int(1e5 + 5)];
ll dist[int(1e5 + 5)];

void prepare() {
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      graph[i + 1].push_back({0, n + 1});
      graph[n + 2].push_back({x_ab, i + 1});
      graph[n + 3].push_back({x_ac, i + 1});
    } else if (s[i] == 'B') {
      graph[i + 1].push_back({0, n + 2});
      graph[n + 1].push_back({x_ab, i + 1});
      graph[n + 3].push_back({x_bc, i + 1});
    } else {
      graph[i + 1].push_back({0, n + 3});
      graph[n + 1].push_back({x_ac, i + 1});
      graph[n + 2].push_back({x_bc, i + 1});
    }
  }
}

int main() {
  cin >> n >> m;
  cin >> x_ab >> x_ac >> x_bc;
  cin >> s;
  prepare();
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
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
      if (!visited[next.second]) {
        que.push({next.first + q.first, next.second});
      }
    }
  }

  cout << dist[n] << endl;

  return 0;
}