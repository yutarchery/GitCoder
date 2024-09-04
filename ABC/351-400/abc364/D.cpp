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

int n, q, k;
ll a[int(1e5 + 5)], b;

int a_search(ll num) {
  if (a[n] <= num) {
    return n;
  }
  if (num < a[1]) {
    return 0;
  }

  int l = 1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= num) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

ll solve() {
  if (a_search(b) - a_search(b - 1) >= k) {
    return 0;
  }

  ll l = 0, r = 2e9;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll cnt = a_search(b + mid) - a_search(b - mid - 1);
    if (cnt < k) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return r;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 0; i < q; i++) {
    cin >> b >> k;
    cout << solve() << endl;
  }

  return 0;
}
