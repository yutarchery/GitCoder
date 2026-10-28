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

int h, w, a[10][10], b[10][10];
int order_h[10], order_w[10];

bool solve() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    order_h[i] = i;
  }
  for (int j = 1; j <= w; j++) {
    order_w[j] = j;
  }

  do {
    do {
      bool flag = true;
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
          if (a[order_h[i]][order_w[j]] != b[i][j]) {
            flag = false;
          }
        }
      }

      if (flag) {
        return true;
      }

    } while (next_permutation(order_w + 1, order_w + w + 1));
  } while (next_permutation(order_h + 1, order_h + h + 1));

  return false;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve() ? Yes() : No();
  }

  return 0;
}
