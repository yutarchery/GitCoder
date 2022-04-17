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

string s;
int n, k, cnt[int(2e5 + 5)];

bool judge(int length) {
  for (int i = length; i <= n; i++) {
    if (cnt[i] - cnt[i - length] <= k) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> s;
  cin >> k;

  n = s.length();
  for (int i = 1; i <= n; i++) {
    cnt[i] = cnt[i - 1];
    if (s[i - 1] == '.') {
      cnt[i]++;
    }
  }

  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (judge(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;

  return 0;
}