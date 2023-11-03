#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <string.h>
#include <fstream>
using namespace std;
int ch=0;
int menu ();
class pomodoro
{

private:
    int workDuration;
    int breakDuration;
    int sessionsCompleted;
    double totalWorkTime;

    public:

    void setworkduration (int wd);
    void setbreakduration (int bd);
    int getworkduration();
    int getbreakduration();
    void settings();
    int startSession ();
    int endSession ();
    void getStatistics();
    pomodoro()
    {
        workDuration=25;
        breakDuration=25;
    }
    int wtimer(int *ch);
    int btimer(int *ch);
};

void pomodoro::setworkduration(int wd)
{
   workDuration=wd;
}


 void pomodoro::setbreakduration (int bd)
 {
    breakDuration=bd;
 }

 int pomodoro::getworkduration ()
 {
     return workDuration;
 }

  int pomodoro::getbreakduration ()
 {
     return breakDuration;
 }
                     //MAIN//
int main()
{
    pomodoro ();
    pomodoro me;
    int re=1, pressedset=0, cho=0, piswstomenu=0;
    char ans;

    while (re!=2)
    {
    cho=0;
    piswstomenu=0;
    cho=menu();
    if (cho==0)
    {
        re=2;
        system("cls");
        cout << "Exiting NtomatoTimer." << endl;
        _sleep(250);
        system("cls");
        cout << "Exiting NtomatoTimer.." << endl;
        _sleep(250);
         system("cls");
        cout << "Exiting NtomatoTimer..." << endl;
        _sleep(500);
       return 0;
    }
    else if (cho==1)
    {
        if (pressedset==0)
        {
            me.setworkduration(25);
            me.setbreakduration(5);
        }
            piswstomenu=me.startSession();
        if (piswstomenu!=69)
        {

            do{
                    piswstomenu==0;
            cout << "Press 1 To Continue With The Same Settings" << endl;
            ans=getch();
                 if((ch==0)&&(ans=='1'))

                 {
                     piswstomenu=me.btimer(&ch);
                 }
                 else if((ch==1)&&(ans=='1'))
                 {
                     piswstomenu=me.startSession();
                 }

    }while((ans=='1')&&(piswstomenu!=69));
        }
   pressedset=0;
    }
    else if (cho==2)
    {
        me.settings();
        pressedset=1;

    }
    else if (cho==3)
    {
        me.getStatistics();
    }
    else if (cho==69)
    {
        cho=menu();
    }
    }

}


// ����� ��������//


int menu()
{
    char op;
        system("cls");
    cout << "                              ***********************************************************" << endl;
    cout << "                                                    POMODORO TIMER" << endl << endl << endl <<endl;
    cout << "1. Start Timer" << endl << endl;
    cout << "2. Settings" << endl << endl;
    cout << "3. Statistics" << endl << endl;
    cout << "4. Exit Program" << endl << endl;
    cout << "                             *************************************************************" << endl;

    op=getch();
    switch (op)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 0;
        break;
    default:
        cout << " "<<endl;
        return 69;
    }
}

