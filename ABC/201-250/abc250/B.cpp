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

int n, a, b;
bool color[15][15];

int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        color[i][j] = false;
      } else {
        color[i][j] = true;
      }
    }
  }

  for (int i = 0; i < a * n; i++) {
    for (int j = 0; j < b * n; j++) {
      if (color[i / a][j / b]) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }

  return 0;
}
