# Author
Stwórz klas¦ Author reprezentuj¡c¡ pisarza. Pisarz ma nazwisko ( string) i tablic¦ ksi¡»ek (zwykªych stringów) napisanych
przez tego pisarza. Tablica ma rozmiar (pojemno±¢) capacity, równy 2, gdy obiekt jest tworzony. Jest te» pole zawieraj¡ce 
aktualn¡ liczb¦ ksi¡»ek (pocz¡tkowo 0). Gdy nowa ksi¡»ka jest dodawana, jest ona wstawiana na pierwsz¡ woln¡ pozycj¦ do tablicy
ksi¡»ek; je±li brakuje na ni¡ miejsca, to

nowa tablica jest alokowana, o pojemno±ci dwa razy wi¦kszej ni» dotychczasowa;

istniejace juz ksiazki sa kopiowane do tej nowej tablicy;

nowa ksiazka jest dodawana do nowej tablicy;

stara tablica jest usuwana;

nowa tablica staje si¦ aktualn¡.

Klasa powinna zawiera¢

konstruktor pobieraj¡cy nazwisko pisarza i tworz¡cy obiekt z pust¡ tablic¡ ksi¡-

»ek; tablica ma pocz¡tkow¡ pojemno±¢ równ¡ 2, a liczba ksi¡»ek jest inicjowana zerem;

konstruktor kopiuj¡cy;

destruktor;

metod¦ addBook dodaj¡c¡ now¡ ksi¡»k¦ (string) do tablicy (by¢ mo»e z re- alokacj¡, je±li nie ma na ni¡ miejsca);

metod¦ changeName zmieniaj¡c¡ nazwisko pisarza;

metod¦ info drukuj¡c¡ informacj¦ o obiekcie;

przeci¡»ony operator przypisania.

Po implementacji wszystkich funkcji, nast¦puj¡cy program

download Author.cpp



#include <iostream> #include <string>

class Author { size_t capacity;

size_t numOfBooks; std::string name; std::string* books;

public:

Author(std::string n); Author(const Author& other);

void addBook(const std::string& book); void info() const;

void changeName(const std::string& n); Author& operator=(const Author& other); ~Author();

};

int main () {

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

powinien wypisa¢ co± w rodzaju

Shakespeare: Macbeth Hamlet Othello
Bacon: Macbeth Hamlet Othello Pericles Tempest 
Shakespeare: Macbeth Hamlet Othello Pericles Tempest 
Bacon: Macbeth Hamlet Othello Pericles Tempest
