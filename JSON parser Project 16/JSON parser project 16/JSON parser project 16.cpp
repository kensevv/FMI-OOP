// jsontxt parser project 16.cpp : Kenan Yusein 71947
#include <stdlib.h>
#include <iostream>
#include "String.h"
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

bool Validate();
String removeWhiteSymbols(String& str);

bool Exit = false;

String filepath;
String jsontxt;
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
        String userEntry;
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
                    String str;
                    MyFile >> str;
                    MyFile.get();
                    jsontxt = jsontxt + str;
                }
                std::cout << jsontxt; 
                
                MyFile.close();
                std::cout << "\nSuccessfully opened " << filepath << std::endl;

                if (Validate())
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
        jsontxt.reset();
        json.reset();
        filepath.reset();
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
        for (int i = 0; i < filepath.lenght() + 1; i++)
        {
            file[i] = filepath[i];
        }
        MyFile.open(file);
        if (MyFile.is_open())
        {
            MyFile << json.getJsontxt() << std::endl;
            std::cout << "Changes have been successfully saved to " << file << std::endl;
            json.reset();
            filepath.reset();
            jsontxt.reset();
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
            filepath.reset();
            jsontxt.reset();
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
}

void exit()
{
    clearScreen();
    Exit = true;
    std::cout << "Exiting the program..." << std::endl;
}

void useroptions()
{
    std::cout << "Options: Print, (Search, Set" << std::endl
        << "Create, Delete, Move" << std::endl
        << "Save [path], SaveAs [<file><path>] )\n>";
    String input;
    std::cin >> input;
    toLower(input);
    if (input == "print")
    {
        print();
    }
    else
    {

    }
}

void print()
{
    clearScreen();
    json.print();
}

bool Validate()
{
    String text = removeWhiteSymbols(jsontxt);
    // to do 
    return true; //zasega priemam che jsona e validen 
}

String removeWhiteSymbols(String& str)
{
    String result;
    for (int i = 0; i < str.lenght(); i++)
    {
        if (str[i] != ' ')
        {
            result = result + str[i];
        }
    }
    return result;
}