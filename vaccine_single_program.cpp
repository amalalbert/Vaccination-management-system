#include<iostream>
#include<ctime>
#include<stdio.h>//standard input output
#include<fstream>
#include<conio.h>//console input output
#include<string>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
#include<cstring>

#define num_of_vaccine 0

using namespace std;

void menu();
void show();

class Vaccine
{
    protected:
	char name[100];
	char mobileNumber[100];
	char vaccine[100];
    char pin[100];
    char date[100];
    char dose;
    int d1,d2,m1,m2,y1,y2;
	public:
		void setData();//1
		void addNew();//2
		void showData();//3
		void showList();//4
		void searchData();//5
		void viewVaccine();//6
    	void search_by_mobile();
        void search_by_vaccine();
        void Search_by_Name();
    	void view_all();//6.2
    	//void Vacc_count();//6.3
    	void view_by_p();//6.4
        bool check();//6.5
        void datecheck();

};
class Pincode : public Vaccine
{
    char pincode[100];

    public:
    //void add_vaccine_pin();
    //void count_in_pin();
};

//void Count::add_vaccine_pin()
struct Date {
    int d, m, y;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };

// This function counts number of
// leap years before the given date
int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
     // multiple of 100.
    return years / 4
           - years / 100
           + years / 400;
}

// This function returns number of
// days between two given dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}

// Driver code

bool Vaccine::check()

{
    ifstream ind;
    int i=0;
    bool isDone=true;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(Vaccine)))
    {
        i++;
    }
    ind.close();
    int s=num_of_vaccine-i;
    int f_var=0;
    fstream file;
    file.open("count.txt",ios::in);
    file>>f_var;
    if((f_var+s)<=0)
    {
        cout<<"WARNIG!!!!,insufficient vaccine,add vaccine"<<endl;
        getch();
        isDone=false;
        Vaccine::viewVaccine();
    }
    getch();
    ind.close();
    return isDone;
}

void Vaccine::setData()//1
{

    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t "<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t ENTER THE DETAILS ";
    cout<<"\n\t\t\t*****************************************\n\n";
    fflush(stdin);
        x2:
        fflush(stdin);
        cout<<"\n\t\t Enter your Mobile number :- ";
        fflush(stdin);
        cin>>mobileNumber;
        fflush(stdin);
        if(strlen(mobileNumber)<10)
        {
            cout<<"Enter a valid mobile number";
            goto x2;
        }
        fflush(stdin);
        char d=dose;
        if(d=='1')
        {
        char pf[100];
        strcpy(pf,mobileNumber);
        ifstream mob;
        mob.open("vaccinetrial.txt");
        while(!mob.eof())
        {
        if(mob.read(reinterpret_cast<char*>(this),sizeof(*this)))
        {

            if(strcmp(pf,mobileNumber)==0)
            {
                cout<<"\n\t\t Number found in records ,enter another mobile number\n";
                goto x2;
            }
            }
        }
        mob.close();
        }
        cout<<"\n\t\t Enter your name :-  ";
        fflush(stdin);
        gets(name);

        cout<<"\n\t\t Enter date :-";
        fflush(stdin);
        gets(date);
        cout<<"\n\t\t Enter the vaccine injected :- ";
        fflush(stdin);
        gets(vaccine);
        cout<<"\n\t\t Enter Pincode :- ";
        fflush(stdin);
        gets(pin);

}

