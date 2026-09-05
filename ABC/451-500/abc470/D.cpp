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
int p[int(5e5 + 5)], idx[int(5e5 + 5)];
int op, x, y;

bool is_p = true;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    idx[p[i]] = i;
  }

  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;

      if (is_p) {
        swap(p[x], p[y]);
        swap(idx[p[x]], idx[p[y]]);
      } else {
        swap(idx[x], idx[y]);
        swap(p[idx[x]], p[idx[y]]);
      }
    } else {
      is_p = !is_p;
    }
  }

  if (is_p) {
    for (int i = 1; i <= n; i++) {
      cout << p[i] << (i == n ? '\n' : ' ');
    }
  } else {
    for (int i = 1; i <= n; i++) {
      cout << idx[i] << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}
