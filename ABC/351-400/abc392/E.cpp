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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];
int par[int(2e5 + 5)];

vector<Pii> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)], edge_used[int(2e5 + 5)];

vector<int> edge_rest;
vector<array<int, 3>> ans;

int calc_parent(int num) {
  if (par[num] == num) {
    return num;
  }

  int res = calc_parent(par[num]);
  return par[num] = res;
}

void unite(int u, int v) {
  int pu = calc_parent(u), pv = calc_parent(v);
  par[u] = min(pu, pv);
  par[v] = min(pu, pv);
  par[max(pu, pv)] = min(pu, pv);
  return;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    graph[a[i]].push_back({b[i], i});
    graph[b[i]].push_back({a[i], i});

    unite(a[i], b[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (i != par[i]) {
      continue;
    }

    queue<int> que;
    que.push(i);
    visited[i] = true;
    while (!que.empty()) {
      int now = que.front();
      que.pop();

      for (Pii next : graph[now]) {
        if (edge_used[next.second]) {
          continue;
        }
        if (visited[next.first]) {
          continue;
        }

        edge_used[next.second] = true;
        visited[next.first] = true;
        que.push(next.first);
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    if (!edge_used[i]) {
      edge_rest.push_back(i);
    }
  }

  set<int> st;
  for (int i = 2; i <= n; i++) {
    if (calc_parent(i) == i) {
      st.insert(i);
    }
  }

  for (int e : edge_rest) {
    if (st.empty()) {
      break;
    }

    if (calc_parent(a[e]) == 1) {
      auto iter = st.begin();
      int to = *iter;
      ans.push_back({e, a[e], to});
      st.erase(to);
      unite(to, 1);
    } else {
      ans.push_back({e, a[e], 1});
      st.erase(calc_parent(a[e]));
      unite(a[e], 1);
      unite(b[e], 1);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
  }

  return 0;
}
