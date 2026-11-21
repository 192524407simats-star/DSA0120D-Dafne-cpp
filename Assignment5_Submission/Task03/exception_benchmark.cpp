#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;using C=chrono::steady_clock;
int main(int argc,char**argv){int pct=argc>1?stoi(argv[1]):1;const int n=1000000;vector<double>v(n,10);for(int i=0;i<n*pct/100;i++)v[i]=-1;long long ok=0;auto a=C::now();for(double x:v)if(x>=0)++ok;auto b=C::now();cout<<"return-code invalid="<<pct<<" accepted="<<ok<<" ms="<<chrono::duration<double,milli>(b-a).count()<<'\n';ok=0;auto c=C::now();for(double x:v)try{if(x<0)throw invalid_argument("negative");++ok;}catch(const invalid_argument&){}auto d=C::now();cout<<"exception invalid="<<pct<<" accepted="<<ok<<" ms="<<chrono::duration<double,milli>(d-c).count()<<'\n';}
