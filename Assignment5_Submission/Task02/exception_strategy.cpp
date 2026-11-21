#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class BillingError:public runtime_error{public:using runtime_error::runtime_error;};
class ClaimError:public BillingError{public:using BillingError::BillingError;};
class MissingPatientError:public BillingError{public:using BillingError::BillingError;};
class UnknownPackageError:public BillingError{public:using BillingError::BillingError;};
struct Guard{string s;Guard(string x):s(move(x)){}~Guard(){cout<<"released "<<s<<'\n';}};
void validate(double x){if(x<0)throw invalid_argument("negative");if(x>1e6)throw out_of_range("too large");cout<<"ok ";}
void process(double x){try{validate(x);}catch(const out_of_range&e){cout<<"[log "<<e.what()<<"] ";throw;}}
double approve(double b,double c){if(b<0||c<0)throw invalid_argument("negative amount");if(b>c)throw ClaimError("exceeds cover");return b;}
double settle(double b,double c){try{return approve(b,c);}catch(const ClaimError&e){cout<<"audit: "<<e.what()<<'\n';throw;}}
int main(){for(double x:{100.0,-5.0,2e6})try{process(x);cout<<"done ";}catch(const exception&e){cout<<"caught "<<e.what()<<' ';}cout<<'\n';double a[][2]={{40000,50000},{60000,50000},{-1,50000}};for(auto&c:a)try{cout<<"approved "<<settle(c[0],c[1])<<'\n';}catch(const exception&e){cout<<"rejected: "<<e.what()<<'\n';}try{Guard g("claim-file");throw ClaimError("test failure");}catch(const exception&e){cout<<"top-level caught: "<<e.what()<<'\n';}}