//���������//


   void pomodoro::settings()
    {
        int key=1, x=0, sizew=0, sizeb=0, correctw, correctb;
        char w[5];
        char b[5];
        int wd=0, bd=0;
        bool checkw, checkb;
        do{
        x=0;
        checkw=false;
        checkb=false;
        sizew=0;
        sizeb=0;
        wd=0;
        bd=0;
            if (key==0)
            {
                cout << "Wrong Values, Please Try Again!" << endl << endl;
            }
        cout << "Adjust Work Duration (Default 25)" << endl;
        cin >> w;
        sizew=strlen(w);

        cout <<  "Adjust Break Duration (Default 5)" <<endl;
        cin >> b;
        sizeb=strlen(b);
        if ((sizew<4)&&(sizeb<4))
        {
            while(x<sizew)
            {
                correctw=isdigit(w[x]);
                if (correctw==0)
                {
                    break;
                }
                x=x+1;
            }
            x=0;
            while(x<sizeb)
            {
                correctb=isdigit(b[x]);
                if (correctb==0)
                {
                    break;
                }
                x=x+1;
            }
            if ((correctw!=0)&&(correctb!=0))
            {
                x=0;
                while(x<sizew)
                {
                    if (((w[0]!='-')&&(w[1]!='-'))&&(w[0]!='0'))
                    {
                        checkw=true;
                        wd=10*wd+(w[x]-'0');
                        x=x+1;
                    }
                    else
                    {
                       checkw=false;
                       break;
                    }
                }
                x=0;
                while (x<sizeb)
                {
                    if(((b[0]!='-')&&(b[1]!='-'))&&(b[0]!='0'))
                    {
                        checkb=true;
                        bd=10*bd+(b[x]-'0');
                        x=x+1;
                    }
                    else
                    {
                        checkb=false;
                        break;
                    }
                }
            }
            else
            {
                checkw=false;
                checkb=false;
            }
        }
        else
        {
            checkw=false;
            checkb=false;
        }
        key=0;
    }while((checkw==false)||(checkb==false));
      setworkduration(wd);
      setbreakduration(bd);
    }


    //������ ���������//

    int pomodoro::startSession()
    {
        char op;
        int telos=0;
        while (true)
        {
            telos=wtimer(&ch);
            if (telos==7)
            {
                return 69;
            }
            cout << "Start Break ?" << endl << endl;
            cout << "1.yes" << endl << "2.Exit" << endl;
            do
            {
                op=getch();
            }while((op!='1')&&(op!='2'));
            telos=0;
            switch(op)
            {
            case '1':
                        telos=btimer(&ch);
                        if(telos==69)
                        {
                            break;
                        }
            case '2':
                return 70;
            default:
                cout << " " <<endl;
                break;
            }
            break;
         }
         return 69;
    }

    //�������//

    int pomodoro::wtimer(int *ch)
    {
        int sec=0, k=0, wd, telos=0, counter=0;
        const string filename1 = "twt.txt";
        const string pause= "Press Space to pause";
        const string esc= "Press escape to exit";
        wd=getworkduration();
        while(k==0)
    {
           *ch=0;
        _sleep(10);
        system("cls");
        cout  << "                                                FOCUS! "<<wd<<" :: "<<sec << endl << endl << endl<<endl;
        if((wd>0)||(sec>0))
        {
        if (sec==0)
        {
            sec=59;
            wd=wd-1;
           counter=counter+1;
        }
        else
        {
            sec=sec-1;
           counter=counter+1;

        }

        if (GetAsyncKeyState(0x20))
            {
                system("pause");
         }
           if (GetAsyncKeyState(0x1B))
            {
                telos=endSession();
                if (telos==5)
                {
                       if (counter%60!=0)
            {
                counter=(counter*60)/100;
            }
              fstream editFile(filename1, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> totalWorkTime;
        totalWorkTime=totalWorkTime+(counter/60);
        editFile.seekg(0);

        editFile << totalWorkTime;

        editFile.close();
            }

                    return 7;
                }
            }
            cout << pause << endl;
            cout << esc << endl;
        }
        else
        {
            cout << "END"<<endl;
            Beep(600,200);
            _sleep(500);
            Beep(600,200);
            _sleep(500);
            Beep(600,200);
            *ch=0;
             fstream editFile(filename1, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> totalWorkTime;
        totalWorkTime=totalWorkTime+(counter/60);
        editFile.seekg(0);

        editFile << totalWorkTime;

        editFile.close();
            }
             return 0;
        }
    }
    }


      //���������//

 int pomodoro::btimer(int *ch)
    {
        int sec=0, bd, k=0, telos=0;
        const string filename = "cs.txt";
        const string pause= "Press Space to pause";
        const string esc= "Press escape to exit";
        bd=getbreakduration();
        while(true)
    {
        _sleep(10);
        system("cls");
        cout  << "                                                  RELAX!"<<bd<<" :: "<<sec << endl << endl << endl<<endl;
        if((bd>0)||(sec>0))
        {
        if (sec==0)
        {
            sec=59;
            bd=bd-1;
        }
        else
        {
            sec=sec-1;

        }
        if (GetAsyncKeyState(0x20))
            {
                system("pause");
            }
             if (GetAsyncKeyState(0x1B))
            {
                telos=endSession();
                if (telos==5)
                {
                    return 69;
                }
            }
            cout << pause << endl;
            cout << esc << endl;
        }
        else
        {
            cout << "END"<<endl;
            Beep(600,200);
            _sleep(500);
            Beep(600,200);
            _sleep(500);
            Beep(600,200);
            _sleep(500);
            k=1;
            *ch=1;
            fstream editFile(filename, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> sessionsCompleted;

       sessionsCompleted=sessionsCompleted+1;

        editFile.seekg(0);

        editFile << sessionsCompleted;

        editFile.close();
            }
            return 0;
    }
    }
    }

    int pomodoro::endSession()
    {
        char op=0;
        cout << "Are you sure you want to end the session?" << endl;
        cout << "1.Yes" << endl  << "2.No" << endl;
        do
        {
            op=getch();
        }while((op!='1')&&(op!='2'));
        switch (op)
        {
        case '1':
            system ("cls");
            cout << "                                                  Session Ended" << endl;
            _sleep(750);
            system("cls");
            return 5;
            break;
        case '2':
            return 10;
            break;
            default:
            cout << " " << endl;
    }
    }


    void pomodoro::getStatistics()
    {
        const string filename = "cs.txt";
        const string filename1 = "twt.txt";
        string l;
        string l1;
        ifstream file(filename);
        if (file.is_open()) {
                cout << "Sessions completed: ";
        while(getline(file,l))
        {
            cout << l;
        }
            file.close();
        }
        else
        {
            cout << "File not found!" << endl;
        }
         cout << " "<<endl;
         ifstream file1(filename1);
        if (file1.is_open()) {
                cout << "Total work time: ";
        while(getline(file1,l1))
        {
            cout << l1;
        }
            file1.close();
            cout <<" minutes " << endl;
        }
        else
        {
            cout << "File not found!" << endl;
        }
        _sleep(3500);
        }

