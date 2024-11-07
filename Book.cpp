#include "book.h"
#include <iostream>
using namespace std;

Book::Book(const string& title, const string& author, int year, const string& annotation,
           const string& genre, int pages, double price)
        : title(title), author(author), year(year), annotation(annotation), genre(genre), pages(pages), price(price) {}

void Book::printInfo() const {
    cout << "Book: " << title << ", Author: " << author << ", Year: " << year
              << ", Genre: " << genre << ", Pages: " << pages << ", Price: $" << price
              << "\nAnnotation: " << annotation << endl;
}

void Book::saveToFile(ofstream& file) const {
    file << "book\n" << title << "\n" << author << "\n" << year << "\n" << annotation << "\n"
         << genre << "\n" << pages << "\n" << price << "\n";
}

void Book::loadFromFile(std::ifstream& file) {
    getline(file, title);
    getline(file, author);
    file >> year;
    file.ignore();
    getline(file, annotation);
    getline(file, genre);
    file >> pages >> price;
    file.ignore();
}

void Book::addElement() {
    cout << "Vvedite nazvanie knigi: ";
    getline(cin, title);
    cout << "Vvedite avtora: ";  
    getline(cin, author);
    cout << "Vvedite god vypuska: ";
    cin >> year;
    cin.ignore();
    cout << "Vvedite annotatsiyu: ";
    getline(cin, annotation);
    cout << "Vvedite zhanr: ";  
    getline(cin, genre);
    cout << "Vvedite ob'yem stranits: ";  
    cin >> pages;
    cout << "Vvedite stoimost: ";  
    cin >> price;
    cin.ignore();
}

void Book::deleteElement() {
    title = "";
    author = "";
    year = 0;
    annotation = "";
    genre = "";
    pages = 0;
    price = 0.0;
    cout << "Kniga udalena." << endl;  
}

void Book::edit() {
    int choice;
    cout << "Izmenenie kantselyarii:" << endl;  
    cout << "1. Izmenit nazvaniya" << endl;  
    cout << "2. Izmenit avtora" << endl;  
    cout << "3. Izmenit god vypuska" << endl;  
    cout << "4. Izmenit annotatsiyu" << endl;  
    cout << "5. Izmenit zhanr" << endl;  
    cout << "6. Izmenit ob'yem stranits" << endl;  
    cout << "7. Izmenit stoimost" << endl;  
    cout << "Viberite, chto khotite izmenit: ";  
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Vvedite novoe nazvanie: ";  
            getline(cin, title);
            break;
        case 2:
            cout << "Vvedite novogo avtora: ";  
            getline(cin, author);
            break;
        case 3:
            cout << "Vvedite god: ";  
            cin >> year;
            cin.ignore();
            break;
        case 4:
            cout << "Vvedite novuyu annotatsiyu: ";  
            getline(cin, annotation);
            break;
        case 5:
            cout << "Vvedite zhanr: ";  
            getline(cin, genre);
            break;
        case 6:
            cout << "Vvedite god: ";  
            cin >> pages;
            cin.ignore();
            break;
        case 7:
            cout << "Vvedite god: ";  
            cin >> price;
            cin.ignore();
            break;

        default:
            cout << "Nevernyy vybor!" << endl;
            break;
    }
}