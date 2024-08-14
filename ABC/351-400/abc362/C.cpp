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
ll l[int(2e5 + 5)], r[int(2e5 + 5)], ans[int(2e5 + 5)];
ll sum_l = 0, sum_r = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    sum_l += l[i];
    sum_r += r[i];
  }

  if (sum_l > 0 || sum_r < 0) {
    No();
    return 0;
  }

  Yes();
  for (int i = 1; i <= n; i++) {
    ans[i] = l[i];
  }

  for (int i = 1; i <= n; i++) {
    if (sum_l < 0) {
      ll diff = r[i] - l[i];
      if (sum_l + diff >= 0) {
        ans[i] += -1 * sum_l;
        break;
      } else {
        sum_l += diff;
        ans[i] += diff;
      }
    } else {
      break;
    }
  }

  cout << ans[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}
