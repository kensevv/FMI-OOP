#pragma once
#include <string>
class Person
{
private:
	std::string person_name;
	size_t insurance_id;

	void copy(const Person& other);
public:
	Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	Person(std::string new_person_name, size_t new_insurance_id); //..

	void set_person_name(const std::string& newPersonName);
	const std::string& get_person_name() const;

	void set_insurance_d(size_t newInsuranceId);
	size_t get_insurance_id()const;
};