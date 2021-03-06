// jsontxt parser project 16.cpp : Kenan Yusein 71947
#include <stdlib.h>
#include <iostream>
#include "Vector.cpp"
#include "Json.h"
#include <fstream>

void clearScreen();

void menu();
void openFile();
void closeFile();
void saveFile();
void saveAsFile();
void help();
void exit();

void useroptions();
void print();
void searchKey(std::string&);
void deleteKey(std::string&);
void create(std::string& newElement);

bool Validate(std::string& jsontxt);
bool brackets(std::string& jsontxt);
bool otherValidations(std::string& jsontxt);

std::string removeWhiteSymbols(std::string& str);
std::string toLower(std::string& s);

bool Exit = false;

std::string filepath;
std::string jsontxt;
Json json;


int main()
{
    std::cout << "JSON parser 1.0" << std::endl; 
    menu();
    do
    {
        char input;
        std::cout << "Enter (1) to open the Menu, Enter (2) for User Menu." << std::endl
            << ">";
        std::cin >> input;
        std::cin.get();
        if (input == '1')
        {
            menu();
        }
        else if (input == '2')
        {
            if(filepath[0] == 0) std::cout << "No information loaded. Open a file first." << std::endl;
            else useroptions();
        }
        else {
            std::cout << "Wrong input, try again!" << std::endl;
        }
    } while (!Exit);
}

void clearScreen()
{
    system("CLS");
}

void menu()
{
    std::cout << std::endl << "Menu: Open, Close, Save, Save As, Help and Exit" << std::endl
        << ">";
    do
    {
        std::string userEntry;
        std::cin >> userEntry;
        toLower(userEntry);

        if (userEntry == "open")
        {
            openFile();
            break;
        }
        else if (userEntry == "close")
        {
            closeFile();
            break;
        }
        else if (userEntry == "save")
        {
            saveFile();
            break;
        }
        else if (userEntry == "save as")
        {
            saveAsFile();
            break;
        }
        else if (userEntry == "help")
        {
            help();
            break;
        }
        else if (userEntry == "exit")
        {
            exit();
            break;
        }
        else
        {
            std::cout << "Wrong input, try again!" << std::endl
                << ">";
        }
    } while (true);
}

void openFile()
{
    clearScreen();
    if (jsontxt[0] != 0)
    {
        std::cout << "Close first! There is already a json loaded into the memory" << std::endl; 
    }
    else
    {
        do
        {
            std::ifstream MyFile;
            std::cout << "Enter file name/path" << std::endl
                << ">";
            char file[50];
            std::cin >> file;
            MyFile.open(file);

            if (MyFile.is_open())
            {
                while (!MyFile.eof())
                {
                    char str[1000];
                    MyFile.getline(str, 1000);
                    jsontxt = jsontxt + str;
                }
                
                MyFile.close();
                std::cout << "\nSuccessfully opened " << filepath << std::endl;

                if (Validate(jsontxt))
                {
                    json.loadNparse(removeWhiteSymbols(jsontxt));
                    filepath = file;
                    std::cout << "The file is valid and the information has been loaded." << std::endl;
                    break;
                }
                else std::cout << "Invalid Json file." << std::endl;
            }
            else
            {
                std::cout << "ERROR! File with such path/name doesn't exist, try again." << std::endl;
            }
        } while (true);
    }
}

void closeFile()
{
    clearScreen();
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to close. (No file opened/parser memory empty" << std::endl;
    }
    else
    {
        std::cout << "Successfully closed "<< filepath << " : memory resetted" << std::endl;
        jsontxt.clear();
        //jsontxt.reset();
        json.reset();
        filepath.clear();
        //filepath.reset();
    }
}

