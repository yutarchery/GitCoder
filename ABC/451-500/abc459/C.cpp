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

int n, q, op, x, y;

int now[int(3e5 + 5)], sum[int(3e5 + 5)], offset = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  now[0] = n;
  fill(sum, sum + q + 2, n);

  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      sum[now[x]]--;
      now[x]++;

      if (sum[offset] == 0) {
        offset++;
      }
    } else {
      cin >> y;
      if (offset + y <= q) {
        cout << sum[q] - sum[offset + y - 1] << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }

  return 0;
}
