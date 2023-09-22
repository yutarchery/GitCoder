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

struct Date {
public:
  int y, m, d;

private:
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool leap(int year) {
    if (year % 400 == 0) {
      return true;
    } else if (year % 100 == 0) {
      return false;
    } else if (year % 4 == 0) {
      return true;
    } else {
      return false;
    }
  }

public:
  void add() {
    if (d >= days[m - 1]) {
      if (m == 2) {
        if (leap(y) && d == 28) {
          d++;
        } else {
          m = 3;
          d = 1;
        }
      } else if (m == 12) {
        y++;
        m = 1;
        d = 1;
      } else {
        m++;
        d = 1;
      }
    } else {
      d++;
    }
    return;
  }
};

int sy, sm, sd, gy, gm, gd;
Date s, g, now;

int main() {
  scanf("%d-%d-%d", &sy, &sm, &sd);
  scanf("%d-%d-%d", &gy, &gm, &gd);

  s.y = sy, s.m = sm, s.d = sd;
  g.y = gy, g.m = gm, g.d = gd;
  now.y = 2022, now.m = 1, now.d = 1;

  int dayofweek = 0, ans = 0;
  g.add();
  bool flag = false;

  while (!(now.y == g.y && now.m == g.m && now.d == g.d)) {
    if (!flag && (now.y == s.y && now.m == s.m && now.d == s.d)) {
      flag = true;
    }

    if (flag && 0 <= dayofweek && dayofweek <= 1) {
      ans++;
    }

    now.add();
    dayofweek = (dayofweek + 1) % 7;
  }

  cout << ans << endl;

  return 0;
}