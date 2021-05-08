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

int H, W;
int A[2005][2005], h[2005], w[2005];

int main(){
  cin >> H >> W;
  for(int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
      h[i] += A[i][j]; w[j] += A[i][j];
    }
  }
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cout << h[i] + w[j] - A[i][j];
      if (j == W - 1) cout << endl;
      else cout << " ";
    }
  }

  return 0;
}