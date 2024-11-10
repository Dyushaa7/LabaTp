#ifndef KEEPER_H
#define KEEPER_H

#include "BaseClass.h"

class Keeper {
private:
    BaseClass** items;

public:
    Keeper();
    ~Keeper();

    void add(BaseClass* item);
    void remove(int index);
    void printAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void edit(int index);


    int size;
};

#endif // KEEPER_H