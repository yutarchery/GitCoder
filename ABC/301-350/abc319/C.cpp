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

int c[9], order[9], now[3], total, ans;
const int target[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                          {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

bool check() {
  for (int i = 0; i < 8; i++) {

    int idx = 0;
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 3; k++) {
        if (order[j] == target[i][k]) {
          now[idx] = order[j];
          idx++;
        }
      }
    }

    if (c[now[0]] == c[now[1]] && c[now[1]] != c[now[2]]) {
      return false;
    }
  }

  return true;
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> c[i];
    order[i] = i;
  }

  do {
    if (check()) {
      ans++;
    }
    total++;
  } while (next_permutation(order, order + 9));

  cout << setprecision(32) << (double)(ans) / (double)(total) << endl;

  return 0;
}