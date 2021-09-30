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

int N;
ll X[int(2e5 + 5)], Y[int(2e5 + 5)];
Pli Xi[int(2e5 + 5)], Yi[int(2e5 + 5)];

vector <int> cand;
vector <ll> dist;

ll calcDist(int i, int j){
  return max(abs(X[i] - X[j]), abs(Y[i] - Y[j]));
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> X[i] >> Y[i];
    Xi[i] = {X[i], i};
    Yi[i] = {Y[i], i};
  }
  sort(Xi, Xi + N);
  sort(Yi, Yi + N);

  for (int i = 0; i < 3; i++){
    cand.push_back(Xi[i].se);
    cand.push_back(Xi[N - 1 - i].se);
    cand.push_back(Yi[i].se);
    cand.push_back(Yi[N - 1 - i].se);
  }
  
  sort(cand.begin(), cand.end());
  cand.erase(unique(cand.begin(), cand.end()), cand.end());

  for (int i = 0; i < cand.size(); i++){
    for (int j = i + 1; j < cand.size(); j++){
      dist.push_back(calcDist(cand[i], cand[j]));
    }
  }
  sort(dist.begin(), dist.end(), greater<ll>());
  cout << dist[1] << endl;

  return 0;
}