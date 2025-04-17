#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<ctime>
#include<string>

using namespace std;

struct Product{
    int productID;
    string name;
    string category;
};

struct Order{
    int orderID;
    int ProductID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main(){
    vector<Product> products = {
        {101, "laptop", "electronics"},
        {102, "stand", "hardware"},
        {103, "blender", "kitchen"},
        {104, "chair", "home"},
        {105, "bed", "home"},
    };

    deque<string> recentCustomers = {"C001", "C002", "C003", "C004"};

    recentCustomers.push_back("C005");
    recentCustomers.push_front("C006");

    list<Order> orderHistory;
    orderHistory.push_back({
        1, 101, 2, "C001", time(0)
    });

    orderHistory.push_back({
        2, 102, 3, "C002", time(0)
    });

    orderHistory.push_back({
        3, 103, 4, "C003", time(0)
    });

    // finfing unique categories through set
    set<string> categories;

    // use auto when different datastructure is available for loop
    for(const auto &product: products){
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 40},
        {103, 45},
        {104, 32},
    };

    // track ultiple orders of a customer
    multimap<string, Order> customerOrders;
    for(const auto &order: orderHistory){
        customerOrders.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData = {
        {"C001", "Alice"},
        {"C002", "Bob"},
        {"C003", "John"},
        {"C004", "Smith"},
        {"C005", "Leo"},
    };

    unordered_set<int> uniqueProductIDs;
    for(const auto &product: products){
        uniqueProductIDs.insert(product.productID);
    }

    cout << "Product List" << endl;
    for(const auto &product: products){
        cout << "Product ID: " << product.productID << " Product Name: " << product.name << " Product Category: " << product.category << endl;
    }

    cout << "Order History" << endl;
    for(const auto &order: orderHistory){
        cout<< "Order ID: " << order.orderID << " Product ID: " << order.ProductID << " Quantity: " << order.quantity << " Customer ID: " << order.customerID << " Order Time: " << order.orderDate << endl;
    }


    cout << "Customer History:\n";
    for(const auto &[customerId, order]: customerOrders){
        cout << "Customer Id: " << customerId << " Order ID: " << order.orderID
        << ", Product ID: " << order.ProductID
        << ", Quantity: " << order.quantity
        << ", Date: " << ctime(&order.orderDate);
    }

return 0;
}