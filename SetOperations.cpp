#include<iostream>
#include<cstdlib>
#include<time.h>
#include<ctime>

using namespace std;
//Group members 
// HAFIZ SAAD MAHMOOD L1F21BSSE0491
// ABDUL BASIT L1F21BSSE0513
class Set
{
public:
	Set();
	Set(int size);
	Set(const Set& obj);
	~Set();
	int getSize();
	void findUnion(const Set& obj);
	void findIntersection(const Set& obj);
	bool checkEquality(const Set& obj);
	int cardinality();
	bool checkMembership(int val);
	void showSet();
	void sort();
	

	private:
	int size;
	int* setPtr;
};
Set::Set()
{
	size = 0;
	setPtr = nullptr;
}
Set::Set(int size)
{
	
	this->size = size;
	setPtr = new int[size];
	
	
	for (int i = 0; i < size; i++)
	{
		
		int flag = 0;
		int temp = 0;
		
		do
		{
			
			flag = 0;
			 temp = rand() % 20;
			 for (int j = 0; j < i; j++)
			 {
				 if (setPtr[j] == temp)
				 {
					 flag++;
				 }
			 }				
		} while (flag != 0);
		if(flag==0)
		setPtr[i] = temp;
	}

}
Set::Set(const Set& obj)
{
	size = obj.size;
	for (int i = 0; i < size; i++)
	{
		setPtr[i] = obj.setPtr[i];
	}

}
Set::~Set()
{
//	delete[] setPtr;
//	setPtr = nullptr;

}
int Set::getSize()
{
	return size;
}
void Set::findUnion(const Set& obj)
{
	bool flag = 0;
	cout << "\nUnion: { ";
	for (int i = 0; i < size; i++)
	{
		cout << setPtr[i]<<",";
	}
	
	for (int i = 0; i < size; i++)
	{
		flag = 0;
		for (int j = 0; j < size; j++)
		{

			if (setPtr[j] == obj.setPtr[i])
			{
				flag=1;
				
			}
			
		}
		if (flag != 1)
		{
			cout << obj.setPtr[i];
			if (i != size - 1)
				cout << ",";
		}
		sort();
		
	}
	cout << " }" << endl;
}
void Set::findIntersection(const Set& obj)
{
	int temp = 0;
	int count = 0;
	cout << "Intersection: { ";
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{
			
			if (setPtr[j] == obj.setPtr[i])
			{
				cout << setPtr[j];
				if (i != size - 1)
					cout << ",";
			}
		}
	}

	cout <<" }"<< endl;
	sort();
}
bool Set::checkEquality(const Set& obj)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (setPtr[i] == obj.setPtr[i])
			count++;
	}
	
	if (count == size)
		return 1;
	return 0;
}
int Set::cardinality()
{
	return size;

}
bool Set::checkMembership(int val)
{
	for (int i = 0; i < size; i++)
	{
		if (val == setPtr[i])
			return 1;
	}
	return 0;
}
void Set::showSet()
{
	cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		cout << setPtr[i];
		if (i != size - 1)
			cout << ",";
	}
	cout << " }"<<endl;

}
void Set::sort()
{
	

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			int temp = 0;
			if (setPtr[i] < setPtr[j])
			{
				temp = setPtr[i];
				setPtr[i] = setPtr[j];
				setPtr[j] = temp;
			}
			
		}
	}
}
void drawBar(int size, char chr)
{
	for (int i = 0; i < size; i++)
		cout << chr;
	cout << endl;
}

