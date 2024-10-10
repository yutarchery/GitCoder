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
ll a, b, ans = 1e16;
char s[10005];

ll solve(ll start) {
  ll res = a * start;
  for (int i = 1; i <= n + 1 - i; i++) {
    if (s[i + start] != s[(n + 1 - i) + start]) {
      res += b;
    }
  }

  return res;
}

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[n + i] = s[i];
  }
  for (int i = 0; i < n; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
