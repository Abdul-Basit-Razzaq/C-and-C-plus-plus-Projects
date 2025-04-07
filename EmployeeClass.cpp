#include<iostream>
using namespace std;
template<typename T>
class Employee{
    public:
    Employee(T);
    void display();
    private:
    T t;
};
template <typename T>
Employee<T>::Employee( T n)
{
    t=n;
}
template <typename T>
void Employee<T>::display(){
    cout<<" ID "<< t; 
}

int main(){
	Employee<int> e(123);
	Employee<string> e1("l1f20bsse0513");
	e.display();
	cout<<endl;
	e1.display();
	return 0;

}
