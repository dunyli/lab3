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



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
