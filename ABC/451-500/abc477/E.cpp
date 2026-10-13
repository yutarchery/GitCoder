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

int n, q;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
vector<Pli> graph[int(2e5 + 5)];

ll sum_a[int(2e5 + 5)];
ll dist_b[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int s, t;

void prepare_b() {
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, n + 1});

  while (!que.empty()) {
    Pli now = que.top();
    que.pop();
    if (visited[now.second]) {
      continue;
    }

    visited[now.second] = true;
    dist_b[now.second] = now.first;

    for (Pli next : graph[now.second]) {
      que.push({now.first + next.first, next.second});
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    graph[i].push_back({a[i], (i % n) + 1});
    graph[(i % n) + 1].push_back({a[i], i});

    sum_a[i] = sum_a[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    graph[n + 1].push_back({b[i], i});
    graph[i].push_back({b[i], n + 1});
  }
  prepare_b();

  while (q--) {
    cin >> s >> t;
    if (s > t) {
      swap(s, t);
    }

    if (t == n + 1) {
      cout << dist_b[s] << '\n';
      continue;
    }

    ll ans = min(sum_a[t - 1] - sum_a[s - 1],
                 sum_a[n] - (sum_a[t - 1] - sum_a[s - 1]));
    ans = min(ans, dist_b[s] + dist_b[t]);

    cout << ans << '\n';
  }

  return 0;
}
