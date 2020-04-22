#pragma once

//#ifndef DATE_H
//#define DATE_H

#include <string>

namespace family {
    using namespace std;

    class Tree {
    public:
        string name;
        int count;
        Tree *father;
        Tree *mother;
        string gander;
        string related;

    public:
        Tree();

        ~Tree() {
            delete father;
            delete mother;
        }

        Tree(string name);

        int getDepth() {
            return this->count;
        }

        string getType() {
            return this->related;
        }

        string getName() {
            return this->name;
        }

//return pointer to the mother of the curr sub tree
        Tree *getMother() {
            return this->mother;
        }

// returns pointer to the father of the curr sub tree
        Tree *getFather() {
            return this->father;
        }

        Tree &addFather(string name, string relation);

        Tree &addMother(string name, string relation);

        void display();

        string relation(string relation);

        string find(string relation);

        void remove(string name);

        Tree *FindByName(Tree *cur, string name);

        Tree *FindByRelated(Tree *cur, string relation);

        void helpRemove(Tree *cur);

        void print(Tree *cur);

        string findrelated(Tree *p);
    };
}

//#endif