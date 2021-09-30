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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, value[3005][5];

bool used[32];

void setUsed(int x) {
  fill(used, used + 32, false);
  for (int i = 0; i < n; i++) {
    int index = 0;
    for (int j = 0; j < 5; j++) {
      index *= 2;
      if (value[i][j] >= x) {
        index++;
      }
    }
    used[index] = true;
  }
}

bool check(int x) {
  setUsed(x);

  for (int i = 0; i < 32; i++) {
    for (int j = i; j < 32; j++) {
      for (int k = j; k < 32; k++) {
        if (used[i] && used[j] && used[k]) {
          if ((i | j | k) == 31) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int solve(int l, int r) {
  if (r - l == 1) {
    return l;
  } else {
    int mid = (l + r) / 2;
    if (check(mid)) {
      return solve(mid, r);
    } else {
      return solve(l, mid);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> value[i][j];
    }
  }
  cout << solve(0, int(1e9 + 1)) << endl;

  return 0;
}