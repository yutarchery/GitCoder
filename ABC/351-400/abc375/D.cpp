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
ll ans = 0, cnt[int(2e5 + 5)][26], rev[int(2e5 + 5)][26];

int main() {
  cin >> s;
  cnt[0][s[0] - 'A']++;
  for (int i = 1; i < s.length(); i++) {
    for (int j = 0; j < 26; j++) {
      cnt[i][j] = cnt[i - 1][j];
    }
    cnt[i][s[i] - 'A']++;
  }

  for (int i = s.length() - 1; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      rev[i][j] = rev[i + 1][j];
      ans += cnt[i - 1][j] * rev[i][j];
    }
    rev[i][s[i] - 'A']++;
  }
  cout << ans << endl;

  return 0;
}
