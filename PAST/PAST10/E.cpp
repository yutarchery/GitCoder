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

int check(int y, int m, int d) {
  bool num[10] = {};
  for (int i = 0; i < 4; i++) {
    num[y % 10] = true;
    y /= 10;
  }
  for (int i = 0; i < 2; i++) {
    num[m % 10] = true;
    num[d % 10] = true;
    m /= 10;
    d /= 10;
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (num[i]) {
      ans++;
    }
  }

  return ans;
}

int y, m, d;
int main() {
  scanf("%d/%d/%d", &y, &m, &d);

  while (check(y, m, d) != 2) {
    d++;

    if (d >= 31) {
      m++;
      d = 1;
    }
    if (m == 13) {
      m = 1;
      y++;
    }
  }

  printf("%04d/%02d/%02d\n", y, m, d);

  return 0;
}