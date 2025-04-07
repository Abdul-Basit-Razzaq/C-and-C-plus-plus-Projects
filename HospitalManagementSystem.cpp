#include<iostream>
#include<string>
using namespace std;
class Date;
class Doctor;
class Patient;
class Bill;
int getSize(char* ptr)
{
	int size = 0;
	for (int i = 0; ptr[i] != '\0'; i++)
	{
		size++;
	}
	return size;
}
char* copy(char* samplePtr, char* targetPtr)
{
	int size = getSize(samplePtr);
	targetPtr = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		targetPtr[i] = samplePtr[i];
	}
	targetPtr[size] = '\0';
	return targetPtr;
}
class Date
{
public:
	Date();
	Date(int date, int month, int year);
	void setDate(int date);
	void setMonth(int month);
	void setYear(int year);
	int getDate();
	int getMonth();
	int getyear();
	void displayDate();
private:
	int date;
	int month;
	int year;
};
class Doctor
{
public:
	Doctor();
	Doctor(char* firstName, char* lastName, Date dateOfBirth, string speciality);
	void setFirstName(char* firstName);
	void setLastname(char* lastName);
	void setDateOfBirth(Date dateOfBirth);
	void setSpeciality(string speciality);
	char* getFirstName();
	char* getLastname();
	string getSpeciality();
	void displayDoctorDetails();
	~Doctor();
private:
	char* firstName;
	char* lastName;
	Date dateOfBirth;
	string speciality;
};
class Patient
{
public:
	Patient();
	Patient(int patientId, char* firstName, char* lastName, Date patientDateOfBith, Doctor Doc, Date admissionDate, Date dischargeDate);
	void setPatientId(int patientId);
	void setFirstName(char* firstName);
	void setLastname(char* lastName);
	void setPatientDateOfBirth(Date patientDateOfBith);
	void setDateOfAdmission(Date admissionDate);
	void setDischageDate(Date dischargeDate);
	void setDoc(Doctor doc);
	int getPatientId();
	char* getFirstName();
	char* getLastname();
	void displayPatientDetails();
	~Patient();
private:
	int patientId;
	char* firstName;
	char* lastName;
	Date patientDateOfBith;
	Doctor Doc;
	Date admissionDate;
	Date dischargeDate;
};

class Bill
{
public:
	Bill();
	Bill(Patient pat, Doctor doc, int doctorFee, int roomCharges, int pharmacyCharges, int nursingCharges);
	void setPatient(Patient pat);
	void setDoctor(Doctor doc);
	void setDoctorFee(int doctorFee);
	void setRoomCharges(int roomCharges);
	void setPharmacyCharges(int pharmacyCharges);
	void setNursingCharges(int nursingCharges);
	int getDoctorFee();
	int getRoomCharges();
	int getPharmacyCharges();
	int getNursingCharges();
	int calculateBill();
	void displayBill();
private:
	Patient pat;
	Doctor doc;
	int doctorFee;
	int roomCharges;
	int pharmacyCharges;
	int nursingCharges;
};




Date::Date()
{
	date = 0;
	month = 0;
	year = 0;
}
Date::Date(int date, int month, int year)
{
	setDate(date);
	setMonth(month);
	setYear(year);
}
void Date::setDate(int date)
{
	this->date = date;
}
void Date::setMonth(int month)
{
	this->month = month;
}
void Date::setYear(int year)
{
	this->year = year;
}
int Date::getDate()
{
	return date;
}
int Date::getMonth()
{
	return month;
}
int Date::getyear()
{
	return year;
}
void Date::displayDate()
{
	cout << date << ":" << month << ":" << year;
}
Doctor::Doctor()
{
	firstName = nullptr;
	lastName = nullptr;
	Date();
	speciality = "\0";
}
Doctor::Doctor(char* firstName, char* lastName, Date dateOfBirth, string speciality)
{
	setFirstName(firstName);
	setLastname(lastName);
	setDateOfBirth(dateOfBirth);
	setSpeciality(speciality);
}
void Doctor::setFirstName(char* firstName)
{
	this->firstName = copy(firstName, this->firstName);
}
void Doctor::setLastname(char* lastName)
{
	this->lastName = copy(lastName, this->lastName);
}
void Doctor::setDateOfBirth(Date dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}
void Doctor::setSpeciality(string speciality)
{
	this->speciality = speciality;
}
char* Doctor::getFirstName()
{
	return firstName;
}
char* Doctor::getLastname()
{
	return lastName;
}
string Doctor::getSpeciality()
{
	return speciality;
}
void Doctor::displayDoctorDetails()
{
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	dateOfBirth.displayDate();
	cout << endl << "Speciality: " << speciality << endl;
}
Doctor::~Doctor()
{
	/*cout << "Doctor Destructor Called!" << endl;
	delete[] firstName;
	delete[] lastName;
	firstName = nullptr;
	lastName = nullptr;*/
}


