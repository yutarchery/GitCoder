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

int n, m, k, t, x[int(2e5 + 5)], y[int(2e5 + 5)];
ll c[int(2e5 + 5)];
int a[int(2e5 + 5)];

vector<Pli> graph[int(2e5 + 5)];
bool have_gym[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
ll dist1[int(2e5 + 5)], dist2[int(2e5 + 5)];

void prepare() {
  fill(visited + 1, visited + n + 1, false);
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;

  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    dist1[q.second] = q.first;

    for (Pli nxt : graph[q.second]) {
      que.push({q.first + nxt.first, nxt.second});
    }
  }

  fill(visited + 1, visited + n + 1, false);
  que.push({0, n});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    dist2[q.second] = q.first;

    for (Pli nxt : graph[q.second]) {
      que.push({q.first + nxt.first, nxt.second});
    }
  }

  return;
}

double calc_time(int gym, ll gym_cnt) {
  double res = dist1[gym];
  res += double(t) * double(gym_cnt);
  res += double(dist2[gym]) / double(gym_cnt + 1);
  return res;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k >> t;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> c[i];

    graph[x[i]].push_back({c[i], y[i]});
    graph[y[i]].push_back({c[i], x[i]});
  }
  prepare();

  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    have_gym[a[i]] = true;
  }

  double ans = dist1[n];
  for (int i = 1; i <= n; i++) {
    if (!have_gym[i]) {
      continue;
    }
    if (!visited[i]) {
      continue;
    }

    ll l = 0, r = ll(1e16);
    while (r - l > 2) {
      ll l1 = (l * 2 + r) / 3, r1 = (l + r * 2) / 3;

      if (calc_time(i, l1) < calc_time(i, r1)) {
        r = r1;
      } else {
        l = l1;
      }
    }

    for (ll j = l; j <= r; j++) {
      ans = min(ans, calc_time(i, j));
    }
  }

  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}
