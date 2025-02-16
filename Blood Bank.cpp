//
// Created by Hamdoon Zafar on 11/29/2024.
//

#include<iostream>
#include<fstream>
#include "Blood Bank.h"
using namespace std;
void adminLogin()
{
    string bloodGroups[8];
    char choice;
    string username, password;
    string storedUsername, storedPassword;
    bool matchedCredentials = false;
    cout<<"Enter your username for login: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Enter your password for login: ";
    getline(cin,password);
    ifstream fin("Login Credentials");
    if (fin.is_open()) {
        while (getline(fin, storedUsername) && getline(fin, storedPassword)) {
            if (storedUsername == username && storedPassword == password) {
                cout << "Credentials matched! Welcome Admin.\n";
                cout<<"Do you want to review stock of blood?(Y for YES and N for NO): ";
                cin>>choice;
                if(choice == 'y' || choice =='Y' ) {
                   ifstream jin("Blood Bank");
                    if(jin.is_open()) {
                    for(int i =0; i< 8; i++) {
                        jin>>bloodGroups[i];
                    }   jin.close();
                        for(int i=0; i<1; i++) {
                            cout<<"\nA Positive Blood in stock "<<bloodGroups[0]<<endl;
                            cout<<"A Negative Blood in stock "<<bloodGroups[1]<<endl;
                            cout<<"B Positive Blood in stock "<<bloodGroups[2]<<endl;
                            cout<<"B Negative Blood in stock "<<bloodGroups[3]<<endl;
                            cout<<"O Positive Blood in stock "<<bloodGroups[4]<<endl;
                            cout<<"O Negative Blood in stock "<<bloodGroups[5]<<endl;
                            cout<<"AB Positive Blood in stock "<<bloodGroups[6]<<endl;
                            cout<<"AB Negative Blood in stock "<<bloodGroups[7]<<endl;
                        }
                    }

                }
                matchedCredentials = true;
                break;
            }
        }
        fin.close();
        if (!matchedCredentials) {
            cout << "INVALID INPUT. Username or password is incorrect.\n";
        }
    }
}
void adminSignUp()
{
    string username, password;
    cout<<"===== Remember the following credentials you are about to enter ====="<<endl;
    cout<<"Enter your username: ";
    cin.ignore();
    getline(cin, username);
    cout<<"Enter your password: ";
    cin>>password;

    ofstream fout("Login Credentials", ios:: app);
    if(fout.is_open()) {
        fout<<username<<endl;
        fout<<password<<endl;
        fout.close();
    }
    else
        cout<<"Error in file opening."<<endl;

}
