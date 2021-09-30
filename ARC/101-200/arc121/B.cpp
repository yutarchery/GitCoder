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

int n;
vector<ll> value[3];
char color[3] = {'R', 'G', 'B'};

ll solve(int i, int j){

  if (value[i].size() == 0 || value[j].size() == 0){
    return 1e16;
  }

  sort(value[j].begin(), value[j].end());

  ll ans = 1e16;
  for (ll vi : value[i]){
    int r = value[j].size() - 1;
    if (vi >= value[j][r]){
      ans = min(ans, vi - value[j][r]);
      continue;
    }
    if (vi <= value[j][0]){
      ans = min(ans, value[j][0] - vi);
      continue;
    }

    int l = 0;
    while (r - l > 1){
      int mid = (l + r) / 2;
      if (vi <= value[j][mid]){
        r = mid;
      }else{
        l = mid;
      }
    }

    ans = min(ans, value[j][r] - vi);
    ans = min(ans, vi - value[j][l]);
  }

  return ans;
}

int main(){
  cin >> n;
  for (int i = 0; i < 2 * n; i++){
    ll a; char c;
    cin >> a >> c;
    for (int j = 0; j < 3; j++){
      if (color[j] == c){
        value[j].push_back(a);
      }
    }
  }


  for (int i = 0; i < 3; i++){
    if (value[i].size() % 2 == 0) continue;

    for (int j = i + 1; j < 3; j++){
      if (value[j].size() % 2 == 0) continue;

      ll k = 3 - (i + j);

      cout << min(solve(i, j), solve(i, k) + solve(j, k)) << endl;

      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}