

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;

TEST_CASE("add father") {
   Tree M("mika");
   M.addFather("mika","Yitzak").addFather("Yitzak","Israel").addFather("Israel","Yaakov");
      CHECK((tree.head->father->name).compare("Yitzak") == 0);
    CHECK((tree.head->father->father->name).compare("Israel") == 0);
   CHECK((tree.head->father->father->father->name).compare("Yaakov") == 0);

}
TEST_CASE("add father") {
   Tree M("mika");
   M.addMother("mika","Stella").addFather("Stella","Michal").addFather("Michal","Tehila");
    CHECK((tree.head->mother->name).compare("Stella") == 0);
    CHECK((tree.head->mothe->mothe->name).compare("Michal") == 0);
   CHECK((tree.head->mothe->mothe->mothe->name).compare("Tehila") == 0);

}

TEST_CASE("check find")
{
    Tree M("Mika");
    M.addFather("Mika", "Yitzak").addFather("Yitzak", "Israel")
     .addFather("Israel", "Avraham") .addMother("Israel", "Pnina")	    
     .addMother("Mika", "Stella").addMother("Stella","Michal").addFather("Stella","Yaakov") 
     .addMother("Yitzak","Tamar").addFather("Tamar","Meir").addMother("Tamar","Hana");
	M.display();
    CHECK(M.find("me") == string("Mika"));
    CHECK(M.find("mother") == string("Stella"));
    CHECK(M.find("father") == string("Yitzak"));
    CHECK(T.find("grandfather") == string("Israel"));
    CHECK(T.find("grandfather") == string("Yaakov"));
    CHECK(T.find("grandmother") == string("Tamar"));
    CHECK(T.find("grandmother") == string("Michal"));
    CHECK(T.find("great-grandmother") == string("Pnina"));
    CHECK(T.find("great-grandmother") == string("Hana"));
    CHECK(T.find("great-grandfather") ==string( "Meir"));
    CHECK(T.find("great-grandfather") == string("Avraham"));	
}

TEST_CASE("check relation")
{
    Tree M("Mika");
    M.addFather("Mika", "Yitzak").addFather("Yitzak", "Israel")
     .addFather("Israel", "Avraham") .addMother("Israel", "Pnina")	    
     .addMother("Mika", "Stella").addMother("Stella","Michal").addFather("Stella","Yaakov") 
     .addMother("Yitzak","Tamar").addFather("Tamar","Meir").addMother("Tamar","Hana");
	M.display();
     CHECK(M.frelation("Mika") == string("me"));
    CHECK(M.relation("Yitzak") == string("father"));
    CHECK(T.relation("Israel") == string("grandfather"));
    CHECK(T.relation("Yaakov") == string("grandfather"));
    CHECK(T.frelation("Tamar") == string("grandmother"));
    CHECK(T.relation("Michal") == string("grandmother"));
    CHECK(T.relation("Pnina") == string("great-grandmother"));
    CHECK(T.relation("Hana") == string("great-grandmother"));
    CHECK(T.relation("Meir") ==string( "great-grandfather"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    //27
}	

TEST_CASE("Tree")
{
  Tree T("Stav");
  T.addMother("Stav","Tal").addFather("Stav","Yitzak");
  T.addMother("Tal","Michal").addMother("Michal","Tehila").addMother("Tehila","Yaffa").addFather("Tehila","Yehoda");
  T.addFather("Michal","Meir").addMother("Meir","Tamar").addFather("Meir","Yossef");
  T.addFather("Tal","Avraham").addFather("Avraham","Shoshana").addFather("Avraham","Michael").addMother("Shoshana","Ester");
  T.addMother("Yitzak","Bat-Zehav").addFather("Yitzak","Israel").addFather("Israel","David").addMother("Israel","Pnina");
  T.display();
     CHECK(T.find("me") == string("Stav"));
    CHECK(T.find("mother") == string("Tal"));
    CHECK(T.find("father") == string("Yitzak"));
    CHECK(T.find("grandfather") == string("Israel"));
    CHECK(T.find("grandfather") == string("Avraham"));
    CHECK(T.find("grandmother") == string("Bat-Zehav"));
    CHECK(T.find("grandmother") == string("Michal"));
    CHECK(T.find("great-grandmother") == string("Pnina"));
    CHECK(T.find("great-grandmother") == string("Tehila"));
       CHECK(T.find("great-grandmother") == string("Shoshana"));
    CHECK(T.find("great-grandfather") ==string( "Meir"));
    CHECK(T.find("great-grandfather") == string("Michael"));	
        CHECK(T.find("great-great-grandmother") == string("Ester"));	
     CHECK(T.find("great-great-grandmother") == string("Tamar"));	
  CHECK(T.find("great-great-grandmother") == string("Yaffa"));
   CHECK(T.find("great-great-grandfather") == string("Yehoda"));	
    CHECK(T.find("great-great-grandfather") == string("Yossef"));	
      CHECK(T.find("great-great-great-grandfather") == string("ERR"));	


     CHECK(T.relation("Stav") == string("me"));
    CHECK(T.relation("Tal") == string("mother"));
    CHECK(T.relation("Yitzak") == string("father"));
    CHECK(T.relation("Israel") == string("grandfather"));
    CHECK(T.relation("Avraham") == string("grandfather"));
    CHECK(T.relation("Bat-Zehav") == string("grandmother"));
    CHECK(T.relation("Michal") == string("grandmother"));
    CHECK(T.relation("Pnina") == string("great-grandmother"));
    CHECK(T.relation("Tehila") == string("great-grandmother"));
       CHECK(T.relation("Shoshana") == string("great-grandmother"));
    CHECK(T.relation("Meir") ==string("great-grandfather"));
    CHECK(T.relation("Michael") == string("great-grandfather"));	
        CHECK(T.relation("Ester") == string("great-great-grandmother"));	
     CHECK(T.relation("Tamar") == string("great-great-grandmother"));	
  CHECK(T.relation("Yaffa") == string("great-great-grandmother"));
   CHECK(T.relation("Yehoda") == string("great-great-grandfather"));	
    CHECK(T.relation("Yossef") == string("great-great-grandfather"));
      CHECK(T.relation("Noam") == string("unrelated"));	
    CHECK(T.relation("Shirel") == string("unrelated"));
//64
}

    









