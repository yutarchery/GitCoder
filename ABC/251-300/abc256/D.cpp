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

int n, cnt[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    cnt[l]++;
    cnt[r]--;
  }

  for (int i = 1; i <= int(2e5); i++) {
    cnt[i] += cnt[i - 1];
  }

  bool left = true;
  for (int i = 1; i <= int(2e5); i++) {
    if (left && cnt[i] > 0) {
      cout << i << " ";
      left = false;
    } else if (!left && cnt[i] == 0) {
      cout << i << endl;
      left = true;
    }
  }

  return 0;
}