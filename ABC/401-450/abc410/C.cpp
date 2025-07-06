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

int n, q, op, p, x, k;
int a[int(1e6 + 5)], sum = 0;

int main() {
  cin >> n >> q;

  a[0] = n;
  for (int i = 1; i < n; i++) {
    a[i] = i;
  }

  while (q--) {
    cin >> op;

    if (op == 1) {
      cin >> p >> x;

      int idx = (p + sum) % n;
      a[idx] = x;
    } else if (op == 2) {
      cin >> p;
      int idx = (p + sum) % n;
      cout << a[idx] << endl;
    } else {
      cin >> k;
      sum = (sum + k) % n;
    }
  }

  return 0;
}
