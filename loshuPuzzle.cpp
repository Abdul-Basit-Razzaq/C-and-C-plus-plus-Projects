#include <iostream>
#include<cstring>
using namespace std;
const int row=3;
const int cols=3;
bool loShu(int arr[row][cols],int row,int cols){
    cout << "\n-------------------------------------------------------------" << endl;
    cout << "\n\t\t   loShu magic puzzle " << endl;
    cout << "\n-------------------------------------------------------------" << endl;
 
    cout << "     |       |       " << endl;
    cout << " " << arr[0][0] << "   |   " << arr[0][1] << "   |    " << arr[0][2] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << "     |       |       " << endl;
    cout << "  " << arr[1][0] << "  |   " << arr[1][1] << "   |    " << arr[1][2] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << "     |       |       " << endl;
    cout << "  " << arr[2][0] << "  |   " << arr[2][1] << "   |    " << arr[2][2] << endl;

int sum[7]={0,0,0,0,0,0,0};
for (int i=0;i<row;i++){
    for (int j=0;j<cols;j++){
        sum[i]=sum[i]+arr[i][j];
       
    }
}
for (int l=0;l<row;l++){
    for (int m=0;m<cols;m++){
    int g=4;
        sum[g]=sum[g]+arr[m][l];
        g++;
    }
}
sum[7]=arr[0][0]+arr[1][1]+arr[2][2];

for (int p=0;p<7;p++){
    if (sum[p]==sum[p+1]){
        cout<<" is it  lo$hu magic ?"<<endl;
        return true;
    }else {cout<<" it is not lo$hu magic puzzle "<<endl;
    return false;}
}}


int main()
{cout <<" enter the array elements "<<endl;
cout<<" for validation enter the "<<endl;
cout<<" 4 , 9 , 2 , 3 , 5 , 7 , 8 , 1 , 6  "<<endl;
    int arr[row][cols];
    for (int i=0;i<row;i++){
    for (int j=0;j<cols;j++){
        cin>>arr[i][j];
    }
}
    int h=0;
    h=loShu(arr,row,cols);
    cout<<h;
    return 0;
}
