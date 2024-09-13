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

int q, num, x;
int cnt[int(1e6 + 5)];

set<int> st;

int main() {
  cin >> q;
  while (q > 0) {
    cin >> num;
    if (num == 1) {
      cin >> x;
      cnt[x]++;
      st.insert(x);
    } else if (num == 2) {
      cin >> x;
      cnt[x]--;
      if (cnt[x] == 0) {
        st.erase(x);
      }
    } else {
      cout << int(st.size()) << endl;
    }
    q--;
  }

  return 0;
}