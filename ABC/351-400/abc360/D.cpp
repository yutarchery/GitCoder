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
ll t, x[int(2e5 + 5)];
string s;

vector<ll> a, b;

int main() {
  cin >> n >> t;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (s[i] == '0') {
      b.push_back(x[i]);
    } else {
      a.push_back(x[i]);
    }
  }
  b.push_back(ll(-2e16));
  b.push_back(ll(2e16));
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = 0;
  int l = 0, r = 0;
  for (int i = 0; i < a.size(); i++) {
    bool left = false, right = false;
    for (int j = l; j < b.size(); j++) {
      if (a[i] <= b[j] && b[j] <= a[i] + 2 * t) {
        l = j;
        left = true;
        break;
      }
    }
    for (int j = r; j < b.size(); j++) {
      if (a[i] + 2 * t < b[j]) {
        r = j;
        right = true;
        break;
      }
    }
    if (left && right) {
      ans += r - l;
    }
  }
  cout << ans << endl;

  return 0;
}
