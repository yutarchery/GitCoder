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
ll a[int(3e5 + 5)];
int p[int(3e5 + 5)];

vector<int> graph[int(3e5 + 5)];
int dist[int(3e5 + 5)];
ll sum[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    graph[p[i]].emplace_back(i);
    graph[i].emplace_back(p[i]);
  }

  queue<int> que;
  que.push(1);
  dist[1] = 1;

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int nxt : graph[q]) {
      if (dist[nxt] == 0) {
        dist[nxt] = dist[q] + 1;
        que.push(nxt);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    sum[dist[i]] += a[i];
  }

  for (int i = n; i >= 1; i--) {
    if (sum[i] == 0) {
      continue;
    }

    if (sum[i] > 0) {
      cout << '+' << '\n';
      return 0;
    } else {
      cout << '-' << '\n';
      return 0;
    }
  }

  if (a[1] > 0) {
    cout << '+' << '\n';
  } else if (a[1] == 0) {
    cout << 0 << '\n';
  } else {
    cout << '-' << '\n';
  }

  return 0;
}
