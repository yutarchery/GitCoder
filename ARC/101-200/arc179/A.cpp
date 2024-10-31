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

ll n, k, a[int(2e5 + 5)], sum = 0;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (k > 0) {
    sort(a + 1, a + n + 1);
    Yes();
    for (int i = 1; i <= n; i++) {
      cout << a[i];
      if (i == n) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
    return 0;
  }

  if (sum >= k) {
    sort(a + 1, a + n + 1, greater<ll>());
    Yes();
    for (int i = 1; i <= n; i++) {
      cout << a[i];
      if (i == n) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  } else {
    No();
  }

  return 0;
}