//------------------------------------------------------
void Vaccine::addNew()//2
{
    int s;
    cout<<"\enter dose\n";
    cin>>dose;
    if(dose=='1')
    {
     goto x;
    }
    else if (dose=='2')
    {
    cout<<"\nenter date of first Vaccination \n";
    cin>>d1>>m1>>y1;
    cout<<"\nenter today's date\n";
    cin>>d2>>m2>>y2;
    std::string tmp = std::to_string(d2) +"/";
    Date dt1 = { d1,m1,y1 };
    Date dt2 = { d2,m2,y2 };
    // Function call
    s=getDifference(dt1, dt2);
    }
    if (s>60)
    {
        goto x;
    }
    else
    {
    cout<<"\n Wait for "<<60-s<<" days before next dose\n";
    return;
    }

    x:fstream outin;

    outin.open("vaccinetrial.txt",ios::app|ios::out);
    setData();
    outin.write((char*)this,sizeof(Vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
}

//---------------------------------------------
// void Vaccine::showData()//3
// {
//     cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
//     cout<<"\t\t\t\t\t\t  "<<endl<<endl;
//     cout<<"\n\t\t\t*****************************************\n";
//     cout<<"\t\t\t\t DETAILS  ";
//     cout<<"\n\t\t\t*****************************************\n\n";
//   	cout<<"\t\t Name is: "<<name<<endl;
//     cout<<"\t\t Mobile number is: "<<mobileNumber<<endl;
//     cout<<"\n\t\t vaccine injected : "<<vaccine<<endl;
//     cout<<"\n\t\t Pin Code : "<<pin<<endl;
// }
//------------------------------------------
void Vaccine::showList()//4
{
    cout<<"\n";
    cout<<setw(15)<<setiosflags(ios::left)<<mobileNumber;
    cout<<setw(15)<<name;
    cout<<setw(15)<<date;
    cout<<setw(15)<<vaccine;
    cout<<setw(15)<<pin<<endl;


}
void Vaccine::view_by_p()
{
    ifstream in;
	in.open("vaccinetrial.txt");
    int p=0;
    char pf[10];
    cout<<"enter pincode"<<endl;
    getch();
    fflush(stdin);
    gets(pf);
       while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(pf,pin)==0)
        {
            p++;
        }
		}
    }
    cout<<"the number of people vaccinated is :"<<endl;
    cout<<p;
    in.close();
    getch();
    }

//-----------------------------------------
void Vaccine ::viewVaccine()//5
{
    ifstream ind;
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(Vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
       cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back"<<endl;
    cin>>ch;
    int f_var=0;
    fstream file("count.txt",ios::in);
    file>>f_var;
    file.close();
    switch(ch)
    {
    case 1:
        int m;
        cout<<"\t Enter number of vaccines you want to add :"<<endl;
        cin>>m;
        f_var=f_var+m;
        file.open("count.txt",ios::out);
        file.seekg(0);
        file<<f_var;
        cout<<"\t\t Now total number of vaccines are : "<<f_var+s;
        file.close();
        break;
    case 2:
    	file.open("count.txt",ios::in);
        cout<<"\n\nAvailable number of vaccines are : "<<s+f_var;
        file.close();
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\nEnter valid option "<<endl;
        menu();
    }
    file.close();
    getch();
}
void Vaccine::searchData()//6
{

    Vaccine item;
    int op;
    cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM "<<endl;
	cout<<"\t\t\t\t\t\t"<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tChoose Option:";
    cout<<"\t\t\t 1.Search by Name\n\t\t\t2.Search by Mobile\n\t\t\t 3.Search by Vaccine"<<endl;
    fflush(stdin);
    cin>>op;
    switch(op)
    {
        case 1:system("cls");
                item.Search_by_Name();
                break;
        case 2:system("cls");
                item.search_by_mobile();
                break;
        case 3: system("cls");
                item.search_by_vaccine();
                break;

    }

        getch();
}
void Vaccine::search_by_mobile()//6.3
{
    ifstream mob;
	mob.open("vaccinetrial.txt");
    bool flag =false;
    int p=0;
    char pf[100];
     cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter mobile number to search: "<<endl;
    fflush(stdin);
    gets(pf);
   while(!mob.eof())
	{
	if(mob.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(pf,mobileNumber)==0)
        {
            showList();
            flag=true;
            
        
        }
        }
    }
    if(flag==false)
    {
    cout<<"SORRY!!This Mobile is not found in records."<<endl;
    }
        mob.close();
}
void Vaccine :: Search_by_Name()
{
    fstream Name;
    Name.open("vaccinetrial.txt");
    bool flag=false;
    int p=0;
    char Search_name[100];
    cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter  Name  to search: "<<endl;
    fflush(stdin);
    gets(Search_name);
    while(!Name.eof())
    {
        if(Name.read(reinterpret_cast<char*>(this),sizeof(*this)))
        {
            if(strcmp(Search_name,name)==0)
            {
                showList();
                flag=true;
                
            }
        }
}
if(flag==false)
{
    cout<<"Sorry This Name Could not find in records!!!...";

}
Name.close();
}
void Vaccine :: search_by_vaccine()
{
    char Vacc_Name[100];
    bool flag=false;
    int p=0;
    fstream vac;
    vac.open("vaccinetrial.txt");
    cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter  Vaccine to Search: "<<endl;
    fflush(stdin);
    gets(Vacc_Name);
    while(!vac.eof())
    {
        if(vac.read(reinterpret_cast<char*>(this),sizeof(*this)))
        {
            if(strcmp(Vacc_Name,vaccine)==0)
            {
                showList();
                flag=true;
                p++;
            }

    }
    
}
if(flag==false)
{
    cout<<"No Records Found";
}
cout<<"\n\n\n No of people vaccinated by this vaccine: "<<p<<endl;
    vac.close();
}

