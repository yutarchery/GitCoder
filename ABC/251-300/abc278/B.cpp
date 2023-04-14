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

bool judge(int h, int m) {
  int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
  return (a * 10 + c) <= 23 && (b * 10 + d) <= 59;
}

int h, m;
int main() {
  cin >> h >> m;

  while (true) {
    if (judge(h, m)) {
      cout << h << " " << m << endl;
      return 0;
    }

    m++;
    if (m == 60) {
      h++;
      m = 0;
    }
    h %= 24;
  }

  return 0;
}