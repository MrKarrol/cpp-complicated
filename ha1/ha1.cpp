#include <iostream>
#include <fstream>

#include "PhoneBook.h"

const std::string filename = "test.txt";

void FillBook()
{
    PhoneBook book;
    book.AddRecord({ "Ilin", "Petr", "Artemovich" }, { 7, 17, "4550767" });
    book.AddRecord({ "Zaitsev", "Zakhar", "Artemovich" }, { 125, 44, "4164751" });
    book.AddRecord({ "Dubinin", "Aleksei", "Mikhailovich" }, { 7, 473, "7449054" });
    book.AddRecord({ "Solovev", "Artur", "Mikhailovich" }, { 4, 940, "2556793" });
    book.AddRecord({ "Gerasimov", "Miroslav", "Stanislavovich" }, { 7, 367, "7508887" });
    book.AddRecord({ "Makeev", "Marat" }, { 77, 4521, "8880876", 999 });
    book.AddRecord({ "Solovev", "Ivan", "Vladimirovich" }, { 7, 273, "5699819", 5543 });
    book.AddRecord({ "Egorov", "Savelii", "Stanislavovich" }, { 77, 4521, "8880876", 99 });
    book.AddRecord({ "Sokolov", "Arsenii" }, { 93, 163, "1992257", 16 });
    book.AddRecord({ "Davydov", "Filipp", "Grigorevich" }, { 7, 247, "1377660" });
    book.AddRecord({ "Morozov", "Vladimir", "Mikhailovich" }, { 37, 2290, "5613649" });
    book.AddRecord({ "Orekhov", "Matvei", "Petrovich" }, { 81, 8281, "7420182", 2 });
    book.AddRecord({ "Titova", "Natalia" }, { 93, 163, "1992257", 9 });
    book.AddRecord({ "Markelov", "Dmitrii", "Vadimovich" }, { 19, 7576, "5734416", 2 });
    book.AddRecord({ "Kozlovskii", "Artem", "Daniilovich" }, { 81, 8281, "7420182", 1 });
    book.AddRecord({ "Kuznetsov", "Kirill", "Kirillovich" }, { 7, 17, "8346563" });
    book.AddRecord({ "Mironova", "Margarita", "Aleksandrovna" }, { 7, 273, "5699819", 5542 });
    book.AddRecord({ "Kotov", "Vasilii", "Eliseevich" }, { 7, 367, "7508888" });
    book.AddRecord({ "Ivanov", "Daniil", "Maksimovich" }, { 7, 366, "7508887" });
    book.AddRecord({ "Aleksandrov", "Georgii" }, { 493, 7637, "6114861" });

    std::ofstream out(filename);
    out << book;
    std::cout << "book wrote to " << filename << std::endl;
    std::cout << "------------------------" << std::endl;
}

int main()
{
    FillBook();
    using namespace std;

    ifstream file(filename); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого        человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;
	
	return 0;
}
