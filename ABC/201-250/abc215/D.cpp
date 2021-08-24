#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int n, m;
int a[int(1e5 + 5)];

bool used[int(1e5 + 5)];

vector<int> ans;

int update(int num){
  if (used[num]) return 0;
  for (int i = num; i <= m; i += num){
    used[i] = true;
  }
  return 0;
}

int main(){
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    for (int j = 2; j * j <= a[i]; j++){
      if (a[i] % j != 0) continue;
      update(j);
      update(a[i] / j);
    }
    if (a[i] != 1){
      update(a[i]);
    }
  }

  for (int i = 1; i <= m; i++){
    if (!used[i]){
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i : ans) cout << i << endl;

  return 0;
}