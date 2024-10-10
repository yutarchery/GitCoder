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

int primes[9] = {4, 5, 7, 9, 11, 13, 17, 19, 23}, sum[9];
int m = 108, a[115], b[115], rest[9];

int main() {
  sum[0] = primes[0];
  for (int i = 1; i < 9; i++) {
    sum[i] = sum[i - 1] + primes[i];
  }

  int now = 1;
  for (int i = 0; i < 9; i++) {
    a[sum[i]] = now;
    for (int j = 1; j < primes[i]; j++) {
      a[now + j - 1] = j + now;
    }
    now += primes[i];
  }

  cout << m << endl;
  for (int i = 1; i <= m; i++) {
    cout << a[i];
    if (i == m) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < 9; i++) {
    rest[i] = b[sum[i]] - a[sum[i]] + 1;
  }

  ll x = rest[8], p = primes[8];
  for (int j = 7; j >= 0; j--) {
    while (x % primes[j] != rest[j] % primes[j]) {
      x += p;
    }
    p *= primes[j];
  }
  cout << x << endl;

  return 0;
}
