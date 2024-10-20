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

int n;
string s;
ll dp1[int(1e6 + 5)], dp2[int(1e6 + 5)];
char now[int(1e6 + 5)];

ll solve() {
  cin >> n;
  cin >> s;

  dp1[0] = s[0] - 'A';
  dp2[0] = 1;
  now[0] = s[0];
  now[n - 1] = s[0];

  ll ans = dp1[0];
  for (int i = 1; i <= n - 1 - i; i++) {
    dp1[i] = (dp1[i - 1] * 26 + dp2[i - 1] * (s[i] - 'A')) % MOD2;
    dp2[i] = 1;
    ans = dp1[i];

    now[i] = s[i];
    now[n - 1 - i] = s[i];
  }

  string t = "";
  for (int i = 0; i < n; i++) {
    t += now[i];
  }

  if (t <= s) {
    return (ans + 1) % MOD2;
  } else {
    return ans;
  }
}

void reset() {
  fill(dp1, dp1 + n + 1, 0);
  fill(dp2, dp2 + n + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }
  return 0;
}
