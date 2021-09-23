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

int h, w, a, b;

int main() {
  cin >> h >> w >> a >> b;

  for (int i = 0; i < b; i++) {
    for (int j = 0; j < w; j++) {
      if (j < a)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
  }
  for (int i = b; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j < a)
        cout << 0;
      else
        cout << 1;
    }
    cout << endl;
  }

  return 0;
}