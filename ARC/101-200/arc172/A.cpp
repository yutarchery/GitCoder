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

int h, w, n, a[1005];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());

  priority_queue<Pii> que;
  que.push({min(h, w), max(h, w)});

  int now = 1;
  while (!que.empty()) {
    Pii q = que.top();
    que.pop();

    if (q.first >= (1 << a[now])) {
      if (now == n) {
        Yes();
        return 0;
      }

      que.push({min(q.first - (1 << a[now]), (1 << a[now])),
                max(q.first - (1 << a[now]), (1 << a[now]))});
      que.push({min(q.second - (1 << a[now]), q.first),
                max(q.second - (1 << a[now]), q.first)});
      now++;
    } else {
      No();
      return 0;
    }
  }

  return 0;
}
