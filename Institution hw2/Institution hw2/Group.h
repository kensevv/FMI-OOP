#pragma once
#include "Payer.h"
#include "Institution.h"
class Group : public Institution
{
private:
	size_t group_id;
	Payer group_payer;

	void copy(const Group& other);
public:
	Group();
	Group(const Group& other);
	Group& operator=(const Group& other);
	Group(size_t new_institution_id, std::string new_institution_name, size_t new_group_id, const Payer& new_group_payer);


	void set_group_id(size_t _group_id);
	const size_t get_group_id()const;

	void set_group_payer(const Payer& _group_payer);
	const Payer& get_group_payer()const;


};

