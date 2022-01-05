
#pragma once
class Vaccine
{
  protected:
	char name[100];
	char mobileNumber[100];
	char vaccine[100];
    char pin[100];
    char date[100];
    char dose;
    int day1,day2,month1,month2,year1,year2;
	public:
		void setData();//1
		void addNew();//2
		void showData();//3
		void showList();//4
		void searchData();//5
		void viewVaccine();//6
    	void search_by_mobile();//7
    	void view_all();//8
    	void view_by_pin();//6.4
        bool check();//6.5
		void Search_by_Name();
		void search_by_vaccine();
}; 
