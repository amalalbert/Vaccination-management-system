#include "vaccine.h"
#include<iostream>
#include<ctime>
#include<stdio.h>//standard input output
#include<fstream>
#include<conio.h>//console input output
#include<string>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info
#define num_of_vaccine 0
using namespace std;
void menu();
void show();

struct Date{
    int day,month,year;
};

const int monthDays[12]  //to store Number of days in all months from Jan to Dec.
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
    
int CountLeapYears(Date day)
 {                          
int years=day.year;
   
    if (day.month <= 2)
        years--;

   
    return years / 4
           - years / 100
           + years / 400;

 }  
 
int getDifference(Date date1,Date date2)
{
    
    long int number1=date1.year*365+date1.day;
    for (int iterator = 0; iterator < date1.month - 1; iterator++)
    {
        number1 += monthDays[iterator];
    }
    number1 += CountLeapYears(date1);
    long int number2 = date2.year * 365 + date2.day;
    for (int iterator = 0; iterator < date2.month - 1; iterator++)
        number2 += monthDays[iterator];
    number2 += CountLeapYears(date2);  
    return (number2 - number1);
    }
bool Vaccine :: check()
{
    ifstream file_obj;
    int iterator=0;
    bool IsTrue=true;
    file_obj.open("vaccinetrial.txt");
    file_obj.seekg(0,ios :: beg);
    while(file_obj.read((char*)this,sizeof(Vaccine)))
    {
        iterator++;

    }
    file_obj.close();
     int sum=num_of_vaccine-iterator;
    int f_var=0;//file variable
    fstream file;
    file.open("count.txt",ios::in);
    file>>f_var;
    if((f_var+sum)<=0)
    {
        cout<<"WARNIG!!!!,insufficient vaccine,add vaccine"<<endl;
        getch();
        IsTrue=false;
        Vaccine::viewVaccine();
    }
    getch();
    file_obj.close();
    return IsTrue;
}

void Vaccine::setData()//1
{

    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t "<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t ENTER THE DETAILS ";
    cout<<"\n\t\t\t*****************************************\n\n";
    fflush(stdin);
        label2:fflush(stdin);
        cout<<"\n\t\t Enter your Mobile number :- ";
        
        gets(mobileNumber);
        fflush(stdin);
        if (dose == '1')
        {
        char pf[100];
        strcpy(pf,mobileNumber);
        ifstream mob;
        mob.open("vaccinetrial.txt");
        while(!mob.eof())
        {
        if(mob.read(reinterpret_cast<char*>(this),sizeof(*this))){

            if(strcmp(pf,mobileNumber)==0)
            {
                cout<<"\n\t\t Number found in records ,enter another mobile number\n";
                getch();
                mob.close();
                goto label2;
            }
            mob.close();
            }
            mob.close();
        }
        }
        cout<<"\n\t\t Enter your name :-  ";
        gets(name);
        fflush(stdin);

        cout<<"\n\t\t Enter date :-";
        gets(date);
        cout<<"\n\t\t Enter the vaccine injected :- ";
        gets(vaccine);
        cout<<"\n\t\t Enter Pincode :- ";
        gets(pin);

}

