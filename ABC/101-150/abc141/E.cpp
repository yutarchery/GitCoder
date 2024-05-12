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
string s;
ll m = 27;

bool judge(int start, int len) {
  if (len == 0) {
    return true;
  }
  if (start + 2 * len - 1 >= n) {
    return false;
  }

  ll h1 = 0, h2 = 0, num1 = 1, num2 = 1;
  for (int i = 0; i < len; i++) {
    h1 = h1 * m % MOD;
    h1 = (h1 + (s[i + start] - 'a' + 1)) % MOD;

    h2 = h2 * m % MOD2;
    h2 = (h2 + (s[i + start] - 'a' + 1)) % MOD2;
  }

  for (int i = 0; i < len - 1; i++) {
    num1 = num1 * m % MOD;
    num2 = num2 * m % MOD2;
  }

  ll h3 = 0, h4 = 0;
  for (int i = 0; i < len - 1; i++) {
    h3 = h3 * m % MOD;
    h3 = (h3 + (s[i + len + start] - 'a' + 1)) % MOD;

    h4 = h4 * m % MOD2;
    h4 = (h4 + (s[i + len + start] - 'a' + 1)) % MOD2;
  }

  for (int i = start + 2 * len - 1; i < n; i++) {
    h3 = (h3 * m + (s[i] - 'a' + 1)) % MOD;
    h4 = (h4 * m + (s[i] - 'a' + 1)) % MOD2;

    if (h1 == h3 && h2 == h4) {
      return true;
    }

    h3 = (h3 - (s[i - (len - 1)] - 'a' + 1) * num1 % MOD) % MOD;
    if (h3 < 0) {
      h3 += MOD;
    }

    h4 = (h4 - (s[i - (len - 1)] - 'a' + 1) * num2 % MOD2) % MOD2;
    if (h4 < 0) {
      h4 += MOD2;
    }
  }

  return false;
}

int main() {
  cin >> n;
  cin >> s;

  int l = 0, r = n / 2 + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (judge(i, mid)) {
        flag = true;
        break;
      }
    }

    if (flag) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;

  return 0;
}
