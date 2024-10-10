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

int n, p, q, r, s, a[105], b[105];

int main() {
  cin >> n >> p >> q >> r >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = r; i <= s; i++) {
    b[i] = a[i - r + p];
  }
  for (int i = p; i <= q; i++) {
    b[i] = a[i - p + r];
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) {
      cout << a[i];
    } else {
      cout << b[i];
    }

    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
