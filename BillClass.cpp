// class of bill
#include <iostream>
using namespace std;
class Bill{
    public:
    Bill(char*,int);
    virtual ~Bill();
    void setAdrress(char*);
    char *getAddress();
    void setHouse(int);
    int getHouse();
    virtual double calcuateBill()=0;
    void display();
    private:
    char *address;
    int house_no;
    
};
void Bill::display(){
    cout<<"address:"<<address<<endl;
    cout<<"house_no:"<<house_no<<endl;
}
Bill::Bill(char* ad,int a){
setAdrress(ad);
setHouse(a);
}
    void Bill::setAdrress(char* address){
            int size=0;
    for (int i=0;address[i]!='\0';i++){
        size++;
    } this->address=new char [size+1];
    for (int i=0;i<size;i++){
        this->address[i]=address[i];
    }
    this->address[size]='\0';
    }
    char * Bill::getAddress(){
        return address;
    }
    Bill::~Bill(){
        address=nullptr;
        delete address;
    }
    
    void Bill::setHouse(int a){
        house_no=a;
    }
    int Bill::getHouse(){
        return house_no;
    }
    
    class Electricity :public Bill{
        public:
        Electricity(char*,int,double);
        double calcuateBill();
        virtual ~Electricity();
        void display();
        private:
    char *address;
    int house_no;
    double units;
    };

        Electricity::Electricity(char* a,int h ,double u):Bill(a,h){
            address=a;
            house_no=h;
            units=u;
        }  
        void Electricity:: display(){
            Bill::display();
            cout<<"units:"<<units<<endl;
        }
        
        double Electricity::calcuateBill(){
            double Ebill=0;
            Ebill=units*30;
            cout<<Ebill<<endl;
            return Ebill;
        }
        Electricity::~Electricity(){
            address=nullptr;
             delete address;
        }    
             
              class Telephone :public Bill{
        public:
        Telephone(char*,int,double);
        double calcuateBill();
        virtual ~Telephone();
        void display();
        private:
    char *address;
    int house_no;
    double minutes;
    };
    void Telephone::display(){
        Bill::display();
        cout<<"minutes:"<<minutes<<endl;
    }

        Telephone::Telephone(char* a,int h ,double u):Bill(a,h){
            address=a;
            house_no=h;
            minutes=u;
        }
        double Telephone::calcuateBill(){
            double Ebill=0;
            Ebill=minutes*15;
            cout<<Ebill;
            return Ebill;
        }
        Telephone::~Telephone(){
            address=nullptr;
             delete address;
        }    
    
          class Water :public Bill{
        public:
        Water(char*,int,double);
        double calcuateBill();
        virtual ~Water();
        void display();
        private:
    char *address;
    int house_no;
    double litres;
    };
    void Water::display(){
        Bill::display();
        cout<<"Litres"<<litres<<endl;
    }

        Water::Water(char* a,int h ,double u):Bill(a,h){
            address=a;
            house_no=h;
            litres=u;
        }
        double Water::calcuateBill(){
            double Ebill=0;
            Ebill=litres*10;
            cout<<Ebill;
            return Ebill;
        }
        Water::~Water(){
            address=nullptr;
             delete address;
        }    
           
          void Bill(Bill* b){
              b->calcuateBill();
              
          } 
          
           
int main()
{ char AR[50]="GULShAN Ravi ";
    Electricity e1(AR,1123,150);
    Telephone  t1(AR,1232,15);
    Water w1(AR,123,50);
    cout<<"Electricity Bill"<<endl;
    e1.display();   
    cout<<"total "<<endl;
    Bill(&e1);
    cout<<"______________________________________________________"<<endl;
    cout<<"Telephone Bill "<<endl;
    t1.display();
    cout<<"total "<<endl;
    Bill(&t1);
    
        cout<<"______________________________________________________"<<endl;
    cout<<"Water Bill "<<endl;
    w1.display();
    cout<<"total "<<endl;
    Bill(&w1);
    

    return 0;
}
