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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int q, k;
const ll minElement = 0, maxElement = ll(1e18) + 1;
ll x;
multiset<ll> mst;

int main() {

  mst.insert(minElement);
  mst.insert(maxElement);

  cin >> q;
  for (int i = 0; i < q; i++) {
    int query;
    cin >> query;

    if (query == 1) {
      cin >> x;
      mst.insert(x);
    } else if (query == 2) {
      cin >> x >> k;

      auto iter = mst.lower_bound(x + 1);
      auto start = mst.lower_bound(0);

      while (iter != start && k > 0) {
        iter--;
        k--;
      }

      if (iter == start) {
        cout << -1 << endl;
      } else {
        cout << *iter << endl;
      }
    } else {
      cin >> x >> k;

      auto iter = mst.lower_bound(x);
      auto last = mst.upper_bound(maxElement - 1);

      while (iter != last && k > 1) {
        iter++;
        k--;
      }

      if (iter == last) {
        cout << -1 << endl;
      } else {
        cout << *iter << endl;
      }
    }
  }

  return 0;
}