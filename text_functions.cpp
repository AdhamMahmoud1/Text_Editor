#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include "text_functions.h"
using namespace std;

void display_content()
{
    string line;
    char myf[81], exe[5] = ".txt";
    cout << "PLease enter the file name without extintion: ";
    gets(myf);
    strcat(myf, exe);
    fstream file(myf, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "That file is not exist" << endl;
    }
}

void add()
{
    string txt;
    char myf[81], exe[5] = ".txt";
    cout << "PLease enter the file name without extintion: ";
    gets(myf);
    strcat(myf, exe);
    fstream file(myf, ios::in);
    if (file.is_open())
    {
        cout << "This file is already exist." << endl;
        file.close();
        fstream file(myf, ios::app);
        cout << "Please enter the text you want to add to the file: ";
        getline(cin, txt);
        file << txt;
        file.close();
    }
    else
    {
        cout << "This file is not exist. I created it for you." << endl;
        file.close();
        fstream file(myf, ios::app);
        cout << "Please enter the text you want to add to the file: ";
        getline(cin, txt);
        file << txt;
        file.close();
    }
}
void cls_file()
{
    string txt;
    char myf[81], exe[5] = ".txt";
    cout << "PLease enter the file name without extintion: ";
    gets(myf);
    strcat(myf, exe);
    fstream file(myf, ios::out | ios::trunc);
    file.close();
    cout << "The data in this file has been deleted!" << endl;
}
void encrypt()
{
    char myf[81], exe[5] = ".txt", ch;
    cout << "PLease enter the file name without extintion: ";
    gets(myf);
    strcat(myf, exe);
    fstream fps, fpt;
    fps.open(myf, fstream::in);
    fpt.open("tmp.txt", fstream::out);
    while (fps >> noskipws >> ch)
    {
        ch = ch + 1;
        fpt << ch;
    }
    fps.close();
    fpt.close();
    fps.open(myf, fstream::out);
    fpt.open("tmp.txt", fstream::in);
    while (fpt >> noskipws >> ch)
    {
        fps << ch;
    }
    fps.close();
    fpt.close();
    cout << "File '" << myf << "' Encrypted Successfully!";
    cout << endl;
}
void dencrypt()
{
    char myf[81], exe[5] = ".txt", ch;
    cout << "PLease enter the file name without extintion: ";
    gets(myf);
    strcat(myf, exe);
    fstream fps, fpt;

    fps.open(myf, fstream::in);
    fpt.open("tmp.txt", fstream::out);
    while (fps >> noskipws >> ch)
    {
        ch = ch - 1;
        fpt << ch;
    }
    fps.close();
    fpt.close();
    fps.open(myf, fstream::out);
    fpt.open("tmp.txt", fstream::in);

    while (fpt >> noskipws >> ch)
    {
        fps << ch;
    }

    fps.close();
    fpt.close();

    cout << "File '" << myf << "' Encrypted Successfully!";
    cout << endl;
}