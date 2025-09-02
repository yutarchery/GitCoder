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
char s[int(1e6 + 5)];

ll ans = 1e16;

int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> s[i];
  }

  ll cnt = 0, now = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (s[i] == 'A') {
      cnt += abs(i - now);
      now += 2;
    }
  }
  ans = min(ans, cnt);

  cnt = 0, now = 2;
  for (int i = 1; i <= 2 * n; i++) {
    if (s[i] == 'A') {
      cnt += abs(i - now);
      now += 2;
    }
  }
  ans = min(ans, cnt);

  cout << ans << endl;

  return 0;
}
