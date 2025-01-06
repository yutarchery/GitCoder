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

int n, h, w, a[7], b[7];

bool used[20][20];

void fill_tile(int idx, int si, int sj) {
  for (int i = 0; i < a[idx]; i++) {
    for (int j = 0; j < b[idx]; j++) {
      used[si + i][sj + j] = true;
    }
  }
  return;
}

bool check() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!used[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void swap_tile(int num, vector<int> order) {
  for (int i = 0; i < order.size(); i++) {
    if (num % 2 == 1) {
      swap(a[order[i]], b[order[i]]);
    }
    num /= 2;
  }
  return;
}

void reset_tile() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      used[i][j] = false;
    }
  }
  return;
}

bool solve(vector<int> order) {
  int m = order.size();

  do {
    for (int i = 0; i < (1 << m); i++) {
      swap_tile(i, order);

      for (int o : order) {
        bool filled = false;
        for (int j = 0; j < h; j++) {
          for (int k = 0; k < w; k++) {
            if (!filled && !used[j][k]) {
              fill_tile(o, j, k);
              filled = true;
            }
          }
        }
      }

      if (check()) {
        return true;
      }

      swap_tile(i, order);
      reset_tile();
    }
  } while (next_permutation(order.begin(), order.end()));

  return false;
}

int main() {
  cin >> n >> h >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < (1 << n); i++) {
    vector<int> order = {};
    int sum = 0, rest = i;
    for (int j = 0; j < n; j++) {
      if (rest % 2 == 1) {
        order.push_back(j);
        sum += a[j] * b[j];
      }
      rest /= 2;
    }

    if (sum != h * w) {
      continue;
    }

    if (solve(order)) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
