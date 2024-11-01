// Лабораторная 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>
#include "Header.h"


// Определение контруктора с параметрами класса Client
Client::Client(char* name, char* phone, char* address)
{
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

// Определение контруктора с параметрами класса Supplier
Supplier::Supplier(char* name, char* phone, char* address)
{
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
    num_products = 0;
}

// Определение контруктора с параметрами класса Category
Category::Category(char* name)
{
    strncpy(this->name, name, sizeof(this->name));
    num_products = 0;
}

// Определение контруктора  класса Product
Product::Product()
{
    price = 0;
    count = 0;
    category_id = 0;
    supplier_id = 0;
}

// Определение контруктора класса Order
Order::Order()
{
    client_id = 0;
    num_products = 0;
    total_price = 0;
}

// Определение контруктора класса Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
}

// Определение контруктора класса OrderHistory
OrderHistory::OrderHistory()
{
    orderCount = 0;
}

// Определение контруктора класса Store
Store::Store()
{
    num_clients = 0;
    num_categories = 0;
    num_suppliers = 0;
}

//Получение значений переменных-членов класса и данных класса Client
void Client::get(char* name, char* phone, char* address) {
    strncpy(name, this->name, sizeof(this->name));
    strncpy(phone, this->phone, sizeof(this->phone));
    strncpy(address, this->address, sizeof(this->address));
}

