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
string x, s[1005];
int x_cnt[26];

int ans = 0, cnt = 0, c = 0;

void solve(int idx) {
  int now[26] = {};
  for (int i = 0; i < s[idx].length(); i++) {
    now[s[idx][i] - 'A']++;
  }

  int now_cnt = 0, now_c = 0;
  for (int i = 0; i < 26; i++) {
    if (now_cnt < min(2, now[i]) + min(3, x_cnt[i])) {
      now_cnt = min(2, now[i]) + min(3, x_cnt[i]);
      now_c = i;
    }
  }

  if (cnt < now_cnt) {
    ans = idx;
    cnt = now_cnt;
    c = now_c;
  } else if (cnt == now_cnt && now_c < c) {
    ans = idx;
    c = now_c;
  }
  return;
}

int main() {
  cin >> n;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    x_cnt[x[i] - 'A']++;
  }

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
