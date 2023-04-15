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

int n, a, b, c, d, t;

int search_a() {
  while (b - a > 0) {
    int mid = (a + b) / 2;
    cout << "? " << a << " " << mid << " " << 1 << " " << n << endl;
    cin >> t;

    if (t == -1) {
      return 0;
    }

    if ((mid - a + 1) == t) {
      a = mid + 1;
    } else {
      b = mid;
    }
  }
  return a;
}

int search_c() {
  while (d - c > 0) {
    int mid = (c + d) / 2;
    cout << "? " << 1 << " " << n << " " << c << " " << mid << endl;
    cin >> t;

    if (t == -1) {
      return 0;
    }

    if ((mid - c + 1) == t) {
      c = mid + 1;
    } else {
      d = mid;
    }
  }
  return c;
}

int main() {
  cin >> n;
  a = 1, b = n, c = 1, d = n;
  search_a();
  search_c();
  cout << "! " << a << " " << c << endl;

  return 0;
}