#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int x = 5, y = 5, z = 5;
int sizes = 15;

void bar(char c, int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << c;
	}
}
class Inventory
{
public:
	Inventory();
	Inventory(string, string, float, int);
	void setItemId(string);
	string getItemId();
	void setItemName(string);
	string getItemName();
	void setPrice(float);
	float getPrice();
	void setQuantity(int);
	int getQuantity();
	void display();
	void show();
private:
	string i_Id;
	string i_Name;
	float i_price;
	int quantity;
};
void Inventoryshow(Inventory* I)
{
	cout << left << setw(25) << "ITEM_ID" << left << setw(25) << "ITEM_NAME" << left << setw(25) << "PRICE" << left << setw(25) << "QUANTITY" << endl;
	for (int i = 0; i < sizes; i++)
	{
		if (I[i].getQuantity() != 0)
			I[i].display();
	}
	bar('-', 80);
}
Inventory::Inventory() {
	i_Id = "0";
	i_Name = "0";
	i_price = 0.0;
	quantity = 0;
}
Inventory::Inventory(string i, string n, float p, int q) {
	setItemId(i);
	setItemName(n);
	setPrice(p);
	setQuantity(q);
}
void Inventory::setItemId(string i) {
	i_Id = i;
}
string Inventory::getItemId() {

	return i_Id;
}
void Inventory::setItemName(string n) {
	i_Name = n;
}
string Inventory::getItemName() {

	return i_Name;
}
void Inventory::setPrice(float p) {
	i_price = p;
}
float Inventory::getPrice() {

	return i_price;
}
void Inventory::setQuantity(int q) {
	quantity = q;
}
int Inventory::getQuantity() {

	return quantity;
}

void Inventory::display()
{
	cout << left << setw(25) << getItemId() << left << setw(25) << getItemName() << left << setw(25) << getPrice() << left << setw(25) << getQuantity() << endl;
}
void Inventory::show()
{
	cout << "Item Id:" << getItemId() << endl;
	cout << "Item Name:" << getItemName() << endl;
	cout << "Item Price:" << getPrice() << endl;

}
Inventory* Copy(Inventory* f, Inventory* e, Inventory* o, Inventory* I)
{
	delete[]I;
	Inventory* Inv = new Inventory[sizes];
	int num = 0;
	for (int i = 0; i < x; i++)
	{
		Inv[num] = f[i];
		num++;
	}
	for (int i = 0; i < y; i++)
	{
		Inv[num] = e[i];
		num++;
	}
	for (int i = 0; i < z; i++)
	{
		Inv[num] = o[i];
		num++;
	}
	return Inv;
}
// USERS 
class User
{
public:
	User();
	User(string, string);
	void setId(string);
	string getId();
	void setPassword(string);
	string getPassword();
	void showPerson();
private:
	string name;
	string id;
	string password;
	string contact;
};
User::User()
{

	id = "0";
	password = "0";

}
User::User(string i, string p)
{

	setId(i);
	setPassword(p);

}
void User::setId(string i) { id = i; }
string User::getId() {
	cout << endl << "id ";
	return id;
}
void User::setPassword(string p) {
	password = p;
}
string User::getPassword() {
	cout << endl << "password:";
	return password;
}
void User::showPerson() {

	cout << "ID :" << getId() << endl;
	cout << "PASSWORD:" << getPassword() << endl;

}
// BRANCH 
class Branch {
public:
	Branch();
	Branch(string, string, string, string, Inventory*, User*);
	void setBranchId(string);
	string getBranchId();
	void setBranchAddress(string);
	string getBranchAddress();
	void setBranchEmail(string);
	string getBranchEmail();
	void setBranchContact(string);
	string getBranchContact();
	void setInventory(Inventory*);
	void setUser(User*);
	void display();
private:
	string branchId;
	string branchAddress;
	string branchEmail;
	string branchContact;
	Inventory* inventory;
	User* user;

};
Branch::Branch() {
	branchId = "0";
	branchAddress = "0";
	branchEmail = "0";
	branchContact = "0";
}
Branch::Branch(string id, string address, string email, string contact, Inventory* I, User* U)
{
	setBranchId(id);
	setBranchAddress(address);
	setBranchEmail(email);
	setBranchContact(contact);
	setInventory(I);
	setUser(U);
}
void Branch::setBranchId(string id) {
	branchId = id;
}
string Branch::getBranchId() {
	return branchId;
}
void Branch::setBranchAddress(string ad) {
	branchAddress = ad;
}
string Branch::getBranchAddress()
{
	return branchAddress;
}
void Branch::setBranchEmail(string em)
{
	branchEmail = em;
}
string Branch::getBranchEmail()
{

	return branchEmail;
}
void Branch::setBranchContact(string c)
{
	branchContact = c;
}
string Branch::getBranchContact()
{

	return branchContact;
}
void Branch::setInventory(Inventory* I)
{
	inventory = I;
}
void Branch::setUser(User* U)
{
	user = U;
}

