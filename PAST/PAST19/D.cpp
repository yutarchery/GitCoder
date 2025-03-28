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

int n, t, a[1005], b[1005];
int a_dash, b_dash;

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a_dash < a[i]) {
      a_dash = a[i];
      b_dash = b[i];
    } else if (a_dash == a[i]) {
      b_dash = min(b[i], b_dash);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << t * (a_dash - a[i]) + (b[i] - b_dash) << endl;
  }

  return 0;
}
