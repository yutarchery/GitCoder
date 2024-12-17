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

char s[3], t[3];

Pii p[3] = {{0, 1}, {0, 2}, {1, 2}};

int calc_count(array<char, 3> now) {
  int cnt = 0;
  for (int i = 0; i <= 3; i++) {
    bool flag = true;
    for (int j = 0; j < 3; j++) {
      if (now[j] != t[j]) {
        flag = false;
      }
    }
    if (flag) {
      return cnt;
    }

    cnt++;

    if (i == 3) {
      break;
    }
    swap(now[p[i].first], now[p[i].second]);
  }

  return -1;
}

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
  }

  do {
    int cnt = calc_count({s[0], s[1], s[2]});

    if (cnt == -1) {
      continue;
    } else if (cnt % 2 == 0) {
      Yes();
      return 0;
    }
  } while (next_permutation(p, p + 3));
  No();

  return 0;
}