void Branch::display()
{
	bar(' ', 62); cout << "ID :" << getBranchId() << endl;
	bar(' ', 62); cout << "address :" << getBranchAddress() << endl;
	bar(' ', 62); cout << "email :" << getBranchEmail() << endl;
	bar(' ', 62); cout << "contact :" << getBranchContact() << endl;
	cout << left << setw(25) << "ITEM_ID" << left << setw(25) << "ITEM_NAME" << left << setw(25) << "PRICE" << left << setw(25) << "QUANTITY" << endl;

	for (int i = 0; i < sizes; i++)
		inventory[i].display();

}
///  STORE 
class Store
{
public:
	Store();
	Store(string, Branch);
	void setName(string);
	void setBranch(Branch);
	string getName();
	void display();
private:
	string storeName;
	Branch branch;

};
Store::Store()
{
	storeName = "0";
}
Store::Store(string n, Branch b)
{
	setName(n);
	setBranch(b);

}
void Store::setName(string n)
{
	storeName = n;
}
void Store::setBranch(Branch b)
{
	branch = b;
}
string Store::getName() {
	return storeName;
}
void Store::display()
{

	bar(' ', 55); cout << "WELCOME TO SUPER STORE MANAGEMENT SYSTEM\n" << endl << endl;
	int b = 0;
	bar(' ', 62); cout << "Store Name: " << getName() << endl;
	branch.display();
	bar('-', 80); cout << endl;
	// system("pause");

}



//  CUSTOMER 
class Customer :public User
{
public:
	Customer();
	Customer(string, string);
	void BuyItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I, string n, ofstream*);
};
Customer::Customer()
{

}

Customer::Customer(string i, string p) :User(i, p)
{

}

void Customer::BuyItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I, string n, ofstream* fout)
{
	int x1 = 0, c = 0, pp = 0;
	cout << "Enter quantity:" << endl;
	cin >> c;
	for (int i = 0; i < x; i++)
	{

		if (n == f[i].getItemId())
		{
			x1 = f[i].getQuantity();
			x1 -= c;
			f[i].setQuantity(x1);
			cout << "You have successfully bought following item:" << endl;
			f[i].show();
			*fout << f[i].getItemId() << "  " << f[i].getItemName() << " " << f[i].getPrice() << " " << c << endl;
		}
	}
	for (int i = 0; i < y; i++)
	{
		if (n == e[i].getItemId())
		{
			x1 = e[i].getQuantity();
			x1 -= c;
			e[i].setQuantity(x1);
			cout << "You have successfully bought following item:" << endl;
			e[i].show();
			*fout << e[i].getItemId() << "  " << e[i].getItemName() << " " << e[i].getPrice() << " " << c << endl;
		}
	}
	for (int i = 0; i < z; i++)
	{
		if (n == o[i].getItemId())
		{
			x1 = o[i].getQuantity();
			x1 -= c;
			o[i].setQuantity(x1);
			cout << "You have successfully bought following item:" << endl;
			o[i].show();
			*fout << o[i].getItemId() << "  " << o[i].getItemName() << " " << o[i].getPrice() << " " << c << endl;
		}
	}
	system("pause");
	I = Copy(f, e, o, I);
	system("cls");
	cout << "-----------------------UPDATED TABLE----------------------------\n";
	Inventoryshow(I);
	cout << endl;
	system("pause");
	bar('-', 80); cout << endl;
}
// ADMIN 
class Admin :public User
{
public:
	Admin();
	Admin(string, string);
	void UpdateItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I);
	void removeItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I);
};

