#include <iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#define debug 1

using namespace std;



int storePriority[8];
int x=0;
char tempusr[12];
/*
class Pragya
{   public:
    void EnterNote()
    {
        char str[20];
        cout<<"Enter your notes";
        cin.getline(str,20);
    }
};



void CreateNote(char username[])
{
    char x[15];
    char ch='y';
    ofstream fout;
    fout.open(x,ios::out);
    Pragya ob;
    while(ch=='y'||ch=='Y')
    {
        ob.EnterNote();
        fout.write((char*)&ob,sizeof(ob)); //ob is object of class
        cout<<"Note added";
        cout<<"Do you want to enter more notes? \n \tPress Y/N";
        cin>>ch;
    }
}

*/

class loginSystem
{
    private:

        char userName[12];
        char password[10];
        char ch;
        int serial;
        char tmppass[10];



    public:



        void createUserInfo()
        {
            int flag=0;
            cout<<"Please enter your desired User name (** MAX 12 characters **)"<<endl;
            cin>>userName;
            ifstream dataFile1("logindat.txt",ios::in);
            while(dataFile1 >> tempusr >> password)
            {
                if(strcmp(userName,tempusr)==0)
                {
                    flag=1;
                }
                if(flag==1)
                {
                    cout<<"This username already exists"<<endl;
                    return ;
                }
                if(flag==0)
                {
                    cout<<"Enter your password(** MAX 10 characters **)"<<endl;
                    cin>>password;
                }
            }

            ofstream dataFile("logindat.txt",ios::out | ios::app);
            dataFile << userName <<' '<< password<<endl<<endl;
        }




        int readUserInfo()
        {
            ifstream dataFile("logindat.txt",ios::in);
            cout<<"Please enter your Username (** MAX 12 characters **)"<<endl;
            cin>>tempusr;
            cout<<"Enter your password(** MAX 10 characters **)"<<endl;
            cin>>tmppass;
            if(debug==1)
            {
                cout<<tempusr<<' '<<tmppass<<endl<<endl;
            }
            int chck=0;
            while(dataFile >> userName >> password)
            {
                if(debug==1)
                {
                    cout<<userName<<' '<<password<<endl;
                    cout<<"\t"<<strcmp(userName,tempusr)<<endl;
                    cout<<"\t"<<strcmp(password,tmppass)<<endl;
                }

                if(strcmp(userName,tempusr)==0 && strcmp(password,tmppass)==0)
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

//*************************************************************************************************************************//

class Stock
{

 public:
    char Item[200];
    void Input()
    {
        gets(Item);
    }
 void Output()
 {
     cout<<Item;
}

};

 void CountWord(char str[])
{
    //ofstream a("3.txt",ios::out | ios::app | ios::binary);
    //ofstream b("2.txt",ios::out | ios::app | ios::binary);
    //a<<"i"<<endl;
    //b<<"am"<<endl;
    ifstream usernameObj(str,ios::in|ios::binary);
    string strname;
    int chck=0;

    int priorityCount=0;
    while(usernameObj >> strname)
    {
        string wordchk;
        char check;

        ifstream dataFile10("10.txt",ios::in | ios::binary);

        while(dataFile10 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=10;
            }
        }

        ifstream dataFile9("9.txt",ios::in | ios::binary);
        while(dataFile9 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=9;
            }
        }
        ifstream dataFile8("8.txt",ios::in | ios::binary);
        while(dataFile8 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=8;
            }
        }
        ifstream dataFile7("7.txt",ios::in | ios::binary);
        while(dataFile7 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=7;
            }
        }
        ifstream dataFile6("6.txt",ios::in | ios::binary);
        while(dataFile6 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=6;
            }
        }
        ifstream dataFile5("5.txt",ios::in | ios::binary);
        while(dataFile5 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=5;
            }
        }
        ifstream dataFile4("4.txt",ios::in | ios::binary);
        while(dataFile4 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=4;
            }
        }
        ifstream dataFile3("3.txt",ios::in | ios::binary);
        while(dataFile3 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=3;
            }
        }
        ifstream dataFile2("2.txt",ios::in | ios::binary);
        while(dataFile2 >> wordchk)
        {
            if(wordchk == strname)
            {
                //cout<<wordchk;
                chck=1;
                priorityCount+=2;
            }
        }
    if(strname == ".")
    {
    storePriority[x]=priorityCount;
      priorityCount=0;
      x++;
    }

    }


}






