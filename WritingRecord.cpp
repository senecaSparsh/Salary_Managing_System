#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (auto i = 0u; i < emp.size(); ++i) {
			for (auto j = 0u; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
					temp->rangeValidate();
					if (activeEmp.SINValidation(emp[i].id)) {
						activeEmp += std::move(temp);
					}
					else {
						throw std::string{ "***InValid!***" };
					}
					delete temp;
					temp = nullptr;
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (auto i = 0u; i < emp.size(); ++i) {
			for (auto j = 0u; j < sal.size(); ++j) {
				if (emp[i].id == sal[j].id) {
					unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
					temp->rangeValidate();
					if (activeEmp.SINValidation(emp[i].id)) {
						activeEmp += std::move(temp);
					}
					else {
						throw std::string{ "***InValid!***" };
					}
				}
			}
		}

		return activeEmp;
	}
}