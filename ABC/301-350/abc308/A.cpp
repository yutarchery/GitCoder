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

int a[8];
bool flag = true;

int main() {
  for (int i = 0; i < 8; i++) {
    cin >> a[i];

    if (!(100 <= a[i] && a[i] <= 675)) {
      flag = false;
    }

    if (a[i] % 25 != 0) {
      flag = false;
    }
  }

  for (int i = 0; i < 7; i++) {
    if (a[i] > a[i + 1]) {
      flag = false;
    }
  }

  if (flag) {
    Yes();
  } else {
    No();
  }

  return 0;
}