void Vaccine::addNew()//2
{
    int sum;
    cout<<"\nenter dose\n";
    cin>>dose;
    if(dose=='1')
    {
     goto label;
    }
    else if (dose=='2')
    {
    cout<<"\nenter date of first Vaccination \n";
    cin>>day1>>month1>>year1;
    cout<<"\nenter today's date\n";
    cin>>day2>>month2>>year2;
    std::string tmp = std::to_string(day2) +"/";
    Date date1 = {day1,month1,year1};
    Date date2 = {day2,month2,year2};
    // Function call
    sum=getDifference(date1, date2);
    }
    if (sum>60)
    {
        goto label;
    }
    else
    {
    cout<<"\n Wait for "<<60-sum<<" days before next dose\n";
    return;
    }

    label:fstream outin;

    outin.open("vaccinetrial.txt",ios::app|ios::out);
    setData();
    outin.write((char*)this,sizeof(Vaccine));
    cout<<"YOUR DATA HAS BEEN SUCCESSFULLY INSERTED "<<endl;
    getch();
    outin.close();
}
/*void Vaccine::showData()//3
{
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t  "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t DETAILS  ";
    cout<<"\n\t\t\t*****************************************\n\n";
  	cout<<"\t\t Name is: "<<name<<endl;
    cout<<"\t\t Mobile number is: "<<mobileNumber<<endl;
    cout<<"\n\t\t vaccine injected : "<<vaccine<<endl;
    cout<<"\n\t\t Pin Code : "<<pin<<endl;
}*/
void Vaccine::showList()//4
{
    cout<<"\n";
    cout<<setw(15)<<setiosflags(ios::left)<<mobileNumber;
    cout<<setw(15)<<name;
    cout<<setw(15)<<date;
    cout<<setw(15)<<vaccine;
    cout<<setw(15)<<pin<<endl;


}
void Vaccine::view_by_pin()
{
    ifstream file_object;
	file_object.open("vaccinetrial.txt");
    int count=0;
    char checkNumber[10];
    cout<<"enter pincode"<<endl;
    getch();
    fflush(stdin);
    gets(checkNumber);
       while(!file_object.eof())
	{
	if(file_object.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(checkNumber,pin)==0)
        {
            count++;
        }
		}
    }
    cout<<"the number of people vaccinated is :"<<endl;
    cout<<count;
    file_object.close();
    getch();
    }
    void Vaccine ::viewVaccine()//5
{
    ifstream file_object;
    int incrementor=0;
    file_object.open("vaccinetrial.txt");
    file_object.seekg(0,ios::beg);
    while(file_object.read((char*)this,sizeof(Vaccine)))
    {
        incrementor++;
    }
    file_object.close();
    int choice;
    int s=num_of_vaccine-incrementor;
       cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tVACCINE STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"\t\t 1. Add more        \t\t\t2.View available \n\t\t\t\t\t 3. Back"<<endl;
    cin>>choice;
    int f_var=0;//file variable
    fstream file("count.txt",ios::in);
    file>>f_var;
    file.close();
    switch(choice)
    {
    case 1:
        int vaccine_number;
        cout<<"\t Enter number of vaccines you want to add :"<<endl;
        cin>>vaccine_number;
        f_var=f_var+vaccine_number;
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
    ifstream file_object;
	file_object.open("vaccinetrial.txt");
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
   while(!file_object.eof())
	{
	if(file_object.read(reinterpret_cast<char*>(this),sizeof(*this))){

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
        file_object.close();
}
void Vaccine :: Search_by_Name()
{
    fstream file_object;
    file_object.open("vaccinetrial.txt");
    bool flag=false;
    char Search_name[100];
    cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM "<<endl;
    cout<<"\t\t\t\t\t\t "<<endl<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter  Name  to search: "<<endl;
    fflush(stdin);
    gets(Search_name);
    while(!file_object.eof())
    {
        if(file_object.read(reinterpret_cast<char*>(this),sizeof(*this)))
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
file_object.close();
}
void Vaccine :: search_by_vaccine()
{
    char Vacc_Name[100];
    bool flag=false;
    int count=0;
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
                count++;
            }

    }
    
}
if(flag==false)
{
    cout<<"No Records Found";
}
cout<<"\n\n\n No of people vaccinated by this vaccine: "<<count<<endl;
    vac.close();
}

void show()//a
{
	cout<<"\n\n\n";
    cout<<setw(15)<<setiosflags(ios::left)<<"Mobile No.";
    cout<<setw(15)<<"Name ";
    cout<<setw(15)<<"Date";
    cout<<setw(15)<<"Vaccine";
    cout<<setw(15)<<"Pincode"<<endl;

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
void Vaccine::view_all(){
			fstream file_object;
			file_object.open("vaccinetrial.txt",ios::binary|ios::in);
			if(!file_object){
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
			while(!file_object.eof()){
				if(file_object.read(reinterpret_cast<char*>(this),sizeof(*this)))
                {
					showList();
				}

			}
			getch();
			file_object.close();
			}
}


