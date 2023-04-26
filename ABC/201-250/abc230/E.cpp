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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll n, ans = 0, idx = 1;

int main() {
  cin >> n;

  ll maxElement = n;
  while (maxElement >= ll(1e6)) {
    ll minElement = n / (idx + 1);
    ans += idx * (maxElement - minElement);
    idx++;
    maxElement = n / idx;
  }
  for (ll i = 1; i <= maxElement; i++) {
    ans += n / i;
  }
  cout << ans << endl;

  return 0;
}