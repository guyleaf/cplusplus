#include <string>
#include<vector>
#include <list>
#include<algorithm>
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(string name)
    {
        this->name = name;
        legs = 4;
    }
    int getLegs()
    {
        return legs;
    }
    void setLegs(int l)
    {
        legs = l;
    }
    string getName()
    {
        return name;
    }
    virtual string sound()
    {
        return "no sound";
    }
    string getAnimal()
    {
        cout << this->getName() << endl;
        return name + ": " + to_string(legs) + " legs / " + sound();
    }
protected:
    string name;
private:
    int legs;
};
class Dog : public Animal
{
public:
    Dog(string color) : Animal("Dog")
    {
        this->color = color;
    }
    string sound()
    {
        return "bark";
    }
    /*int getTotalLegs(Animal& a)
    {
        return a.legs + legs;
    }*/
    string getColor()
    {
        return color;
    }
private:
    string color;
};
class Chicken : public Animal
{
public:
    Chicken() : Animal("Chicken"), wings(2)
    {
        setLegs(2);
    }
    string sound()
    {
        return "bok";
    }
    int getWings()
    {
        return wings;
    }
    string getTotalName(Animal& a)
    {
        return name + " " + a.getName();
    }
    bool isAfraidOf(Animal a)
    {
        return a.getName() == "Dog";
    }
    string getAnimal()
    {
        return Animal::getAnimal() + " / " + to_string(wings) + " wings";
    }
private:
    int wings;
};

void main()
{
    Dog dog("yellow");
    cout << dog.getAnimal() << endl;
}