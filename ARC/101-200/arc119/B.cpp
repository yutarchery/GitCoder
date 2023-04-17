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
string s, t;

int cnt_s = 0, cnt_t = 0, ans = 0;

int main() {
  cin >> n >> s >> t;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt_s++;
    }
    if (t[i] == '0') {
      cnt_t++;
    }

    if (s[i] == '0') {
      if (cnt_s != cnt_t || s[i] != t[i]) {
        ans++;
      }
    }
  }

  if (cnt_s != cnt_t) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}