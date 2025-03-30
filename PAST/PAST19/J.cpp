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

int n, a[15], ans = 1e9;
bool used[15];

void solve(int turn, vector<int> now) {
  if (turn == n) {
    sort(now.begin(), now.end());
    ans = min(ans, now[n - 1] - now[0]);
    return;
  }

  int now_i;
  for (int i = 0; i < n * 3; i++) {
    if (!used[i]) {
      now[turn] += a[i];
      used[i] = true;
      now_i = i;
      break;
    }
  }

  for (int j = 0; j < n * 3; j++) {
    if (used[j]) {
      continue;
    }
    used[j] = true;
    now[turn] += a[j];
    for (int k = j + 1; k < n * 3; k++) {
      if (used[k]) {
        continue;
      }
      used[k] = true;
      now[turn] += a[k];
      solve(turn + 1, now);
      used[k] = false;
      now[turn] -= a[k];
    }
    used[j] = false;
    now[turn] -= a[j];
  }

  used[now_i] = false;
  now[turn] -= a[now_i];

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n * 3; i++) {
    cin >> a[i];
  }
  sort(a, a + n * 3);

  vector<int> now(n);
  solve(0, now);
  cout << ans << endl;

  return 0;
}
