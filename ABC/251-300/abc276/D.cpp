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

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int n, a[1005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int g = a[1];
  for (int i = 1; i <= n; i++) {
    g = gcd(g, a[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int rest = a[i] / g;

    while (rest > 1) {
      if (rest % 2 != 0 && rest % 3 != 0) {
        cout << -1 << endl;
        return 0;
      }

      if (rest % 2 == 0) {
        rest /= 2;
      } else {
        rest /= 3;
      }
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}