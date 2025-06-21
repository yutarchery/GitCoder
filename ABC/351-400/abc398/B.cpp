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

int a[7], cnt[15];

int main() {
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  int cnt2 = 0, cnt3 = 0;
  for (int i = 0; i <= 13; i++) {
    if (cnt[i] >= 3) {
      cnt3++;
    } else if (cnt[i] == 2) {
      cnt2++;
    }
  }

  if (cnt3 >= 2) {
    Yes();
  } else if (cnt3 == 1 && cnt2 >= 1) {
    Yes();
  } else {
    No();
  }

  return 0;
}
