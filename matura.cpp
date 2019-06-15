#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

double mybin(double iz, double is){
 double rj=1;
 for(double i=iz;i>(iz-is);i--){
  rj *= i;
 }
 for(double i=1;i<=is;i++)
  rj /= i;
 return rj;
}
double mypow(double base, double eks){
 double rj=1;
 for(double i=0;i<eks;i++){
  rj*=base;
 }
 return rj;
}

int main(){
 double rj=0;
 cout << "3c2=" << mybin(3,2) << endl;
 cout << "3pow2=" << mypow(3,2) << endl;
 for(double i=100;i>=0;i--){
 
  
 if(!((int)i%2))
  rj+=(mybin(100,100-i)*mypow(2,i));
 else
  rj-=(mybin(100,100-i)*mypow(2,i));
  
  cout << "100c" << i << "=" << mybin(100,100-i) << ", 2^" << i << "=" << mypow(2,i) << ". E se zbraja zbrajanje? (0=NE/1=DA) " << !((int)i%2) << ". Trenutno rijesenje= " << rj << endl;
 }
 cout << rj;
 return 0;
}