Admin::Admin()
{
}

Admin::Admin(string i, string p) :User(i, p)
{
}
void Admin::UpdateItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I)
{
	bool wro = true; int quan = 0;
	int y = 0; string t;
	cout << "Enter Item id of the item you want to update :\n";
	while (wro) {
		cin >> t;
		for (int i = 0; i < sizes; i++) {
			if (t == I[i].getItemId() && I[i].getQuantity() != 0) {
				wro = false; break;
			}
		}
		if (wro)
			cout << "Invalid Input\n";
	}
	for (int i = 0; i < sizes; i++)
	{
		if (i < x && t == f[i].getItemId())
		{
			string n; float g = 0.0;
			cout << "Press 1 to update Item id: \n";
			cout << "Press 2 to update Item Name: \n";
			cout << "Press 3 to update Item Price: \n";
			cout << "Press 4 to update Item Quantity: \n";
			cin >> y;
			if (y == 1)
			{
				cout << "Enter New Id: \n";
				cin >> n;
				f[i].setItemId(n);
			}
			else if (y == 2)
			{
				cout << "Enter New Name: \n";
				cin >> n;
				f[i].setItemName(n);
			}
			else if (y == 3)
			{
				cout << "Enter New Price: \n";
				cin >> g;
				f[i].setPrice(g);
			}
			else if (y == 4)
			{
				cout << "Enter New Quantity: \n";
				cin >> quan;
				f[i].setQuantity(quan);
			}
		}
	}
	for (int i = 0; i < sizes; i++)
	{
		if (i < y && t == e[i].getItemId())
		{
			string n; float g = 0.0;
			cout << "Press 1 to update Item id: \n";
			cout << "Press 2 to update Item Name: \n";
			cout << "Press 3 to update Item Price: \n";
			cout << "Press 4 to update Item Quantity: \n";
			cin >> y;
			if (y == 1)
			{
				cout << "Enter New Id: \n";
				cin >> n;
				e[i].setItemId(n);
			}
			else if (y == 2)
			{
				cout << "Enter New Name: \n";
				cin >> n;
				e[i].setItemName(n);
			}
			else if (y == 3)
			{
				cout << "Enter New Price: \n";
				cin >> g;
				e[i].setPrice(g);
			}
			else if (y == 4)
			{
				cout << "Enter New Quantity: \n";
				cin >> quan;
				e[i].setQuantity(quan);
			}
		}
	}

	for (int i = 0; i < sizes; i++)
	{
		if (i < z && t == o[i].getItemId())
		{
			string n; float g = 0.0;
			cout << "Press 1 to update Item id: \n";
			cout << "Press 2 to update Item Name: \n";
			cout << "Press 3 to update Item Price: \n";
			cout << "Press 4 to update Item Quantity: \n";
			cin >> y;
			if (y == 1)
			{
				cout << "Enter New Id: \n";
				cin >> n;
				o[i].setItemId(n);
			}
			else if (y == 2)
			{
				cout << "Enter New Name: \n";
				cin >> n;
				o[i].setItemName(n);
			}
			else if (y == 3)
			{
				cout << "Enter New Price: \n";
				cin >> g;
				o[i].setPrice(g);
			}
			else if (y == 4)
			{
				cout << "Enter New Quantity: \n";
				cin >> quan;
				o[i].setQuantity(quan);
			}
		}
	}
	I = Copy(f, e, o, I);
	system("cls");
	cout << "-----------------------UPDATED TABLE----------------------------\n";
	Inventoryshow(I);
	system("pause");

}

