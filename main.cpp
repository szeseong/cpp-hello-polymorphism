#include <iostream>
using namespace std;

class ManagerRights {
public:
	ManagerRights() {}
	virtual void Planning() = 0;
};

class Employee {
public:
	Employee(char* title) { _title = title; }
	virtual char* GetTitle() { return _title; }
	virtual void DoWork() = 0;
private:
	char* _title;
};

class Engineer : public Employee {
public:
	Engineer(char* title) : Employee(title) {}
	void DoWork() { cout << GetTitle() << " is building things." << endl; }
};

class Accountant : public Employee {
	public:
		Accountant(char* title) : Employee(title) {}
		void DoWork() { cout << GetTitle() << " is preparing balance sheet." << endl; }
		void AuditDocument() { cout << GetTitle() << " is auditing documents." << endl; }
};

class Cfo : public Accountant, public ManagerRights {
public:
	Cfo(char* title) : Accountant(title) , ManagerRights(){}
	void DoWork() { cout << GetTitle() << " is doing budgeting." << endl; }
	void Planning() { cout << GetTitle() << " is doing planning." << endl; }
};


int main() {
	char accountantTitle[] = "Accountant";
	Accountant *accountant = new Accountant(accountantTitle);

	char cfoTitle[] = "CFO";
	Cfo *cfo = new Cfo(cfoTitle);

	char engineerTitle[] = "Engineer";
	Engineer *engineer = new Engineer(engineerTitle);

	Employee *emp = engineer;
	emp->DoWork(); // Eningeer DoWork

	emp = accountant;
	emp->DoWork(); // Accountant DoWork
	accountant->AuditDocument();  // Accountant

	emp = cfo;
	emp->DoWork(); // CFO DoWork
	cfo->AuditDocument(); // CFO
	ManagerRights *manager = cfo; // Transform to ManagerRights
	manager->Planning(); //

	std::cin.get(); // Pause
}