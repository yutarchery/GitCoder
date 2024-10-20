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
ll k[25], sum = 0, ans = 1e16;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    sum += k[i];
  }

  for (int i = 0; i < (1 << n); i++) {
    int rest = i;
    ll now = 0;
    for (int j = 0; j < n; j++) {
      if (rest % 2 == 1) {
        now += k[j];
      }
      rest /= 2;
    }

    ans = min(ans, max(now, sum - now));
  }
  cout << ans << endl;

  return 0;
}
