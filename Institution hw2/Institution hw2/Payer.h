#pragma once
#include<string>

class Payer
{
private:
	std::string payer_name;

	//void copy(const Payer& other);
public:
	Payer();
	//Payer(const Payer& other);
	//Payer& operator=(const Payer& other);
	//Payer(std::string new_payer_name);

	//bool payer_member_rule(); // group_id potrebitelska polica

	void set_payer_name(const std::string& new_payer_name);
	const std::string& get_payer_name()const;
};

