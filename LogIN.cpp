#include <iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

class loginSystem
{
    private:

        char userName[12];
        char password[10];

        int serial;


    public:


        void createUserInfo()
        {
            cout<<"Please enter your desired User name (** MAX 12 characters **)"<<endl;
            cin>>userName;
            cout<<"Enter your password(** MAX 10 characters **)"<<endl;
            cin>>password;
            ofstream dataFile("logindat",ios::out | ios::app | ios::binary);
            dataFile << userName <<' '<< password<<endl;
        }
        int readUserInfo()
        {
            ifstream dataFile("logindat",ios::in | ios::binary);
            string tempusr,tmppass;
            cout<<"Please enter your Username (** MAX 12 characters **)"<<endl;
            cin>>tempusr;
            cout<<"Enter your password(** MAX 10 characters **)"<<endl;
            cin>>tmppass;
            int chck=0;
            while(dataFile >> userName >> password)
            {
                if(userName==tempusr && password==tmppass)
                {
                  cout<<"You have successfully logged in"<<endl;
                    chck=1;
                    return chck;
                }

            }
            if(chck==0)
            {
                cout<< endl;
                cout<<"Username or password you entered is incorrect "<<endl<<"OR"<<endl<<"**User doesn't exists !! ,Please create a user **"<<endl;
                return chck;
            }



        }

};

class userInput
{
private:
    string item;
public:
    void toDoItem()
    {
        ofstream inputFile("inputdat.dat",ios::out | ios::app | ios::binary);
        cout<<"PLease enter the stuff that you want to do"<<endl;
        do
        {
            cin>>item;
            inputFile<<item<<endl;
        }
        while(item!="exit");

    }

};

int main()
{
   char loginExitVar;
   int loginMenu;
   cout << endl;


   do
   {
        cout<<"Enter 1 to login"<<endl;
        cout<<"Enter 2 for creating a new user"<<endl;
        cin >> loginMenu;
        cout << endl;
        loginSystem existingUser;
        userInput eStuff;
        switch(loginMenu)
       {
            case 1 :if(existingUser.readUserInfo()== 1 )
                    {
                            eStuff.toDoItem();
                            break;
                    }
                    else
                    {
                            break;
                    }


            case 2: loginSystem newUser;
                    newUser.createUserInfo();
                    break;
        }

       cout<<"Do you wish to continue Press Y/N"<<endl;
       cin>>loginExitVar;
       cout<<endl;
       system("cls");
   }
    while(loginExitVar=='Y' || loginExitVar=='y');

}


