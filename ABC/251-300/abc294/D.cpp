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

int n, q, nxt = 1;
set<int> waiting;
vector<int> ans;

int main() {
  cin >> n >> q;

  while (q--) {
    int num;
    cin >> num;

    if (num == 1) {
      waiting.insert(nxt);
      nxt++;
    } else if (num == 2) {
      int x;
      cin >> x;
      waiting.erase(x);
    } else {
      for (int i : waiting) {
        ans.push_back(i);
        break;
      }
    }
  }

  for (int a : ans) {
    cout << a << endl;
  }

  return 0;
}
