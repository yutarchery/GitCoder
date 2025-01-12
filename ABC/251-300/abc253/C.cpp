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

int q, n, x, c;
multiset<int> s;

int main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> n;
    if (n == 1) {
      cin >> x;
      s.insert(x);
    } else if (n == 2) {
      cin >> x >> c;
      for (int j = 0; j < c; j++) {
        auto iter = s.find(x);
        if (iter == s.end()) {
          break;
        } else {
          s.erase(iter);
        }
      }
    } else {
      auto min_iter = s.begin(), max_iter = s.end();
      max_iter--;
      cout << *max_iter - *min_iter << endl;
    }
  }

  return 0;
}
