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

int max_h, max_w, n;
int h[int(2e5 + 5)], w[int(2e5 + 5)];

priority_queue<pair<Pii, int>> que_h, que_w;
bool used[int(2e5 + 5)];

int now_x = 1, now_y = 1;
int x[int(2e5 + 5)], y[int(2e5 + 5)];

int main() {
  cin >> max_h >> max_w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> w[i];
    que_h.push({{h[i], w[i]}, i});
    que_w.push({{w[i], h[i]}, i});
  }

  int cnt = 0, now_h = max_h, now_w = max_w;
  while (cnt < n) {
    while (!que_h.empty()) {
      pair<Pii, int> q = que_h.top();
      if (used[q.second]) {
        que_h.pop();
        continue;
      }
      break;
    }

    while (!que_w.empty()) {
      pair<Pii, int> q = que_w.top();
      if (used[q.second]) {
        que_w.pop();
        continue;
      }
      break;
    }

    pair<Pii, int> ph = que_h.top(), pw = que_w.top();

    if (now_h == ph.first.first) {
      used[ph.second] = true;
      x[ph.second] = now_x;
      y[ph.second] = now_y;
      now_y += ph.first.second;
      now_w -= ph.first.second;
    } else {
      used[pw.second] = true;
      x[pw.second] = now_x;
      y[pw.second] = now_y;
      now_x += pw.first.second;
      now_h -= pw.first.second;
    }

    cnt++;
  }

  for (int i = 1; i <= n; i++) {
    cout << x[i] << " " << y[i] << endl;
  }

  return 0;
}
