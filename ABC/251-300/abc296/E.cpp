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

struct UnionFind {
private:
  int n;
  int parent[int(2e5 + 5)];

public:
  void prepare(int nodeNum) {
    n = nodeNum;
    for (int i = 1; i <= nodeNum; i++) {
      parent[i] = i;
    }
    return;
  }

  int searchParent(int u) {
    if (parent[u] == u) {
      return u;
    } else {
      int tmp = parent[u];
      return parent[u] = searchParent(tmp);
    }
  }

  void unite(int u, int v) {
    int pu = searchParent(u), pv = searchParent(v);
    parent[max(pu, pv)] = min(pu, pv);
    return;
  }
};

int n, a[int(2e5 + 5)];
UnionFind uf;
vector<int> graph[int(2e5 + 5)];
bool first_visited[int(2e5 + 5)], second_visited[int(2e5 + 5)],
    searched[int(2e5 + 5)];

void secondSearch(int node) {
  for (int next : graph[node]) {
    if (second_visited[next]) {
      continue;
    }
    second_visited[next] = true;
    secondSearch(next);
  }
  return;
}

void firstSearch(int node) {
  for (int next : graph[node]) {
    if (second_visited[next]) {
      continue;
    }
    if (first_visited[next]) {
      second_visited[next] = true;
      secondSearch(next);
    } else {
      first_visited[next] = true;
      firstSearch(next);
    }
  }
  return;
}

int main() {
  cin >> n;
  uf.prepare(n);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    graph[i].push_back(a[i]);
    uf.unite(i, a[i]);
  }

  for (int i = 1; i <= n; i++) {
    int pi = uf.searchParent(i);
    if (!searched[pi]) {
      searched[pi] = true;
      first_visited[i] = true;
      firstSearch(i);
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (second_visited[i]) {
      res++;
    }
  }
  cout << res << endl;

  return 0;
}