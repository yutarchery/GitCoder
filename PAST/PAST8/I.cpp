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
ll a[int(1e5 + 5)];

bool judge(ll num) {
  ll cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n; i++) {
    ll now = a[i];
    while (now % 2 == 0) {
      now /= 2;
      cnt2++;
    }
    while (now < num) {
      now *= 3;
      cnt3++;
    }
  }

  return cnt2 >= cnt3;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll l = 0, r = INF;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (judge(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;

  return 0;
}