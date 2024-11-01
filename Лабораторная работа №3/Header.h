//����� ��� �������� ������ � �������
class Client {
private:
    char name[50];
    char phone[20];
    char address[100];
public:
    Client(char* name, char* phone, char* address); //����������� � �����������
    void set(char* name, char* phone, char* address); //��������� �������� ����������-������ ������
    void get(char* name, char* phone, char* address); //��������� ������ ������
};

//����� ��� �������� ���������� � ������
class Product {
private:
    char name[50];
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //�����������
    void get(char* name, int* price, int* count, int* category_id, int* supplier_id); //��������� ������ ������
    void set(char* name, int price, int count, int category_id, int supplier_id); //��������� �������� ����������-������ ������
    int getPrice() { //����� ��� ������ ���� ��������
        return price;
    };
    int getCount() { //����� ��� ������ ����������� ��������
        return count;
    };
};

//����� ��� �������� ������ � ����������
class Supplier {
private:
    char name[50];
    char phone[20];
    char address[100];
    Product* products;
    int num_products;
public:
    Supplier(char* name, char* phone, char* address); //����������� � �����������
    ~Supplier() {
        delete[] products; //���������� ��� �������� ������
    };
    void addProduct(Product* product); //��������� ����� ��� Products
    void get(char* name, char* phone, char* address); //��������� ������ ������
    void set(char* name, char* phone, char* address); //��������� �������� ����������-������ ������
};

//����� ��� �������� ������ � ��������� ������
class Category {
private:
    char name[50];   // �������� ��������� ("����", "�������", "����������")
    Product* products;
    int num_products;
public:
    Category(char* name); //����������� � �����������
    ~Category() {
        delete[] products; //���������� ��� �������� ������
    }
    void addProduct(Product* product); //��������� ����� ��� Products
    void get(char* name); //��������� ������ ������
    void set(char* name); //��������� �������� ����������-������ ������
};

//����� ��� �������� ���������� � ������
class Order {
private:
    int client_id;
    Product* products;
    int num_products;
    int total_price;
public:
    Order(); //�����������
    ~Order() {
        delete[] products; //���������� ��� �������� ������
    };
    void addProduct(Product* product); //��������� ����� ��� Products
    void get(int* client_id, int* num_products, int* total_price); //��������� ������ ������
    void set(int client_id, int num_products, int total_price); //��������� �������� ����������-������ ������
    void listProducts(Product* product, int count); // ��������� ����� � ��������
};

// ����� ��� �������� ���������� � ���������� ������
class Storehouse {
private:
    Product* products;
    int num_products;
public:
    Storehouse(); //�����������
    ~Storehouse() {
        delete[] products; //���������� ��� �������� ������
    };
    void addProduct(Product* product); //��������� ����� ��� Products
    void editProduct(int product_id, char* name, int price, int volume, int category_id, int supplier_id); //�������������� ������ ������
    void listStorehouse(Product* product, int count); // ��������� ����� � ��������
    void get(int num_products); //��������� ������ ������
    int listnum_products() { //����� ��� ������ ���-�� ���������
        return num_products;
    };
};

//����� ��� �������� ������� �������
class OrderHistory {
private:
    Order* orders; // ������ �������
    int orderCount;
public:
    OrderHistory(); //�����������
    ~OrderHistory() {
        delete[] orders; //���������� ��� �������� ������
    };
    void addOrder(Order* order); //��������� ����� ��� Orders
    void listOrders(Order* order, int count); //��������� ����� � ������
    int listorder_count() { //����� ��� ������ ���-�� �������
        return orderCount;
    };
};

//����� ��� �������� ���������� � ��������
class Store {
private:
    Client* clients;
    int num_clients;
    Category* categories;
    int num_categories;
    Supplier* suppliers;
    int num_suppliers;
public:
    Store(); //�����������
    ~Store() { //���������� ��� �������� ������
        delete[] clients; 
        delete[] categories;
        delete[] suppliers;
    };
    void addClient(Client* client); //��������� ����� ��� Client
    void addCategory(Category* category); //��������� ����� ��� Category
    void addSupplier(Supplier* supplier); //��������� ����� ��� Supplier
    void listClients(Client* client, int count); //��������� ����� � �������
    void listCategories(Category* category, int count); // ��������� ����� � ���������
    void listSuppliers(Supplier* supplier, int count); // ��������� ����� � ����������
    int listnum_categories() { //����� ��� ������ ���-�� ���������
        return num_categories;
    };
    int listnum_suppliers() { //����� ��� ������ ���-�� �����������
        return num_suppliers;
    };
    int listnum_clients() { //����� ��� ������ ���-�� ��������
        return num_clients;
    };
};


