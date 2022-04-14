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

int n;
ll k, x, a[int(2e5 + 5)];

int main() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<ll>());

  for (int i = 0; i < n; i++) {
    ll necessary = a[i] / x;

    if (k == 0) {
      continue;
    } else if (k >= necessary) {
      k -= necessary;
      a[i] %= x;
    } else {
      a[i] -= x * k;
      k = 0;
    }
  }

  sort(a, a + n, greater<ll>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (k == 0) {
      ans += a[i];
    } else {
      k--;
    }
  }
  cout << ans << endl;

  return 0;
}