Patient::Patient()
{
	
	patientId = 0;
	firstName = nullptr;
	lastName = nullptr;
	Date();

}
Patient::Patient(int patientId, char* firstName, char* lastName, Date patientDateOfBith, Doctor Doc, Date admissionDate, Date dischargeDate)
{
	setDoc(Doc);
	setPatientId(patientId);
	setFirstName(firstName);
	setLastname(lastName);
	setPatientDateOfBirth(patientDateOfBith);
	setDateOfAdmission(admissionDate);
	setDischageDate(dischargeDate);
	
}
void Patient::setPatientId(int PatientId)
{
	this->patientId = PatientId;
}
void Patient::setFirstName(char* firstName)
{
	this->firstName = copy(firstName, this->firstName);
}
void Patient::setLastname(char* lastName)
{
	this->lastName = copy(lastName, this->lastName);
}
void Patient::setPatientDateOfBirth(Date patientDateOfBith)
{
	this->patientDateOfBith = patientDateOfBith;
}
void Patient::setDateOfAdmission(Date admissionDate)
{
	this->admissionDate = admissionDate;

}
void Patient::setDischageDate(Date dischargeDate)
{
	this->dischargeDate = dischargeDate;
}
void Patient::setDoc(Doctor doc) 
{
	Doc = doc;
}
int Patient::getPatientId()
{
	return patientId;
}
char* Patient::getFirstName()
{
	return firstName;
}
char* Patient::getLastname()
{
	return lastName;
}

void Patient::displayPatientDetails()
{
	cout << "Patient ID: " << patientId << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	patientDateOfBith.displayDate();
	cout << endl;
	admissionDate.displayDate();
	cout << endl;
	dischargeDate.displayDate();
	cout << endl;
	Doc.displayDoctorDetails();
}
Patient::~Patient()
{
	/*cout << "Patient Destructor Called!" << endl;
	delete[] firstName;
	delete[] lastName;
	firstName = nullptr;
	lastName = nullptr;*/
}
Bill::Bill()
{
	
	doctorFee = 0;
	roomCharges = 0;
	pharmacyCharges = 0;
	nursingCharges = 0;
}
Bill::Bill(Patient pat, Doctor doc, int doctorFee, int roomCharges, int pharmacyCharges, int nursingCharges)
{
	setPatient(pat);
	setDoctor(doc);
	setDoctorFee(doctorFee);
	setRoomCharges(roomCharges);
	setPharmacyCharges(pharmacyCharges);
	setNursingCharges(nursingCharges);
}
void Bill::setPatient(Patient pat)
{
	this->pat = pat;
}
void Bill::setDoctor(Doctor doc)
{
	this->doc = doc;
}
void Bill::setDoctorFee(int doctorFee)
{
	this->doctorFee = doctorFee;
}
void Bill::setRoomCharges(int roomCharges)
{
	this->roomCharges = roomCharges;
}
void Bill::setPharmacyCharges(int pharmacyCharges)
{
	this->pharmacyCharges = pharmacyCharges;
}
void Bill::setNursingCharges(int nursingCharges)
{
	this->nursingCharges = nursingCharges;
}
int Bill::getDoctorFee()
{
	return doctorFee;
}
int Bill::getRoomCharges()
{
	return roomCharges;
}
int Bill::getPharmacyCharges()
{
	return pharmacyCharges;
}
int Bill::getNursingCharges()
{
	return nursingCharges;
}
int Bill::calculateBill()
{
	return doctorFee + roomCharges + pharmacyCharges + nursingCharges;
}
void Bill::displayBill()
{
	cout << endl;
	pat.displayPatientDetails();
	cout << endl;
	cout << "Doctor Fee: " << doctorFee << endl;
	cout << "Room Charges: " << roomCharges << endl;
	cout << "Pharmacy Charges: " << pharmacyCharges << endl;
	cout << "Nursing Charges: " << nursingCharges << endl;
	cout << "---------------------" << endl;
	cout << "Total Bill: "<< calculateBill(); cout << endl;
}




int main()
{
	Date d1(22,12,2000);
	Date d2(15, 1, 2016);
	Date d3(18, 15, 2022);
	Date d4(12, 16, 2022);
	char arr[10] ;
	char arr1[10]="ali";
	cout<<"Enter name to be changed ";
	cin.getline(arr,10);
	Doctor doc(arr,arr1,d1,"cardiologogist");
	Patient p(871, arr, arr1, d2, doc, d3, d4);

	Bill bill(p,doc,200,100,100,100);
	bill.displayBill();


	return 0;
}