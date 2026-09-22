#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Book{
public:
    int Id;
    string Title;
    string Author;
    bool available;


    Book(int Id, string Title, string Author,bool available){
        this->Id = Id;
        this->Title = Title;
        this->Author = Author;
        this->available = available;
    }
    Book(int Id, string Title, string Author){
        this->Id = Id;
        this->Title = Title;
        this->Author = Author;
        this->available = true;
    
    }
};

class Library{
private:
    vector<Book>books;

public:
// add the books 
    void addbook(){
        int Id;
        string Title, Author;

        cout<<"Enter book Id : ";
        cin>>Id;

        cin.ignore();

        cout<<"Enter the book Title : ";
        getline(cin,Title);

        cout<<"Enter the Author of Book : ";
        getline(cin,Author);

        books.push_back(Book(Id,Title,Author));
    }
    // display the book
    void displayBook(){
        if(books.empty()){
            cout<<"Books are not Available ";
        }

        for(Book& book : books){
            cout<<"\nbook Id : "<<book.Id<<endl;
            cout<<"Book Title : "<<book.Title<<endl;
            cout<<"Book Author : "<<book.Author<<endl;

            if(book.available){
                cout<<"Status : Available";
            }
            else{
                cout<<"Status : Not Available";
            
            }

        }
    }

    void searchBook(){
        int Id;

        cout<<"Enter the Book Id : ";
        cin>>Id;

        for(const Book& book : books){

            if(book.Id==Id){
                cout<<endl;
                cout<<"Book Id : "<<book.Id<<endl;
                cout<<"Book title : "<<book.Title<<endl;
                cout<<"Book Author : "<<book.Author<<endl;

                if(book.available){
                    cout<<"Status : Available";
                }
                else{
                    cout<<"Status : Not Available";

                }

            }
        }

    }
    void returnBook(){
        int Id;

        cout<<"Enter the Book Id : ";
        cin>>Id;

        for( Book& book : books){

            if(book.Id==Id){
                if (!book.available) {
                    book.available = true;
                    cout << "Book returned successfully!\n";
                }
                else {
                    cout << "This book was not borrowed.\n";
                }
                return;
            }

        }
        cout<<"Book are not found";
    }

    void borrowBook(){
        int Id;
        string Title,Author;
        cout<<"Enter the Book Id : ";
        cin>>Id;

        for(Book& book : books){
            if(book.Id==Id){
                if(book.available){
                    book.available = false;
                    cout<<"Book succesfully borrowed";
                }
                else{
                    cout<<"Book is already borrowed";
                }
                return;
            }
        }
        cout<<"Books are not found";  
    }

};
int main(){
    Library l;
    // Book b;
    int choice;
    do
    {
        cout<<"\nLIBRARY MANAGEMENT SYSTEM"<<endl<<endl;

        cout<<"1. Add Book\n";
        cout<<"2. Display Book\n";
        cout<<"3. search Book\n";
        cout<<"4. Return Book\n";
        cout<<"5. Borrowed Book\n";
        cout<<"6. exit\n\n\n";

        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            l.addbook();
            break;

        case 2 : 
            l.displayBook();
            break;

        case 3 : 
            l.searchBook();
            break;

        case 4 : 
            l.returnBook();
            break;

        case 5 :
            l.borrowBook();
            break;

        case 6 :
            cout<<"Thank you🙏";
            break;
        
        default:
        cout<<"Invalid work in library";
            break;
        }

        
    } while (choice!=6);
    
}