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

int n, m, k, p[2005], d[2005], dist[2005][2005];
vector<int> graph[2005];
bool white[2005], black[2005];

void white_search(int start, int d) {
  bool visited[2005] = {};
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        dist[start][next] = dist[start][q] + 1;
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[start][i] < d) {
      white[i] = true;
    }
  }
  return;
}

bool black_search() {
  for (int i = 0; i < k; i++) {
    bool has_candidate = false;
    for (int j = 1; j <= n; j++) {
      if (dist[p[i]][j] == d[i] && !white[j]) {
        has_candidate = true;
        break;
      }
    }

    if (!has_candidate) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> p[i] >> d[i];
    white_search(p[i], d[i]);
  }

  if (black_search()) {
    Yes();
    for (int i = 1; i <= n; i++) {
      if (white[i]) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    cout << endl;
  } else {
    No();
  }

  return 0;
}