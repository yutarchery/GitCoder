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
ll a[int(1e5 + 5)], a_max;

ll ans[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a_max = max(a_max, a[i]);
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = ll(1e9) * a[i] * 2 / a_max;
    if (ans[i] % 2 == 0) {
      ans[i] /= 2;
    } else {
      ans[i] = ans[i] / 2 + 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];

    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
