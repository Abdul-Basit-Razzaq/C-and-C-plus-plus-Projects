#include<iostream>
using namespace std;
 class student{
     private:
     string name;
     int size;
     string registration;
     string courses;
     string semester;
     public:
     student(string name ,string registration ,string courses ,string semester ){
         this->name=name;
         this->size=size;
         this->registration=registration;
         this->semester=semester;
         this->courses=courses;
     }
     void display(){
         cout<<name<<endl;
         cout<<registration<<endl;
         cout<<semester<<endl;
         cout<<" courses :"<<endl;
             cout<<courses<<endl;
         }
 };
 
 
 
class teacher{
    
    private:
    string name;
    int size;
    student *std;
    public:
    teacher(string name ,student *stdd ):std(stdd)
{
    this->name=name;
    this->size=size;
}
void display(){
    cout<<name<<endl;
    cout<<"currently teaching "<<endl;
std->display();
}
}; 
 int main (){
     string arr[7]={"Cal1","ENG1","SE","ITC","ISL","STD","ITC_lab"};
     student s1("ali","l1f21bsse0512","cal","1st");
teacher t1("IMRAN",&s1);
t1.display();
    
     
     return 0;
 }
 
