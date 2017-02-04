#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class Author
{
    size_t capacity;
    size_t numOfBooks;
    string name;
    string* books;

public:
    Author(string n)
        :name(n)
    {
        this->capacity=12;
        this->numOfBooks=0;
        this->books = new string[capacity];
    }
    Author(const Author& other)
    {
        this->books = (string*)malloc(sizeof(string)*other.capacity);
        memcpy(this->books, other.books, sizeof(string)*other.capacity);
        capacity =other.capacity;
        numOfBooks = other.numOfBooks;
    }

    void addBook(const string& book)
    {
        numOfBooks++;
        if (numOfBooks > capacity)
        {
           // capacity *= 2;
            doubleSize(this->books,this->capacity);
            this->books = (string*)realloc(this->books, sizeof(string)*capacity);
        }

        this->books[numOfBooks-1] = book;
    }

    string* doubleSize(string *arr,int length)
    {
        string *arr2= new string[length*2];
        for(int i=0; i<arr->length(); i++)
            arr2[i]=arr[i];
        delete arr;
        return arr2;
    }

    void info() const
    {
        cout<< this->name<< ": ";
        for (int i=0; i<this->numOfBooks; i++)
            cout<<this->books[i]<<" ";
        cout<< endl;
    }

    void changeName(const std::string& n)
    {
        this->name = n;
    }
    Author& operator=(const Author& other)
    {
        if (this==&other)
            return *this;
        this->name = other.name;

        memcpy(books, other.books, sizeof(string)*sizeof(other.books));
        this->books = other.books;
    }
    ~Author()
    {
        if (books)
        {
            free(books); // Freeing memory
            books = NULL;
        }
    };

};

int main ()
{
    Author ws("Shakespeare");
    ws.addBook("Macbeth");
    ws.addBook("Hamlet");
    ws.addBook("Othello");
    Author fb(ws);
    fb.changeName("Bacon");
    fb.addBook("Pericles");
    fb.addBook("Tempest");
    ws.info();
    fb.info();
    ws = fb = fb; // sic!
    ws.changeName("Shakespeare");
    ws.info();
    fb.info();
}


