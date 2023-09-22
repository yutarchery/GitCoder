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
vector<int> a[35];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (j == 0 || j == i - 1) {
        a[i].push_back(1);
      } else {
        a[i].push_back(a[i - 1][j - 1] + a[i - 1][j]);
      }
    }

    for (int j = 0; j < i; j++) {
      cout << a[i][j];
      if (j == i - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}