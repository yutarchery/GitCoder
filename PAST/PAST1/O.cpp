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

int n, a[int(3e4 + 5)][6];

double dice[int(3e4 + 5)][6], max_dice = 0;

priority_queue<pair<int, Pii>> que;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
      que.push({a[i][j], {i, j}});
    }
  }

  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();

    int i = q.second.first, j = q.second.second;
    dice[i][j] = max_dice + 1;

    double now = 0;
    for (int k = 0; k < 6; k++) {
      now += dice[i][k] / 6;
    }
    max_dice = max(max_dice, now);
  }

  cout << fixed << setprecision(10) << max_dice + 1 << endl;

  return 0;
}
