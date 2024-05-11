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

ll n, a[int(3e5 + 5)];
ll cnt, sum;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i] * (n - 1);
  }
  sort(a, a + n + 1);

  for (int i = 1; i <= n; i++) {
    if (a[i - 1] + a[i] < int(1e8)) {
      continue;
    }

    int l = 0, r = i - 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (a[mid] + a[i] < int(1e8)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cnt += (i - 1) - l;
  }

  cout << sum - cnt * ll(1e8) << endl;

  return 0;
}
