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

int main() {
  string s;
  cin >> s;

  int ans = 1000;
  for (int i = 0; i + 2 < s.length(); i++) {
    int now = 0;
    for (int j = 0; j < 3; j++) {
      now *= 10;
      now += s[i + j] - '0';
    }
    ans = min(ans, abs(now - 753));
  }
  cout << ans << endl;

  return 0;
}