void Admin::removeItem(Inventory* f, Inventory* e, Inventory* o, Inventory* I)
{
	bool wro = true;
	string t;
	cout << "Enter Item id you want to remove :\n";
	while (wro) {
		cin >> t;
		for (int i = 0; i < sizes; i++) {
			if (t == I[i].getItemId() && I[i].getQuantity() != 0) {
				wro = false; break;
			}
		}
		if (wro)
			cout << "Invalid Input\n";
	}
	for (int i = 0; i < x; i++) {
		if (i < x && t == f[i].getItemId())
		{
			f[i].setQuantity(0);
		}
	}
	for (int i = 0; i < y; i++) {
		if (i < y && t == e[i].getItemId())
		{
			e[i].setQuantity(0);
		}
	}
	for (int i = 0; i < z; i++) {
		if (i < z && t == o[i].getItemId())
		{
			o[i].setQuantity(0);
		}
	}
	I = Copy(f, e, o, I);
	system("cls");
	cout << "-----------------------UPDATED TABLE----------------------------\n";
	Inventoryshow(I);
	system("pause");
}


// FOOD ITEMS 
class FoodItems :public Inventory
{
public:
	FoodItems();
	FoodItems(string, string, float, int);

};
FoodItems::FoodItems()
{

}
FoodItems::FoodItems(string i, string n, float p, int q) :Inventory(i, n, p, q)
{

}
// ELECTRONICS 
class ElecronicItems :public Inventory
{
public:
	ElecronicItems();
	ElecronicItems(string, string, float, int);


};

ElecronicItems::ElecronicItems()
{

}

ElecronicItems::ElecronicItems(string i, string n, float p, int q) :Inventory(i, n, p, q)
{

}

// OTHERS 
class OtherItems :public Inventory
{
public:
	OtherItems();
	OtherItems(string, string, float, int);


};
OtherItems::OtherItems()
{
}
OtherItems::OtherItems(string i, string n, float p, int q) :Inventory(i, n, p, q)
{

}

Inventory* foodi = nullptr;
Inventory* elect = nullptr;
Inventory* othe = nullptr;
Inventory* Inve = nullptr;

// SUPPLIER 
class Supplier :public User
{
public:
	Supplier();
	Supplier(string i, string p);
	void addItem(Inventory* I, Inventory* f, Inventory* e, Inventory* o);

private:
};
Supplier::Supplier()
{
}

Supplier::Supplier(string i, string p) :User(i, p)
{
}
Inventory* itemadding(Inventory* a, int n, char ch = '0')
{
	string abc; float num2 = 0.0f;
	int num1 = 0;
	n++;
	Inventory* temp = nullptr;
	if (ch == 'f')
		temp = new FoodItems[n];
	else if (ch == 'e')
		temp = new ElecronicItems[n];
	else if (ch == 'o')
		temp = new OtherItems[n];
	else
		temp = new Inventory[n];

	for (int i = 0; i < n - 1; i++)
	{
		temp[i] = a[i];
	}

	cout << "Enter information of new item:\n";
	cout << "Enter Item ID:" << endl;
	cin >> abc;
	temp[n - 1].setItemId(abc);
	cout << "Enter Item Name: " << endl;
	cin >> abc;
	temp[n - 1].setItemName(abc);
	cout << "Enter Item Price:" << endl;
	cin >> num2;
	temp[n - 1].setPrice(num2);
	cout << "Enter Item Quantity:" << endl;
	cin >> num1;
	temp[n - 1].setQuantity(num1);

	delete[]a;
	return temp;
}

