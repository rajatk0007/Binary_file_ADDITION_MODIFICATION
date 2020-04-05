/*Define class “Residence” with data members: house_no, income, house_name, and house_type. The class has the following member functions: ? void input() – obtains house_no, 
house_name and income. 
Calls assign() ? 
void assign() – allocates house type based on income (A/B/C/etc.) 
void output() – prints house details 
int house() – returns house_no
main() is menu driven to (1) add multiple records as required into a binary file in append mode (2) Enter house_no to locate the record in the binary file and modify 
it using random access (3) display records from the binary file.*/


#include<iostream>
#include<fstream>
using namespace std;

class Residence{
	public:
		int house_no;
		int income;
		char house_name;
		char house_type;
		
		void input()
		{
			cout<<"Enter the house number:";
			cin>>house_no;
			cout<<"Enter the house income:";
			cin>>income;
			cout<<"Enter the house name:";
			cin>>house_name;
			assign();
		}
		
		void assign()
		{
			if(income<10000)
			house_type='B';
			else
			house_type='A';
		}
		
		void output()
		{
		  cout<<"House Number:"<<house_no<<" "<<"House Income:"<<income<<" "<<"House Name:"<<house_name<<endl;
		}
		
		int house()
		{
			return house_no;
		}
		
		
};

void add_record();
void modify();
void display();

int main()
{
	while(1)
	{
	cout<<"\n1.Add record  2.Locate and modify existing record  3.Display records"<<endl;
	cout<<"Enter the choice:";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				add_record();
				break;
			}
		case 2:
			{
				modify();
				break;
			}
		case 3:
			{
				display();
				break;
			}
	}
    }
}

void add_record()
{
	ofstream file;
	file.open("House_records.dat",ios::binary|ios::app);
	Residence obj;
	obj.input();
	file.write((char*)&obj, sizeof(obj));
	file.close();
}

void modify()
{
char chr;
cout<<"\nEnter the house name to modify:";
cin>>chr;
int num=0;
Residence obj;
ofstream file1;
ifstream file2;
file1.open("House_records1.dat",ios::binary);
file2.open("House_records.dat",ios::binary);
while(file2.read((char*)&obj, sizeof(obj)))
{
	if(chr==obj.house_name)
	{
		cout<<"Enter New Values";
		obj.input();
		num++;
	}
	file1.write((char*)&obj, sizeof(obj));
	
}
file1.close();
file2.close();
remove("House_records.dat");
rename("House_records1.dat","House_records.dat");
if(num!=0)
cout<<"RECORD MODIFIED!!!";

	
	
}


void display()
{
	ifstream file;
	file.open("House_records.dat",ios::binary);
	Residence obj;
	while(file.read((char*)&obj, sizeof(obj)))
	{
	
	obj.output();
	
    }
	
	file.close();
	
}
