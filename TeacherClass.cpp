#include <iostream>
using namespace std;
// TEACHER class 
class Teacher{
    public:
    Teacher();
    Teacher(string ,char ,string,string,string,string);
    Teacher(Teacher &);
    void setFname(string);
    string getFname();
    void setMID(char);
    char getMID();
    void setLname(string);
    string getLname();
    void setPhone(string);
    void setEmail(string);
    string getEmail();
    string getPhone();
    void setEduction(string);
    string getEducation();
    void teacherdisplay();
    private:
    string Fname;
    char midCid;
    string Lname;
    string tEmail;
    string phone;
    string education;
};
Teacher:: Teacher(){
    Fname=nullptr;
    midCid='\0';
    Lname=nullptr;
    tEmail=nullptr;
    phone=nullptr;
    education=nullptr;
}
    Teacher::Teacher(string Fname,char midCid,string Lname,string tEmail,string phone,string education){
        this->Fname=Fname;
        this->midCid=midCid;
        this->Lname=Lname;
        this->tEmail=tEmail;
        this->phone=phone;
        this->education=education;
    }
    Teacher::Teacher(Teacher & obj){
        obj.setFname(Fname);
        obj.setMID(midCid);
        obj.setLname(Lname);
        obj.setEmail(tEmail);
        obj.setPhone(phone);
        obj.setEduction(education);
    }
    void Teacher:: setFname(string Fname){
        this->Fname=Fname;
    }
    string Teacher::getFname(){
        cout<<"Name "<<endl;
        cout <<Fname<<" ";
        return Fname;
    }
    void Teacher::setMID(char midCid){
        this->midCid=midCid;
    }
    char Teacher::getMID(){
        return midCid;
    }
    void Teacher::setLname(string Lname){
        this->Lname=Lname;
    }
    string Teacher::getLname(){
        cout<<Lname;  
        return Lname;
    }
    void Teacher::setPhone(string phone){
        this->phone=phone;
    }
    string Teacher::getPhone(){
        cout<<endl<<" Phone no :";
        return phone;
    }
    void Teacher::setEduction(string education){
        this->education=education;
    }
    string Teacher::getEducation(){
        cout<<endl<<" Education :";
        return education;
    }
    void Teacher:: setEmail(string tEmail){
        this->tEmail=tEmail;
    }
    string Teacher::getEmail(){
        cout<<" email "<<endl;
        return tEmail;
    }
    void Teacher::teacherdisplay(){
        cout<<" Name :"<<Fname<<" . "<<midCid<<". "<<Lname<<endl<< " teacher email:"<<tEmail<<endl<<" contact :"<<phone<<endl<<" Education :"<<education<<endl;
    }
     
     // COURSE CLASS 
     class Course{
         public:
         Course (string ,string , Teacher * );
         void setCname(string);
         string getCname();
         void setCid(string);
         string getCid();
         void Coursedisplay();
         private:
         string courseId;
         string courseName;
         Teacher * teacherName;
         
     };
     Course::Course (string courseid ,string cname  ,Teacher * obj):courseId(courseid),courseName(cname),teacherName(obj){}
         void Course::setCname(string cname){
             courseName=cname;}
         
         string Course:: getCname(){
             cout<<" COURSE NAME :";
             return courseName;
         }
         void Course::setCid(string cid ){
             courseId=cid;
         }
         string Course::getCid(){
           return courseId;
         }
         void Course::Coursedisplay(){
             cout<<" Course NAME : "<<courseName<<endl;
             cout<<" Course ID :   "<<courseId<<endl;
             cout<<"__________Course teacher info ________________"<<endl;
             teacherName->teacherdisplay();
         }
int main()
{
    Teacher t1("ABDUL",'B',"RAZZAQ","ab4382906@gmail.com","03030463210","MSc(SE)");
   /*t1.teacherdisplay(); */{
   Course c1("l1043503","OOP",& t1);
    c1.Coursedisplay();
   }
    return 0;
}
