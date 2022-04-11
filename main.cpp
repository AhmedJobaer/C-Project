/*
EOP Project

4. Ahmed Jobaer 1918243
*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdlib.h>

using namespace std;

//function prototype
void intro();
void recipt(char *dt, struct vichle *v);
void payment(struct vichle *v);
void userinput(vichle *v);
void printInFile(char *dt, struct vichle *v);

//global variables


const float MotorBike[] = {15, 12, 15, 18, 10, 20, 60};
const float Car[] = {20, 16, 18, 20, 15, 25, 80};
const float Others[] = {25, 18, 25, 20, 18, 35, 100};



int service, i = 0;

//using structure
struct vichle
{
    string vichleType[4] = {"Motor Bike", "Car", "Others", "Exit"};
    string service[8] = {"Wash", "Rinse", "Scrub", "Steam", "Vacuum", "Wax", "Full Service", "Exit"};
    string service0;
    int userService[10] = {0}; //service typeExit
    int uservichle;            //vehicle type
    float total = 0.00;
};

int main()
{
    system("Color 2");
    intro();
    vichle v;
    userinput(&v);

    return 0;
}

void intro()
{
    string name [4] [2] =
    {
        {"Ahmad Sanoh", "\t\t\t1921973"},
        {"Asyari Shabir Taufiqurrahman", "\t2019681"},
        {"Anwar Fakhrurrazi", "\t\t1920337"},
        {"Jobaer Ahmed", "\t\t\t1918243"}
    };


    cout<<"\n\n\n\t\t\t\t\t****IIUM VEHICLE WASHSING SERVICE****";
    cout<<"\n\n\n\t\t\t\t\t\t\t\t**Created By**\n";
    for (int i=0 ; i<=3 ; i++)
    {
        cout<<"\n\t\t\t\t\t\t\t\t";
        for(int j=0; j<2; j++)
        {
            cout << name [i][j];
        }
    }
    cin.get();
    system("cls");
}

void userinput(vichle *v)
{
    do
    {

        cout << "\t\tWelcome To IIUM Vehicle Washing Service" << endl;
        cout << "\t\t------------------------------------" << endl
             << endl;

        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << "." << v->vichleType[i] << endl;// choose vechicle type then it goes to switch statement
        }
        cout << endl;
        cout << "Enter your vehicle type : ";
        cin >> v->uservichle;


        switch (v->uservichle)
        {

        case 1:
            do
            {
                do
                {
                    cout << endl;
                    cout << "\tMotor Bike" << endl;
                    cout << "\t----------" << endl
                         << endl;
                    cout << setw(8) << "Service" << setw(21) << "price" << endl;
                    cout << setw(8) << "-------" << setw(21) << "-----" << endl
                         << endl;
                    //showing services;
                    for (int i = 0; i <= 7; i++)
                    {
                        if (i == 7)
                        {
                            cout << i + 1 << "." << setw(17) << left << v->service[i] << endl
                                 << endl;
                        }
                        else

                            cout << i + 1 << "." << setw(17) << left << v->service[i] << setw(7) << right << MotorBike[i] << " RM" << endl;
                    }
                    cout << "Enter your desire service: ";

                    cin >> service;      // choice desire service
                    v->userService[i] = service;
                    cout << endl;

                    if (service >= 1 && service <= 7)
                    {
                        v->total += MotorBike[service - 1];
                    }

                    else if (service == 8)
                    {
                        cout << "\t\t!!Thanks For Choosing Our Service!!" << endl;
                        exit(0); // If user want to exit, then it immediately exit the program
                    }
                    else
                    {
                        cout << endl;
                        cout << "!!!Please Renter a Correct Number Between (1 to 8)!!!" << endl;
                    }

                }
                while (service < 1 || service > 8);
                i++;
                cout << "\t\tYou have to pay = " << v->total << " RM" << endl//for payment
                     << endl;
                cout << "Do you need other service(y/n): ";
                cin >> ws;
                getline(cin, v->service0);
                while (v->service0 != "y" && v->service0 != "n")
                {
                    cout << endl
                         << endl;
                    cout << "\t\t\a!!Please Renter y or n!!" << endl
                         << endl;
                    cout << "Do you need other service(y/n): ";
                    cin >> ws;
                    getline(cin, v->service0);
                }


            }
            while (v->service0 != "n");

            payment(v);

            break;

        case 2:
            do
            {
                do
                {

                    cout << endl;
                    cout << "\t\tCar" << endl;
                    cout << "\t\t---" << endl
                         << endl;
                    cout << setw(8) << "Service" << setw(21) << "price" << endl;
                    cout << setw(8) << "-------" << setw(21) << "-----" << endl
                         << endl;
                    for (int i = 0; i <= 7; i++)
                    {
                        if (i == 7)
                        {
                            cout << i + 1 << "." << setw(17) << left << v->service[i] << endl
                                 << endl;
                        }
                        else

                            cout << i + 1 << "." << setw(17) << left << v->service[i] << setw(7) << right << Car[i] << " RM" << endl;
                    }
                    cout << "Enter your desire service: ";
                    cin >> service;
                    v->userService[i] = service;
                    cout << endl;

                    if (service >= 1 && service <= 7)
                    {
                        v->total += Car[v->userService[i] - 1];
                    }

                    else if (service ==8)
                    {
                        cout << "\t\t!!Thanks For Choosing Our Service!!" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << endl;
                        cout << "!!!Please Renter a Correct Number Between (1 to 8)!!!" << endl;
                    }

                }
                while (service < 1 || service > 8);
                i++;
                cout << "\t\tYou have to pay = " << v->total << " RM" << endl
                     << endl;
                cout << "Do you need other service(y/n): ";
                cin >> ws;
                getline(cin, v->service0);
                while (v->service0 != "y" && v->service0 != "n")
                {
                    cout << endl
                         << endl;
                    cout << "\t\t\a!!Please Renter y or n!!" << endl
                         << endl;
                    cout << "Do you need other service(y/n): ";
                    cin >> ws;
                    getline(cin, v->service0);
                }

            }
            while (v->service0 != "n");

            payment(v);

            break;

        case 3:

            do
            {
                do
                {

                    cout << endl;
                    cout << "\t\tOthers" << endl;
                    cout << "\t\t------" << endl
                         << endl;
                    cout << setw(8) << "Service" << setw(21) << "price" << endl;
                    cout << setw(8) << "-------" << setw(21) << "-----" << endl
                         << endl;
                    for (int i = 0; i <= 7; i++)
                    {
                        if (i == 7)
                        {
                            cout << i + 1 << "." << setw(17) << left << v->service[i] << endl
                                 << endl;
                        }
                        else

                            cout << i + 1 << "." << setw(17) << left << v->service[i] << setw(7) << right << Others[i] << " RM" << endl;
                    }
                    cout << "Enter your desire service: ";
                    cin >> service;

                    v->userService[i] = service;
                    cout << endl;

                    if (service >= 1 && service <= 7)
                    {
                        v->total += Others[v->userService[i] - 1];
                    }

                    else if (service == 8)
                    {
                        cout << "\t\t!!Thanks For Choosing Our Service!!" << endl;
                        exit(0);
                    }
                    else
                    {
                        cout << endl;
                        cout << "!!!Please Renter a Correct Number Between (1 to 8)!!!" << endl;
                    }

                }
                while (service < 1 || service > 8);
                i++;
                cout << "\t\tYou have to pay = " << v->total << " RM" << endl
                     << endl;
                cout << "Do you need other service(y/n): ";
                cin >> ws;
                getline(cin, v->service0);
                while (v->service0 != "y" && v->service0 != "n")
                {
                    cout << endl
                         << endl;
                    cout << "\t\t\a!!Please Renter y or n!!" << endl
                         << endl;
                    cout << "Do you need other service(y/n): ";
                    cin >> ws;
                    getline(cin, v->service0);
                }

            }
            while (v->service0 != "n");

            payment(v);

            break;

        case 4:
            cout << endl;
            cout << "\t\t!!Thanks For Choosing Our Service!!" << endl;
            break;

        default:
            cout << endl;
            cout << "\t\t!!Sorry You have Enter Wrong Input!!\n\t\t!!Please Renter a Correct Number between 1 to 4!!" << endl
                 << endl;
            break;
        }

    }
    while (v->uservichle < 1 || v->uservichle > 4);

    cout << endl;
}

void payment(struct vichle *v)
{
    int input;
    float userpay = 0.00, payments = 0.00;
    cout << endl;
    cout << "Enter  your amount : ";
    cin >> userpay; //take money from user

    if (userpay == v->total) // if the money is equal to total price then the program go for processing
    {
        cout << endl;
        cout << "1.Start\n2.Quit\nPlease Select: ";
        cin >> input;
        if (input == 1)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\aProcess is Starting........" << endl
                 << endl
                 << endl;
            sleep(2);
            cout << "\t\t\a!!Your order is completed!!\n\t\t!!Please take your receipt!!" << endl;

            sleep(2);
            //printing time and date
            time_t now = time(0);
            char *dt = ctime(&now);

            recipt(dt, v);
            printInFile(dt, v);// Create and open a text file
        }
        else
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\a!!Please take you money " << v->total << " RM !!"
                 << "\n\n\t\t!!Thank you for using our service" << endl;
        }
    }
    else if (userpay > v->total) //if the money is more to total price then it return extra money and go for processing
    {

        payments = userpay - v->total;
        cout << endl;
        cout << "\t\t\a!!Please take your money " << payments << " RM !!" << endl
             << endl;
        sleep(2);
        cout << endl;
        cout << "1.Start\n2.Quit\nPlease Select: ";
        cin >> input;
        if (input == 1)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\tProcess is Starting........" << endl
                 << endl
                 << endl;
            sleep(2);
            cout << "\t\t\a!!Your order is completed!!\n\t\t!!Please take your receipt!!" << endl;

            sleep(2);
            //printing time and date
            time_t now = time(0);
            char *dt = ctime(&now);

            recipt(dt, v);
            printInFile(dt, v);
        }
        else
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\a!!Please take you money " << v->total << " RM !!"
                 << "\n\n\t\t!!Thank you for using our service" << endl;
        }
    }

    else if (userpay < v->total)
    {
        payments = v->total - userpay;

        while (userpay < v->total)
        {
            cout << endl;
            cout << "\t\t\a!!Please insert more " << payments << " RM !!" << endl
                 << endl;
            cout << "Enter  your amount: ";
            cin >> userpay;
            payments = payments - userpay;
            if (payments == 0)
                break;
        }
        cout << endl;
        cout << "1.Start\n2.Quit\nPlease Select: ";
        cin >> input;
        if (input == 1)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\tProcess is Starting........" << endl
                 << endl
                 << endl;
            sleep(2);
            cout << "\t\t\a!!Your order is completed!!\n\n\t\t!!Please take your receipt!!" << endl
                 << endl
                 << endl;
            sleep(2);
            //printing time and date
            time_t now = time(0);
            char *dt = ctime(&now);

            recipt(dt, v);
            printInFile(dt, v);

        }
        else
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\a!!Please take you money " << v->total << " RM!!"
                 << ""
                 "\n\n\t\t!!Thank you for using our service!!"
                 << endl;
        }
    }
}

// for showing reciept
void recipt(char *dt, struct vichle *v)
{
    cout << endl
         << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t Receipt" << endl;
    cout << "\t\t++++++++++++++++++++++++++++" << endl
         << endl
         << endl;
    cout << "\t\tVehicle Type : " << v->vichleType[(v->uservichle) - 1] << endl;
    cout << "\t\tService Type: ";

    for (int i = 0; i < 10; i++)
    {
        if (v->userService[i] == 1)
            cout << "Wash ";
        else if (v->userService[i] == 2)
            cout << "Rinse ";
        else if (v->userService[i] == 3)
            cout << "Scrub ";
        else if (v->userService[i] == 4)
            cout << "Steam ";
        else if (v->userService[i] == 5)
            cout << "Vacuum ";
        else if (v->userService[i] == 6)
            cout << "Wax ";
        else if (v->userService[i] == 7)
            cout << "Full Service ";
        if (v->userService[i] == 0)
        {
            cout << endl;
            break;
        }
    }

    cout << "\t\tTotal Price: " << v->total << " RM" << endl
         << endl
         << endl;

    cout << "\t!!Thank you for choosing our service!!" << endl
         << endl
         << endl
         << endl;

    cout << "Date and time: " << dt << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
}

void printInFile(char *dt, vichle *v)
{
    ofstream MyFile("Receipt.txt"); // save receipt file

    MyFile << "-----------------------------------------------------------------------------------------------------" << endl
           << "\t\t\Receipt" << endl
           << "\t\t++++++++++++++++++++++++++++" << endl
           << endl
           << endl
           << "\t\tVehicle Type : " << v->vichleType[v->uservichle - 1] << endl;
    MyFile << "\t\tService Type: ";
    for (int i = 0; i < 10; i++)
    {
        if (v->userService[i] == 1)
            MyFile << "Wash ";
        else if (v->userService[i] == 2)
            MyFile << "Rinse ";
        else if (v->userService[i] == 3)
            MyFile << "Scrub ";
        else if (v->userService[i] == 4)
            MyFile << "Steam ";
        else if (v->userService[i] == 5)
            MyFile << "Vacuum ";
        else if (v->userService[i] == 6)
            MyFile << "Wax ";
        else if (v->userService[i] == 7)
            MyFile << "Full Service ";
        if (v->userService[i] == 0)
        {
            cout << endl;
            break;
        }
    }
    MyFile << "\n\t\tTotal Price: " << v->total << " RM" << endl
           << endl
           << endl
           << "\t!!Thank you for choosing our service!!" << endl
           << endl
           << endl
           << endl
           << "Date and time: " << dt << endl
           << "-----------------------------------------------------------------------------------------------------" << endl;

    MyFile.close();
}

