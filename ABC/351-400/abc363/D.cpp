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

ll n;
ll cnt[105];
int ans[105];

int calc_digit() {
  int digit = 1;
  ll rest = n, now = 9;

  while (true) {
    if (digit % 2 != 0 && digit > 1) {
      now *= 10;
    }

    if (rest <= now) {
      cnt[digit] += rest;
      break;
    } else {
      cnt[digit] += now;
    }

    digit++;
    rest -= now;
  }

  return digit;
}

int main() {
  cin >> n;
  n--;

  int digit = calc_digit();

  ll sum = 0;
  for (int i = (digit % 2); i <= digit; i += 2) {
    sum += cnt[i];
  }

  for (int i = (digit - 1) / 2; i >= 0; i--) {
    ans[i] = sum % 10;
    sum /= 10;
  }

  for (int i = 0; i <= (digit - 1) / 2; i++) {
    cout << ans[i];
  }
  if (digit % 2 == 0) {
    cout << ans[(digit - 1) / 2];
  }
  for (int i = (digit - 1) / 2 - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
