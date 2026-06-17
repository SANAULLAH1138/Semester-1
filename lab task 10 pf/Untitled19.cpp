#include <iostream>
#include <string>
using namespace std;

// Base class Animal
class Animal {
public:
    string name;
    int age;

    // Constructor to initialize name and age
    Animal(string n = "", int a = 0) : name(n), age(a) {}

    // Display information directly from the class
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class Mammal
class Mammal : public Animal {
public:
    // Method to demonstrate feeding baby
    void feedBaby() {
        cout << "Feeding baby mammal." << endl;
    }
};

// Derived class Bird
class Bird : public Animal {
public:
    // Method to demonstrate laying an egg
    void layEgg() {
        cout << "Laying an egg." << endl;
    }
};

// Derived class Reptile
class Reptile : public Animal {
public:
    // Method to demonstrate shedding skin
    void shedSkin() {
        cout << "Shedding skin." << endl;
    }
};

// Main function
int main() {
    // Creating objects of the derived classes
    Mammal mammal("Elephant", 10);
    Bird bird("Parrot", 5);
    Reptile reptile("Snake", 3);

    // Displaying information and calling specific methods for each animal
    cout << "\nMammal Info: ";
    mammal.displayInfo();
    mammal.feedBaby();

    cout << "\nBird Info: ";
    bird.displayInfo();
    bird.layEgg();

    cout << "\nReptile Info: ";
    reptile.displayInfo();
    reptile.shedSkin();

    return 0;
}