void Client::set(char* name, char* phone, char* address) {
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

//Получение значений переменных-членов класса и данных класса Suppplier
void Supplier::get(char* name, char* phone, char* address) {
    strncpy(name, this->name, sizeof(this->name));
    strncpy(phone, this->phone, sizeof(this->phone));
    strncpy(address, this->address, sizeof(this->address));
}

void Supplier::set(char* name, char* phone, char* address) {
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

//Получение значений переменных-членов класса и данных класса Category
void Category::get(char* name) {
    strncpy(name, this->name, sizeof(this->name));
}

void Category::set(char* name) {
    strncpy(this->name, name, sizeof(this->name));
}

//Получение значений переменных-членов класса и данных класса Product
void Product::get(char* name, int* price, int* count, int* category_id, int* supplier_id) {
    strncpy(name, this->name, sizeof(this->name));
    *price = this->price;
    *count = this->count;
    *category_id = this->category_id;
    *supplier_id = this->supplier_id;
}

void Product::set(char* name, int price, int count, int category_id, int supplier_id) {
    strncpy(this->name, name, sizeof(this->name));
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

//Получение значений переменных-членов класса и данных класса Product
void Order::get(int* client_id, int* num_products, int* total_price) {
    *client_id = this->client_id;
    *num_products = this->num_products;
    *total_price = this->total_price;
}

void Order::set(int client_id, int num_products, int total_price) {
    this->client_id = client_id;
    this->num_products = num_products;
    this->total_price = total_price;
}

//Определение функции-члена класса Order для вывода истории заказов
void Order::listProducts(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

//Определение функции-члена класса OrderHistory для вывода истории заказов
void OrderHistory::listOrders(Order* order, int count) {
    for (int i = 0; i < orderCount; i++) {
        if (i == count) *order = orders[i];
    }
}

//Определение функции-члена класса Storehouse для вывода списка товаров
void Storehouse::listStorehouse(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

//Определение функции-члена класса Store для вывода списка клиентов
void Store::listClients(Client* client, int count) {
    for (int i = 0; i < num_clients; i++) {
        if (i == count) *client = clients[i];
    }
}

//Определение функции-члена класса Store для вывода списка категорий
void Store::listCategories(Category* category, int count) {
    for (int i = 0; i < num_categories; i++) {
        if (i == count) *category = categories[i];
    }
}

//Определение функции-члена класса Store для вывода списка поставщиков
void Store::listSuppliers(Supplier* supplier, int count) {
    for (int i = 0; i < num_suppliers; i++) {
        if (i == count) *supplier = suppliers[i];
    }
}

// Определение функции-члена класса Category - функции addProduct()
void Category::addProduct(Product* product) {
    products = (Product*)realloc(products, (num_products + 1) * sizeof(Product));
    products[num_products] = *product;
    num_products++;
}

// Определение функции-члена класса Supplier - функции addProduct()
void Supplier::addProduct(Product* product) {
    products = (Product*)realloc(products, (num_products + 1) * sizeof(Product));
    products[num_products] = *product;
    num_products++;
}

// Определение функции - члена класса Storehouse - функции addProduct()
void Storehouse::addProduct(Product* product) {
    products = (Product*)realloc(products, (num_products + 1) * sizeof(Product));
    products[num_products] = *product;
    num_products++;
}

// Определение функции-члена класса Order - функции addProduct()
void Order::addProduct(Product* product) {
    products = (Product*)realloc(products, (num_products + 1) * sizeof(Product));
    products[num_products] = *product;
    num_products++;
}

// Определение функции - члена класса OrderHistory - функции addOrder()
void OrderHistory::addOrder(Order* order) {
    orders = (Order*)realloc(orders, (orderCount + 1) * sizeof(Order));
    orders[orderCount] = *order;
    orderCount++;
}

// Определение функции - члена класса Store - функции addClient()
void Store::addClient(Client* client) {
    clients = (Client*)realloc(clients, (num_clients + 1) * sizeof(Client));
    clients[num_clients] = *client;
    num_clients++;
}

// Определение функции - члена класса Store - функции addCategory()
void Store::addCategory(Category* category) {
    categories = (Category*)realloc(categories, (num_categories + 1) * sizeof(Category));
    categories[num_categories] = *category;
    num_categories++;
}

// Определение функции - члена класса Store - функции addSupplier()
void Store::addSupplier(Supplier* supplier) {
    suppliers = (Supplier*)realloc(suppliers, (num_suppliers + 1) * sizeof(Supplier));
    suppliers[num_suppliers] = *supplier;
    num_suppliers++;
}

void Storehouse::editProduct(int product_id, char* name, int price, int volume, int category_id, int supplier_id) {
    products[product_id].set(name, price, volume, category_id, supplier_id);
}

// Функция для вывода меню
void outmenu() {
    printf("\nЗоомагазин Собачий Патруль\n");
    printf("1. Добавить клиента\n");
    printf("2. Добавить категорию\n");
    printf("3. Добавить поставщика\n");
    printf("4. Добавить товар\n");
    printf("5. Создать заказ\n");
    printf("6. Вывести список клиентов\n");
    printf("7. Вывести список категорий\n");
    printf("8. Вывести список поставщиков\n");
    printf("9. Вывести список товаров\n");
    printf("10. Вывести список заказов\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "Rus");
    Store store;
    Storehouse storehouse;
    OrderHistory orderhistory;
    Order new_order;
    int choice;
    char name[50], address[100], phone[20];
    int price, num_products = 0, count, category_id, supplier_id;
    int client_id, product_id, volume;
    int num_products_order = 0, total_price = 0;
    int count_product_volume;
    do {
        outmenu();
        scanf("%d", &choice);
        getchar();  // Удаляем символ новой строки из буфера
        switch (choice) {
        case 1: {
            printf("Введите имя клиента: ");
            fgets(name, 50, stdin);
            printf("Введите телефон клиента: ");
            fgets(phone, 20, stdin);
            printf("Введите адрес клиента: ");
            fgets(address, 100, stdin);
            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;
            phone[strcspn(phone, "\n")] = 0;
            address[strcspn(address, "\n")] = 0;
            Client new_client(name, phone, address);
            store.addClient(&new_client);
            break;
        }
        case 2: {
            printf("Введите название категории:  ");
            fgets(name, 50, stdin);
            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;
            Category new_category(name);
            store.addCategory(&new_category);
            break;
        }
        case 3: {
            printf("Введите название поставщика: ");
            fgets(name, 50, stdin);
            printf("Введите адрес поставщика:  ");
            fgets(address, 100, stdin);
            printf("Введите телефон поставщика: ");
            fgets(phone, 20, stdin);
            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;
            address[strcspn(address, "\n")] = 0;
            phone[strcspn(phone, "\n")] = 0;
            Supplier new_supplier(name, phone, address);
            store.addSupplier(&new_supplier);
            break;
        }
        case 4: {
            do {
                printf("Введите ID категории (или 0 для выхода): ");
                scanf("%d", &category_id);
                if (category_id < 0 || category_id > store.listnum_categories()) printf("Неверный ID категории! ");
            } while (category_id < 0 || category_id > store.listnum_categories());
            if (category_id != 0) {
                do {
                    printf("Введите ID поставщика (или 0 для выхода): ");
                    scanf("%d", &supplier_id);
                    if (supplier_id < 0 || supplier_id > store.listnum_suppliers()) printf("Неверный ID поставщика! ");
                } while (supplier_id < 0 || supplier_id > store.listnum_suppliers());
                if (supplier_id != 0) {
                    while (getchar() != '\n');
                    printf("Введите название товара:");
                    fgets(name, 50, stdin);
                    printf("Введите цену товара: ");
                    scanf("%d", &price);
                    printf("Введите количество товара: ");
                    scanf("%d", &count);
                    // Удаляем символ новой строки
                    name[strcspn(name, "\n")] = 0;
                    Product new_product;
                    new_product.set(name, price, count, category_id, supplier_id);
                    storehouse.addProduct(&new_product);
                    printf("Товар добавлен! ");
                }
            }
            break;
        }
        case 5: {
            num_products_order = 0;
            total_price = 0;
            do {
                printf("Введите ID клиента (или 0 для завершения): ");
                scanf("%d", &client_id);
                if (client_id < 0 || client_id > store.listnum_categories()) printf("Неверный ID клиента! ");
            } while (client_id < 0 || client_id > store.listnum_clients());
            if (client_id != 0) {
                printf("Введите ID товара (или 0 для завершения): ");
                scanf("%d", &product_id);
                while (product_id != 0) {
                    if (product_id > 0 && product_id <= storehouse.listnum_products()) {
                        Product new_product;
                        storehouse.listStorehouse(&new_product, product_id - 1);
                        printf("%d", new_product.getCount());
                        printf("Введите количество товара: ");
                        scanf("%d", &volume);
                        if (volume > 0 && volume <= new_product.getCount()) {
                            total_price += new_product.getPrice() * volume;
                            new_product.get(name, &price, &count, &category_id, &supplier_id);
                            count_product_volume = count - volume;
                            storehouse.editProduct(product_id - 1, name, price, count_product_volume, category_id, supplier_id);
                            new_product.set(name, price, volume, category_id, supplier_id);
                            new_order.addProduct(&new_product);
                            num_products_order++;
                        }
                        else printf("Неверное количество товара!\n");
                    }
                    else printf("Неверный ID товара!\n");
                    printf("Введите ID нового товара (или 0 для завершения): ");
                    scanf("%d", &product_id);
                }
            }
            if (num_products_order > 0) {
                new_order.set(client_id, num_products_order, total_price);
                orderhistory.addOrder(&new_order);
                printf("Заказ создан!\n");
            }
            break;
        }
        case 6:
            printf("Список клиентов:\n");
            for (int j = 0; j < store.listnum_clients(); j++) {
                printf("ID клиента: %d\n", j + 1);
                Client new_client(name, phone, address);
                store.listClients(&new_client, j);
                new_client.get(name, phone, address);
                printf("Имя клиента: %s, Телефон: %s, Адрес: %s\n", name, phone, address);
            }
            break;
        case 7:
            printf("Список категорий:\n");
            for (int j = 0; j < store.listnum_categories(); j++) {
                printf("ID категории: %d  ", j + 1);
                Category new_category(name);
                store.listCategories(&new_category, j);
                new_category.get(name);
                printf("Название категории: %s\n", name);
            }
            break;
        case 8:
            printf("Список поставщиков:\n");
            for (int j = 0; j < store.listnum_suppliers(); j++) {
                printf("ID поставщика: %d  ", j + 1);
                Supplier new_supplier(name, phone, address);
                store.listSuppliers(&new_supplier, j);
                new_supplier.get(name, phone, address);
                printf("Название поставщика: %s, Телефон: %s, Адрес: %s\n", name, phone, address);
            }
            break;
        case 9:
            printf("Список товаров:\n");
            for (int j = 0; j < storehouse.listnum_products(); j++) {
                printf("ID: %d. ", j + 1);
                Product new_product;
                new_product.set(name, price, count, category_id, supplier_id);
                storehouse.listStorehouse(&new_product, j);
                new_product.get(name, &price, &count, &category_id, &supplier_id);
                printf("Название продукта: %s, Цена: %d, Количество: %d\n", name, price, count);
            }
            break;
        case 10:
            printf("История заказов:\n");
            for (int j = 0; j < orderhistory.listorder_count(); j++) {
                printf("Заказ №%d. ", j + 1);
                orderhistory.listOrders(&new_order, j);
                new_order.get(&client_id, &num_products, &total_price);
                printf("ID клиента: %d  ", client_id);
                for (int a = 0; a < num_products; a++) {
                    printf("Товары: ");
                    printf("%d. ", a + 1);
                    Product new_product;
                    new_order.listProducts(&new_product, a);
                    new_product.get(name, &price, &count, &category_id, &supplier_id);
                    printf("Название продукта: %s, Цена: %d, Количество: %d\n", name, price, count);
                }
                printf("Общая стоимость: %d\n", total_price);
                printf("\n");
            }
            break;
        case 0:
            printf("Выход...\n");
            break;
        default:
            printf("Неверный ввод. Пожалуйста, попробуйте еще раз.\n");
        }
    } while (choice != 0);
    return 0;
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
