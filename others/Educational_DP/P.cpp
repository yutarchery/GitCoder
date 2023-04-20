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

int n, dist[int(1e5 + 5)];
vector<int> graph[int(1e5 + 5)];
ll dp[int(1e5 + 5)][2];
bool visited[int(1e5 + 5)];

void calc_dist(int node) {
  for (int next : graph[node]) {
    if (!visited[next]) {
      visited[next] = true;
      dist[next] = dist[node] + 1;
      calc_dist(next);
    }
  }
  return;
}

void coloring(int node) {
  if (visited[node]) {
    return;
  }

  visited[node] = true;
  ll white = 1, black = 1;
  for (int next : graph[node]) {
    if (dist[next] == dist[node] + 1) {
      coloring(next);
      white *= dp[next][0] + dp[next][1];
      white %= mod;

      black *= dp[next][0];
      black %= mod;
    }
  }

  dp[node][0] = white;
  dp[node][1] = black;

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  visited[1] = true;
  calc_dist(1);

  fill(visited, visited + n + 1, false);
  coloring(1);

  cout << (dp[1][0] + dp[1][1]) % mod << endl;

  return 0;
}