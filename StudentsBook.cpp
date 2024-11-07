#include "StudentsBook.h"
#include <iostream>

using namespace std;

StudentsBook::StudentsBook(const string& title, const string& author, int year, const string& institution,
                           int studyYear, int pages, double price)
        : title(title),
        author(author),
        year(year),
        institution(institution),
        studyYear(studyYear),
        pages(pages),
        price(price) {}

void StudentsBook::printInfo() const {
    cout << "StudentsBook: " << title << ", Author: " << author << ", Year: " << year
              << ", Institution: " << institution << ", Study Year: " << studyYear
              << ", Pages: " << pages << ", Price: $" << price << endl;
}

void StudentsBook::saveToFile(ofstream& file) const {
    file << "StudentsBook\n" << title << "\n" << author << "\n" << year << "\n" << institution << "\n"
         << studyYear << "\n" << pages << "\n" << price << "\n";
}

void StudentsBook::loadFromFile(ifstream& file) {
    getline(file, title);
    getline(file, author);
    file >> year;
    file.ignore();
    getline(file, institution);
    file >> studyYear >> pages >> price;
    file.ignore();
}

void StudentsBook::addElement() {
    cout << "Vvedite nazvanie uchebnika: ";
    getline(cin, title);
    cout << "Vvedite avtora: ";
    getline(cin, author);
    cout << "Vvedite god vypuska: ";
    cin >> year;
    cin.ignore();
    cout << "Vvedite dlya kakogo uchebnogo zavedeniya prednaznacheno: ";
    getline(cin, institution);
    cout << "Vvedite god obucheniya: ";
    cin >> studyYear;
    cout << "Vvedite ob'yem stranits: ";
    cin >> pages;
    cout << "Vvedite stoimost: ";
    cin >> price;
    cin.ignore();
}

void StudentsBook::deleteElement() {
    title = "";
    author = "";
    year = 0;
    institution = "";
    studyYear = 0;
    pages = 0;
    price = 0.0;
    cout << "Uchebnik udalen." << endl;
}

void StudentsBook::edit() {
    int choice;
    cout << "Izmenenie kantselyarii:" << endl;
    cout << "1. Izmenit nazvaniya" << endl;
    cout << "2. Izmenit avtora" << endl;
    cout << "3. Izmenit god vypuska" << endl;
    cout << "4. Izmenit dlya kakogo uchebnogo zavedeniya prednaznacheno" << endl;
    cout << "5. Izmenit god obucheniya" << endl;
    cout << "6. Izmenit ob'yem stranits" << endl;
    cout << "7. Izmenit stoimost" << endl;
    cout << "Vybirite, chto khotite izmenit: ";
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
            cout << "Vvedite novoe prednaznachenie: ";
            getline(cin, institution);
            break;
        case 5:
            cout << "Vvedite novyy uchebnYY god: ";
            cin >> studyYear;
            cin.ignore();
            break;
        case 6:
            cout << "Vvedite novoje kol-vo stranits: ";
            cin >> pages;
            cin.ignore();
            break;
        case 7:
            cout << "Vvedite novuyu tsenu: ";
            cin >> price;
            cin.ignore();
            break;

        default:
            cout << "Nevernyy vybor!" << endl;
            break;
    }
}