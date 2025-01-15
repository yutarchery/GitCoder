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

int n, q, num, x, a;
ll c[int(2e5 + 5)], odd_min = 1e16, whole_min = 1e16;
ll cnt[int(2e5 + 5)], odd_cnt = 0, whole_cnt = 0;
ll ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (i % 2 == 1) {
      odd_min = min(odd_min, c[i]);
    }
    whole_min = min(whole_min, c[i]);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> num;
    if (num == 1) {
      cin >> x >> a;
      if (x % 2 == 1 && c[x] >= cnt[x] + odd_cnt + whole_cnt + a) {
        cnt[x] += a;
        ans += a;

        odd_min = min(odd_min, c[x] - (cnt[x] + odd_cnt + whole_cnt));
        whole_min = min(whole_min, c[x] - (cnt[x] + odd_cnt + whole_cnt));
      } else if (x % 2 == 0 && c[x] >= cnt[x] + whole_cnt + a) {
        cnt[x] += a;
        ans += a;

        whole_min = min(whole_min, c[x] - (cnt[x] + whole_cnt));
      }
    } else if (num == 2) {
      cin >> a;
      if (a <= odd_min) {
        ans += a * ((n + 1) / 2);
        odd_cnt += a;
        odd_min -= a;
        whole_min = min(odd_min, whole_min);
      }
    } else {
      cin >> a;
      if (a <= whole_min) {
        ans += a * n;
        whole_cnt += a;
        odd_min -= a;
        whole_min -= a;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
