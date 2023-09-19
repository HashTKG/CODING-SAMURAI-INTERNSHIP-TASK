#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void input();
void game_box();
bool isBoxEmpty();
void show_box();
void calculation(int);
bool Final_Result();


char game[3][3],ch;
bool flag = true;

int main()
{
    do
    {

            cout<<"---------------------------------------TIC TAC TOE-----------------------------------------------"<<endl<<endl;

            input();
            game_box();
            int turn = 1;
            do{
                show_box();
                calculation(turn);
                ++turn;

                if(Final_Result())
                {
                    show_box();
                    flag = false;
                    break;
                }
                    

            }while(isBoxEmpty());
            
            if(flag)
            {
                show_box();
                cout<<endl<<endl<<"Match Drawn"<<endl<<endl;
            }
                    
    
            cout<<endl<<endl<<"Do You want to play again ? Press 'y' OtherWise any key to EXIT    -----> ";
            cin>>ch;
            system("cls");

    }while(ch=='y');

    cout<<"-------------------Thanku for playing----------------------"<<endl;
    cout<<"press any key to exit";
    getch();
    return 0;
}




void input()
{
    cout<<"Player 1 has mark "<<"'X'"<<endl;
    cout<<"Player 2 has mark "<<"'O'"<<endl;
}
void game_box()
{
    for(int i = 0;i<3;++i)
        for(int j=0;j<3;++j)
            game[i][j]=' ';
}
bool isBoxEmpty()
{
    for(int i = 0;i<3;++i)
        for(int j=0;j<3;++j)
            if(game[i][j]==' ')
                return true;
    return false;
}

void show_box()
{
    cout<<endl;
            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[0][0];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[0][1];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[0][2];
                else
                    cout<<' ';

            cout<<endl;
        

        for(int k=0;k<11;++k)
            cout<<"-";

        cout<<endl;

       
            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[1][0];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[1][1];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[1][2];
                else
                    cout<<' ';

            cout<<endl;
        

        for(int k=0;k<11;++k)
            cout<<"-";
        
        cout<<endl;
       
        
            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[2][0];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[2][1];
                else
                    cout<<' ';
        
            
            cout<<"|";

            for(int j=0;j<3;++j)
                if(j==1)
                    cout<<game[2][2];
                else
                    cout<<' ';

            cout<<endl;
    
}




void calculation(int chance)
{   
    do{
        string boxno;
        int row,col;
        cout<<endl<<"Select box number (Row-wise ,ie, 1 to 9):- ";
        cin>>boxno;
        int box_no= boxno[0] - '0';
        
        if(box_no>=1 && box_no<=9)
        {
            row = (box_no-1)/3;
            if(box_no == 1) 
                col = (box_no-1)/3;
            else
                col = (box_no-1)%3;

            if(game[row][col]==' ')
            {    
                if(chance%2==0)
                {          
                    game[row][col]='O';        
                }        
                else
                {
                    game[row][col]='X';        
                }   
            }
            else
            {
                cout<<endl<<"box already occupied"<<endl;
                continue;
            }  
        }
        else
        {
            cout<<endl<<"Wrong Input"<<endl;
            continue;
        }
        break;
    }while(true);
}


bool Final_Result()
{
    if( (game[0][0]=='X' && game[0][1]== 'X' && game[0][2]=='X') ||
        (game[1][0]=='X' && game[1][1]== 'X' && game[1][2]=='X') ||
        (game[2][0]=='X' && game[2][1]== 'X' && game[2][2]=='X') ||
        (game[0][0]=='X' && game[1][0]== 'X' && game[2][0]=='X') ||
        (game[0][1]=='X' && game[1][1]== 'X' && game[2][1]=='X') ||
        (game[0][2]=='X' && game[1][2]== 'X' && game[2][2]=='X') ||
        (game[0][0]=='X' && game[1][1]== 'X' && game[2][2]=='X') ||
        (game[2][0]=='X' && game[1][1]== 'X' && game[0][2]=='X'))
    {

            cout<<endl<<endl<<"Player 1 Won"<<endl<<endl;
            return true;
    }
    
    if( (game[0][0]=='O' && game[0][1]== 'O' && game[0][2]=='O') ||
        (game[1][0]=='O' && game[1][1]== 'O' && game[1][2]=='O') ||
        (game[2][0]=='O' && game[2][1]== 'O' && game[2][2]=='O') ||
        (game[0][0]=='O' && game[1][0]== 'O' && game[2][0]=='O') ||
        (game[0][1]=='O' && game[1][1]== 'O' && game[2][1]=='O') ||
        (game[0][2]=='O' && game[1][2]== 'O' && game[2][2]=='O') ||
        (game[0][0]=='O' && game[1][1]== 'O' && game[2][2]=='O') ||
        (game[2][0]=='O' && game[1][1]== 'O' && game[0][2]=='O'))
    {

             cout<<endl<<endl<<"Player 2 Won"<<endl<<endl;
             return true;
    }
    return false;


}
