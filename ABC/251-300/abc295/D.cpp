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

string s;
ll now[10], cnt[(1 << 10)];

int main() {
  cin >> s;
  cnt[0]++;
  for (int i = 0; i < s.length(); i++) {
    now[s[i] - '0']++;
    int num = 0;
    for (int j = 0; j < 10; j++) {
      if (now[j] % 2 == 1) {
        num += (1 << j);
      }
    }
    cnt[num]++;
  }

  ll ans = 0;
  for (int i = 0; i < (1 << 10); i++) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
