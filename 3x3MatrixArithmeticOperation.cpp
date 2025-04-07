/*Question # 2: Write a program that creates a two-dimensional array initialized with test data.
Use any data type you wish. The program should have the following functions:
• getAverage. This function should accept a two-dimensional array as its argument and return the
average of all the values in the array.
• getColumnTotal . This function should accept a two-dimensional array as its first argument and an
integer as its second argument. The second argument should be the subscript of a column in the
array. The function should return the total of the values in the specified column.
• getLowestInRow. This function should accept a two-dimensional array as its first argument and an
integer as its second argument. The second argument should be the subscript of a row in the array.
The function should return the lowest value in the specified row of the array.
Demonstrate each of the functions in this program. */
#include <iostream>
using namespace std;
const int row=3;
const int cols=3;
int average(int arr[row][cols],int row,int cols){
    int sum=0;
    int average=0;
    for (int i=0;i<row;i++){
        for (int y=0;y<cols;y++){
            sum=sum+arr[i][y];
        }
    }average=sum/(row*cols);
cout<<"average of all elements "<<endl;
  return average;}
  int getsumOfSepecificArray(int arr[row][cols],int row,int cols ,int s){
      cout<<" enter the subscript of array as columns, to find the sum of that column__>equal to zero less than 3"<<endl;
      cin>>s;
        int sum=0;
      for (int i=0;i<row;i++){
          sum=sum+arr[i][s];
      }
      cout<<"sum "<<endl;
     return sum; }
  int getlowestOfSepecificArray(int arr[row][cols],int row,int cols ,int s){
      cout<<" enter the subscript of array as row ,to find lowest __>equal to zero less than 3"<<endl;
      cin>>s;
        int min=arr[s][0];
      for (int i=0;i<cols;i++){
          if(min>arr[s][i]){
              min=arr[s][i];}
      }
    cout<<" minimum "<<endl;
    return min;}
int main()
{cout<<" enter the elements in array "<<endl;
    int arr[row][cols];
    for (int f=0;f<row;f++){
        for (int e=0;e<cols;e++){
            cin>>arr[f][e];
        }
    }cout<<" elements in grid form "<<endl;
    cout << "     |       |       " << endl;
    cout << " " << arr[0][0] << "   |   " << arr[0][1] << "   |    " << arr[0][2] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << "     |       |       " << endl;
    cout << "   " << arr[1][0] << " |   " << arr[1][1] << "   |    " << arr[1][2] << endl;
    cout << "_____|_______|_______" << endl;
    cout << "     |       |       " << endl;
    cout << "     |       |       " << endl;
    cout << "  " << arr[2][0] << "  |   " << arr[2][1] << "   |    " << arr[2][2] << endl;
 int u=average(arr,row,cols);
 cout<<u<<endl;
 int s=0;
 int o=0;
 o=getsumOfSepecificArray(arr,row,cols,s);
 cout<<o<<endl;
 int y=0;
 y=getlowestOfSepecificArray(arr,row,cols,s);
 cout<<y;
    return 0;
}
