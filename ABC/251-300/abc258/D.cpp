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

ll n, x, a[int(2e5 + 5)], b[int(2e5 + 5)];

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  ll min_cost = 1e18, ans = 2e18, sum = 0;
  for (ll i = 1; i <= min(n, x); i++) {
    sum += a[i] + b[i];
    min_cost = min(min_cost, b[i]);
    ans = min(ans, sum + min_cost * (x - i));
  }
  cout << ans << endl;

  return 0;
}