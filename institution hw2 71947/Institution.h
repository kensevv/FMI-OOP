#pragma once
#include <iostream>
#include <string>

class Institution
{
protected:
	unsigned int institution_id;
	std::string institution_name;

	void copy(const Institution& other);
public:
	Institution();
	Institution(const Institution& other);
	Institution& operator=(const Institution& other);
	Institution(unsigned int new_institution_id, std::string new_institution_name);

	void set_institution_id(unsigned int newInstitutionId);
	unsigned int get_institution_id()const;

	void set_institution_name(const std::string& newInstitutionName);
	const std::string& get_institution_name()const;

	friend std::ostream& operator<<(std::ostream& out, const Institution& current);
	friend std::istream& operator>>(std::istream& in, Institution& current);
};

