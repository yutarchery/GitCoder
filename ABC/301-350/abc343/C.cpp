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

ll n, ans;

bool judge(ll num) {
  vector<int> v;
  while (num > 0) {
    v.push_back(num % 10);
    num /= 10;
  }

  int l = v.size();
  for (int i = 0; i < l; i++) {
    if (v[i] != v[l - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (ll i = 1; i * i * i <= n; i++) {
    if (judge(i * i * i)) {
      ans = i * i * i;
    }
  }
  cout << ans << endl;

  return 0;
}
