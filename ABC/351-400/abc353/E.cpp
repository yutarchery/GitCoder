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
string s[int(3e5 + 5)];

ll ans = 0;
map<ll, ll> cnt;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    ll num = 1, sum = 0;
    for (int j = 0; j < s[i].length(); j++) {
      sum += (s[i][j] - 'a' + 1) * num;
      sum %= ll(1e16);

      ans += cnt[sum];
      cnt[sum]++;
      num *= 27;
      num %= ll(1e16);
    }
  }
  cout << ans << endl;

  return 0;
}
