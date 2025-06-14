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
ll a[int(2e5 + 5)];
vector<ll> odds, evens;
ll ans = -1;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 != 0) {
      odds.push_back(a[i]);
    } else {
      evens.push_back(a[i]);
    }
  }

  if (odds.size() >= 2) {
    sort(odds.begin(), odds.end(), greater<ll>());
    ans = max(ans, odds[0] + odds[1]);
  }
  if (evens.size() >= 2) {
    sort(evens.begin(), evens.end(), greater<ll>());
    ans = max(ans, evens[0] + evens[1]);
  }

  cout << ans << endl;

  return 0;
}
