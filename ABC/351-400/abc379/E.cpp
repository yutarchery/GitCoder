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
char s[int(2e5 + 5)];
ll now, ans[int(1e6 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (ll i = 1; i <= n; i++) {
    ans[n - i + 1] = ans[n - i + 2] + (s[i] - '0') * i;
  }

  int l = 0;
  for (int i = 1; i <= int(1e6); i++) {
    ans[i + 1] += ans[i] / 10;
    ans[i] %= 10;
    if (ans[i] > 0) {
      l = i;
    }
  }

  for (int i = l; i >= 1; i--) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
