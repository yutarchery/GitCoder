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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, a[int(2e5 + 5)], u, v;
vector<int> graph[int(2e5 + 5)];

set<int> st;
int dist[int(2e5 + 5)];
bool ans[int(2e5 + 5)];

void solve(int now = 1, bool flag = false) {
  if (!flag) {
    st.insert(a[now]);
  }

  for (int next : graph[now]) {
    if (dist[next] != 0) {
      continue;
    }

    dist[next] = dist[now] + 1;
    if (flag) {
      ans[next] = true;
      solve(next, true);
    } else {
      auto iter = st.find(a[next]);
      if (iter == st.end()) {
        solve(next, false);
      } else {
        ans[next] = true;
        solve(next, true);
      }
    }
  }

  if (!flag) {
    st.erase(a[now]);
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  dist[1] = 1;
  solve();

  for (int i = 1; i <= n; i++) {
    ans[i] ? Yes() : No();
  }

  return 0;
}
