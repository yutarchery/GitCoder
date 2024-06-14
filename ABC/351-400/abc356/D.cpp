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

ll n, m, ans;

int main() {
  cin >> n >> m;
  ll num = 1;
  for (int i = 1; i <= 61; i++) {
    num *= 2;
    if ((m & (num / 2)) == 0) {
      continue;
    }
    ans += (n / num) * (num / 2);
    ans += max(0ll, (n % num) - (num / 2 - 1));
    ans %= MOD2;
  }

  cout << ans << endl;

  return 0;
}
