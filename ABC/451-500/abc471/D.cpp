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

int q, v;
int op, t[int(3e5 + 5)], w[int(3e5 + 5)];

priority_queue<Pii> que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> q >> v;
  for (int i = 1; i <= q; i++) {
    cin >> op >> t[i];

    if (op == 1) {
      cin >> w[i];
      que.push({w[i] - t[i], i});
    } else {
      if (!que.empty()) {
        Pii q = que.top();

        que.pop();
        cout << min(v, w[q.second] + (t[i] - t[q.second])) << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }

  return 0;
}
