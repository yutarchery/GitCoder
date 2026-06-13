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

int n, k, m, c[int(2e5 + 5)];
ll v[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
priority_queue<Pli> f_que, s_que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> v[i];
    f_que.push({v[i], c[i]});
  }

  ll ans = 0;
  int cnt = 0;
  while (cnt < m) {
    Pli q = f_que.top();
    f_que.pop();

    if (visited[q.second]) {
      s_que.push(q);
    } else {
      visited[q.second] = true;
      ans += q.first;
      cnt++;
    }
  }
  while (!f_que.empty()) {
    Pli q = f_que.top();
    f_que.pop();
    s_que.push(q);
  }

  while (cnt < k) {
    Pli q = s_que.top();
    s_que.pop();

    ans += q.first;
    cnt++;
  }
  cout << ans << '\n';

  return 0;
}
