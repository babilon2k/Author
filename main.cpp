#include <iostream>
#include <cstring>

using namespace std;

class Author
{
    size_t capacity;
    size_t numOfBooks;
    string name;
    string* books;

public:
    Author(string n)
        :name(n), capacity(2),numOfBooks(0)
    {
        books = new string[capacity];
    }
    Author(const Author& other)
        :name(other.name),capacity(other.capacity), numOfBooks(other.numOfBooks)
    {
        books = new string [other.capacity];
        memcpy(books, other.books, sizeof(string)*other.capacity);
    }

    void addBook(const string& book)
    {
        if (numOfBooks == capacity)
        {
            doubleSize();
        }
        numOfBooks++;
        books[numOfBooks-1] = book;
    }

    void doubleSize()
    {
        string *tempBooks= new string[capacity*2];
        for(int i=0; i<numOfBooks; i++)
            tempBooks[i]=books[i];
        delete[] books;
        capacity = capacity*2;
        books = tempBooks;
    }

    void info() const
    {
        cout<< name<< ": ";
        for (int i=0; i<numOfBooks; i++)
            cout<<books[i]<<" ";
        cout<< endl;
    }

    void changeName(const std::string& n)
    {
        name = n;
    }
    Author& operator=(const Author& other)
    {
        if (this==&other)
            return *this;

        name = other.name;
        delete[] books;
        books = new string [other.capacity];
        memcpy(books, other.books, sizeof(string)*other.capacity);
        capacity = other.capacity;
        numOfBooks = other.numOfBooks;
        return *this;
    }
    ~Author()
    {
        delete[] books;
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


