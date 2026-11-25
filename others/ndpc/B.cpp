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

int n, m, u[int(2e5 + 5)], v[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int cnt_in[int(2e5 + 5)];

ll ans[int(2e5 + 5)];

ll solve() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }
  fill(ans + 1, ans + n + 1, 0);
  fill(cnt_in + 1, cnt_in + n + 1, 0);

  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];

    cnt_in[v[i]]++;
    graph[u[i]].emplace_back(v[i]);
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (cnt_in[i] == 0) {
      que.push(i);
    }
  }

  ans[1] = 1;
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int nxt : graph[q]) {
      cnt_in[nxt]--;
      ans[nxt] += ans[q];
      ans[nxt] %= MOD2;

      if (cnt_in[nxt] == 0) {
        que.push(nxt);
      }
    }
  }

  return ans[n];
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
