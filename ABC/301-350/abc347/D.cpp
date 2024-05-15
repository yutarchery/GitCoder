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

int a, b;
ll c;

bool xor_bit[65], ans_a[65], ans_b[65];

int main() {
  cin >> a >> b >> c;
  int cnt = 0;
  for (int i = 0; i < 60; i++) {
    if (c % 2 == 1) {
      xor_bit[i] = true;
      cnt++;
    }
    c /= 2;
  }

  for (int i = 0; i < 60; i++) {
    if (xor_bit[i]) {
      if (a >= b) {
        ans_a[i] = true;
        a--;
      } else {
        ans_b[i] = true;
        b--;
      }
    }
  }

  if (a != b || a < 0 || b < 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < 60; i++) {
    if (!xor_bit[i] && a >= 1) {
      ans_a[i] = true;
      a--;
      ans_b[i] = true;
      b--;
    }
  }

  if (a > 0 || b > 0) {
    cout << -1 << endl;
    return 0;
  }

  ll num_a = 0, num_b = 0, digit = 1;
  for (int i = 0; i < 60; i++) {
    if (ans_a[i]) {
      num_a += digit;
    }
    if (ans_b[i]) {
      num_b += digit;
    }
    digit *= 2;
  }
  cout << num_a << " " << num_b << endl;

  return 0;
}
