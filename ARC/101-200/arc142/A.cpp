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

ll n, k;

ll rev(ll num) {
  while (num % 10 == 0) {
    num /= 10;
  }

  ll ans = 0;
  while (num > 0) {
    ans *= 10;
    ans += num % 10;
    num /= 10;
  }

  return ans;
}

ll calc(ll num) {
  while (num % 10 == 0) {
    num /= 10;
  }

  return min(num, rev(num));
}

int main() {
  cin >> n >> k;

  if (k != calc(k)) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  ll now_k = k, rev_k = rev(k);
  while (now_k <= n) {
    ans++;
    now_k *= 10;
  }

  if (k != rev(k)) {
    while (rev_k <= n) {
      ans++;
      rev_k *= 10;
    }
  }
  cout << ans << endl;

  return 0;
}
