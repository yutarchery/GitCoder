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

bool solve1(ll x, ll y, ll a, ll b, ll c) {
  ll rest_x = x - ((c - 1) / y + 1);
  if (rest_x <= 0) {
    return false;
  }

  ll rest_y = y - ((b - 1) / rest_x + 1);
  if (rest_y <= 0) {
    return false;
  }

  return rest_x * rest_y >= a;
}

bool solve2(ll x, ll y, ll a, ll b, ll c) {
  ll x_a = (a - 1) / y + 1;
  ll x_b = (b - 1) / y + 1;
  ll x_c = (c - 1) / y + 1;
  return x_a + x_b + x_c <= x;
}

ll origin[2], breadth[3];

int main() {
  for (int i = 0; i < 2; i++) {
    cin >> origin[i];
  }
  sort(origin, origin + 2);
  for (int j = 0; j < 3; j++) {
    cin >> breadth[j];
  }
  sort(breadth, breadth + 3);

  do {
    do {
      if (solve1(origin[0], origin[1], breadth[0], breadth[1], breadth[2])) {
        Yes();
        return 0;
      }
      if (solve2(origin[0], origin[1], breadth[0], breadth[1], breadth[2])) {
        Yes();
        return 0;
      }
    } while (next_permutation(breadth, breadth + 3));
  } while (next_permutation(origin, origin + 2));

  No();

  return 0;
}