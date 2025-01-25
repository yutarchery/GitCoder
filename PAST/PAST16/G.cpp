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

int n, a[12], order[12];

bool check(int idx) {
  vector<int> now;
  for (int i = 0; i < 3 * n; i++) {
    if (order[i] == idx) {
      now.push_back(a[i]);
    }
  }
  sort(now.begin(), now.end());

  if (now[0] + now[1] <= now[2]) {
    return false;
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < 3 * n; i++) {
    cin >> a[i];
    order[i] = i / 3;
  }

  int ans = 0;
  do {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      flag = flag & check(i);
    }

    if (flag) {
      ans++;
    }
  } while (next_permutation(order, order + 3 * n));

  for (int i = 1; i <= n; i++) {
    ans /= i;
  }
  cout << ans << endl;

  return 0;
}
