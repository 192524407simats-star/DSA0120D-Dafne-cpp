#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Bill{protected:string patient;public:Bill(string p):patient(move(p)){}virtual double total()const=0;virtual string type()const=0;virtual~Bill()=default;};
class OPBill:public Bill{double c,t;public:OPBill(string p,double x,double y):Bill(move(p)),c(x),t(y){}double total()const override{return c+t;}string type()const override{return "OP";}};
class MaternityBill:public Bill{double delivery,room;public:MaternityBill(string p,double d,double r):Bill(move(p)),delivery(d),room(r){}double total()const override{return delivery+room;}string type()const override{return "Maternity";}};
class Payer{public:virtual double cover(const Bill&)const=0;virtual string name()const=0;virtual~Payer()=default;};
class Insurance:public Payer{double limit;public:Insurance(double x):limit(x){}double cover(const Bill&b)const override{return min(limit,b.total());}string name()const override{return "Insurance";}};
class CharityFund:public Payer{double pct;public:CharityFund(double p):pct(p){}double cover(const Bill&b)const override{return b.total()*pct/100;}string name()const override{return "CharityFund";}};
int main(){vector<unique_ptr<Bill>>b;b.push_back(make_unique<OPBill>("Ravi",500,1200));b.push_back(make_unique<MaternityBill>("Latha",30000,12000));Insurance i(20000);CharityFund c(25);for(auto&x:b)cout<<x->type()<<" total="<<x->total()<<" | "<<i.name()<<'='<<i.cover(*x)<<" | "<<c.name()<<'='<<c.cover(*x)<<'\n';}
