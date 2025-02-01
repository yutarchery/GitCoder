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

ll n, k, a[int(2e5 + 5)], d[int(2e5 + 5)];
vector<ll> ans;

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

bool judge(ll num) { return a[1] + num * (n - 1) >= a[k]; }

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k - 1; i++) {
    d[i] = a[i + 1] - a[i];
  }

  ll g = d[1];
  for (int i = 1; i <= k - 1; i++) {
    g = my_gcd(g, d[i]);
  }

  for (ll i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      if (judge(i)) {
        ans.push_back(i);
      }
      if (i * i != g && judge(g / i)) {
        ans.push_back(g / i);
      }
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }

  return 0;
}
