#pragma once
#include <iostream>
#include "Institution.h"
#include "Payer.h"

#include <string>

class Group : public Institution
{
private:
	unsigned int group_id;
	Payer group_payer;
	         
	void copy(const Group& other);
public:
	Group();
	Group(const Group& other);
	Group& operator=(const Group& other);
	Group(unsigned int new_institution_id, std::string new_institution_name, unsigned int new_group_id, const Payer& new_group_payer);


	void set_group_id(unsigned int _group_id);
	const unsigned int get_group_id()const;

	void set_group_payer(const Payer& _group_payer);
	const Payer& get_group_payer()const;

	friend std::ostream& operator<<(std::ostream& out, const Group& current);
	friend std::istream& operator>>(std::istream& in, Group& current);
};

