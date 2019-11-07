#include<bits/stdc++.h>
using namespace std;

class Details{
private:
	string place;
	int pin_code;
	long mobile;
	int exp;
public:
	Details(string p="nagpur",int pin=440010,long m=0, int e=0){
		place=p;
		pin_code=pin;
		mobile=m;
		exp=e;
	}
	//copy constructor
	Details(const Details &d){
		place=d.place;
		pin_code=d.pin_code;
		mobile=d.mobile;
		exp=d.exp;
	}
	void address(string s,int pin,long mb){
		place=s;
		pin_code=pin;
		mobile=mb;
	}
	void printAddress(){
		cout<<"Address :"<<endl;
		cout<<"\tCity : "<<place<<endl;
		cout<<"\tPin Code : "<<pin_code<<endl;
		cout<<"\tMobile no : "<<mobile<<endl;
	}
	void experience(int e){
		exp=e;
	}
	void printExperience(){
		cout<<"Experience of :"<<exp<<" years"<<endl;
	}
};

class Salary{
	private:
		int sal;
	public:
		Salary (int s=1){	//base salary
			sal=s;
		}
		void salary(int s){
			sal=s;
		}
		void printSalary(){
			cout<<"Salary: "<<sal<<" LPA"<<endl;
		}
};

class Employee{
	private:
		string name;
		Details d;
		Salary income;
	public:
		Employee(string p,int pin,long m,int e,int sal,string s="abc"):d(p,pin,m,e),income(sal){
			name=s;
		}
		void setName(string s){
			name=s;
		}
		void displayName(){
			cout<<"Name : "<<name<<endl;
		}
		void displayAddress(){
			d.printAddress();
		}
		void displaySalary(){
			income.printSalary();
		}
		void displayAllDetails(){
			displayName();
			d.printAddress();
			d.printExperience();
			income.printSalary();
		}

};


int main(){
	string s,c;
	int p,in,exp;
	long m;
	cout<<"Name :";
	cin>>s;
	cout<<"City :";
	cin>>c;
	cout<<"Pin code :";
	cin>>p;
	cout<<"Mob no :";
	cin>>m;
	cout<<"Salary (in LPA ):";
	cin>>in;	
	cout<<"Experience (in years):";
	cin>>exp;

	Employee e(c,p,m,exp,in,s);
	
	printf("entered name is\n");
	e.displayName();
	printf("entered address is\n");
	e.displayAddress();
	printf("entered salary is\n");
	e.displaySalary();
	printf("the entered details are:\n");
	e.displayAllDetails();
}

