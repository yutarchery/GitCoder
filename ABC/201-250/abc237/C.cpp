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

int n, m;
string s;

int main() {
  cin >> s;
  n = s.length();
  int start = 0, end = n - 1, cnt = 0;

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'a') {
      end--;
      cnt++;
    } else {
      break;
    }
  }
  for (int i = 0; i < cnt; i++) {
    if (s[i] == 'a') {
      start++;
    } else {
      break;
    }
  }

  for (int i = 0; i <= end - start; i++) {
    if (s[start + i] == s[end - i]) {
      continue;
    } else {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
