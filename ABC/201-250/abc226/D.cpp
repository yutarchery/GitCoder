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

int n, x[505], y[505];
int ans = 0;
map<Pii, bool> used;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      int diffx = x[i] - x[j], diffy = y[i] - y[j];
      Pii next;

      if (diffx == 0) {
        if (diffy > 0) {
          next = {0, 1};
        } else {
          next = {0, -1};
        }
      } else if (diffy == 0) {
        if (diffx > 0) {
          next = {1, 0};
        } else {
          next = {-1, 0};
        }
      } else {
        int g = gcd(abs(diffx), abs(diffy));
        next = {diffx / g, diffy / g};
      }

      if (!used[next]) {
        ans++;
        used[next] = true;
      }
    }
  }

  cout << ans << endl;

  return 0;
}