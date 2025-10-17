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

int n, m, k, u, v;
char s[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)][25];
bool dp[int(2e5 + 5)][25];

bool judge(int now, int rest) {
  if (visited[now][rest]) {
    return dp[now][rest];
  }

  visited[now][rest] = true;
  if (rest == 0) {
    if (s[now] == 'A') {
      return dp[now][rest] = true;
    } else {
      return dp[now][rest] = false;
    }
  }

  if (rest % 2 == 0) {
    bool ans = false;
    for (int next : graph[now]) {
      ans = ans | judge(next, rest - 1);
    }
    return dp[now][rest] = ans;

  } else {
    bool ans = true;
    for (int next : graph[now]) {
      ans = ans & judge(next, rest - 1);
    }
    return dp[now][rest] = ans;
  }
}

bool solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  return judge(1, 2 * k);
}

void reset() {
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
    fill(visited[i], visited[i] + 2 * k + 1, false);
    fill(dp[i], dp[i] + 2 * k + 1, false);
  }

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << (solve() ? "Alice" : "Bob") << endl;
    reset();
  }

  return 0;
}
