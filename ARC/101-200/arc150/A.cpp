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

int t, k, n;
string s;

bool solve() {
  int left = 1e9, right = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      left = min(left, i);
      right = max(right, i);
    }
  }

  if (right != -1) {
    if (right - left + 1 > k) {
      return false;
    }
    for (int i = left; i <= right; i++) {
      if (s[i] == '0') {
        return false;
      }
    }

    if (right - left + 1 == k) {
      return true;
    }

    int cnt_l = 0, cnt_r = 0;
    for (int i = left - 1; i >= 0; i--) {
      if (s[i] == '?') {
        cnt_l++;
      } else {
        break;
      }
    }
    for (int i = right + 1; i < n; i++) {
      if (s[i] == '?') {
        cnt_r++;
      } else {
        break;
      }
    }

    if (cnt_l + cnt_r + (right - left + 1) == k) {
      return true;
    } else if (cnt_l + cnt_r + (right - left + 1) > k) {
      return cnt_l == 0 || cnt_r == 0;
    } else {
      return false;
    }
  }

  int cnt = 0, match = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt >= k) {
      match++;
    }
  }
  return match == 1;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k >> s;
    if (solve()) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}