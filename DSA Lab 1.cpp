#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
private:
    string name;
    int quantity;
    double price;

public:
    Item(string n, int q, double p) : name(n), quantity(q), price(p) {}

    void displayItem() {
        cout << "Name: " << name << "\n" << "Quantity: " << quantity << "\n" << "Price: " << price << "$" <<endl;
    } 

    void addItem(int amount) {
        quantity = quantity + amount;
        cout << "Quatity changed to " << quantity << endl;
    
    }

    void removeItem(int amount) {
        quantity = quantity - amount;
        cout << "Quatity changed to " << quantity << endl;
    }

    string itemName() {
        return name;
    }

    double calculateTotalValue() {
        float total;
        total = (quantity*price);
        cout << total << endl;
        return 0;
    }
};



class Inventory {
private:
    vector <Item> items;
    int itemCount;
public:
    
    Inventory() {
        itemCount = 0;

        
    }

    void addItem(const Item& newItem) {
        itemCount = itemCount + 1;
        items.push_back(newItem);
        cout << "item is added" << endl;
    }

    void removeItem(const string& itemName) {
        for (int i = itemCount; i > 0; i--) {

            if ((items.at(i).itemName()).compare(itemName)) {

                items.erase(items.begin()+(i));
                itemCount = itemCount - 1;
                cout << "item is removed" << endl;
                break;

            }
        }

        
        
    }

    void displayInventory() {
        cout << "\n";
        for (int i = itemCount; i > 0;) {
            
            items.at(i-1).displayItem();
            cout << "-----------------------------" << endl;
            i = i -1;
        }
    }
};















int main() {
    Inventory store;
    store = Inventory();
    Item ipad = Item("Ipad",12,500);
    Item mac = Item("Macbook",3,1500);
    Item phone = Item("Iphone",40,700);
    Item vision = Item("Vision Pro",3,3500);
    store.addItem(ipad);
    store.addItem(mac);
    store.addItem(phone);
    store.addItem(vision);
    store.displayInventory();
    return 0;
}