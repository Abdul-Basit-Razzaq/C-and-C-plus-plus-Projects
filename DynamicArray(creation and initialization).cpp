/*writa a program to create a dynamic array and store a  into a new dynamic array */
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
int size;
cout<<" enter the size ";
cin>>size;
int *ptr=new int [size];
for (int i=0;i<size;i++){
    cin>>ptr[i];
    
}
cout<<"first "<<*ptr<<endl;
cout<<"second array "<<endl;
int *ptr1=new int [size];
for (int j=0;j<size;j++){ptr1[j]=ptr[j];cout<<*ptr1+j<<endl;}



    return 0;
}
