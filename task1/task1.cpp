#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void input();
int calculation();
void output(int);

string sname,a_score,q_score,e_score;
int sid,total,avg;
char ch;

int main()
{
    do
    {

            cout<<"---------------------------------------STUDENT GRADE CALCULATOR-----------------------------------------------"<<endl<<endl;

            input();
            int perc = calculation();
            output(perc);
    
            cout<<endl<<endl<<"Do You want to check another result ? Press 'y' OtherWise any key to EXIT    -----> ";
            cin>>ch;
            system("cls");

    }while (ch=='y');

    cout<<"-------------------Thanku for using our product----------------------"<<endl;
    cout<<"press any key to exit";
    getch();
    return 0;
}




void input()
{
    cout<<"Enter 4 Digit Student ID : ";
    cin>>sid;
    if(sid<1000 || sid>9999)
    {
        cout<<"Invalid input"<<endl<<"press any key to exit";
        getch();
        exit(0);
    }
    cout<<"Enter Student name : ";
    cin>>ws;
    getline(cin,sname);
    for(int i = 0; i < sname.length(); i++)
    {
        if((sname[i]>='a' && sname[i]<='z') || (sname[i]>='A' && sname[i]<='Z') || sname[i] == ' ')
        {}
        else
        {
            cout<<"Invalid input"<<endl<<"press any key to exit";
            getch();
            exit(0);
        }
    }
    
    cout<<endl<<"Enter Marks in number format in range of 0 to 100"<<endl;
    cout<<"Enter Total marks of assignments : ";
    cin>>a_score;

    for(int i = 0; i < a_score.length(); i++)
    {
        if((a_score[i]>='0' && a_score[i]<='9') && (stoi(a_score)>=0 && stoi(a_score)<=100))
        {}
        else
        {
            cout<<"Invalid input"<<endl<<"press any key to exit";
            getch();
            exit(0);
        }
    }

    cout<<"Enter Total marks of quizzes : ";
    cin>>q_score;

    for(int i = 0; i < q_score.length(); i++)
    {
        if((q_score[i]>='0' && q_score[i]<='9') && (stoi(q_score)>=0 && stoi(q_score)<=100))
        {}
        else
        {
            cout<<"Invalid input"<<endl<<"press any key to exit";
            getch();
            exit(0);
        }
    }

    cout<<"Enter Total marks of exams : ";
    cin>>e_score;
    
    for(int i = 0; i < e_score.length(); i++)
    {
        if((e_score[i]>='0' && e_score[i]<='9') && (stoi(e_score)>=0 && stoi(e_score)<=100))
        {}
        else
        {
            cout<<"Invalid input"<<endl<<"press any key to exit";
            getch();
            exit(0);
        }
    }
}



int calculation()
{
    cout<<endl<<"The total marks got out of 300 : ";
    total = stoi(a_score) + stoi(q_score) + stoi(e_score);
    cout<<total;
    avg = total/3;
    return avg;
}



void output(int perc)
{
    cout<<endl<<"Percentage got : ";
    cout<<perc;
    cout<<endl<<"CGPA got : ";
    if(perc>=80)
        cout<<"A";
    else if(perc>=60)
        cout<<"B";
    else
        cout<<"C";
}
