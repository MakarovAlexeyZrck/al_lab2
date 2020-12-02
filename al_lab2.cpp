// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "ks.h"
#include "trumpet.h"


using namespace std;


// Функция по добавлению трубы
void new_trumpet(vector<trumpet>& trumpets_data) {

    /*
        *  В этой функции мы создаем новую трубу и добавлем ее в простаранство всех труб
    */

    // Создаем трубу
    trumpet current_trumpet;

    // Пользователь заполняет остальную информацию о трубе
    current_trumpet.length = is_float("Введите длину трубы:   ");

    // Добавляем диаметр трубы
    current_trumpet.diam = is_float("Введите диаметр трубы:   ");

    // Добавляем признак в работе или нет
    current_trumpet.repaired = is_bool("Труба в ремонте? (1 - да, 0 - нет):  ");


    cout << "\nДобавлена новая труба: " << endl;
    cout << "Идентификатор: " << current_trumpet.id << endl;
    cout << "Длина: " << current_trumpet.length << endl;
    cout << "Диаметр трубы: " << current_trumpet.diam << endl;
    cout << (current_trumpet.repaired ? "Труба в ремонте" : "Труба работает") << endl << endl;

    trumpets_data.push_back(current_trumpet);

}


// Добавляем новую КС
void new_ks(vector<ks>& kss_data) {

    /*
        *  В этой функции мы создаем новую компрессорную станцию и добавляем ее в пространство всех кс
    */

    // Создаем трубу
    ks current_ks;

    // Пользователь заполняет имя КС
    cout << "Введите наименование КС:   ";
    cin >> current_ks.name;

    // Пользователь вводит количество цехов
    current_ks.number = is_integer("Введите количество цехов в КС:   ");

    // Пользователь вводит количество цехов в работе
    current_ks.numberOfAvailable = is_integer("Введите количество цехов КС в работе:   ");

    // Цехов в работе должно быть меньше, чем цехов всего
    if (current_ks.numberOfAvailable > current_ks.number) {
        while (current_ks.numberOfAvailable > current_ks.number) {
            current_ks.numberOfAvailable = is_integer("Введенное число цехов в работе превышает число всех цехов:   ");
        }
    }

    // Введите показатель эфективности КС
    current_ks.efficiency = is_float("Введите показатель эффективности:     ");


    cout << "\nДобавлена новая КС: " << endl;
    cout << "Идентификатор: " << current_ks.id << endl;
    cout << "Наименованиие: " << current_ks.name << endl;
    cout << "Кол-во цехов всего: " << current_ks.number << endl;
    cout << "Кол-во цехов в работе: " << current_ks.numberOfAvailable << endl;
    cout << "Эффективность КС: " << current_ks.efficiency << endl << endl;

    kss_data.push_back(current_ks);

}


// Просмотр всех существующих объектов
void show_all(int is_trumpet, int is_ks, vector<trumpet> trumpets_data, vector<ks> kss_data) {

    /*
        *  В этой функции мы просматриваем все объекты
    */

    if (is_trumpet == 1) {
        // Отображение всех труб 
        int trumpets_count;
        trumpets_count = trumpets_data.size();
        if (trumpets_count == 0) {
            cout << "\nТрубы не добавлены. Введите 1 для добавлениия труб ..." << endl;
        }
        else
        {
            cout << "\nTRUMPETS DATA \n";
            for (auto& im : trumpets_data) {
                cout << "Идентификатор трубы: " << im.id << ", длина трубы: " << im.length << ", диаметр трубы: " << im.diam << ", состояние трубы: " << (im.repaired ? "Труба в ремонте" : "Труба работает") << endl;

            }
        }
    }

    if (is_ks == 1) {
        // Отоюражение всех КС и их характеристик 
        int kss_count;
        kss_count = kss_data.size();
        if (kss_count == 0) {
            cout << "\nКС отсутствуют. Введите 2 для добавлениия КС ..." << endl;
        }
        else
        {
            cout << "\nKS DATA \n";
            for (auto& im : kss_data) {
                cout << "Идентификатор КС: " << im.id << ", наменование КС: " << im.name << ", кол-во цехов КС: " << im.number << ", цехов в работе: " << im.numberOfAvailable << ", эффективность КС: " << im.efficiency << endl;
            }
        }
    }

    cout << endl;

}


