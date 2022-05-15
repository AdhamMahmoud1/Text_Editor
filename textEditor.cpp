#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include "text_functions.cpp"
using namespace std;
int main()
{ 
    int choice;
    do{
        cout << "******************Hello in our Text Editor***********************" << endl;
        cout << "What would you like to do in your text file:\n"
             << "1- Add" << endl
             << "2- Display the content" << endl
             << "3- Clear" << endl
             << "4- Encrypt the file content" << endl
             << "5- Decrypt the file content" << endl;
             cout<< "6- Merge another file" << endl;
            cout << "7- Count the number of words in the file."<<endl;
             cout << "8- Count the number of characters in the file"<<endl;
             cout<< "9- Count the number of lines in the file"<<endl;
            cout << "10- Search for a word in the file"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            display_content();
            break;
        case 3:
            cls_file();
            break;
        case 4:
            encrypt();
            break;
        case 5:
            dencrypt();
            break;
        case 6:
            merge();
            break;
        case 7:
            count_words();
            break;
        case 8:
            count_char();
            break;
        case 9:
            count_lines();
            break;
        case 10:
            word_search(); 
            break;                   
        default:
            break;
        }
        cout << "Do you need to do any thing more?\n1-Yes         2-No" << endl;
        cin >> choice;
    } while (choice == 1);
    cout << "Thanks for using our ***TEXT EDITOR***" << endl;
    return 0;
}