#include <iostream>

using namespace std;

class House {
public:
    virtual void build() = 0;
};

class Apartment : public House {
public:
    void build() override {
        cout << "Building an apartment" << endl;
    }
};

class Villa : public House {
public:
    void build() override {
        cout << "Building a villa" << endl;
    }
};

class HouseBuilder {
public:
    virtual House* buildApartment() = 0;
    virtual House* buildVilla() = 0;
};

class ApartmentBuilder : public HouseBuilder {
public:
    House* buildApartment() override {
        return new Apartment();
    }

    House* buildVilla() override {
        return nullptr;
    }
};

class VillaBuilder : public HouseBuilder {
public:
    House* buildApartment() override {
        return nullptr;
    }

    House* buildVilla() override {
        return new Villa();
    }
};

int main() {
    ApartmentBuilder apartmentBuilder;
    House* apartment = apartmentBuilder.buildApartment();
    apartment->build();

    VillaBuilder villaBuilder;
    House* villa = villaBuilder.buildVilla();
    villa->build();

    return 0;
}