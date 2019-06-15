//©branimir116™
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iomanip>
#include <list>
#include <queue>
#include <map>

using namespace std;
#define mod 1000000007
#define eps (1.0E-9)

queue<int> q;
bool notprm[20010];
bool graf[210][210];
bool bill[210];
int n;
vector<int> a;

vector<vector<int> > povezan,petlje;



struct point{
	double x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};


bool dfs(int cur,int petlja){
	bill[cur]=true;
	if (povezan[cur].size()<2){
		return false;
	}
	petlje[petlja].push_back(cur);
	bool poc;
	
	for (int i=0;i<povezan[cur].size();i++){
		int broj=povezan[cur][i];
		if (!bill[broj]){
			if(!dfs(broj,petlja)){
				return false;
			}
			
		}
	}
	return true;
}

void debug(){
	for (int i=0;i<n;i++){
		cout << a[i] << ":  ";
		for (int j=0;j<povezan[i].size();j++){
			int broj=povezan[i][j];
			cout << a[broj] << ' ';
		}
		cout << endl;
	}
}
void ispis(int red){
	cout << red << ":  ";
	
	for (int i=0;i<petlje[red].size();i++){
		int id=petlje[red][i];
		cout << a[id] << "  ";
	}
	cout << endl;
}
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	notprm[0]=true;
	notprm[1]=true;
	for (int i=2;i<20010;i++){
		if (!notprm[i]){
			for (int j=i+i;j<20010;j+=i){
				notprm[j]=true;
			}
		}
	}
}
int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
int lcm(int a, int b){
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}
long long fast_pow(int a, int n){
	long long result = 1;
	long long power = n;
	long long value = a;
	while (power>0)
	{
		if (power & 1)
		{
			result = result*value;
			result = result % mod;
		}
		value = value*value;
		value = value % mod;
		power /= 2;
		//power >>= 1;
	}
	return result;
}

int main()
{
	init();
	cin >> n;
	for (int i=0;i<n;i++){
		int temp;
		cin >> temp;
		a.push_back(temp);
		vector<int> temppov;
		for (int j=0;j<i;j++){
			int broj=a[i]+a[j];
			if (!notprm[broj]){
				povezan[j].push_back(i);
				temppov.push_back(j);
				graf[i][j]=true;		
				graf[j][i]=true;
			}
		}
		povezan.push_back(temppov);
	}
	int jod=0;
	for (int i=0;i<n;i++){
		if (!bill[i]){
			vector<int> nis;
			petlje.push_back(nis);
			if (!dfs(i,jod)){
				cout << "Impossible";
				return 0;
			}
			ispis(jod);
			jod++;	
		}
	}
	debug();
	cout << jod;
	return 0;
}

