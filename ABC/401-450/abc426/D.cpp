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
char s[int(5e5 + 5)];

int cnt_l[int(5e5 + 5)][2], cnt_r[int(5e5 + 5)][2];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  vector<pair<int, Pii>> p;
  int l = 1;
  for (int i = 1; i <= n; i++) {
    if (s[l] == s[i]) {
      continue;
    } else {
      p.push_back({s[l] - '0', {l, i - 1}});
      l = i;
    }
  }
  p.push_back({s[l] - '0', {l, n}});

  cnt_l[0][0] = 0;
  cnt_l[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      cnt_l[i][0] = cnt_l[i - 1][0] + 2;
      cnt_l[i][1] = cnt_l[i - 1][1] + 1;
    } else {
      cnt_l[i][0] = cnt_l[i - 1][0] + 1;
      cnt_l[i][1] = cnt_l[i - 1][1] + 2;
    }
  }

  cnt_r[n + 1][0] = 0;
  cnt_r[n + 1][1] = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '0') {
      cnt_r[i][0] = cnt_r[i + 1][0] + 2;
      cnt_r[i][1] = cnt_r[i + 1][1] + 1;
    } else {
      cnt_r[i][0] = cnt_r[i + 1][0] + 1;
      cnt_r[i][1] = cnt_r[i + 1][1] + 2;
    }
  }

  int ans = 1e9;
  for (pair<int, Pii> now : p) {
    int idx = now.first, l = now.second.first, r = now.second.second;
    ans = min(ans, cnt_l[l - 1][idx] + cnt_r[r + 1][idx]);
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
