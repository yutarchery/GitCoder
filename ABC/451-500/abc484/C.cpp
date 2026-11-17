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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
int cnt_a[int(2e5 + 5)], cnt_b[int(2e5 + 5)];

bool judge() {
  int now_b = 1, cnt = 0, changed_a = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[now_b]) {
      now_b++;
      continue;
    }

    if (cnt == 0) {
      cnt++;
      changed_a = a[i];
      continue;
    }

    if (b[now_b] == changed_a) {
      now_b++;
      i--;
      changed_a = 0;
      continue;
    }
    return false;
  }
  return true;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt_a[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    cnt_b[b[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt_a[i] != cnt_b[i]) {
      No();
      return 0;
    }
  }

  bool judge_a = judge();
  for (int i = 1; i <= n; i++) {
    swap(a[i], b[i]);
  }
  bool judge_b = judge();

  (judge_a | judge_b) ? Yes() : No();

  return 0;
}