// Изменение статуса трубы 
void trumpet_editor(vector<trumpet>& trumpets_data, vector<ks>& ks_data) {

    /*
         * Изменение статуса трубы
    */

    show_all(1, 0, trumpets_data, ks_data);
    bool was_rewrite = false;

    // Перебор объектов, если индекс совпадает с вводимым - меняем состояние трубы
    if (trumpets_data.size() == 0) {

    }
    else {
        int trumpet_id;
        trumpet_id = is_integer("Выберите идентификатор редактируемой трубы:    ");
        for (auto& im : trumpets_data) {
            if (im.id == trumpet_id) {
                im.repaired = is_bool("Труба в ремонте? (1 - да, 0 - нет):  ");
                cout << "Статус трубы изменен!" << endl << endl;
                was_rewrite = true;
            }
        }
    }

    if ((was_rewrite == false) & (trumpets_data.size() != 0)) {
        cout << "Проверьте идентификатор и запустите функцию снова. Трубы с данным идентификатором не существует" << endl << endl;
    }
}


// Изменение статуса КС
void ks_editor(vector<trumpet>& trumpets_data, vector<ks>& kss_data) {

    /*
         * В данной функции мы изменяем количество активных цехов КС
    */
    show_all(0, 1, trumpets_data, kss_data);
    bool was_rewrite = false;
    int should_repair = 0;

    // Перебор объектов, если индекс совпадает с вводимым - меняем состояние трубы
    if (kss_data.size() == 0) {

    }
    else {
        int ks_id;
        ks_id = is_integer("Выберите идентификатор редактируемой КС:    ");
        for (auto& im : kss_data) {
            if (im.id == ks_id) {

                should_repair = is_integer("Добавить работающий цех? (1 - да, 0 - нет):  ");
                if (should_repair >= 1) {
                    if ((im.numberOfAvailable + 1) <= (im.number)) {
                        im.numberOfAvailable = im.numberOfAvailable + 1;
                        cout << "Кол-во работающих цехов изменено!" << endl << endl;
                        was_rewrite = true;
                    }
                    else {
                        cout << "Невозможно добавить из-за логической ошибки" << endl << endl;
                        was_rewrite = true;
                    }
                }
            }
        }
    }

    if ((was_rewrite == false) & (kss_data.size() != 0)) {
        cout << "Проверьте идентификатор и запустити функцию снова. КС с данным идентификатором не существует" << endl << endl;
    }

}


// Выполнение чтения данных из файла
void read_data(vector<trumpet>& trumpets_data, vector<ks>& kss_data) {

    ifstream fin("input.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        string buff;
        string here;
        while (fin >> buff)
        {
            if (buff == "t")
            {
                trumpet current_trumpet;
                fin >> current_trumpet.length;
                fin >> current_trumpet.diam;
                fin >> current_trumpet.repaired;
                trumpets_data.push_back(current_trumpet);
            }
            else if (buff == "ks") {
                ks current_ks;
                fin >> current_ks.name;
                fin >> current_ks.number;
                fin >> current_ks.numberOfAvailable;
                fin >> current_ks.efficiency;
                kss_data.push_back(current_ks);
            }
        }
    }
    cout << "Данные успешно прочитаны ... \n\n";
    fin.close();
}


// Выполнение записи в файл
void output_data(vector<trumpet> trumpets_data, vector<ks> kss_data) {

    bool was_output = false;
    ofstream fout;
    fout.open("output.txt");
    if (!fout.is_open())
        cout << "Файл не может быть открыт!\n";
    else {

        if (trumpets_data.size() == 0) {
            cout << "Данных о трубах нет. Введите 1, чтобы добавить\n";
        }
        else {
            for (auto& ct : trumpets_data)
            {
                fout << "t " << ct.length << " " << ct.diam << " " << ct.repaired << endl;
            }
            was_output = true;
        }

        if (kss_data.size() == 0) {
            cout << "Данных о КС нет. Введите 2, чтобы добавить" << endl;
        }
        else {
            for (auto& cks : kss_data)
            {
                fout << "ks " << cks.name << " " << cks.number << " " << cks.numberOfAvailable << " " << cks.efficiency << endl;
            }
            was_output = true;
        }

        if (was_output) {
            cout << "Данные успешно выведены!\n";
        }

        fout.close();
    }

    cout << endl;
}


