#pragma once

//#ifndef DATE_H
//#define DATE_H

#include <string>

namespace family{
    using namespace std;
    class Tree
{
private:
    string name;
    int count;
    Tree *father;
    Tree *mother;

public:
    Tree();
    ~Tree()
    {
        delete father;
        delete mother;
    }
    Tree(string name);
    Tree &addFather(string name , string relation);
    Tree &addMother(string name , string relation);
    void display();
    string relation(string relation);
    string find(string relation);
    void remove(string name);
};

}

//#endif