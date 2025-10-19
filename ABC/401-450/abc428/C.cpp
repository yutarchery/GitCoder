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

int q, op;
char c;

int val[int(8e5 + 5)], sum[int(8e5 + 5)];
int now_bottom = 0, minus_cnt = 0;

bool ans[int(8e5 + 5)];

int main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> op;

    if (op == 1) {
      cin >> c;
      now_bottom++;

      if (c == '(') {
        val[now_bottom] = 1;
      } else {
        val[now_bottom] = -1;
      }
      sum[now_bottom] = sum[now_bottom - 1] + val[now_bottom];
      if (sum[now_bottom] < 0) {
        minus_cnt++;
      }
    } else {
      if (sum[now_bottom] < 0) {
        minus_cnt--;
      }
      now_bottom--;
    }

    if (sum[now_bottom] == 0 && minus_cnt == 0) {
      ans[i] = true;
    }
  }

  for (int i = 1; i <= q; i++) {
    ans[i] ? Yes() : No();
  }

  return 0;
}
