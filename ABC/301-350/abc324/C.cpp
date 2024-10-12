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

int n, a[int(5e5 + 5)], b[int(5e5 + 5)];
string s[int(5e5 + 5)], t;
vector<int> ans;

void calc(int idx) {
  int m = min(int(s[idx].length()), int(t.length()));
  for (int i = 0; i < m; i++) {
    if (s[idx][i] == t[i]) {
      a[idx]++;
    } else {
      break;
    }
  }

  for (int i = 0; i < m; i++) {
    if (s[idx][s[idx].length() - 1 - i] == t[t.length() - 1 - i]) {
      b[idx]++;
    } else {
      break;
    }
  }

  return;
}

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    calc(i);

    int sl = s[i].length(), tl = t.length();

    if (sl == tl) {
      if (a[i] + b[i] >= min(sl, tl) - 1) {
        ans.push_back(i);
      }
    } else if (abs(sl - tl) == 1) {
      if (a[i] + b[i] >= min(sl, tl)) {
        ans.push_back(i);
      }
    }
  }

  int k = ans.size();
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i];
    if (i == k - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
