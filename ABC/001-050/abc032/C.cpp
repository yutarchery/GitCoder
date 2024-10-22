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

int n, ans, r, now = 1;
ll k, s[int(1e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] > k) {
      r = i + 1;
      now = 1;
      continue;
    }

    if (r <= i) {
      r = i;
      now = s[i];
    }

    while (now <= k) {
      if (r == n) {
        break;
      }

      if (now * s[r + 1] <= k) {
        r++;
        now *= s[r];
        continue;
      } else {
        break;
      }
    }

    ans = max(ans, r - i + 1);
    now /= s[i];
  }
  cout << ans << endl;

  return 0;
}
