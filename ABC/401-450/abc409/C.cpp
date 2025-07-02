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

int n, l, d[int(3e5 + 5)];
ll cnt[int(3e5 + 5)];

int main() {
  cin >> n >> l;

  int now = 0;
  cnt[0]++;
  for (int i = 1; i <= n - 1; i++) {
    cin >> d[i];
    now = (now + d[i]) % l;
    cnt[now]++;
  }

  ll ans = 0;
  if (l % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i + l * 2 / 3 <= l; i++) {
    ans += cnt[i] * cnt[i + l / 3] * cnt[i + l * 2 / 3];
  }
  cout << ans << endl;

  return 0;
}
