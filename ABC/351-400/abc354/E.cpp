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

int n, a[20], b[20];
bool visited[1 << 20][2];
int ans[1 << 20][2];

int solve(int num, int turn) {
  if (visited[num][turn]) {
    return ans[num][turn];
  }

  visited[num][turn] = true;
  for (int i = 1; i <= n; i++) {
    if ((num & (1 << i)) > 0) {
      continue;
    }

    for (int j = i + 1; j <= n; j++) {
      if ((num & (1 << j)) > 0) {
        continue;
      }

      if (a[i] == a[j] || b[i] == b[j]) {
        int next = solve(num + (1 << i) + (1 << j), 1 - turn);
        if (next == turn) {
          return ans[num][turn] = turn;
        }
      }
    }
  }

  return ans[num][turn] = 1 - turn;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  if (solve(0, 0) == 0) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  return 0;
}
