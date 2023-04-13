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

int n, a[int(2e5 + 5)];

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }

  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int g = 0;
  for (int i = 1; i < n; i++) {
    if (g == 0) {
      g = abs(a[i] - a[i - 1]);
    }
    if (a[i] == a[i - 1]) {
      continue;
    }

    g = gcd(g, abs(a[i] - a[i - 1]));
  }

  if (g == 1) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
  }

  return 0;
}