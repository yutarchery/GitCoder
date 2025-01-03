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

int n, m, u, v;

vector<int> graph[int(2e5 + 5)];
int group[int(2e5 + 5)];
ll cnt[int(2e5 + 5)][2];
bool color[int(2e5 + 5)], visited[int(2e5 + 5)];

int find_parent(int i) {
  if (group[i] == i) {
    return i;
  }

  int gi = find_parent(group[i]);
  return group[i] = gi;
}

void unite(int i, int j) {
  int gi = find_parent(i), gj = find_parent(j);
  group[i] = min(gi, gj);
  group[j] = min(gi, gj);
  group[max(gi, gj)] = min(gi, gj);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    unite(u, v);
  }

  for (int i = 1; i <= n; i++) {
    find_parent(i);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int q = que.front();
      que.pop();
      cnt[group[q]][color[q]]++;
      for (int next : graph[q]) {
        if (!visited[next]) {
          visited[next] = true;
          color[next] = !color[q];
          que.push(next);
        }

        if (color[next] == color[q]) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += n - (cnt[group[i]][color[i]] + graph[i].size());
  }
  cout << ans / 2 << endl;

  return 0;
}
