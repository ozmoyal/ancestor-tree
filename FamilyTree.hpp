#pragma once

//#ifndef DATE_H
//#define DATE_H

#include <string>

namespace family{
    using namespace std;

    class Tree
{
public:
    string name;
    int count;
    Tree *father;
    Tree *mother;
    string gander;
    string related;

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
    Tree* Tree::FindByName(Tree *cur,string name);
     Tree* Tree::FindByRelated(Tree *cur,string relation);
    void Tree::helpRemove(Tree *cur);
    void print(Tree *cur);
    string Tree::findrelated(Tree* p);
};

//#endif