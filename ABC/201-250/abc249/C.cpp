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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, k;
string s[20];

int ans = 0;

void solve(int idx) {
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    if (idx % 2 != 0) {
      int l = s[i].length();
      for (int j = 0; j < l; j++) {
        cnt[s[i][j] - 'a']++;
      }
    }
    idx /= 2;
  }

  int res = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == k) {
      res++;
    }
  }

  ans = max(ans, res);
  return;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}