//
// Created by Humdoon Zafar on 11/29/2024.
//
#include<iostream>
#include "Blood Bank.h"
//#include "Blood Bank.cpp"
#include<fstream>
using namespace std;
struct Blood {

    double aPos = 3;
    double aNeg = 6;
    double bPos = 5;
    double bNeg = 8;
    double oNeg = 5;
    double oPos = 4;
    double abPos = 2;
    double abNeg = 9;
    void loadFromFile()
    {
    ifstream fin("Blood Bank");
        if(fin.is_open()) {
            fin>>aPos;
            fin>>aNeg;
            fin>>bPos;
            fin>>bNeg;
            fin>>oPos;
            fin>>oNeg;
            fin>>abPos;
            fin>>abNeg;
        }
    fin.close();
    }


    void donateBlood()
    {
        int  noOfBottles;
        string bloodGroup ;
        cin.ignore();
        bool bloodGroupFound = false;
        do {
            cout<<"Enter your blood group (in words): ";
            getline(cin,bloodGroup);
            if(bloodGroup != "A Positive" && bloodGroup != "a positive" && bloodGroup != "A positive"
            && bloodGroup !="A Negative" && bloodGroup != "a negative" && bloodGroup != "A negative"
            && bloodGroup !="B Positive" && bloodGroup != "b positive" && bloodGroup != "B positive"
            && bloodGroup !="B Negative" && bloodGroup != "b negative" && bloodGroup != "B negative"
            && bloodGroup !="O Positive" && bloodGroup != "o positive" && bloodGroup != "O positive"
            && bloodGroup !="O Negative" && bloodGroup != "o negative" && bloodGroup != "O negative"
            && bloodGroup !="AB Positive" && bloodGroup != "ab positive" && bloodGroup != "AB positive"
            && bloodGroup !="AB Negative" && bloodGroup != "ab negative" && bloodGroup != "AB negative")
                cout<<"Blood group not found."<<endl;
            else
            {
                bloodGroupFound = true;
            }
        }while(bloodGroupFound != true);
        cout<<"Enter the number of bottles you want to donate: ";
        cin>>noOfBottles;
            if(bloodGroup == "A Positive" || bloodGroup == "a positive" || bloodGroup== "A positive" )
                aPos+=noOfBottles;
            if(bloodGroup=="A Negative" || bloodGroup == "a negative" || bloodGroup== "A negative" )
                aNeg+=noOfBottles;
            if(bloodGroup=="B Positive" || bloodGroup == "b positive" || bloodGroup== "B positive" )
                bPos+=noOfBottles;
            if(bloodGroup=="B Negative" || bloodGroup == "b negative" || bloodGroup== "B negative" )
                bNeg+=noOfBottles;
            if(bloodGroup=="O Positive" || bloodGroup == "o positive" || bloodGroup== "O positive" )
                oPos+=noOfBottles;
            if(bloodGroup=="O Negative" || bloodGroup == "o negative" || bloodGroup== "O negative" )
                oNeg+=noOfBottles;
            if(bloodGroup=="AB Positive" || bloodGroup == "ab positive" || bloodGroup== "AB positive" )
                abPos+=noOfBottles;
            if(bloodGroup=="AB Negative" || bloodGroup == "ab negative" || bloodGroup== "AB negative" )
                abNeg+=noOfBottles;
            storeInFile();
    }


    void receiveBlood()
    {
        int  noOfBottles;
        string bloodGroup ;
        cin.ignore();
        bool bloodGroupFound = false;
     do {
         cout<<"Enter your blood group (in words): ";
         getline(cin,bloodGroup);
            if(bloodGroup != "A Positive" && bloodGroup != "a positive" && bloodGroup != "A positive"
            && bloodGroup !="A Negative" && bloodGroup != "a negative" && bloodGroup != "A negative"
            && bloodGroup !="B Positive" && bloodGroup != "b positive" && bloodGroup != "B positive"
            && bloodGroup !="B Negative" && bloodGroup != "b negative" && bloodGroup != "B negative"
            && bloodGroup !="O Positive" && bloodGroup != "o positive" && bloodGroup != "O positive"
            && bloodGroup !="O Negative" && bloodGroup != "o negative" && bloodGroup != "O negative"
            && bloodGroup !="AB Positive" && bloodGroup != "ab positive" && bloodGroup != "AB positive"
            && bloodGroup !="AB Negative" && bloodGroup != "ab negative" && bloodGroup != "AB negative")
             cout<<"Blood group not found."<<endl;
         else
         {
             bloodGroupFound = true;
         }
     }while(bloodGroupFound != true);
        cout<<"Enter the number of bottles you want to donate: ";
        cin>>noOfBottles;
        if(bloodGroup == "A Positive" || bloodGroup == "a positive" || bloodGroup== "A positive" )
            aPos+=noOfBottles;
        if(bloodGroup=="A Negative" || bloodGroup == "a negative" || bloodGroup== "A negative" )
            aNeg+=noOfBottles;
        if(bloodGroup=="B Positive" || bloodGroup == "b positive" || bloodGroup== "B positive" )
            bPos+=noOfBottles;
        if(bloodGroup=="B Negative" || bloodGroup == "b negative" || bloodGroup== "B negative" )
            bNeg+=noOfBottles;
        if(bloodGroup=="O Positive" || bloodGroup == "o positive" || bloodGroup== "O positive" )
            oPos+=noOfBottles;
        if(bloodGroup=="O Negative" || bloodGroup == "o negative" || bloodGroup== "O negative" )
            oNeg+=noOfBottles;
        if(bloodGroup=="AB Positive" || bloodGroup == "ab positive" || bloodGroup== "AB positive" )
            abPos+=noOfBottles;
        if(bloodGroup=="AB Negative" || bloodGroup == "ab negative" || bloodGroup== "AB negative" )
            abNeg+=noOfBottles;

        storeInFile();
    }

    void storeInFile()
    {
        ofstream fout("Blood Bank");
        fout    << aPos << endl
                << aNeg << endl
                << bPos << endl
                << bNeg << endl
                << oPos << endl
                << oNeg << endl
                << abPos << endl
                << abNeg << endl;
        fout.close();
    }
};

int main()
{
    Blood h;
    h.loadFromFile();
    h.storeInFile();
    int choice;
    do
    {
    cout<<"\n======= BLOOD BANK SERVICE ======= "<<endl;
    cout<<" 1- Donate Blood."<<endl;
    cout<<" 2- Receive Blood."<<endl;
    cout<<" 3- Run as Administrator."<<endl;
    cout<<" 4- Exit."<<endl;
    cout<<"Choose an option: ";
    cin>>choice;
    switch (choice) {
        case 1:
            h.donateBlood();
        cout<<"Blood donation successful"<<endl;
        break;
        case 2:
            h.receiveBlood();
        cout<<"Blood received successfully"<<endl;
           break;
        case 3:
            int choice3;
           cout<<"\n 1-Login.\n 2-Sign up."<<endl;
            cout<<"Choose an option: ";
            cin>>choice3;
        switch(choice3) {
            case 1:
                adminLogin();
                break;
            case 2:
                adminSignUp();
            break;
        }
           break;
        case 4:
            cout<<"Program Exited."<<endl;
            break;
        }
    }while(choice!=4);

}