void Supplier::addItem(Inventory* I, Inventory* f, Inventory* e, Inventory* o)
{
	int l = 0, m = 0, n = 0, get = 0;
	bool wro = true;
	string t = "0";
	do {
		system("pause");
		system("cls");
		cout << "1. For New Item\n";
		cout << "2. For Adding more quantity to Existing Items\n";
		cout << "3. Exit\nEnter: ";
		cin >> m;
		if (m == 1) {
			do
			{
				cout << "Enter type of item:\n";
				cout << "Press 1 for food item.\n";
				cout << "Press 2 for electronics item.\n";
				cout << "Press 3 for other item.\n";
				cout << "Press 4 to EXIT\n";
				cin >> l;
				if (l == 1)
				{
					f = itemadding(f, x, 'f');
					x++;
					sizes++;
					I = Copy(f, e, o, I);
				}
				else if (l == 2)
				{
					e = itemadding(e, y, 'e');
					y++;
					sizes++;
					I = Copy(f, e, o, I);
				}
				else if (l == 3)
				{
					o = itemadding(o, z, 'o');
					z++;
					sizes++;

					I = Copy(f, e, o, I);
				}
				else if (l == 4)
				{
					break;
				}
				else
				{
					cout << "Invalid input Enter again!!!!!!!" << endl;
				}
				system("pause");
				cout << "-----------------------UPDATED TABLE----------------------------\n";
				system("cls");
				Inventoryshow(I);
				system("pause");
				foodi = f;
				elect = e;
				othe = o;
				Inve = I;
			} while (1);
		}
		else if (m == 2) {
			cout << "Enter the Item Id \n";
			while (wro) {
				cin >> t;
				for (int i = 0; i < sizes; i++) {
					if (t == I[i].getItemId() && I[i].getQuantity() != 0) {
						n = i;
						wro = false; break;
					}
				}
				if (wro)
					cout << "Invalid Input\n";
			}
			cout << "Enter Quantity you want to add\n";
			cin >> l;
			get = I[n].getQuantity();
			get += l;
			I[n].setQuantity(get);
			Inve = I;
		}
		else if (m == 3) {
			break;
		}
		else {
			cout << "Invalid Input\n";
		}
	} while (m != 3);
}


bool checkCredential(string i, string p, char c)
{
	if (c == 'a')
	{
		if ((i == "123" || i == "234") && (p == "abc" || p == "cde"))
		{
			cout << "You have successfully Log in...\n";
			return true;
		}
		else
		{
			cout << "Wrong id or Password Enter again.\n";
			return false;
		}

	}
	else if (c == 'b')
	{
		if ((i == "a123" || i == "a234") && (p == "aabc" || p == "acde"))
		{
			cout << "You have successfully Log in...\n";
			return true;
		}
		else
		{
			cout << "Wrong id or Password Enter again.\n";
			return false;
		}
	}
	else if (c == 'c')
	{
		if ((i == "123b" || i == "234b") && (p == "abcb" || p == "cdeb"))
		{

			cout << "You have successfully Log in...\n";
			return true;
		}
		else
		{
			cout << "Wrong id or Password Enter again.\n";
			return false;
		}
	}
	return false;
}

