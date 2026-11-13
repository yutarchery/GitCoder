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

int n;
int u[int(2e5 + 5)], v[int(2e5 + 5)];
ll w[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
ll dist[int(2e5 + 5)];
vector<Pli> graph[int(2e5 + 5)];

void prepare(int start = 1) {
  queue<int> que;
  que.push(start);

  visited[start] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (Pli nxt : graph[q]) {
      if (!visited[nxt.second]) {
        visited[nxt.second] = true;
        dist[nxt.second] = (dist[q] ^ nxt.first);
        que.push(nxt.second);
      }
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u[i] >> v[i] >> w[i];

    graph[u[i]].push_back({w[i], v[i]});
    graph[v[i]].push_back({w[i], u[i]});
  }
  prepare();

  ll ans = 0;
  for (int i = 0; i <= 60; i++) {
    ll bits = (1ll << i), cnt0 = 0, cnt1 = 0;

    for (int j = 1; j <= n; j++) {
      if ((bits & dist[j]) == 0) {
        cnt0++;
      } else {
        cnt1++;
      }
    }

    ll now = ((bits % MOD) * ((cnt0 * cnt1) % MOD)) % MOD;
    ans += now;
    ans %= MOD;
  }
  cout << ans << '\n';

  return 0;
}
