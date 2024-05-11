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

int n, a;
deque<int> que;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    que.push_back(a);

    while (que.size() >= 2) {
      int q1 = que.back();
      que.pop_back();
      int q2 = que.back();
      que.pop_back();

      if (q1 == q2) {
        que.push_back(q1 + 1);
        continue;
      } else {
        que.push_back(q2);
        que.push_back(q1);
        break;
      }
    }
  }

  cout << que.size() << endl;

  return 0;
}
