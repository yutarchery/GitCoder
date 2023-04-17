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

int n;
string s, t;
int cnt_s[26], cnt_t[26];

bool judge(int idx) {
  for (int j = 0; j < n; j++) {
    if (idx == n) {
      return true;
    }

    if (s[idx] == t[j]) {
      idx++;
    }
  }

  return false;
}

int main() {
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    cnt_s[s[i] - 'a']++;
    cnt_t[t[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt_s[i] != cnt_t[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (s == t) {
    cout << 0 << endl;
    return 0;
  }

  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (judge(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;

  return 0;
}