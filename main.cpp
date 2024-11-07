// Класс Книжный магазин хранит данные о книгах, учебниках, канцелярии.
// - Для книг определено: Book
//          название,
//          автор,
//          год выпуска,
//          аннотация,
//          жанр,
//          объем страниц,
//          стоимость.
// - Для учебника определено:  StudentsBook
//          название,
//          автор,
//          год выпуска,
//          для какого учебного заведения предназначено,
//          год обучения,
//          объем страниц,
//          стоимость.
// - Для канцелярии определено:
//          тип канцелярии,
//          цвет,
//          назначение,
//          стоимость.


// по задачам
// 1) создать класс Keeper
// 2) add, delete производных объектов абстрактного класса
// 3) полное сохранение в файле
// 4) полное восстановление из файла


#include <iostream>
#include "BaseClass.h"
#include "Book.h"
#include "StudentsBook.h"
#include "Chancellery.h"
#include "Keeper.h"
using namespace std;

int main() {
    Keeper keeper;
    int c;
    do {
        printf("==========================================\n");
        printf("__________POL'ZOVATEL'SKOE MENYU:__________\n");
        printf(">> Vvedite '1' esli vy khotite redaktirovat' opredelennyy nabor\n");
        printf(">> Vvedite '2' dlya sokhraneniya keeper\n");
        printf(">> Vvedite '3' dlya zagruzki keeper iz biblioteki imeyushchikhsya\n");
        printf(">> Vvedite '-1' dlya vykhoda iz programmi\n");
        cin >> c;
        switch (c) {
            case 1: {
                int c1;
                do {
                    printf(">> Vvedite '1' dlya dobavleniya elementa\n");
                    printf(">> Vvedite '2' dlya udaleniya elementa\n");
                    printf(">> Vvedite '3' dlya izmeneniya opredelennogo elementa\n");
                    printf(">> Vvedite '0' dlya vozvrata v glavnoe menyu\n");

                    cin >> c1;
                    switch (c1) {
                        case 1: {
                            int type;
                            printf("Vyberite tip ob'ekta dlya dobavleniya:\n");
                            printf("Vvedite '1' - Kniga\n");
                            printf("Vvedite '2' - Uchebnik\n");
                            printf("Vvedite '3' - Kantselyariya\n");
                            cin >> type;
                            cin.ignore();  // Игнорировать символ новой строки

                            switch (type) {
                                case 1: {
                                    Book *b = new Book();
                                    b->addElement();
                                    keeper.add(b);
//                                    keeper.setSize();
                                    break;
                                }
                                case 2: {
                                    StudentsBook *sb = new StudentsBook();
                                    sb->addElement();
                                    keeper.add(sb);
//                                    keeper.setSize();
                                    break;
                                }
                                case 3: {
                                    Chancellery *ch = new Chancellery();
                                    ch->addElement();
                                    keeper.add(ch);
//                                    keeper.setSize();
                                    break;
                                }
                                default:
                                    printf("Nevernyy vybor!\n");
                                    break;
                            }
                            break;
                        }
                        case 2: {
                            keeper.printAll();
                            printf("Vvedite indeks elementa dlya udalenya: ");
                            int index;
                            cin >> index;
//                            if (index >= 0 && index < keeper.getSize()) {
//                                keeper.remove(index);
//                            } else {
//                                std::cout << "Такого индекса нет" << std::endl;
//                            }
                            keeper.remove(index);


                            break;
                        }

                        case 3: {
                            keeper.printAll();
                            printf("Vvedite indeks elementa dlya izmeneniya: ");
                            int index;
                            cin >> index;
                            keeper.edit(index);
                            break;
                        }

                        case 0:
                            break;
                        default:
                            printf("Nevernyy vvod! Poprobuyte snova.\n");
                            break;
                    }
                } while (c1 != 0);
                break;
            }
            case 2: {
                string filename;
                printf("Vvedite imya fayla dlya sokhraneniya: ");
                cin >> filename;
                keeper.saveToFile(filename);
                break;
            }
            case 3: {
                string filename;
                printf("Vvedite imya fayla-keeper dlya zagruzki: ");
                cin >> filename;
                keeper.loadFromFile(filename);
                break;
            }
            case -1:
                printf("Vykhod iz programmy...\n");
                break;
            default:
                printf("Nevernyy vvod! Poprobuyte snova.\n");
                break;

        }
    } while (c != -1);

    return 0;
}
