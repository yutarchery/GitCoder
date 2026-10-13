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

int n, a[int(4e5 + 5)];
int whole_xor = 0, ng = 0;

map<int, int> cnt;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    whole_xor ^= a[i];
  }

  for (int i = 1; i <= n; i++) {
    int now = whole_xor ^ a[i];

    if (now == 0) {
      cout << "Win\n";
      return 0;
    }

    if (cnt[now] > 0) {
      ng++;
    }
  }

  if ((n - ng) % 2 == 0) {
    cout << "Lose\n";
  } else {
    cout << "Win\n";
  }

  return 0;
}
