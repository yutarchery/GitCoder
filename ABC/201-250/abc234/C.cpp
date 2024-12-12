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

ll k;
char c[int(2e5 + 5)];

int main() {
  cin >> k;
  int idx = 0;
  while (k > 0) {
    if (k % 2 == 1) {
      c[idx] = '2';
    } else {
      c[idx] = '0';
    }
    k /= 2;
    idx++;
  }

  for (int i = idx - 1; i >= 0; i--) {
    cout << c[i];
  }
  cout << endl;

  return 0;
}
