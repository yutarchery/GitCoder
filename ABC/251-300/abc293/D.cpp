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

int n, m, a, c;
char b, d;
vector<int> graph[int(4e5 + 5)];
int group[int(4e5 + 5)], x, y, sum;
bool visited[int(4e5 + 5)];

void solve(int start) {
  if (visited[start]) {
    return;
  }
  visited[start] = true;
  sum++;

  queue<int> que;
  que.push(start);
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        que.push(next);
      }
    }
  }
  return;
}

int findParent(int node) {
  if (group[node] == node) {
    return group[node];
  } else {
    int tmp = group[node];
    return group[node] = findParent(tmp);
  }
}

void unite(int u, int v) {
  int pu = findParent(u), pv = findParent(v);
  group[max(pu, pv)] = min(pu, pv);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n * 2; i++) {
    group[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    unite(i, i + n);
    graph[i].push_back(i + n);
    graph[i + n].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c >> d;
    if (b == 'B') {
      a += n;
    }
    if (d == 'B') {
      c += n;
    }

    if (findParent(a) == findParent(c)) {
      x++;
    }
    unite(a, c);
    graph[a].push_back(c);
    graph[c].push_back(a);
  }
  for (int i = 1; i <= n * 2; i++) {
    solve(i);
  }
  y = sum - x;
  cout << x << " " << y << endl;

  return 0;
}