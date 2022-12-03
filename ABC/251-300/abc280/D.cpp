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

ll k, ans = 0;

ll divideTimes(ll value, ll prime) {
  ll cnt = 0;
  while (value % prime == 0) {
    value /= prime;
    cnt++;
  }
  return cnt;
}

void solve(ll prime, ll cnt) {
  if (cnt == 0) {
    return;
  }

  ll now = 0;
  while (cnt > 0) {
    now += prime;
    cnt -= divideTimes(now, prime);
  }

  ans = max(ans, now);
  return;
}

int main() {
  cin >> k;

  ll rest = k;
  for (ll i = 2; i * i <= k; i++) {
    int cnt = 0;
    while (rest % i == 0) {
      cnt++;
      rest /= i;
    }
    solve(i, cnt);
  }

  if (rest > 1) {
    ans = max(rest, ans);
  }
  cout << ans << endl;

  return 0;
}