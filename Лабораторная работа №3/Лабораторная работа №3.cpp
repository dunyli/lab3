// Лабораторная работа №3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
Client::Client(char *name, char* phone, char* adress)
{
    strcpy(this->name, name);
    strcpy(this->phone, phone);
    strcpy(this->address, address);
}

// Определение контруктора с параметрами класса Supplier
Supplier::Supplier(char* name, char* phone, char* adress)
{
    strcpy(this->name, name);
    strcpy(this->phone, phone);
    strcpy(this->address, address);
}

// Определение контруктора с параметрами класса Category
Category::Category(char* name)
{
    strcpy(this->name, name);
}

// Определение контруктора с параметрами класса Supplier
Supplier::Supplier(char* name, char* phone, char* adress)
{
    strcpy(this->name, name);
    strcpy(this->phone, phone);
    strcpy(this->address, address);
}


// Определение функции-члена класса Catergory - функции addProduct()
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

// Определение класса Product
class Product {
private:
    char name[50];
    int price;
    int count;
    int category_id;
    int supplier_id;

public:
    Product(const char* name, int price, int count, int category_id, int supplier_id) {
        strncpy(this->name, name, sizeof(this->name));
        this->price = price;
        this->count = count;
        this->category_id = category_id;
        this->supplier_id = supplier_id;
    }

    void display() const {
        printf("Product Name: %s, Price: %d, Count: %d\n", name, price, count);
    }

    int getPrice() const {
        return price;
    }
};

// Определение класса Client
class Client {
private:
    char name[50];
    char phone[20];
    char address[100];

public:
    Client(char* name, const char* phone, const char* address) {
        strncpy(this->name, name, sizeof(this->name));
        strncpy(this->phone, phone, sizeof(this->phone));
        strncpy(this->address, address, sizeof(this->address));
    }

    void display() const {
        printf("Client Name: %s, Phone: %s, Address: %s\n", name, phone, address);
    }
};

// Определение класса Supplier
class Supplier {
private:
    char name[50];
    char address[100];
    char phone[20];

public:
    Supplier(const char* name, const char* address, const char* phone) {
        strncpy(this->name, name, sizeof(this->name));
        strncpy(this->address, address, sizeof(this->address));
        strncpy(this->phone, phone, sizeof(this->phone));
    }

    void display() const {
        printf("Supplier Name: %s, Phone: %s, Address: %s\n", name, phone, address);
    }
};

// Определение класса Category
class Category {
private:
    char name[50];

public:
    Category(const char* name) {
        strncpy(this->name, name, sizeof(this->name));
    }

    void display() const {
        printf("Category Name: %s\n", name);
    }
};

// Определение класса Order
class Order {
private:
    Client* client;
    Product** products;
    int total_price;
    int num_products;
    int capacity;

    void expand() {
        capacity *= 2;
        Product** new_products = new Product * [capacity];
        for (int i = 0; i < num_products; ++i) {
            new_products[i] = products[i];
        }
        delete[] products;
        products = new_products;
    }

public:
    Order(Client* client) : client(client), total_price(0), num_products(0), capacity(2) {
        products = new Product * [capacity];
    }

    ~Order() {
        delete[] products;
    }

    void addProduct(Product* product) {
        if (num_products >= capacity) {
            expand();
        }
        products[num_products++] = product;
        total_price += product->getPrice();
    }

    void display() const {
        client->display();
        printf("Total Price: %d\n", total_price);
        for (int i = 0; i < num_products; ++i) {
            products[i]->display();
        }
    }
};

// Определение класса Store
class Store {
private:
    Client** clients;
    Product** products;
    Category** categories;
    Supplier** suppliers;
    Order** orders;
    int num_clients;
    int num_products;
    int num_categories;
    int num_suppliers;
    int num_orders;
    int client_capacity;
    int product_capacity;
    int category_capacity;
    int supplier_capacity;
    int order_capacity;

    void expandClients() {
        client_capacity *= 2;
        Client** new_clients = new Client * [client_capacity];
        for (int i = 0; i < num_clients; ++i) {
            new_clients[i] = clients[i];
        }
        delete[] clients;
        clients = new_clients;
    }

    void expandProducts() {
        product_capacity *= 2;
        Product** new_products = new Product * [product_capacity];
        for (int i = 0; i < num_products; ++i) {
            new_products[i] = products[i];
        }
        delete[] products;
        products = new_products;
    }

    void expandCategories() {
        category_capacity *= 2;
        Category** new_categories = new Category * [category_capacity];
        for (int i = 0; i < num_categories; ++i) {
            new_categories[i] = categories[i];
        }
        delete[] categories;
        categories = new_categories;
    }

    void expandSuppliers() {
        supplier_capacity *= 2;
        Supplier** new_suppliers = new Supplier * [supplier_capacity];
        for (int i = 0; i < num_suppliers; ++i) {
            new_suppliers[i] = suppliers[i];
        }
        delete[] suppliers;
        suppliers = new_suppliers;
    }

    void expandOrders() {
        order_capacity *= 2;
        Order** new_orders = new Order * [order_capacity];
        for (int i = 0; i < num_orders; ++i) {
            new_orders[i] = orders[i];
        }
        delete[] orders;
        orders = new_orders;
    }

public:
    Store()
        : num_clients(0), num_products(0), num_categories(0), num_suppliers(0), num_orders(0),
        client_capacity(2), product_capacity(2), category_capacity(2), supplier_capacity(2), order_capacity(2) {
        clients = new Client * [client_capacity];
        products = new Product * [product_capacity];
        categories = new Category * [category_capacity];
        suppliers = new Supplier * [supplier_capacity];
        orders = new Order * [order_capacity];
    }

