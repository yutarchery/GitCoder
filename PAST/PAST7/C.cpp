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
int l, r;

int intLength(int num) {
  if (num == 0) {
    return 1;
  }
  int ans = 0;
  while (num > 0) {
    num /= 10;
    ans++;
  }
  return ans;
}

string convert(int num) {
  if (num == 0) {
    return "0";
  }

  string ans = "";
  while (num > 0) {
    char last = '0' + num % 10;
    ans = last + ans;
    num /= 10;
  }
  return ans;
}

bool check1() {
  if (intLength(l) > s.length()) {
    return false;
  } else if (intLength(l) < s.length()) {
    return true;
  } else {
    return convert(l) <= s;
  }
}

bool check2() {
  if (s.length() < intLength(r)) {
    return true;
  } else if (s.length() == intLength(r)) {
    return s <= convert(r);
  } else {
    return false;
  }
}

int main() {
  cin >> s;
  cin >> l >> r;

  if (s[0] == '0' && s.length() >= 2) {
    No();
  } else if (check1() && check2()) {
    Yes();
  } else {
    No();
  }

  return 0;
}