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

int h, w, a[5][5], b[5][5];

int order_h[5], order_w[5], c[5][5], ans = 1e9;
bool visited_h[5], visited_w[5];

int calc_cnt() {
  int cnt = 0;
  int now_h[5] = {0, 1, 2, 3, 4}, now_w[5] = {0, 1, 2, 3, 4};

  for (int i = 0; i < h; i++) {
    for (int j = i + 1; j < h; j++) {
      if (order_h[i] > order_h[j]) {
        cnt++;
      }
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = i + 1; j < w; j++) {
      if (order_w[i] > order_w[j]) {
        cnt++;
      }
    }
  }

  return cnt;
}

void solve() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      c[order_h[i]][order_w[j]] = a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (b[i][j] != c[i][j]) {
        return;
      }
    }
  }

  ans = min(ans, calc_cnt());
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    order_h[i] = i;
  }
  for (int j = 0; j < w; j++) {
    order_w[j] = j;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
    }
  }

  do {
    do {
      solve();
    } while (next_permutation(order_w, order_w + w));
  } while (next_permutation(order_h, order_h + h));

  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
