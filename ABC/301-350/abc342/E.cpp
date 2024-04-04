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

int n, m;
ll l[int(2e5 + 5)], d[int(2e5 + 5)], k[int(2e5 + 5)], c[int(2e5 + 5)];
int a[int(2e5 + 5)], b[int(2e5 + 5)];

vector<Pii> graph[int(2e5 + 5)];
ll ans[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> d[i] >> k[i] >> c[i] >> a[i] >> b[i];
    graph[b[i]].push_back({a[i], i});
  }

  priority_queue<Pli> que;
  que.push({4e18, n});

  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    ans[q.second] = q.first;

    for (Pii g : graph[q.second]) {
      int next = g.first, idx = g.second;
      if (visited[next]) {
        continue;
      }

      ll t = q.first - c[idx];

      if (t < l[idx]) {
        continue;
      } else if (l[idx] + (k[idx] - 1) * d[idx] < t) {
        que.push({l[idx] + (k[idx] - 1) * d[idx], next});
        continue;
      }

      t = t - (t - l[idx]) % d[idx];
      que.push({t, next});
    }
  }

  for (int i = 1; i <= n - 1; i++) {
    if (visited[i]) {
      cout << ans[i] << endl;
    } else {
      cout << "Unreachable" << endl;
    }
  }

  return 0;
}