// Удаление объектов по идентификатору
void delete_objects(vector<trumpet>& trumpets_data, vector<ks>& ks_data, const bool object_id) {


    // Если пользователь решил удалить трубу
    if (object_id == 0) {

        bool was_delete = false;

        cout << "Выбран пункт для удаления трубы" << endl;

        // Выведем все трубы
        show_all(1, 0, trumpets_data, ks_data);

        if (trumpets_data.size() == 0) {

        }
        else {

            int counter = 0;

            // Запросим от пользователя идентификатор трубы, которую он хочет удалить
            int useless_trumpet;
            useless_trumpet = is_integer("Введите идентификатор трубы, которую хотите удалить: ");

            // Поиск трубы и удаление
            for (auto& im : trumpets_data) {
                if (im.id == useless_trumpet) {
                    trumpets_data.erase(trumpets_data.begin() + counter);
                    was_delete = true;
                    cout << "Труба удалена!" << endl << endl;
                }
                counter = counter + 1;
            }

            // Если удаление не произошло и при этом трубы есть в массиве - выводим сообщение
            if ((was_delete == false) & (trumpets_data.size() != 0)) {
                cout << "Проверьте идентификатор и запустите функцию снова. Трубы с данным идентификатором не существует" << endl << endl;
            }

        }
  
    }

    // Если пользователь решил удалить КС
    if (object_id == 1) {

        bool was_delete = false;

        cout << "Выбран пункт для удаления КС" << endl;

        // Выведем все трубы
        show_all(0, 1, trumpets_data, ks_data);

        if (ks_data.size() == 0) {

        }
        else {

            int counter = 0;

            // Запросим от пользователя идентификатор трубы, которую он хочет удалить
            int useless_trumpet;
            useless_trumpet = is_integer("Введите идентификатор КС, которую хотите удалить: ");

            // Поиск трубы и удаление
            for (auto& im : ks_data) {
                if (im.id == useless_trumpet) {
                    ks_data.erase(ks_data.begin() + counter);
                    was_delete = true;
                    cout << "КС удалена!" << endl << endl;
                }
                counter = counter + 1;
            }

            // Если удаление не произошло и при этом трубы есть в массиве - выводим сообщение
            if ((was_delete == false) & (ks_data.size() != 0)) {
                cout << "Проверьте идентификатор и запустите функцию снова. КС с данным идентификатором не существует" << endl << endl;
            }

        }

    }


}


// Функция с вводом и проверкой начальной комманды первоначальной команды
int main_menu(vector<trumpet>& trumpets_data, vector<ks>& ks_data)
{

    // Меню пользователя по выбору функции программы
    cout << "1. Добавить трубу" << endl <<
            "2. Добавить КС" << endl <<
            "3. Просмотр всех объектов" << endl <<
            "4. Редактировать трубу" << endl <<
            "5. Редактировать КС" << endl <<
            "6. Загрузить" << endl <<
            "7. Сохранить" << endl <<
            "8. Удаление трубы" << endl <<
            "9. Удаление КС" << endl <<
            "0. Выход" << endl;;

    // Ввода пользователя (защита от текстового ввода, отр. чисел, чисел > кол-ва пунктов в меню
    int user_input_main = is_invalidinput("Введите желаемое действие (1-7): ");

    // Запуск функционала программы
    switch (user_input_main)
    {
    case 1:
    {
        cout << endl << " --- Создание новой трубы --- " << endl;
        new_trumpet(trumpets_data);
        return 1;
    }

    case 2:
    {
        cout << endl << " --- Создание новой КС --- " << endl;
        new_ks(ks_data);
        return 1;
    }

    case 3:
    {
        cout << endl << " --- Просмотр всех объектов --- " << endl;
        show_all(1, 1, trumpets_data, ks_data);
        return 1;
    }

    case 4:
    {
        cout << endl << " --- Изменение статуса трубы --- " << endl;
        trumpet_editor(trumpets_data, ks_data);
        return 1;
    }

    case 5:
    {
        cout << endl << " --- Изменение кол-ва активных цехов КС --- " << endl;
        ks_editor(trumpets_data, ks_data);
        return 1;
    }

    case 6:
    {
        cout << endl << " --- Чтение данных из файла --- " << endl;
        read_data(trumpets_data, ks_data);
        return 1;
    }

    case 7:
    {
        cout << endl << " --- Запись данных в файла --- " << endl;
        output_data(trumpets_data, ks_data);
        return 1;
    }

    case 8:
    {
        cout << endl << " --- Удаление труб --- " << endl;
        delete_objects(trumpets_data, ks_data, 0);
        return 1;
    }

    case 9:
    {
        cout << endl << " --- Удаление КС --- " << endl;
        delete_objects(trumpets_data, ks_data, 1);
        return 1;
    }

    case 0:
    {
        return 0;
    }

    }

}

int main()
{

    // Глобальный вектор для информации о трубах
    vector <trumpet> trumpets_data;

    // Глобальный вектор для информации о КС
    vector <ks> kss_data;

    // Делаем отображение русского текста в консоли
    setlocale(LC_ALL, "Russian");

    // Переменная, обозначающая пользовательский ввод
    int user_point = 1;

    // До тех пор, пока пользователь не введет нуль из главного меню - программа выполняется
    while (user_point != 0) {
        user_point = main_menu(trumpets_data, kss_data);
    }

    cout << "\n\nПрограмма завершила работу!!! \n\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.