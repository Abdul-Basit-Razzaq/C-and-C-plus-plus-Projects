#include <iostream>
using namespace std;
class BankAccount{
private:
 string Title;
string AccountNumber;
double Balance;
public:
BankAccount();
BankAccount(string,string,double);
void setTitle(string);
string getTitle();
void setAccountNumber(string);
string getAccountNumber();
void setBalance(double);
double getBalance();
 double Deposit(double);
	double Withdraw(double);
	void display();
};
BankAccount::BankAccount(){
    Title="any";
    AccountNumber="B221S0513";
    Balance=0.9;
}
BankAccount::BankAccount(string title ,string acN,double B){
    setTitle(title);
    setAccountNumber(acN);
    setBalance(B);
}
void BankAccount::setTitle(string t){
    Title=t;
}
string BankAccount::getTitle(){
    cout<<"Title :";
    return Title;
}
void BankAccount::setAccountNumber(string acN){
    AccountNumber=acN;
}
string BankAccount::getAccountNumber(){
    return AccountNumber;
}
void BankAccount::setBalance(double b){
    Balance=b;
}
double BankAccount:: getBalance(){
    cout<<endl<<"Balance :";
    return Balance;
}
 double BankAccount::Deposit(double balance){
    Balance=Balance+balance;
    cout<<"Amount after Deposit :";
    return Balance;cout<<endl;
 }
	double BankAccount::Withdraw(double balance){
	    Balance=Balance-balance;
	    cout<<"Amount after Withdraw :";
	return Balance;}
	void BankAccount::display(){
	    cout<<"Title :"<<Title<<endl
	    <<"Account Number :"<<AccountNumber<<endl
	    <<"Balance :"<<Balance<<endl;
	}
	class SavingAccount :public BankAccount{
	    public:
	    void setInterest(double);
	    double CalculateInterest();
	    void display();
	    void setBalance(double);
	    private:
	    double interest;
	    double Balance;
	};
	void SavingAccount::setInterest(double in){
	    interest=in;
	}
	    double SavingAccount::CalculateInterest(){
	   Balance=Balance*interest;
	   return Balance;
	    }
	    void SavingAccount::display(){
	       BankAccount::display();
	        cout<<" interest :"<<interest<<endl;
	    }
	      void SavingAccount::setBalance(double b){
	          Balance=b;
	      }
int main()
{ BankAccount b1("HBL","l1f21bsse",120000);
b1.display();
cout<<b1.Withdraw(1200)<<endl;
    cout<<b1.Deposit(1200);
    SavingAccount s;
    s.setBalance(1200);
    s.setInterest(1.051);cout<<endl;
   cout<< s.CalculateInterest();

    return 0;
}
