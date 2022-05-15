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
void toLowerCase(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = (char)tolower(str[i]);
    }
}
void merge(){
    char fileOne[30], fileTwo[30],  ch ,chr ,exe[5]=".txt";
    fstream fpsOne, fpsTwo, fpTemp ;
    cout<<"Enter the Name of First File without exetintion: ";
    gets(fileOne);
    strcat(fileOne,exe);
    cout<<"Enter the Name of Second File without exetintion: ";
    gets(fileTwo);
    strcat(fileTwo,exe);

    fpsOne.open(fileOne, fstream::in);
    fpsTwo.open(fileTwo, fstream::in);
    if((!fpsOne) || (!fpsTwo))
    {
        cout<<"file open error";
        
    }
    else
    {
        // creating and opening a temp file to make the mrege to it then retrun it to the first file
        fpTemp.open("temp.txt", fstream::out);
        if(!fpTemp)
            cout<<"\nError Occurred (Target File)!";
        else
        {
            // copying data to the temp file 
            while(fpsOne>>noskipws>>ch){
                fpTemp<<ch;}
            fpTemp<<"\n";
            while(fpsTwo>>noskipws>>ch){
                fpTemp<<ch;}

    }

    fpsOne.close();
    fpsTwo.close();
    fpTemp.close();
    // reopen temp file as input and reopen first file as output
    fpTemp.open("temp.txt",fstream::in);
    fpsOne.open(fileOne,fstream::out);
    // copying the whole temp file to the first file
    fpsOne << fpTemp.rdbuf();

    fpsOne.close();
    fpTemp.close();
    // deleting the temp file 
    remove("temp.txt");
        }
    cout<<endl;
}
void word_search(){
    string word,str;
    int a;
    char  filename[81],exe[5]=".txt";
    fstream filedata;
    cout<<"Enter the Name of File without exetension: ";
    gets(filename);
    strcat(filename,exe);
    filedata.open(filename,ios::in);
    filedata.seekg(0,ios::beg);
    cout<<"enter a word: ";
    cin>>str;
    if(!filedata){
        cout<<"error whlie opening file";
    }
    else{
        while (!filedata.eof())
        {
        
        while(getline(filedata,word)){
        toLowerCase(word);
        toLowerCase(str);
        // the if condition is to find the word from the begin of the file to its end
            if((word.find(str,0)) != string::npos){
                cout << "The word has been found "<<endl;
                a=1;
                break;
            }

        }
                if(a==0){
                cout<<"the word has not been found"<<endl;
                break;
            }

        }

      filedata.close();
      
    }
}
void count_lines(){
        int line_num=0;
    string line;
    char  filename[81],exe[5]=".txt";
    fstream filedata;
    cout<<"Enter the Name of Source File: ";
    gets(filename);
    strcat(filename,exe);
    filedata.open(filename,ios::in);
    if(!filedata){
        cout<<"error whlie opening file";
    }
    else{
        while(!filedata.eof()){
            // getline() is suitable to count lines
            getline(filedata,line);
            cout<<line<<endl;
            line_num++;
        }
      filedata.close();
      cout<<"number of lines = "<<line_num<<endl;
    } 
}
void count_words(){
        int word_num=1;
    string line;
    char a , filename[81],exe[5]=".txt";
    fstream filedata;
    cout<<"Enter the Name of File without exetension: ";
    gets(filename);
    strcat(filename,exe);
    filedata.open(filename,ios::in);
    filedata.seekg(0,ios::beg);
    if(!filedata){
        cout<<"error whlie opening file";
    }
    else{
        while(filedata){
          // get() is to read file word by word and if condition is to read spaces and endl to regonise words 
          filedata.get(a); 
        if(a==' ' || a=='\n'){
            word_num++;
        }
        }
    cout<<"number of words = "<<word_num<<endl;
      filedata.close();
      
    }
}
void count_char(){
        int char_num=0;
    string line;
    char a , filename[81],exe[5]=".txt";
    fstream filedata;
    cout<<"Enter the Name of Source File: ";
    gets(filename);
    strcat(filename,exe);
    filedata.open(filename,ios::in);
    filedata.seekg(0,ios::beg);
    if(!filedata){
        cout<<"error whlie opening file";
    }
    else{
        //  skipws is to skip counting spaces and endl
        while(filedata>>skipws>>a){
         
            char_num++;
        
        }
        
    cout<<"number of words = "<<char_num<<endl;
      filedata.close();
      
    }
}
