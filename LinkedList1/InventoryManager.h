
#pragma once
#include <string>
#include <iostream>
#include "DoubleLinkedListT.h"
using namespace std;
class Item;
class Section {
private:
    string name;
    DoubleLinkedListT<Item> items;

public:
    Section(const string& name) : name(name) {}

    string getName() {
        return name;
    }

    void addItem() {
        string itemName;
        cout << "Enter Item name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, itemName);
        Item newItem(itemName);
        items.insertAtEnd(newItem);
        cout << "Item " << itemName << " added successfully!" << endl;
    }

    void displayAllItems() {
        items.display();
    }

    Item findItem() {
        string itemName;
        cout << "Enter Item Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, itemName);
        return items.find(Item(itemName));
    };

    void removeItems() {
        string itemName;
        cout << "Enter Item name to remove: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, itemName);
        items.deleteNode(Item(itemName));
    }
};
class Shop {
private:
    string name;
    DoubleLinkedListT<Section> sections;

public:
    Shop(const string& name) : name(name) {}

    string getName() { return name; };
    DoubleLinkedListT<Section> getSection() { return sections; };

    void addSection() {
        string sectionName;
        cout << "Enter Section name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, sectionName);
        Section newSection(sectionName);
        sections.insertAtEnd(newSection);
        cout << "Section " << sectionName << " added successfully!" << endl;
    }

    void displayAllSections() {
        sections.display();
    }

    Section findSection() {
        string sectionName;
        cout << "Enter Section Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, sectionName);
        return sections.find(Section(sectionName));
    }

    void displayAllItemsOfSection() {
        Section section = findSection();
        section.displayAllItems();
    }
};
class Item {
private:
    string name;
    string description;

public:
    Item(const string& name) : name(name) {}

    
};


// Global variable
DoubleLinkedListT<Shop> shoppingChain;




class Utility {
public:
    void menu() {
        int option;
        cout << "Select Option" << endl;
        cout << "1- Add Shop" << endl;
        cout << "2- Add Section" << endl;
        cout << "3- Add Items" << endl;
        cout << "4- Remove Items" << endl;
        cout << "5- Display all Shops" << endl;
        cout << "6- Display all Items of a Section" << endl;
        cout << "7- Display all Items of a Shop" << endl;
        cin >> option;

        switch (option) {
        case 1:
            addShopToChain();
            break;
        case 2:
            addSectionToShop();
            break;
        case 3:
            addItemToSection();
            break;
        case 4:
            removeItemFromSection();
            break;
        case 5:
            shoppingChain.display();
            break;
        case 6:
            displayItemsOfSection();
            break;
        case 7:
            //displayAllItemsOfShop();
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
            break;
        }
    }

    Section findItemsFromAllTheListsMegaFunction() 
    {
        Shop shop = findShop();
        return shop.findSection();
    };

    void addSectionToShop() {
        //first get the shop from the list then add the section
        Shop shop = findShop();
        //now add section
        shop.addSection();
    };

    void addItemToSection() {
        Section section = findItemsFromAllTheListsMegaFunction();
        section.addItem();
    };
    
     
    void removeItemFromSection() {
        Section section = findItemsFromAllTheListsMegaFunction();
        section.removeItems();
    }; 
    
    void displayItemsOfSection() {
        Section section = findItemsFromAllTheListsMegaFunction();
        section.displayAllItems();
    };
   
    /*/void displayAllItemsOfShop() {
        string shopName;
        cout << "Enter the name of the shop: ";
        getline(cin, shopName);

        // Find the shop in the shoppingChain
        Shop selectedShop = shoppingChain.find(Shop(shopName));

        // Display all items of the selected shop
        cout << "Shop: " << selectedShop.getName() << endl;
        DoubleLinkedList<Section> currentSectionNode = selectedShop.getSection();
        Node* currentSectionNode = currentSectionNode;
        while (currentSectionNode != nullptr) {
            Section currentSection = currentSectionNode->data;
            cout << "Section: " << currentSection.getName() << endl;
            currentSection.displayAllItems();
            currentSectionNode = currentSectionNode->nextNode;
        }
    };*/


};

void addShopToChain() {
    string shopName;
    cout << "Enter shop name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, shopName);
    Shop newShop(shopName);
    shoppingChain.insertAtEnd(newShop);
    cout << "Shop " << shopName << " added successfully!" << endl;
}

Shop findShop() {
    string shopName;
    cout << "Enter Shop Name: " << endl;
    getline(cin,shopName);
    return shoppingChain.find(shopName);
};
