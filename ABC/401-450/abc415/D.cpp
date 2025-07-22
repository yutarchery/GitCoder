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

ll n, a[int(2e5 + 5)], b[int(2e5 + 5)];
int m;
Pll diff_a[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    diff_a[i] = {a[i] - b[i], a[i]};
  }
  sort(diff_a + 1, diff_a + m + 1);

  ll ans = 0, rest = n;
  for (int i = 1; i <= m; i++) {
    if (diff_a[i].second > rest) {
      continue;
    }
    ans += (rest - diff_a[i].second) / diff_a[i].first;
    rest =
        rest - ((rest - diff_a[i].second) / diff_a[i].first) * diff_a[i].first;

    if (rest >= diff_a[i].second) {
      rest -= diff_a[i].first;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
