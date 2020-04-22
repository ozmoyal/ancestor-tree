#include <iostream>
#include <string>
#include <cstring>
#include "FamilyTree.hpp"

using namespace std;

namespace family {

    Tree::Tree(string name) {
        this->name = name;
        this->father = nullptr;
        this->mother = nullptr;
        this->count = 0;
    }


    /*Tree &Tree::addFather(string name, string fatherName) {
        Tree *p = FindByName(this, name);
        if (p == nullptr) throw runtime_error("ERR  " + name + "dosen't exiest");
        else if (p->father != nullptr) throw runtime_error("ERR  " + name + "have a father");
        else {
            p->father = new Tree(fatherName);
            p->count = p->father->count + 1;
            p->related = findrelated(p);
            p->gander = "male";
            return *this;
        }
    }

    Tree &Tree::addMother(string name, string motherName) {
        Tree *p = FindByName(this, name);
        if (p == nullptr) throw runtime_error("ERR  " + name + "dosen't exiest");
        else if (p->father != nullptr) throw runtime_error("ERR  " + name + "have a mother");
        else {
            p->mother = new Tree(motherName);
            p->count = p->mother->count + 1;
            p->related = findrelated(p);
            p->gander = "female";
            return *this;
        }
    }*/

    Tree &Tree::addFather(string from, string fatherName) {
        Tree *curr = FindByName(this, from);
        if (curr != nullptr) {
            if (curr->father == nullptr) {
                curr->father = new Tree(fatherName);
                curr->father->count = curr->count + 1;
                curr->father->related = "father";
            } else {
                string test = "'" + from + "' Allready have a father";
                throw invalid_argument(test);
            }
        } else {
            string test = "Could'nt find '" + from + "'";
            throw invalid_argument(test);
        }
        return *this;
    }

    Tree &Tree::addMother(string name, string motherName) {
        Tree *curr = FindByName(this, name);
        if (curr != nullptr) {
            if (curr->mother == nullptr) {
                curr->mother = new Tree(motherName);
                curr->mother->count = curr->count + 1;
                curr->mother->related = "mother";
            } else {
                string test = "'" + name + "' Allready have a mother";
                throw invalid_argument(test);
            }
        } else {
            string test = "Could'nt find '" + name + "'";
            throw invalid_argument(test);
        }
        return *this;
    }

    void Tree::display() {
        Tree *p = this;
        print(p);


    }

    /*string Tree::relation(string name) {
        Tree *p = FindByName(this, name);
        if (p == nullptr) return "unrelated";
        return p->related;

    }*/

    string Tree::relation(string rel) {
        Tree *ans = FindByName(this, rel);
        string result = "";
        if (ans == nullptr) {
            return "unrelated";
        }
        if (ans->count == 0) {
            return "me";
        }
        if (ans->related == "father") {
            result = "father";
            for (int i = 1; i <= ans->count; i++) {
                if (i == 2) {
                    result = "grand" + result;;
                } else if (i > 2) {
                    result = "great-" + result;
                }
            }
        } else {
            result = "mother";
            for (int i = 1; i <= ans->count; i++) {
                if (i == 2) {
                    result = "grand" + result;;
                } else if (i > 2) {
                    result = "great-" + result;
                }
            }
        }
        return result;
    }


    /*string Tree::find(string relation) {
        Tree *p = FindByRelated(this, relation);
        if (p == nullptr) throw runtime_error("ERR  " + relation + "dosen't exiest");
        return p->name;
    }*/

    Tree *findAtDepth(Tree *t, int depth, string what) {
        if (t == nullptr) {
            return nullptr;
        }
        if (what == t->getType() && t->getDepth() == depth) {
            return t;
        } else {
            Tree *f = findAtDepth(t->getFather(), depth, what);
            if (f != nullptr) {
                return f;
            }
            Tree *m = findAtDepth(t->getMother(), depth, what);
            if (m != nullptr) {
                return m;
            }
        }
        return nullptr;
    }