void viewOldList(char Fname[])
{
 fstream Fil; Stock S;
 Fil.open(Fname,ios::binary|ios::in);
 while (Fil.read((char*)&S,sizeof(S)))
 S.Output();

 Fil.close();
}


void Create(char Fname[])
{
     fstream Fil(Fname,ios::binary|ios::out);
     Stock S;
     char Choice;
     do
     {
         S.Input();
         Fil.write((char*)&S,sizeof(S));
         cout<<"More(Y/N)?";
         cin>>Choice;
    }
         while (Choice=='Y' || Choice=='y');
         Fil.close();
}

Stock S;

void toDoItem(char str[])
    {
        char item[200];

        ofstream inputFile(str,ios::out | ios::binary);
        cout<<"PLease enter the stuff that you want to do"<<endl;
        do
        {
            S.Input();
            inputFile<<S.Item<<endl;
        }
        while(strcmp(S.Item,"exit")!=0);

    }


void SortList(char Fname[])
{
     fstream F;
     F.open(Fname,ios::binary|ios::in|ios::out);
     //Move to the last record
     F.seekg(0,ios::end); //To move the record pointer to end of file
     int NOR=F.tellg()/sizeof(Stock); //To find number of records in the file
     Stock EJ,EJP1;
     for (int i=0;i<NOR-1;i++)
     {
        for (int j=0;j<NOR-i-1;j++)
        {
             F.seekg(j*sizeof(Stock)); //To move the file pointer to jth position
             F.read((char*)&EJ,sizeof(Stock)); //reads jth record
             F.read((char*)&EJP1,sizeof(Stock)); //reads (j+1)th record
                if (storePriority[i]<storePriority[i+1]) //******HERE GetEno Function returns the priority level of the line*****
             /* But I have stored the value of the tasks in an array StorePriority . Fix these*/
                 {
                 F.seekp(j*sizeof(Stock));
                 F.write((char*)&EJP1,sizeof(Stock));
                 F.write((char*)&EJ,sizeof(Stock));
                 }
        }
    }
     F.close();
}



int main()
{
   char loginExitVar;
   int loginMenu;
   int subLoginMenu;
   string tempstr;
   cout << endl;


   do
   {
        cout<<"Enter 1 to Login"<<endl;
        cout<<"Enter 2 for Creating a New User"<<endl;
        cout<<"Enter 3 to Exit"<<endl;
        cout<<"Enter 4 for Help(We don't mean SOS!!)"<<endl;
        cin >> loginMenu;
        cout << endl;
        loginSystem existingUser;

        switch(loginMenu)
       {
            case 1 :if(existingUser.readUserInfo()== 1 )
                    {
                            system("cls");
                            cout<<"\tWhat do you want to do now ??"<<endl;
                            cout<<" 1. Create a new to-do list "<<endl;
                            cout<<" 2. View previous list "<<endl;
                            cout<<" 3. Create Notes "<<endl;
                            cout<<" 4. Logout"<<endl;
                            cin>>subLoginMenu;
                            switch(subLoginMenu)
                            {
                                case 1 : toDoItem(tempusr);
                                            CountWord(tempusr);
                                            if(debug == 1)
                                            {
                                                cout<<storePriority[0]<<endl;
                                                cout<<storePriority[1]<<endl;
                                                cout<<storePriority[2]<<endl;
                                            }
                                           int i;
                                           SortList(tempusr);
                                            /*
                                            for(i=0;i<50;i++)
                                            {
                                                Sleep(100);
                                                printf("%c",177);
                                            }
                                            cout<<"You have successfully created a to-do"<<endl;
                                            */
                                case 2 : viewOldList(tempusr);
                                //case 3 : CreateNote(tempusr);
                                case 4 : cout<<endl<<"Thanks !!  :)"<<endl;
                                            goto Exit;
                            }
                            break;
                    }
                    else
                    {
                            break;
                    }


            case 2: loginSystem newUser;
                    newUser.createUserInfo();
                    break;

            case 3: cout<<"Thanks"<<endl;
                    return 0;

            case 4: ifstream Help("Help.txt",ios::in);
                    while(Help>>tempstr)
                    {
                        if(tempstr=="..")
                        {
                            cout<<endl;
                        }
                        if(tempstr!="..")
                        {
                            cout<<tempstr<<' ';
                        }
                    }
                    break;


        }

       Exit:
        cout<<"Do you wish to login again Press Y/N"<<endl;
        cin>>loginExitVar;
        cout<<endl;
        system("cls");
   }
    while(loginExitVar=='Y' || loginExitVar=='y');

}
