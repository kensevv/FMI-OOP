#include <iostream>

#include <stdlib.h>
#include "Institution.h"
#include "Organization.h"
#include "Group.h"
#include "Payer.h"
#include "Person.h"


void addElemetns();
void useroptions();
void printAll();

bool Exit = false;
std::string toLower(std::string& s);
void clearScreen();

std::vector<Person> people;
std::vector<Group> groups;
std::vector<Institution> institutions;
std::vector<Organization> organizations;
std::vector<Payer> payers;

int main()
{
    do
    {
        char input;
        std::cout << "Enter (1) to Add (Institutions, Organizations, Groups, Payers, People)" << std::endl 
                  << "Enter (2) for User functional menu." << std::endl
            << ">";
        std::cin >> input;
        std::cin.get();
        if (input == '1')
        {
            addElemetns();
        }
        else if (input == '2')
        {
            useroptions();
        }
        else {
            std::cout << "Wrong input, try again!" << std::endl;
        }
    } while (!Exit);
}

void addElemetns()
{
    clearScreen();
    std::cout << "Add to program memory." << std::endl << std::endl;

    std::cout << std::endl << "Person, Payer, Group, Organization, Institution." << std::endl
        << ">";
    do
    {
        std::string userEntry;
        std::cin >> userEntry;
        toLower(userEntry);

        if (userEntry == "person")
        {
            Person newPerson;
            std::cin >> newPerson;
            people.push_back(newPerson);
            //
            break;
        }
        else if (userEntry == "Payer")
        {
            Payer newPayer;
            std::cin >> newPayer;
            payers.push_back(newPayer);
            //
            break;
        }
        else if (userEntry == "Group")
        {
            Group newGroup;
            std::cin >> newGroup;
            groups.push_back(newGroup);
            //
            break;
        }
        else if (userEntry == "Organization")
        {
            Organization newOrganization;
            std::cin >> newOrganization;
            organizations.push_back(newOrganization);
            //
            break;
        }
        else if (userEntry == "Institution")
        {
            Institution newInstitution;
            std::cin >> newInstitution;
            institutions.push_back(newInstitution);
            //
            break;
        }
        else
        {
            std::cout << "Wrong input, try again!" << std::endl
                << ">";
        }
    } while (true);


}

void useroptions()
{
    clearScreen();

    std::cout << "User functional oprtions:" << std::endl;

    std::cout << std::endl << "Print, " << std::endl
        << ">";
    do
    {
        std::string userEntry;
        std::cin >> userEntry;
        toLower(userEntry);

        if (userEntry == "print")
        {
            printAll();
            //
            break;
        }
        else
        {
            std::cout << "Wrong input, try again!" << std::endl
                << ">";
        }
    } while (true);
}

void printAll()
{
    for (int i = 0; i < people.size(); i++)
    {
        std::cout << people[i];
    }
    for (int i = 0; i < groups.size(); i++)
    {
        std::cout << groups[i];
    }
    for (int i = 0; i < institutions.size(); i++)
    {
        std::cout << institutions[i];
    }
    for (int i = 0; i < organizations.size(); i++)
    {
        std::cout << organizations[i];
    }
    for (int i = 0; i < payers.size(); i++)
    {
        std::cout << payers[i];
    }
}


std::string toLower(std::string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
    }
    return s;
}

void clearScreen()
{
    system("CLS");
}
