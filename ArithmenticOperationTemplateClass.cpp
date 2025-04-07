/*Task 4 
Make a menu-based program for basic arithmetic operation using class template 
Press 1 for addition 
Press 2 for subtraction 
Press 3 for multiplication Press 4 for division 
*/
#include<iostream>
using namespace std;
template <typename T>
T add(T x, T y){
    T add1=x+y;
    cout<<add1;
    return add1;
}
template <typename T>
T subtraction(T x, T y){
    T minus=x-y;
    cout<<minus;
    return minus;
}
template <typename T>
T multiply(T x, T y){
    T multip=x*y;
    cout<<multip;
    return multip;
}
template <typename T>
T divide(T x, T y){
    T divide=x/y;
    cout<<divide;
    return divide;
}
int main (){
    string b;
    float a1;
    float b1;
    int a2,b2;
cout<<" enter a for float "<<endl;
cout<<" enter b for integers"<<endl;
cin>>b;
if (b=="a"){
    int a=0;
    
    cout<<" enter 1 to add"<<endl;
    cout<<" enter 2 to minus "<<endl;
    cout<<" enter 3 to multiply "<<endl;
    cout<<" enter 4 to divide "<<endl;
cin>>a;
    if (a==1){
        cout<<"enter floats "<<endl;
        cin>>a1;
        cin>>b1;
        add<float>(a1,b1);
    }    if (a==2){
        cout<<"enter floats "<<endl;
        cin>>a1;
        cin>>b1;
        subtraction<float>(a1,b1);
    }
        if (a==3){
        cout<<"enter floats "<<endl;
        cin>>a1;
        cin>>b1;
        multiply<float>(a1,b1);
    }    if (a==4){
        cout<<"enter floats "<<endl;
        cin>>a1;
        cin>>b1;
        divide<float>(a1,b1);
    }
    
}
if (b=="b"){
    int a=0;
    cout<<" enter 1 to add"<<endl;
    cout<<" enter 2 to minus "<<endl;
    cout<<" enter 3 to multiply "<<endl;
    cout<<" enter 4 to divide "<<endl;
       cin>>a;
    if (a==1){
        cout<<"enter integers "<<endl;
        cin>>a2;
        cin>>b2;
        add<int>(a2,b2);
    }    if (a==2){
        cout<<"enter int "<<endl;
        cin>>a2;
        cin>>b2;
        subtraction<int>(a2,b2);
    }
        if (a==3){
        cout<<"enter int"<<endl;
        cin>>a2;
        cin>>b2;
        multiply<int>(a2,b2);
    }    if (a==4){
        cout<<"enter int "<<endl;
        cin>>a2;
        cin>>b2;
        divide<int>(a2,b2);
    }
}
    return 0;
    
}