    string Tree::find(string relation) {
        if (relation == " ") throw invalid_argument("empty");
        int searchDepth = 0;
        string what;
        int counter = 0;
        if ((relation.find_first_not_of(' ') != string::npos)) {
            char *cstrText = new char[relation.length() + 1];
            strcpy(cstrText, relation.c_str());
            char *test;
            test = strtok(cstrText, "-");

            while (test != nullptr) {
                counter++;
                test = strtok(nullptr, "-");
            }
            if (counter == 1) {
                if (relation == "me") {
                    return this->name;
                }
                if (relation == "mother") {
                    if (this->mother != NULL) {
                        return this->mother->name;
                    } else {
                        string test = "Can't handle " + relation;
                        throw invalid_argument(test);
                    }
                }
                if (relation == "father") {
                    if (this->father != NULL) {
                        return this->father->name;
                    } else {
                        string test = "Can't handle " + relation;
                        throw invalid_argument(test);
                    }
                }
                if (relation == "grandmother" || relation == "grandfather") {
                    searchDepth = 2;
                    size_t pos = relation.find("grand");
                    what = relation.substr(pos + 5);
                } else {
                    string test = "Can't handle " + relation;
                    throw invalid_argument(test);
                }
                Tree *ans = findAtDepth(this, searchDepth, what);
                if (ans == nullptr) {
                    string test = "Can't handle " + relation;
                    throw invalid_argument(test);
                } else {
                    return ans->getName();
                }
            }
            if (counter > 1) {
                searchDepth = counter + 1;
                size_t pos = relation.find("grand");
                if (pos == string::npos || pos == 0) {
                    string test = "Can't handle " + relation;
                    throw invalid_argument(test);
                }
                what = relation.substr(pos + 5);
                Tree *ans = findAtDepth(this, searchDepth, what);
                if (ans == nullptr) {
                    string test = "Can't handle " + relation;
                    throw invalid_argument(test);
                } else {
                    return ans->getName();
                }
            } else {
                string test = "Can't handle " + relation;
                throw invalid_argument(test);
            }
        } else {
            return "Can't handle empty names";
        }
    }

    Tree *Tree::FindByName(Tree *cur, string name) {
        /*if (cur->name == name) return cur;
        if (cur->mother != nullptr) {
            Tree *ans = FindByName(cur->mother, name);
            if (ans != nullptr) return ans;
        }
        if (cur->father != nullptr) {
            Tree *ans = FindByName(cur->father, name);
            if (ans != nullptr) return ans;
        }
        return nullptr;*/

        if (cur == nullptr) {
            return nullptr;
        }
        if (name == cur->name) {
            return cur;
        } else {
            Tree *f = FindByName(cur->father, name);
            if (f != nullptr) {
                return f;
            }
            Tree *m = FindByName(cur->mother, name);
            if (m != nullptr) {
                return m;
            }
        }
        return nullptr;
    }

    Tree *Tree::FindByRelated(Tree *cur, string related) {
        if (cur->related == related) return cur;
        if (cur->mother != nullptr) {
            Tree *ans = FindByRelated(cur->mother, related);
            if (ans != nullptr) return ans;
        }
        if (cur->father != nullptr) {
            Tree *ans = FindByRelated(cur->father, related);
            if (ans != nullptr) return ans;
        }
        return nullptr;
    }

    /*void Tree::helpRemove(Tree *cur) {
        if (cur == nullptr)
            return
                    helpRemove(cur->father);
        helpRemove(cur->mother);

        cur = nullptr;
    }

    void Tree::remove(string name) {
        Tree *p = FindByName(this, name);
        if (p == nullptr) throw runtime_error("ERR  " + name + "dosen't exiest");
        helpRemove(p);
    }*/

    Tree *removeHelper(string name, Tree *t) {
        if (t != nullptr) {
            if (t->father != nullptr) {
                if (name == t->father->getName()) {
                    return t;
                }
            }
            if (t->mother != nullptr) {
                if (name == t->getMother()->getName()) {
                    return t;
                }
            }

            Tree *f = removeHelper(name, t->getFather());
            if (f != nullptr) {
                return f;
            }
            Tree *m = removeHelper(name, t->getMother());
            if (m != nullptr) {
                return m;
            }
            return nullptr;
        }
        return nullptr;
    }

    void Tree::remove(string name) {

        Tree *curr = removeHelper(name, this);
        //cout << curr->name;
        if (curr) {
            if (curr->father != nullptr) {
                if (curr->father->name == name) {
                    delete curr->father;
                    curr->father = nullptr;
                    return;
                }
            }
            if (curr->mother != nullptr) {
                if (curr->mother != nullptr) {
                    delete curr->mother;
                    curr->mother = nullptr;
                    return;
                }
            }

        } else {
            string test = "Can't handle " + name;
            throw invalid_argument(test);
        }
    }

    void Tree::print(Tree *cur) {
        if (cur == nullptr) return;
        print(cur->father);
        print(cur->mother);
        printf("--->,%s", cur->name.c_str());
    }

    /*string Tree::findrelated(Tree *p)
        {
            if (p->count == 0) return "me";
            if ((p->count) == 1) {
                if (p->gander == "male") return "father";
                else return "mather";
            }
            string ans = "";
            int i = p->count;
            while (i >= 2) {
                ans = ans + "great- ";
                i--;
            }
            if (p->gander == "male") ans = ans + "grandfather";
            else return ans = ans + "grandmather";
            return ans;

        }*/
};