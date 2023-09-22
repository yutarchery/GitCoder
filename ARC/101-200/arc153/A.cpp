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

int n;
vector<ll> ans;
map<ll, bool> used;

void solve(int num, int turn, ll now) {
  if (turn == 1) {
    now += num * 1e6;
  } else if (turn == 2) {
    now += num * 1e5;
  } else if (turn == 3) {
    now += num * 11 * 1e3;
  } else if (turn == 4) {
    now += num * 101;
  } else if (turn == 5) {
    now += num * 10;
  } else {
    if (!used[now]) {
      ans.push_back(now);
    }
    used[now] = true;
    return;
  }

  for (int i = 0; i < 10; i++) {
    solve(i, turn + 1, now);
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < 10; i++) {
    solve(i, 1, 0);
  }

  vector<int> res;
  for (int i = 1; i <= 9; i++) {
    for (int j : ans) {
      res.push_back(11 * i * 1e7 + j);
    }
  }
  sort(res.begin(), res.end());

  cout << res[n - 1] << endl;

  return 0;
}