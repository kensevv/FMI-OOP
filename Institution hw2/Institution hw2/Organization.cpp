#include "Organization.h"

void Organization::copy(const Organization& other)
{
	Institution::copy(other);
	set_organization_adress(other.organization_adress);
	set_institutions_list(other.institutions_list);
}

Organization::Organization() : Institution()
{
}

Organization::Organization(const Institution& other)
{
	copy(other);
}

Organization& Organization::operator=(const Organization& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Organization::Organization(size_t new_institution_id, std::string new_institution_name, 
	std::vector<Institution> new_institutions_list, std::string new_organization_adress)
	: Institution(new_institution_id, new_institution_name)
{
	set_organization_adress(new_organization_adress);
	set_institutions_list(new_institutions_list);
}

void Organization::add_institution(const Institution& newInstitution)
{
	this->institutions_list.push_back(newInstitution);
}

void Organization::set_institutions_list(const std::vector<Institution> new_institutions_list)
{
	this->institutions_list = new_institutions_list;
}

const std::vector<Institution>& Organization::get_institutions_list() const
{
	return this->institutions_list;
}

void Organization::set_organization_adress(const std::string& newAddress)
{
	this->organization_adress = newAddress;
}

const std::string& Organization::get_organization_adress() const
{
	return this->organization_adress;
}
