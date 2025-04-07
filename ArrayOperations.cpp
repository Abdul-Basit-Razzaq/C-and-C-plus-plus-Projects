#include <iostream>
using namespace std;
// Get an array of size 7 from user,
//find the sum and arrange it in ascending order using function template.  
template<typename T>
void sort(T arr[7]){
for (int i=0;i<7;i++){
    for (int j=0;j<7;j++){
        T temp;
        if (arr[i]<arr[j]){
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
          
        }
    }
}
for (int i=0;i<7;i++){
    cout<<arr[i]<<" , ";
}
}
template<typename T>
T sum(T arr[7]){
     T sum1;
    for (int i=0;i<7;i++){
        sum1=0;
        sum1=arr[i]+sum1;
    }
    cout<<sum1;
    return sum1;
}
int main()
{   int arr1[7];
    char arr[7];
    cout<<"enter characters  "<<endl;
    for (int i=0;i<7;i++){
        cin>>arr[i];
    }cout<<" sorted "<<endl;
     sort<char>(arr);
     cout<<" enter integers "<<endl;
    for (int i=0;i<7;i++){
        cin>>arr1[i];
    }
    cout<<" sorted "<<endl;
    sort<int>(arr1);
    sum<int>(arr1);
    return 0;
}
