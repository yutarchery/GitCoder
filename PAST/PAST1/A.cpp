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

char s[3];

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }

  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans *= 10;
    if ('0' <= s[i] && s[i] <= '9') {
      ans += s[i] - '0';
    } else {
      cout << "error" << endl;
      return 0;
    }
  }
  cout << ans * 2 << endl;

  return 0;
}
