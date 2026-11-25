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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
int q, t[int(2e5 + 5)], e[int(2e5 + 5)];
ll x[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int dist[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

ll sum[int(2e5 + 5)];

void prepare(int start = 1) {
  queue<int> que;
  visited[start] = true;
  que.push(start);

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int nxt : graph[q]) {
      if (visited[nxt]) {
        continue;
      }

      visited[nxt] = true;
      dist[nxt] = dist[q] + 1;
      que.push(nxt);
    }
  }

  return;
}

void solve(int start = 1) {
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int nxt : graph[q]) {
      if (dist[q] > dist[nxt]) {
        continue;
      }

      sum[nxt] += sum[q];
      que.push(nxt);
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
    cin >> a[i] >> b[i];
    graph[a[i]].emplace_back(b[i]);
    graph[b[i]].emplace_back(a[i]);
  }
  prepare();

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i] >> e[i] >> x[i];

    if (t[i] == 1) {
      if (dist[a[e[i]]] < dist[b[e[i]]]) {
        sum[1] += x[i];
        sum[b[e[i]]] -= x[i];
      } else {
        sum[a[e[i]]] += x[i];
      }
    } else {
      if (dist[a[e[i]]] < dist[b[e[i]]]) {
        sum[b[e[i]]] += x[i];
      } else {
        sum[1] += x[i];
        sum[a[e[i]]] -= x[i];
      }
    }
  }

  solve();
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << '\n';
  }

  return 0;
}
