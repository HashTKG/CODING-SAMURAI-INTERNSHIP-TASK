#include<iostream>
#include<iomanip>
#include<conio.h>
#include<vector>
using namespace std;

class Book;

string choice;
char ch;
vector<Book> Books;

class Book{
    public:
    string title,author,isbn,isPresent;

    void addBookInfo()
    {
        cin.sync();
        cout<<"Enter Book Name : ";
        getline(cin,title);
        cout<<"Enter Author Name : ";
        getline(cin,author);
        cout<<"Enter ISBN : ";
        getline(cin,isbn);
        isPresent = "Yes";

        cout<<endl<<endl<<"Book Information Addedd Successfully"<<endl<<endl;
    }
};

void viewBooks()
{
    if(Books.size() >0)
    {
        cout<<endl<<endl;
        cout<<setw(15)<<"Title";
        cout<<setw(15)<<"Author";
        cout<<setw(15)<<"ISBN";
        cout<<setw(15)<<"Available";
        cout<<endl<<endl;
        for(int i=0;i<Books.size();++i)
        {
            cout<<setw(15)<<Books[i].title;
            cout<<setw(15)<<Books[i].author;
            cout<<setw(15)<<Books[i].isbn;
            cout<<setw(15)<<Books[i].isPresent;
            cout<<endl;

        }
    }
    else
    {
        cout<<endl<<"No Books Present in the Library"<<endl;
    }
}

bool bookSearchBorrow()
{
     cout<<endl<<endl<<"Enter Book ISBN : ";
                            string book_isbn;
                            cin.sync();
                            getline(cin,book_isbn);
                            for(int i=0;i<Books.size();++i)
                            {
                                if(book_isbn == Books[i].isbn)
                                {
                                    cout<<endl<<endl;
                                    cout<<setw(15)<<"Title";
                                    cout<<setw(15)<<"Author";
                                    cout<<setw(15)<<"ISBN";
                                    cout<<setw(15)<<"Available";
                                    cout<<endl<<endl;

                                    cout<<setw(15)<<Books[i].title;
                                    cout<<setw(15)<<Books[i].author;
                                    cout<<setw(15)<<Books[i].isbn;
                                    cout<<setw(15)<<Books[i].isPresent;
                                    cout<<endl;
                                    if(Books[i].isPresent == "Yes")
                                    {
                                        cout<<endl<<"Want to Borrow ? Y/N "<<endl;
                                        string to_borrow;
                                        cin>>to_borrow;
                                        if(to_borrow[0] == 'Y' || to_borrow[0] == 'y')
                                        {
                                            Books[i].isPresent = "No";
                                            cout<<endl<<endl<<"Book Borrowed Successfully"<<endl<<endl;
                                        }
                                        else if(to_borrow[0] == 'N' || to_borrow[0] == 'n')
                                        {
                                            cout<<endl<<endl<<"That's OK!"<<endl<<endl;
                                        }
                                        else
                                        {
                                            cout<<endl<<endl<<"Wrong Input or Choice"<<endl<<endl;
                                        }
                                        return true;

                                    }

                                    if(Books[i].isPresent == "No")
                                        return true;
                                }
                            }
                            return false;
}

bool bookReturn()
{
                                cout<<endl<<endl<<"Enter Book ISBN : ";
                            string book_isbn;
                            cin.sync();
                            getline(cin,book_isbn);
                            for(int i=0;i<Books.size();++i)
                            {
                                if(book_isbn == Books[i].isbn)
                                {
                                    if(Books[i].isPresent == "Yes")
                                    {
                                        cout<<endl<<endl<<"You didn't borrow this book from our store"<<endl<<endl;
                                    }
                                    else
                                    {
                                        Books[i].isPresent = "Yes";
                                        cout<<endl<<endl<<"Book Returned Successfully"<<endl<<endl;
                                    }
                                    return true;
                                }
                            }
                            return false;
}

bool bookRemove()
{
                                cout<<endl<<endl<<"Enter Book ISBN : ";
                            string book_isbn;
                            cin.sync();
                            getline(cin,book_isbn);
                            for(int i=0;i<Books.size();++i)
                            {
                                if(book_isbn == Books[i].isbn)
                                {
                                    Books.erase(Books.begin()+i);
                                    cout<<endl<<"Book Information Removed Successfully"<<endl;
                                    return true;
                                }
                            }
                            return false;
}

int main()
{
    do{
    cout<<"----------------------------------LIBRARY MANAGEMENT SYSTEM--------------------------------------"<<endl;
    cout<<"What you want to Perform ?"<<endl<<endl;
    cout<<"1.Add book information\n2.List All Books\n3.Search/Borrow Book\n4.Return a Book\n5.Remove Book information"<<endl<<endl;
    cin>>choice;
    

        if(choice[0]>='1' && choice[0]<='5')
        {
            switch(choice[0])
            {
                case '1': 
                        {   
                            Book book;
                            book.addBookInfo();
                            Books.push_back(book);
                            break;
                        }

                case '2':
                        {   
                            viewBooks();
                            break;
                        }
                case '3':
                        {   
                            if(bookSearchBorrow())
                            {}
                            else
                            {
                                cout<<endl<<"Desired Book Not Found"<<endl;
                            }
                            break;
                        }
                case '4':
                        {
                            if(bookReturn())
                            {}
                            else
                            {
                                cout<<endl<<"Desired Book Not Found"<<endl;
                            }
                            break;

                        }
                case '5':
                        {   
                            if(bookRemove())
                            {}
                            else
                            {
                                cout<<endl<<"Desired Book Not Found"<<endl;
                            }
                            break;
                        }
                default:    cout<<"Try Again"<<endl;
            }
        }
        else
        {
            cout<<endl<<"Wrong Choice"<<endl;
        }
        


        cout<<endl<<endl<<"Get back to Main Menu---> Press 'y' OtherWise any key to EXIT    -----> ";
        cin>>ch;
        system("cls");

    }while(ch=='y');

    cout<<"-------------------=======================Thanku for Visiting Us==========================----------------------"<<endl;
    cout<<"press any key to exit";
    getch();

    return 0;
}