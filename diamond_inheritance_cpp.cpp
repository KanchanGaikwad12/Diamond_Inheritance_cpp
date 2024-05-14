//Diamond Inheritance of Employee, Manager,SalesPerson,SalesManager
#include<iostream>
#include<string>
using namespace std;
class Employee{
	  public:int id;
	        string name;
  double salary;  
	        public:Employee(){
	        	id=0;
	        	name="NA";
	        	salary=100.00;
			}	
		Employee(int id,string name,double salary){
			this->id=id;
			this->name=name;
			this->salary=salary;
		}	
		void display(){
			cout<<"ID: "<<this->id<<endl;
			cout<<"Name: "<<this->name<<endl;
			cout<<"Salaray: "<<this->salary<<endl;
		}
	
};
class Manager: virtual public Employee{
	protected:string dname;
	        double incentives;
	      public:Manager(){
	        	dname="No department assigned";
	        	incentives=0.00;
			}
			Manager(int id,string name,double salary,string dname,double incentives):Employee(id,name,salary){
				this->dname=dname;
				this->incentives=incentives;
			}
			void display(){
				cout<<"Department Name: "<<this->dname<<endl;
				cout<<"Manager Total Salary: "<<this->salary+incentives<<endl;
				
			}
	
};
class SalesPerson: virtual public Employee{
	protected: double pa,fa,ta;
	public:SalesPerson(){
		pa=25.25;
		fa=20.00;
		ta=12.50;
	}
	SalesPerson(int id,string name,double salary,double pa,double fa, double ta):Employee(id,name,salary){
		this->pa=pa;
		this->fa=fa;
		this->ta=ta;
	}
	void display(){
		cout<<"Pa: "<<this->pa<<endl;
		cout<<"Fa: "<<this->fa<<endl;
		cout<<"Ta: "<<this->ta<<endl;
		cout<<"Sales Person Salary: "<<this->salary+pa+fa+ta<<endl;
		
	}
};
	class SalesManager:public Manager,public SalesPerson{
		private: string position;
		public:
		SalesManager(){
			position="Position Not Assigned!";
		}
		SalesManager(int id,string name,double salary,string dname,double incentives,double pa,double fa,double ta,string position):Employee(id,name,salary),Manager(id,name,salary,dname,incentives),SalesPerson(id,name,salary,pa,fa,ta){
			this->position=position;
		}
		void display(){
			cout<<id<<" "<<name<<" "<<salary<<" "<<dname<<" "<<incentives<<" "<<pa<<" "<<fa<<" "<<ta<<" "<<position<<endl;
		}	
	};
int main(){
	Employee emp1;
	emp1.display();
	cout<<"\n\n-------------------------"<<endl;
	SalesManager sm1(012,"Ajit",5000.5,"CSE",1500,500,400,300,"Senior");
	sm1.display();
//	Employee emp(5,"Gauraw",50000);
//	emp.display();
}

