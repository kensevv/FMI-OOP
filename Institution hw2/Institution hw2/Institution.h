#pragma once
#include <string>
class Institution
{
protected:
	size_t institution_id;
	std::string institution_name;

	void copy(const Institution& other);
public:
	Institution();
	Institution(const Institution& other);
	Institution& operator=(const Institution& other);
	Institution(size_t new_institution_id, std::string new_institution_name);

	void set_institution_id(size_t newInstitutionId);
	size_t get_institution_id()const;

	void set_institution_name(const std::string& newInstitutionName);
	const std::string& get_institution_name()const;
};