    ~Store() {
        for (int i = 0; i < num_clients; ++i) {
            delete clients[i];
        }
        for (int i = 0; i < num_products; ++i) {
            delete products[i];
        }
        for (int i = 0; i < num_categories; ++i) {
            delete categories[i];
        }
        for (int i = 0; i < num_suppliers; ++i) {
            delete suppliers[i];
        }
        for (int i = 0; i < num_orders; ++i) {
            delete orders[i];
        }
        delete[] clients;
        delete[] products;
        delete[] categories;
        delete[] suppliers;
        delete[] orders;
    }

    void addClient(Client* client) {
        if (num_clients >= client_capacity) {
            expandClients();
        }
        clients[num_clients++] = client;
    }

    void addProduct(Product* product) {
        if (num_products >= product_capacity) {
            expandProducts();
        }
        products[num_products++] = product;
    }

    void addCategory(Category* category) {
        if (num_categories >= category_capacity) {
            expandCategories();
        }
        categories[num_categories++] = category;
    }

    void addSupplier(Supplier* supplier) {
        if (num_suppliers >= supplier_capacity) {
            expandSuppliers();
        }
        suppliers[num_suppliers++] = supplier;
    }

    void addOrder(Order* order) {
        if (num_orders >= order_capacity) {
            expandOrders();
        }
        orders[num_orders++] = order;
    }

    void displayClients() const {
        printf("Clients:\n");
        for (int i = 0; i < num_clients; ++i) {
            clients[i]->display();
        }
    }

    void displayProducts() const {
        printf("Products:\n");
        for (int i = 0; i < num_products; ++i) {
            products[i]->display();
        }
    }

    void displayCategories() const {
        printf("Categories:\n");
        for (int i = 0; i < num_categories; ++i) {
            categories[i]->display();
        }
    }

    void displaySuppliers() const {
        printf("Suppliers:\n");
        for (int i = 0; i < num_suppliers; ++i) {
            suppliers[i]->display();
        }
    }

    void displayOrders() const {
        printf("Orders:\n");
        for (int i = 0; i < num_orders; ++i) {
            orders[i]->display();
        }
    }
};

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Client\n");
    printf("2. Add Product\n");
    printf("3. Add Category\n");
    printf("4. Add Supplier\n");
    printf("5. Create Order\n");
    printf("6. Display Clients\n");
    printf("7. Display Products\n");
    printf("8. Display Categories\n");
    printf("9. Display Suppliers\n");
    printf("10. Display Orders\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Store store;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Удаляем символ новой строки из буфера

        switch (choice) {
        case 1: {
            char name[50], phone[20], address[100];
            printf("Enter client name: ");
            fgets(name, 50, stdin);
            printf("Enter client phone: ");
            fgets(phone, 20, stdin);
            printf("Enter client address: ");
            fgets(address, 100, stdin);

            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;
            phone[strcspn(phone, "\n")] = 0;
            address[strcspn(address, "\n")] = 0;

            store.addClient(new Client(name, phone, address));
            break;
        }
        case 2: {
            char name[50];
            int price, count, category_id, supplier_id;
            printf("Enter product name: ");
            fgets(name, 50, stdin);
            printf("Enter product price: ");
            scanf("%d", &price);
            printf("Enter product count: ");
            scanf("%d", &count);
            printf("Enter category ID: ");
            scanf("%d", &category_id);
            printf("Enter supplier ID: ");
            scanf("%d", &supplier_id);
            getchar();

            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;

            store.addProduct(new Product(name, price, count, category_id, supplier_id));
            break;
        }
        case 3: {
            char name[50];
            printf("Enter category name: ");
            fgets(name, 50, stdin);

            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;

            store.addCategory(new Category(name));
            break;
        }
        case 4: {
            char name[50], address[100], phone[20];
            printf("Enter supplier name: ");
            fgets(name, 50, stdin);
            printf("Enter supplier address: ");
            fgets(address, 100, stdin);
            printf("Enter supplier phone: ");
            fgets(phone, 20, stdin);

            // Удаляем символ новой строки
            name[strcspn(name, "\n")] = 0;
            address[strcspn(address, "\n")] = 0;
            phone[strcspn(phone, "\n")] = 0;

            store.addSupplier(new Supplier(name, address, phone));
            break;
        }
        case 5: {
            int clientIndex;
            printf("Enter client index for the order: ");
            scanf("%d", &clientIndex);
            getchar();
            if (clientIndex < 0 || clientIndex >= store.num_clients) {
                printf("Invalid client index.\n");
                break;
            }
            Order* order = new Order(store.clients[clientIndex]);
            int productIndex;
            while (true) {
                printf("Enter product index to add to order (-1 to finish): ");
                scanf("%d", &productIndex);
                getchar();
                if (productIndex == -1) {
                    break;
                }
                if (productIndex < 0 || productIndex >= store.num_products) {
                    printf("Invalid product index.\n");
                    continue;
                }
                order->addProduct(store.products[productIndex]);
            }
            store.addOrder(order);
            break;
        }
        case 6:
            store.displayClients();
            break;
        case 7:
            store.displayProducts();
            break;
        case 8:
            store.displayCategories();
            break;
        case 9:
            store.displaySuppliers();
            break;
        case 10:
            store.displayOrders();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
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
