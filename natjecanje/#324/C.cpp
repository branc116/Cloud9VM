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

string a,b,c;
vector <int> d,e;
int dif,dif_a,dif_b,same;
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
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
	int useless;
	cin >> useless >> dif;
	cin >> a >> b;
	for (int i=0;i<a.size();i++){
		if (a[i]==b[i]){
			d.push_back(i);
			same++;
		}
		else {
			e.push_back(i);
		}
	}
	c=a;
	dif_a=0;
	dif_b=dif-same;
	if (same>dif){
		cout << -1;
		return 0;
	}
	int poz_e=0;
	int poz_d=0;
	while (dif_a!=dif||dif_b!=dif){
		if (dif_a<dif && dif_b<dif&&poz_d!=d.size()){
			a[poz_d]--;
			b[poz_d]--;
			dif_a++;
			dif_b++;
			poz_d++;
		}
		else if (dif_a>dif && dif_b>dif && poz_e!=d.size()){
			c[poz_d]=a[poz_d];
			dif_a --;
			dif_b--;
			poz_d++;
		}else if (dif_a<dif && poz_e!=e.size()){
			
			if (dif_b==dif){
				
			}else if (dif_b>dif){
				
			}
			
		}else if (dif_a>dif && poz_e!=e.size()){
			if (dif_b==dif){
				
			}else if (dif_b<dif){
				
			}
		}else if (dif_a==dif && poz_e!=e.size()){
			if (dif_b>dif){
				
			}else if (dif_b==dif){
				
			}
		}else if (e.size()==poz_e && d.size()==poz_d){
			cout << -1;
			return 0;
		}
		
	}
	return 0;
}

