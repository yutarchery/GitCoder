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
ll k, a[int(2e5 + 5)], ans[int(2e5 + 5)];

int choosed[int(6e5 + 5)];
ll ls, le;

int main() {
  cin >> n >> k;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n + 1; i++) {
    ll now = ans[i - 1] % ll(n);

    ans[i] = ans[i - 1] + a[now];

    if (choosed[now] == 0) {
      choosed[now] = i;
    } else {
      ls = choosed[now];
      le = i - 1;
      break;
    }
  }

  if (k <= ls) {
    cout << ans[k] << endl;
    return 0;
  }

  ll res = (ans[le] - ans[ls - 1]) * ((k - ls + 1) / (le - ls + 1)) +
           ans[(k - ls + 1) % (le - ls + 1) + (ls - 1)];
  cout << res << endl;

  return 0;
}
