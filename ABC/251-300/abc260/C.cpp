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

ll n, x, y;
ll red[15], blue[15];

int main() {
  cin >> n >> x >> y;
  
  red[n] = 1;
  for (int i = n; i >= 2; i--) {
    red[i - 1] += red[i];
    blue[i] += x * red[i];

    red[i - 1] += blue[i];
    blue[i - 1] += y * blue[i];
  }

  cout << blue[1] << endl;

  return 0;
}
