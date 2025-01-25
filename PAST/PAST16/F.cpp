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

string s;

ll solve(ll ans = 1, ll tmp = 0, int idx = 0) {
  if (idx == s.length()) {
    return ans * tmp % MOD2;
  }

  if (s[idx] == '*') {
    return solve(ans * tmp % MOD2, 0, idx + 1);
  } else {
    return solve(ans, (tmp * 10 + (s[idx] - '0')) % MOD2, idx + 1);
  }
}

int main() {
  cin >> s;
  cout << solve() << endl;

  return 0;
}
