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

int q, op, h;
priority_queue<int, vector<int>, greater<int>> que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> op >> h;
    if (op == 1) {
      que.push(h);
    } else {
      while (!que.empty()) {
        int now = que.top();
        if (now > h) {
          break;
        }
        que.pop();
      }
    }

    cout << que.size() << '\n';
  }

  return 0;
}