/*void Vaccine :: Vacc_count()
{
    fstream pinf;
    pinf.open("Plist.txt",ios::app|ios::out);
    Vaccine v;
    v.vpin=v.Vax_in_pin;
    pinf.write((char*)&v,sizeof(Vaccine));
    pinf.close();
}*/
//---------------------------------------------------------
void show()//a
{
	cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Mobile No.";
    cout<<setw(15)<<"Name ";
    cout<<setw(15)<<"Date";
    cout<<setw(15)<<"Vaccine";
    cout<<setw(15)<<"Pincode"<<endl;

}
//-------------------------------------------------
void Vaccine::view_all(){
			fstream outfile;
			outfile.open("vaccinetrial.txt",ios::binary|ios::in);
			if(!outfile){
				cout<<"File doesnot exist\n";
				return;
			}
			else{
			cout<<"\t\t\t\t"<<"     VACCINE MANAGEMENT SYSTEM"<<endl;
    		cout<<"\t\t\t\t\t\t "<<endl<<endl;
    		cout<<"\n\t\t\t*****************************************\n";
    		cout<<"\t\t\t\t\tALL DATA ";
    		cout<<"\n\t\t\t*****************************************\n\n";
			show();
			while(!outfile.eof()){
				if(outfile.read(reinterpret_cast<char*>(this),sizeof(*this)))
                {
					showList();
				}

			}
			getch();
			outfile.close();
			}
}

void menu()//c
{
    system("cls");
    cout<<"\t\t\t\t"<<"     VACCINE MANAGEMENT SYSTEM "<<endl;
	cout<<"\t\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\t\t\t\t"<<"==================================\n";
    cout<<"\t\t\t\t\t"<<"   MAIN MENU"<<endl;
    cout<<"\t\t\t\t"<<"==================================\n";
    cout<<"\n\t\t1: Add NEW Record\t\t\t 2: View VACCINE DATA"<<endl;
    cout<<"\n\t\t3: search   \t\t\t\t 4: View All Data"<<endl;
    cout<<"\n\t\t5: View Vaccine by Pincode"<<"\t\t"<<" 6: Exit"<<endl;
}
//----------------------------------------
int main()//MAINFUNCTION
{
     Vaccine obj;
      int ch;
      do{x:obj.check();
            cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t\t  "<<endl;
            menu();
            cout<<"\n\t\n\tSelect option : ";
            cin>>ch;
      switch(ch)

       {
         case 1: system("cls");
                 bool Isdone;
                 Isdone=obj.check();
                 if(Isdone==true)
                 {
                 obj.addNew();
                 }
                 else
                 {
                     goto x;
                 }
                 break;
         case 2: system("cls");
       	   	  	obj.viewVaccine();
                 break;
         case 3:system("cls");
            	obj.searchData();
                break;
         case 4:system("cls");
            	obj.view_all();
                break;
         case 5 :system("cls");
                 obj.view_by_p();
                 break;
         case 6:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tWrong choice\n";
                  exit(0);
       }

      }while(ch!=0);

      return 0;
}
