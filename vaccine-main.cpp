#include<iostream>
#include<ctime>
#include<stdio.h>//standard input output
#include<fstream>
#include<conio.h>//console input output
#include<string>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>
#include "vaccine.cpp"
using namespace std;
void menu();
void show();
int main()//MAINFUNCTION
{
     Vaccine obj;
      int choice;
      do{label:obj.check();
            cout<<setw(50)<<"VACCINE MANAGEMENT SYSTEM"<<endl;
            cout<<"\t\t\t\t\t\t  "<<endl;
            menu();
            cout<<"\n\t\n\tSelect option : ";
            cin>>choice;
      switch(choice)

       {
         case 1: system("cls");
                 bool IsTrue;
                 IsTrue=obj.check();
                 if(IsTrue==true)
                 {
                 obj.addNew();
                 }
                 else
                 {
                     goto label;
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
                 obj.view_by_pin();
                 break;
         case 6:  system("cls");
                    exit(0);
         default: system("cls");
                  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tWrong choice\n";
                  exit(0);
       }

      }while(choice!=0);

      return 0;
}