#include <chrono>
#include <iostream>
#include <memory>
#include <variant>
#include <vector>
using namespace std;using Clock=chrono::steady_clock;
struct Base{virtual double total()const=0;virtual~Base()=default;};
struct OP:Base{double a,b;OP(double x,double y):a(x),b(y){}double total()const override{return a+b;}};
struct IP:Base{double d,r,p;IP(double x,double y,double z):d(x),r(y),p(z){}double total()const override{return d*r+p;}};
struct S{int type;double x,y,z;};double sw(const S&b){return b.type==0?b.x+b.y:b.x*b.y+b.z;}
using V=variant<OP,IP>;
template<class F>void run(const char*n,F f){auto a=Clock::now();volatile double sum=f();auto ms=chrono::duration<double,milli>(Clock::now()-a).count();cout<<n<<" checksum="<<sum<<" time_ms="<<ms<<'\n';}
int main(int argc,char**argv){size_t n=argc>1?stoull(argv[1]):1000000;vector<unique_ptr<Base>>p;vector<S>s;vector<V>v;p.reserve(n);s.reserve(n);v.reserve(n);for(size_t i=0;i<n;i++)if(i%2==0){p.push_back(make_unique<OP>(500,1200));s.push_back({0,500,1200,0});v.emplace_back(OP(500,1200));}else{p.push_back(make_unique<IP>(3,2500,40000));s.push_back({1,3,2500,40000});v.emplace_back(IP(3,2500,40000));}run("virtual",[&]{double x=0;for(auto&b:p)x+=b->total();return x;});run("switch",[&]{double x=0;for(auto&b:s)x+=sw(b);return x;});run("variant",[&]{double x=0;for(auto&b:v)x+=visit([](auto&t){return t.total();},b);return x;});}
