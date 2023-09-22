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

int another(int num) {
  int ans = 1, rest = num;

  for (int i = 2; i * i <= num; i++) {
    if (rest % i != 0) {
      continue;
    }

    int cnt = 0;
    while (rest % i == 0) {
      rest /= i;
      cnt++;
    }

    if (cnt % 2 != 0) {
      ans *= i;
    }
  }

  return ans * rest;
}

int main() {
  cin >> n;
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j * another(i) <= n; j++) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}