int main()
{
	int size = 0;
	do
	{
		cout << "Enter size of both Sets: ";
		cin >> size;
		if (size < 20 && size > 1)
		break;
		cout << "Invalid Input!\nPlease Enter size below than 20 and greater than 1Try Again\n";
	} while (1);
	
	cout << "The Created sets are: \n";
	srand(time(NULL));
	Set set1(size);
	Set set2(size);
	cout << "A= ";
	set1.showSet();
	cout << "B= ";
	set2.showSet();
	char x = '\0';
	drawBar(30, '-');
	a:
	do
	{
		cout << "Press 'U' to Find Union\n";
		cout << "Press 'I to Find Intersection\n";
		cout << "Press 'E' to check Equality of Sets\n";
		cout << "Press 'M' to perform Membership Test\n";
		cout << "Press 'C' to check Number of Members in the Set (Cardinality)\n";
		cout << "Press 'S' to Sort the Set\n";
		cout << "Press 'X' to exit\n";
		cout << "Please Select the Operation you want to perform on these Sets: ";
		cin.ignore();
		cin >> x;
		if (x == 'U' || x == 'u' || x == 'I' || x == 'i' || x == 'E' || x == 'e' || x == 'M' || x == 'm' || x == 'C' || x == 'c' || x == 'S' || x == 's' || x == 'X' || x == 'x')
			break;
		else
			cout << "Invalid Input!\nPlease Try Again--------->\n" << endl;
	} while (1);
	drawBar(30, '-');
	if (x == 'U' || x == 'u')
	{
		set1.findUnion(set2);
		drawBar(30, '-');
		goto a;
	}
	

	else if (x == 'I' || x == 'i')
	{
		set1.findIntersection(set2);
		drawBar(30, '-');
		goto a;
	}
		

	else if (x == 'E' || x == 'e')
	{
		if(	set1.checkEquality(set2));
		cout << "These Sets are not Equal" << endl;
		drawBar(30, '-');
		goto a;
	}
		

	else if (x == 'M' || x == 'm')
	{
		

		
		int val = 0;
		do
		{
			cout << "Press 'A' to check Membership of Set-1\n";
			cout << "Press 'B' to chech Membership of Set-2\n";
			cout << "Enter: "; cin >> x;
			if (x == 'A' || x == 'a' || x == 'B' || x == 'b')
				break;
			cout << "Inavlid Input!\n";

		}while (1);
		cout << "Enter Any Value to check Memership (whether it is part of the set or not): ";
		cin >> val;
		if (x == 'A' || x == 'a')
		{
			if (set1.checkMembership(val))
				cout << val << " is exists in Set-1" << endl;
			else
				cout << val << " does not existsin Set-1" << endl;
		}
		else
		{
			if (set2.checkMembership(val))
				cout << val << " is exists in Set-2" << endl;
			else
				cout << val << " does not existsin Set-2" << endl;
		}
		drawBar(30, '-');
		goto a;
	}
	else if (x == 'C' || x == 'c')
	{
		do
		{
			cout << "Press 'A' to check Cardinality of Set-1\n";
			cout << "Press 'B' to chech Cardinality of Set-2\n";
			cout << "Enter: "; cin >> x;
			if (x == 'A' || x == 'a' || x == 'B' || x == 'b')
				break;
			cout << "Inavlid Input!\n";

		} while (1);
		if (x == 'A' || x == 'a')
			cout << "Cardinality of Set-1: " << set1.cardinality()<<endl;
		else
			cout << "Cardinality of Set-2: " << set2.cardinality()<<endl;

		drawBar(30, '-');
		goto a;
	}
	else if (x == 'S' || x == 's')
	{
		do
		{
			cout << "Press 'A' to Sort the Set-1\n";
			cout << "Press 'B' to Sort the Set-2\n";
			cout << "Enter: "; cin >> x;
			if (x == 'A' || x == 'a' || x == 'B' || x == 'b')
				break;
			cout << "Inavlid Input!\n";

		} while (1);
		if (x == 'A' || x == 'a')
		{
			cout << "Sorted Set-1: "; set1.sort();

			set1.showSet(); cout << endl;
		}
		else
		{
			cout << "Sorted Set-2: "; set2.sort();
			set2.showSet(); cout << endl;
		}
		drawBar(30, '-');
		goto a;
	}
	else
		cout << "Thanks for running the program.......\nYou are Exiting................\nProgram Exit!" << endl;



	
	
	return 0;
}jiiug