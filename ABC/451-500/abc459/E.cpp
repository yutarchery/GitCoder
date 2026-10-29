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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return (a * my_pow(a, n - 1, mod)) % mod;
  }
}

int n, p[int(2e5 + 5)];
ll c[int(2e5 + 5)], d[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
int dist[int(2e5 + 5)];
ll sum_c[int(2e5 + 5)], sum_d[int(2e5 + 5)];

void search(int node = 1) {
  sum_c[node] += c[node];
  sum_d[node] += d[node];
  for (int next : graph[node]) {
    dist[next] = dist[node] + 1;
    search(next);

    sum_c[node] += sum_c[next];
    sum_d[node] += sum_d[next];
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    graph[p[i]].emplace_back(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  search();

  priority_queue<Pli> que;
  for (int i = 1; i <= n; i++) {
    que.push({dist[i], i});
  }

  ll ans = 1;
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    ll now_c = sum_c[q.second] - (sum_d[q.second] - d[q.second]);

    ll now_head = 1, now_bottom = 1;
    for (ll i = 1; i <= d[q.second]; i++) {
      now_head *= (now_c - i + 1) % MOD2;
      now_head %= MOD2;

      now_bottom *= i;
      now_bottom %= MOD2;
    }

    ans *= now_head;
    ans %= MOD2;

    ans *= my_pow(now_bottom, MOD2 - 2, MOD2);
    ans %= MOD2;
  }

  cout << ans << '\n';

  return 0;
}