void saveFile()
{
    clearScreen();
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to save. (No file opened/parser memory empty" << std::endl;
    }
    else
    {
        std::ofstream MyFile;
        char file[50];
        for (int i = 0; i < filepath.length() + 1; i++)
        {
            file[i] = filepath[i];
        }
        MyFile.open(file);
        if (MyFile.is_open())
        {
            MyFile << json.getJsontxt() << std::endl;
            std::cout << "Changes have been successfully saved to " << file << std::endl;
            json.reset();
            filepath.clear();
            jsontxt.clear();
        }
        MyFile.close();
    }
}

void saveAsFile()
{
    clearScreen();
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to save. (No file opened/parser memory empty" << std::endl;
    }
    else
    {
        char file[50];
        std::cout << "Input new file name." << std::endl
            << ">";
        std::cin >> file;
        std::ofstream MyFile;
        MyFile.open(file);
        if (MyFile.is_open())
        {
            MyFile << json.getJsontxt() << std::endl;
            std::cout << "Changes have been successfully Saved AS to " << file << std::endl;
            json.reset();
            filepath.clear();
            jsontxt.clear();
        }
        else
        {
            std::cout << "Error, changes could not been saved." << std::endl;
        }
        MyFile.close();
    }
}

void help()
{
    clearScreen();
    // ...
}

void exit()
{
    clearScreen();
    Exit = true;
    std::cout << "Exiting the program..." << std::endl;
}

void useroptions()
{
    std::cout << "Options: Print, Search, Delete, Create" << std::endl;
    std::cout << ">";
    std::string input;
    std::getline(std::cin, input);
    toLower(input);
    if (input == "print")
    {
        print();
    }
    else if (input == "search")
    {
        std::cout << "<key>: >";
        std::string sKey;
        std::getline(std::cin, sKey);

        searchKey(sKey);
    }
    else if (input == "delete")
    {
        std::cout << "<key>: >";
        std::string dKey;
        std::getline(std::cin, dKey);

        deleteKey(dKey);
    }
    else if (input == "create")
    {
        std::cout << "Enter valid Json format key - value. (\"KEY\": value)" << std::endl;
        std::cout << ">";
        std::string newElement;
        std::getline(std::cin, newElement);
        create(newElement);
    }
    else
    {

    }
}

void print()
{
    clearScreen();
    std::cout << "Parsed Json:" << std::endl;
    json.print();
}

void searchKey(std::string& sKey)
{
    clearScreen();

    bool found = false;
    json.searchKey(sKey, found);

    if (!found) std::cout << "Key \"" << sKey << "\" was not found!" << std::endl;
}

void deleteKey(std::string& dKey)
{
    clearScreen();
    bool deleted = false;

    json.deleteKey(dKey, deleted);

    if (!deleted) std::cout << "Key \"" << dKey << "\" was not found!" << std::endl;
}

void create(std::string& newElement)
{
    clearScreen();
    std::cout << newElement << std::endl;
    if (Validate(newElement))
    {
        json.create(newElement);
    }
    else std::cout << "Invalid json format input." << std::endl;
}

bool Validate(std::string& jsontxt)
{
    return brackets(jsontxt) && otherValidations(jsontxt);
}

bool brackets(std::string& jsontxt)
{
    std::string str = removeWhiteSymbols(jsontxt);
    //checking { } brackets.
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{') counter++;
        else if (str[i] == '}') counter--;

        if (counter < 0) return false;
    }
    if (counter != 0) return false;

    // checking [ ] brackets;
    counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ('[' == str[i])counter++;
        else if (']' == str[i])  counter--;

        if (counter < 0) return false;
    }
    if (counter != 0) return false;

    return true;
}

bool otherValidations(std::string& jsontxt)
{
    std::string str = removeWhiteSymbols(jsontxt);
    int comas = 0, quotes = 0, doubledots = 0;

    //to:do
    for (int i = 0; i < str.length(); i++)
    {

    }
    
    return true;
}


std::string removeWhiteSymbols(std::string& str)
{
    std::string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            result = result + str[i];
        }
    }
    return result;
}

std::string toLower(std::string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
    }
    return s;
}