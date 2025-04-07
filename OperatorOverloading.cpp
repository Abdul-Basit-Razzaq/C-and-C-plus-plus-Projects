/*Create a class integer having one private data member number. You have to create

Implement a class called Integer. The integer class will have one data members:
•	int number;	//integer number.
You have to implement default constructor, overloaded constructor, setter, getter, 
display function and overload the operators are +, -, *, /, %, ^, <,>, ==, != , ++, -- , 
your source code should be as below
*/

#include <iostream>
#include<cmath>
using namespace std;
class Ar{
    private:
    double a;
    double b;
    public:
    Ar();
    Ar(double,double);
    void setA(double);
    double getA();
    void setB(double);
    double getB();
    Ar operator +(Ar & obj);
    bool operator >(Ar & obj);
    Ar operator *(Ar & obj);
    Ar operator ^(Ar & obj);
    bool operator !=(Ar & obj);
    Ar operator =(Ar & obj);
    void display(){
        cout<<"a :"<<a<<endl<<"b :"<<b<<endl;
    }
};
 Ar::Ar(){
     a=0;
     b=0;
 }
    Ar::Ar(double a,double b){
        setA(a);
        setB(b);
    }
    void Ar::setA(double a){
        this->a=a;
    }
    double Ar::getA(){
        cout<<" first :";
        return a;cout<<endl;
    }
    void Ar::setB(double b){
        this->b=b;
    }
    double Ar::getB(){
        cout<<" second :";
        return b;cout<<endl;
    }
   Ar Ar :: operator +(Ar & obj){
       Ar h;
       h.a=this->a+obj.a;
       h.b=this->b+obj.b;
       return h;cout<<endl;}
    bool Ar::operator >(Ar & obj){
        if (this->a>obj.a&&this->b>obj.b){
            cout<<endl<<" first is greater "<<endl;
            return true;
        }
        else {return false;}
    }
    Ar Ar :: operator *(Ar & obj){
        Ar h;
        h.a=this->a*obj.a;
        h.b=this->b*obj.b;
     return h;}
 Ar  Ar :: operator ^(Ar & obj){
     Ar h;
  h.a=pow(obj.a,this->a);
  h.b=pow(obj.b,this->b);
  h.display();
     return h;
     
 }
    bool Ar:: operator !=(Ar & obj){
        if (obj.a!=this->a && obj.b!=this->b){
            cout<<" they both are not equal "<<endl;
            return true;
        }
        else {return false;}
    }
    Ar Ar:: operator =(Ar & obj){
        obj.a=this->a;
        obj.b=this->b;
        return obj;
    }
int main()
{
  Ar a(2,2);
cout<<  a.getA();
  cout<<a.getB();
  Ar a2(5,6);
a2!=a;
a^a2;
cout<<a2.getA()<<endl;
cout<<a2.getB();
a2>a;
    return 0;
}
