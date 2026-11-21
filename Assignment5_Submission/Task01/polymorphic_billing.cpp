#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;
class Bill{protected:string patient;public:explicit Bill(string p):patient(move(p)){} virtual double total()const=0;virtual string type()const=0;virtual void print()const{cout<<type()<<" "<<patient<<": "<<total()<<'\n';}virtual ~Bill()=default;};
class OutPatient:public Bill{double consult,tests;public:OutPatient(string p,double c,double t):Bill(move(p)),consult(c),tests(t){if(c<0||t<0)throw invalid_argument("negative charge");}double total()const override{return consult+tests;}string type()const override{return "OP";}};
class InPatient:public Bill{int days;double rate,procedures,medicines;public:InPatient(string p,int d,double r,double pr,double m):Bill(move(p)),days(d),rate(r),procedures(pr),medicines(m){if(d<0||r<0||pr<0||m<0)throw invalid_argument("negative charge");}double total()const override{return days*rate+procedures+medicines;}string type()const override{return "IP";}};
class DayCare:public Bill{double package;public:DayCare(string p,double x):Bill(move(p)),package(x){if(x<0)throw invalid_argument("negative charge");}double total()const override{return package;}string type()const override{return "DayCare";}};
class Emergency:public Bill{double base,hourRate;int hours;public:Emergency(string p,double b,int h,double r):Bill(move(p)),base(b),hourRate(r),hours(h){if(b<0||h<0||r<0)throw invalid_argument("negative charge");}double total()const override{return base+hours*hourRate;}string type()const override{return "Emergency";}};
class Payer{public:virtual double amountCovered(const Bill&)const=0;virtual string name()const=0;virtual ~Payer()=default;};
class SelfPay:public Payer{public:double amountCovered(const Bill&)const override{return 0;}string name()const override{return "SelfPay";}};
class Insurance:public Payer{double limit,copay;public:Insurance(double l,double c):limit(l),copay(c){}double amountCovered(const Bill&b)const override{return min(b.total(),limit)*(100-copay)/100;}string name()const override{return "Insurance";}};
class GovernmentScheme:public Payer{double rate;public:explicit GovernmentScheme(double r):rate(r){}double amountCovered(const Bill&b)const override{return min(b.total(),rate);}string name()const override{return "Government";}};
class CorporatePayer:public Payer{double pct;public:explicit CorporatePayer(double p):pct(p){}double amountCovered(const Bill&b)const override{return b.total()*pct/100;}string name()const override{return "Corporate";}};
int main(){vector<unique_ptr<Bill>> bills;bills.push_back(make_unique<OutPatient>("Ravi",500,1200));bills.push_back(make_unique<InPatient>("Meena",3,2500,40000,5000));bills.push_back(make_unique<DayCare>("Asha",18000));bills.push_back(make_unique<Emergency>("Kiran",2000,4,750));double sum=0;for(auto&b:bills){b->print();sum+=b->total();}cout<<"Day total: "<<sum<<'\n';Insurance ins(50000,20);GovernmentScheme gov(15000);CorporatePayer corp(60);const Payer* ps[]={&ins,&gov,&corp};for(auto&b:bills)for(auto*p:ps)cout<<p->name()<<" covers "<<p->amountCovered(*b)<<'\n';}
