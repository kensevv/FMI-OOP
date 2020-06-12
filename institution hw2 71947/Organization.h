#pragma once
#include <iostream>

#include "Institution.h"
#include "Payer.h"
#include <string>
#include <vector>

class Organization : public Institution
{
private:
	std::vector<Institution> institutions_list;
	std::string organization_adress;

	void copy(const Organization& other);

public:
	Organization();
	Organization(const Institution& other);
	Organization& operator=(const Organization& other);
	Organization(unsigned int new_institution_id, std::string new_institution_name, 
		std::vector<Institution> new_institutions_list, std::string new_organization_adress);

	void add_institution(const Institution& newInstitution);

	void set_institutions_list(const std::vector<Institution> new_institutions_list);
	const std::vector<Institution>& get_institutions_list()const;

	void set_organization_adress(const std::string& newAddress);
	const std::string& get_organization_adress()const;

	friend std::ostream& operator<<(std::ostream& out, const Organization& current);
	friend std::istream& operator>>(std::istream& in, Organization& current);
};