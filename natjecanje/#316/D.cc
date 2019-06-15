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

struct vertex{
	int depth;
	int parent;
	int c;
	vector<int> children;
};
vector<vertex> p;
int n;
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
	vertex temp;
	temp.depth=1;
	temp.parent=-1;
	p.push_back(temp);
	p.push_back(temp);
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
string rj;
void makestring(int id,int doo){
	if (p[id].depth==doo){rj+=p[id].c;return;}
	for (int i=0;i<p[id].children.size();i++){
		makestring(p[id].children[i],doo);
	}
	return;
}
bool palind(string a){
	int slova[26];
	for (int i=0;i<26;i++){
		slova[i]=0;
	}
	for (int i=0;i<a.size();i++){
		slova[a[i]-'a']++;
	}
	int nepar=0;
	if (a.size()%2)nepar--;
	for (int i=0;i<26;i++){
		if (slova[i]%2)nepar++;
		if (nepar>0)return false;
	}
	return true;
}
int main()
{
	init();
	int n,q;
	cin >> n>>q;
	for (int i=2;i<=n;i++){
		vertex temp;
		cin >> temp.parent;
		temp.depth=p[temp.parent].depth+1;
		//cout << i << "  " << temp.depth << endl;
		p.push_back(temp);
		p[temp.parent].children.push_back(i);
		
	}	
	string s;
	cin >> s;
	for (int i=1;i<=n;i++)
		p[i].c=s[i-1];
	for(int i=0;i<q;i++){
		rj="";
		int id,doo;
		cin >> id >> doo;
		if (p[id].depth>=doo){
			cout << "Yes" << endl;
		}else{
			makestring(id,doo);
			//cout << rj << endl;
			if (palind(rj))cout << "Yes" <<endl;else cout << "No" << endl;
		}
	}
	return 0;
}

