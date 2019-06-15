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
struct unit{
    int hp,wp,hpoz,wpoz;
};

vector<unit> p;
vector<int> sorth,sortw;
int n,q;

void mesort(){
    //cout << 1 << endl;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if(p[i].hp<p[j].hp){
                int temp=sorth[i];
                sorth[i]=sorth[j];
                sorth[j]=temp;
            }
            
            if(p[i].wp<p[j].wp){
                int temp=sortw[i];
                sortw[i]=sortw[j];
                sortw[j]=temp;
            }
        }
    }
    //cout << 2 << endl;
    for (int i=0;i<n;i++){
        int brh=sorth[i],brw=sortw[i];
        p[brh].hpoz=i;
        p[brw].wpoz=i;
    }
   // cout << 3 << endl;
}
void sw(int a,int b){
    
    int temp=p[a].hp;
    p[a].hp=p[b].hp;
    p[b].hp=temp;
   // cout << 3.2 << endl;
    int ah=p[a].hpoz,bh=p[b].hpoz;
    
    temp=sorth[ah];
    sorth[ah]=sorth[bh];
    sorth[bh]=temp;
    //cout << 3.4 << endl;
    temp=p[a].hpoz;
    p[a].hpoz=p[b].hpoz;
    p[b].hpoz=temp;
   // cout << 4 << endl;
}

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
	cin >> n>>q;
	for (int i=0;i<n;i++){
	    unit temp;
	    cin >>  temp.wp;
	    sorth.push_back(i);
	    sortw.push_back(i);
	    p.push_back(temp);
	}
	for (int i=0;i<n;i++){
	    cin >> p[i].hp;
	}
	mesort();
	for (int i=0;i<q;i++){
	    int a,b;
	    cin >> a >> b;
	    sw(a-1,b-1);
	    unsigned long long sum=0;
	    for (int j=0;j<n;j++){
	        int idh=sorth[j],idw=sortw[j];
	        if (idh==idw){
	            idw=sortw[j+1];
	            sum=sum+(p[idh].hp*p[idw].wp);
	            idw=sortw[j];
	            idh=sorth[j+1];
	            sum=sum+(p[idh].hp*p[idw].wp);
	            j++;
	        }else{
	            sum=sum+(p[idh].hp*p[idw].wp);
	        }
	        
	    }
	    cout << sum << endl;
	}
	
	
	return 0;
}

