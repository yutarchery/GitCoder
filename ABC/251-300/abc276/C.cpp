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

int n, p[105], ans[105];

void solve(int idx) {
  int head = 0, head_idx;
  for (int i = idx + 1; i <= n; i++) {
    if (p[i] < p[idx] && head < p[i]) {
      head = max(head, p[i]);
      head_idx = i;
    }
  }
  swap(p[idx], p[head_idx]);
  sort(p + idx + 1, p + n + 1, greater<int>());

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  for (int i = n; i >= 1; i--) {
    if (p[i - 1] >= p[i]) {
      solve(i - 1);
      break;
    }
  }

  cout << p[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << p[i];
  }
  cout << endl;

  return 0;
}