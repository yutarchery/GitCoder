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
string s, t, ans;

int cnt = 0;

int main() {
  cin >> n;
  cin >> s;
  cin >> t;

  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      cnt++;
    }
  }

  if (cnt % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }

  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      ans += '0';
      continue;
    }

    if (s[i] == '0') {
      if (b < cnt / 2) {
        b++;
        ans += '0';
      } else {
        a++;
        ans += '1';
      }
    } else {
      if (a < cnt / 2) {
        a++;
        ans += '0';
      } else {
        b++;
        ans += '1';
      }
    }
  }

  cout << ans << endl;

  return 0;
}
