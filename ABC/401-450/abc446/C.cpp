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

int n, d, a[int(2e5 + 5)], b[int(2e5 + 5)];

void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  deque<Pii> que;
  for (int i = 1; i <= n; i++) {
    que.push_back({a[i], i});

    int now = 0;
    while (!que.empty()) {
      Pii q = que.front();
      que.pop_front();

      if (now + q.first >= b[i]) {
        que.push_front({q.first - (b[i] - now), q.second});
        break;
      } else {
        now += q.first;
      }
    }

    while (!que.empty()) {
      Pii q = que.front();
      if (q.second <= i - d) {
        que.pop_front();
      } else {
        break;
      }
    }
  }

  int ans = 0;
  while (!que.empty()) {
    Pii q = que.front();
    que.pop_front();
    ans += q.first;
  }
  cout << ans << '\n';

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
