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

int n, cnt[10], now[10], ans;
char s[15];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i] - '0']++;
  }

  for (ll i = 0; i * i < pow(ll(10), n); i++) {
    fill(now, now + 10, 0);
    ll rest = i * i;
    while (rest > 0) {
      now[rest % 10]++;
      rest /= 10;
    }

    bool flag = true;
    for (int j = 1; j <= 9; j++) {
      if (cnt[j] != now[j]) {
        flag = false;
      }
    }

    if (flag) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
