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

int n, m, u, v, w;
char s[int(1e5 + 5)][15];

vector<int> raw_graph[int(1e5 + 5)];
vector<Pii> graph[int(1e5 + 5)][15];
int input_cnt[int(1e5 + 5)][15];

void reset() {
  for (int i = 1; i <= n; i++) {
    raw_graph[i].resize(0);
    for (int j = 1; j <= w; j++) {
      graph[i][j].resize(0);
      input_cnt[i][j] = 0;
    }
  }

  return;
}

bool judge() {
  queue<Pii> que;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= w; j++) {
      if (input_cnt[i][j] == 0) {
        que.push({i, j});
      }
    }
  }

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();
    for (Pii next : graph[q.first][q.second]) {
      input_cnt[next.first][next.second]--;

      if (input_cnt[next.first][next.second] == 0) {
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (input_cnt[i][1] > 0) {
      return true;
    }
  }

  return false;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    raw_graph[u].emplace_back(v);
    raw_graph[v].emplace_back(u);
  }
  cin >> w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }

    for (int j = 1; j + 1 <= w; j++) {
      if (s[i][j] == 'o' && s[i][j + 1] == 'o') {
        graph[i][j].push_back({i, j + 1});
        input_cnt[i][j + 1]++;
      }
    }
    if (s[i][w] == 'o' && s[i][1] == 'o') {
      graph[i][w].push_back({i, 1});
      input_cnt[i][1]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int next : raw_graph[i]) {
      for (int j = 1; j + 1 <= w; j++) {
        if (s[i][j] == 'o' && s[next][j + 1] == 'o') {
          graph[i][j].push_back({next, j + 1});
          input_cnt[next][j + 1]++;
        }
      }
      if (s[i][w] == 'o' && s[next][1] == 'o') {
        graph[i][w].push_back({next, 1});
        input_cnt[next][1]++;
      }
    }
  }

  judge() ? Yes() : No();
  reset();

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
