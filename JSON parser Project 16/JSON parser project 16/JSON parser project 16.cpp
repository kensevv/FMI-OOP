// jsontxt parser project 16.cpp : Kenan Yusein 71947
#include <iostream>
#include "String.h"
#include "Vector.cpp"
#include "Json.h"
#include <fstream>

void menu(std::ifstream & MyFile, String & jsontxt, String& filepath);
void openFile(std::ifstream& MyFile, String & jsontxt, String& filepath);
void closeFile(String & jsontxt, String & filepath);
void saveFile(String& jsontxt);
void saveAsFile(String& jsontxt);
void help();
void exit();

void useroptions(Json & json, std::ifstream& MyFile, String& jsontxt, String& filepath);

bool Validate(String & jsontxt);
String removeWhiteSymbols(String& str);

bool Exit = false;

int main()
{
    std::cout << "JSON parser 1.0" << std::endl; 
    std::ifstream MyFile;
    String filepath;
    String jsontxt;
    do
    {
        menu(MyFile, jsontxt, filepath);
        if (Validate(jsontxt)) 
        {
            Json json(jsontxt);
            //json.parse();
            useroptions(json, MyFile, jsontxt, filepath);
        }

    } while (!Exit);
}

void menu(std::ifstream& MyFile, String & jsontxt, String& filepath)
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
            openFile(MyFile, jsontxt, filepath);
            break;
        }
        else if (userEntry == "close")
        {
            closeFile(jsontxt, filepath);
            break;
        }
        else if (userEntry == "save")
        {
            saveFile(jsontxt);
            break;
        }
        else if (userEntry == "save as")
        {
            saveAsFile(jsontxt);
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

void openFile(std::ifstream& MyFile, String & jsontxt, String & filepath)
{
    if (jsontxt[0] != 0)
    {
        std::cout << "Close first! There is already a json loaded into the memory" << std::endl; 
        menu(MyFile, jsontxt, filepath);
    }
    else
    {
        do
        {
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
                std::cin.get();
                std::cout << "Successfully opened " << filepath << std::endl
                    << "The information from the file has been loaded and the file has been closed." << std::endl;
                filepath = file;
                break;
            }
            else
            {
                std::cout << "ERROR! File with such path/name doesn't exist, try again." << std::endl;
            }
        } while (true);
    }
}

void closeFile(String & jsontxt, String & filepath)
{
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to close. (No file opened/parser memory empty" << std::endl;
    }
    else
    {
        jsontxt.reset();
        std::cout << "Successfully closed "<< filepath << " : memory resetted" << std::endl;
    }
}

void saveFile(String & jsontxt)
{
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to save. (No file opened/parser memory empty" << std::endl;
    }
    else
    {

    }
}

void saveAsFile(String & jsontxt)
{
    if (jsontxt[0] == 0)
    {
        std::cout << "Nothing to save. (No file opened/parser memory empty" << std::endl;
    }
    else
    {

    }
}

void help()
{

}

void exit()
{
    Exit = true;
    std::cout << "Exiting the program..." << std::endl;

}

void useroptions(Json& json, std::ifstream& MyFile, String& jsontxt, String& filepath)
{
    std::cout << "Options: (print), (search <key>), (set <path> <string>)" << std::endl
        << "(create <path> <string>), (delete <path>), (move <from> <to>)" << std::endl
        << "(save [<path>]), (saveas <file>[<path>])" << std::endl
        << "To open the user menu type menu." << std::endl;
    String input;
    std::cin >> input;
    toLower(input);
    if (input == "menu")
    {
        menu(MyFile, jsontxt, filepath);
    }
    else if (input == "print")
    {

    }
    else
    {

    }
}

bool Validate(String & jsontxt)
{
    String text = removeWhiteSymbols(jsontxt);

    int openingCurves = 0;
    int closingCurves = 0;
    int openingBrackets = 0;
    int closingBrackets = 0;
    int comas = 0;
    int quotes = 0;
    int doubleDots = 0;

    // to do 
    return true;
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
