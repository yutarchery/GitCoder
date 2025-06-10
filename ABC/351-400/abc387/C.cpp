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

ll my_pow(ll a, int n) {
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= a;
  }
  return ans;
}

bool check(ll num) {
  ll head = num;
  while (head >= 10) {
    head /= 10;
  }

  while (num >= 10) {
    if (head <= num % 10) {
      return false;
    }
    num /= 10;
  }
  return true;
}

ll solve(ll num) {
  ll head = num, digit = 0;
  while (head >= 10) {
    head /= 10;
    digit++;
  }
  digit++;

  ll ans = 0;
  for (int i = 1; i < digit; i++) {
    for (int j = 1; j <= 9; j++) {
      ans += my_pow(j, i - 1);
    }
  }

  for (int i = 1; i < head; i++) {
    ans += my_pow(i, digit - 1);
  }

  for (int i = digit - 1; i >= 1; i--) {
    ll now = (num / my_pow(10, i - 1)) % 10;
    for (int j = 0; j <= min(now - 1, head - 1); j++) {
      ll sum = 1;
      for (int k = 0; k < i - 1; k++) {
        sum *= ll(head);
      }
      ans += sum;
    }

    if (now >= head) {
      break;
    }
  }

  if (check(num)) {
    ans++;
  }

  return ans;
}

int main() {
  ll l, r;
  cin >> l >> r;
  cout << solve(r) - solve(l - 1) << endl;
  return 0;
}
