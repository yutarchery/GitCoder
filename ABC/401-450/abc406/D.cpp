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
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int h, w, n, x, y;
set<int> x_gb[int(2e5 + 5)], y_gb[int(2e5 + 5)];
int q, op;

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;

    x_gb[x].insert(y);
    y_gb[y].insert(x);
  }

  cin >> q;
  while (q--) {
    cin >> op;

    if (op == 1) {
      cin >> x;
      cout << x_gb[x].size() << endl;
      for (int j : x_gb[x]) {
        y_gb[j].erase(x);
      }
      x_gb[x].clear();
    } else {
      cin >> y;
      cout << y_gb[y].size() << endl;
      for (int i : y_gb[y]) {
        x_gb[i].erase(y);
      }
      y_gb[y].clear();
    }
  }

  return 0;
}