int main()
{

	Inventory* f = new FoodItems[x];
	Inventory* e = new ElecronicItems[y];
	Inventory* o = new OtherItems[z];

	Inventory* I = new Inventory[sizes];

	f[0].setItemId("123");
	f[0].setItemName("MILK");
	f[0].setPrice(40.0);
	f[0].setQuantity(6);
	f[1].setItemId("345");
	f[1].setItemName("BREAD");
	f[1].setPrice(50.0);
	f[1].setQuantity(8);
	f[2].setItemId("789");
	f[2].setItemName("EGGS");
	f[2].setPrice(60.0);
	f[2].setQuantity(7);
	f[3].setItemId("867");
	f[3].setItemName("WHEAT");
	f[3].setPrice(70.0);
	f[3].setQuantity(3);
	f[4].setItemId("432");
	f[4].setItemName("SUGAR");
	f[4].setPrice(80.0);
	f[4].setQuantity(4);
	//////////////////////
	e[0].setItemId("123a");
	e[0].setItemName("TV");
	e[0].setPrice(4000.0);
	e[0].setQuantity(6);
	e[1].setItemId("345a");
	e[1].setItemName("RADIO");
	e[1].setPrice(5000.0);
	e[1].setQuantity(8);
	e[2].setItemId("789a");
	e[2].setItemName("OVEN");
	e[2].setPrice(6000.0);
	e[2].setQuantity(7);
	e[3].setItemId("867a");
	e[3].setItemName("WASHING M");
	e[3].setPrice(7000.0);
	e[3].setQuantity(3);
	e[4].setItemId("432a");
	e[4].setItemName("LAPTOP");
	e[4].setPrice(8000.0);
	e[4].setQuantity(4);

	///////////////////////
	o[0].setItemId("B123");
	o[0].setItemName("SHAMPOO");
	o[0].setPrice(4023.0);
	o[0].setQuantity(6);
	o[1].setItemId("B345");
	o[1].setItemName("SOAP");
	o[1].setPrice(502.0);
	o[1].setQuantity(8);
	(o[2]).setItemId("7B89");
	o[2].setItemName("TSHIRT");
	o[2].setPrice(602.0);
	o[2].setQuantity(7);
	o[3].setItemId("86B7");
	o[3].setItemName("COAT");
	o[3].setPrice(703.0);
	o[3].setQuantity(3);
	o[4].setItemId("43B2");
	o[4].setItemName("Roll");
	o[4].setPrice(806.0);
	o[4].setQuantity(4);
	I = Copy(f, e, o, I);

	ofstream* fout, * fout1,fout2;

	Admin admin;
	Customer cust;
	Supplier supplier;



	User user[3];
	user[0] = admin;
	user[1] = cust;
	user[2] = supplier;




	Branch b("1a2b3c", "branch@email.com", "Johar town", "384847482", I, user);
	Store s("MyStore", b);


	s.display();
	string fo = "0";
	fout2.open("Customer.txt");
	int a = 0;
	string id, password;
	do
	{
		fout1 = new ofstream("Customer.txt", ios::app);

		fout = new ofstream("Inventory.txt");
		*fout << "ItemID    ItemName   Price   Quantity\n";
		for (int i = 0; i < sizes; i++) {
			if (I[i].getQuantity() != 0) {
				*fout << setw(4) << I[i].getItemId() << setw(12) << I[i].getItemName()
					<< setw(9) << I[i].getPrice() << setw(7) << I[i].getQuantity() << endl;
			}
		}
		cout << "Press 1 for admin.\n";
		cout << "Press 2 for customer.\n";
		cout << "Press 3 for supplier.\n";
		cout << "Press 4 to Show Inventory\n";
		cout << "Press 5 to EXIT.\n";
		cin >> a;
		if (a == 1)
		{
			do
			{
				cout << "Enter your id: " << endl;
				cin >> id;
				cout << "Enter password: " << endl;
				cin >> password;
			} while (!checkCredential(id, password, 'a'));
			int h = 0;
			cout << "Press 1 to Update an item.\n";
			cout << "Press 2 to remove an item.\n";
			cin >> h;
			if (h == 1)
			{
				admin.UpdateItem(f, e, o, I);
				bar('-', 80);
			}
			else if (h == 2)
			{
				admin.removeItem(f, e, o, I);
				bar('-', 80);
			}
		}
		else if (a == 2)
		{
			bool wro = true;
			do
			{
				cout << "Enter your id: " << endl;
				cin >> id;
				cout << "Enter password: " << endl;
				cin >> password;
			} while (!checkCredential(id, password, 'b'));
			cout << "Enter Item id of the item you want to buy......\n";
			while (wro) {
				cin >> fo;
				for (int i = 0; i < sizes; i++) {
					if (fo == I[i].getItemId() && I[i].getQuantity() != 0) {
						wro = false; break;
					}
				}
				if (wro)
					cout << "Invalid Input\n";
			}
			*fout1 << "CustomerID: " << id << endl;
			*fout1 << "Purchase Detail: ";
			cust.BuyItem(f, e, o, I, fo, fout1);
		}
		else if (a == 3)
		{
			do
			{
				cout << "Enter your id: " << endl;
				cin >> id;
				cout << "Enter password: " << endl;
				cin >> password;
			} while (!checkCredential(id, password, 'c'));
			supplier.addItem(I, f, e, o);
			f = foodi; e = elect; o = othe;
			I = Inve;
		}
		else if (a == 4) {
			Inventoryshow(I);
		}
		else if (a == 5) {
			break;
		}
		else
		{
			cout << "Invalid Input! Enter Again\n";
		}
		cout << endl;
		delete fout;
		delete fout1;
	} while (1);

	return 0;
}