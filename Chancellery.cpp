#include "Chancellery.h"
#include <iostream>

using namespace std;

Chancellery::Chancellery(const string& Type, const string& color, const string& purpose, double price)
        : type(type), color(color), purpose(purpose), price(price) {}

void Chancellery::printInfo() const {
    cout << "Chancellery: " << type << ", Color: " << color << ", Purpose: " << purpose
              << ", Price: $" << price << endl;
}

void Chancellery::saveToFile(ofstream& file) const {
    file << "\nChancellery\n" << type << "\n" << color << "\n" << purpose << "\n" << price << "\n";
}

void Chancellery::loadFromFile(std::ifstream& file) {
    getline(file, type);
    getline(file, color);
    getline(file, purpose);
    file >> price;
    file.ignore();
}

void Chancellery::addElement() {
    cout << "Vvedite tip kantselyarii: ";
    getline(cin, type);
    printf("Vvedite tsvet %s: ", type.c_str());
    getline(cin, color);
    cout << "Vvedite nazvanie knigi: ";
    getline(cin, purpose);
    cout << "Vvedite tsena: ";
    cin >> price;
    cin.ignore();
}

void Chancellery::deleteElement() {
    type = "";
    color = "";
    purpose = "";
    price = 0.0;
    cout << "Kantselyarka udalena." << endl;
}

void Chancellery::edit() {
    int choice;
    cout << "Izmenenie kantselyarii:" << endl;
    cout << "1. Izmenit' tip" << endl;
    cout << "2. Izmenit' tsvet" << endl;
    cout << "3. Izmenit' naznachenie" << endl;
    cout << "4. Izmenit' stoimost' " << endl;
    cout << "Vyberite, chto khotite izmenit': ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Vvedite novyy tip: ";
            getline(cin, type);
            break;
        case 2:
            cout << "Vvedite novyy tsvet: ";
            getline(cin, color);
            break;
        case 3:
            cout << "Vvedite novoe naznachenie: ";
            getline(cin, purpose);
            break;
        case 4:
            cout << "Vvedite novuyu stoimost': ";
            cin >> price;
            cin.ignore();
            break;
        default:
            cout << "Nevernyy vybor!" << endl;
            break;
    }
}
