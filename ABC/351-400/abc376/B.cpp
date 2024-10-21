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

int n, q, t[105], l = 1, r = 2;
char h[105];

int ans = 0;

int solve_r(int t) {
  int now_r = r, cnt = 0;
  bool flag = true;
  while (now_r != t) {
    now_r++;
    cnt++;
    if (now_r > n) {
      now_r -= n;
    }

    if (now_r == l) {
      flag = false;
      break;
    }
  }

  if (flag) {
    return cnt;
  }

  cnt = 0;
  now_r = r;
  while (now_r != t) {
    now_r--;
    cnt++;
    if (now_r == 0) {
      now_r += n;
    }
  }
  return cnt;
}

int solve_l(int t) {
  int now_l = l, cnt = 0;
  bool flag = true;
  while (now_l != t) {
    now_l++;
    cnt++;
    if (now_l > n) {
      now_l -= n;
    }

    if (now_l == r) {
      flag = false;
      break;
    }
  }

  if (flag) {
    return cnt;
  }

  cnt = 0;
  now_l = l;
  while (now_l != t) {
    now_l--;
    cnt++;
    if (now_l == 0) {
      now_l += n;
    }
  }

  return cnt;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> h[i] >> t[i];
    if (h[i] == 'L') {
      ans += solve_l(t[i]);
      l = t[i];
    } else {
      ans += solve_r(t[i]);
      r = t[i];
    }
  }

  cout << ans << endl;

  return 0;
}
