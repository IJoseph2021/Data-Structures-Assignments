#include "catch.hpp"
#include "doublelinkedlist.h"
#include "node.h"
#include "stack.h"
#include "adjacencylist.h"

TEST_CASE("DoubleLinkedList and Stack and AdjacentList", "")
{
    DoubleLinkedList<int> a;
    DoubleLinkedList<int> c(3);

    SECTION("DDL:Constructor Test and Return Size"){
        REQUIRE(a.returnSize() == 0);
        REQUIRE(c.returnSize() == 1);
    }


    SECTION("DDL:InsertFront Test"){
        a.insertFront(75);
        a.insertFront(85);
        a.insertFront(95);
        a.insertFront(105);
        a.insertFront(115);
        REQUIRE(a[5] == 75);
        REQUIRE(a[4] == 85);
        REQUIRE(a[3] == 95);
        REQUIRE(a[2] == 105);
        REQUIRE(a[1] == 115);
        REQUIRE(a.returnSize() == 5);
    }

   SECTION("DDL:RemoveFront Test"){
       a.insertFront(75);
       a.insertFront(85);
       a.insertFront(95);
       a.insertFront(105);
       a.insertFront(115);
       a.removeFront();

       REQUIRE(a[1] == 105);
       REQUIRE(a[2] == 95);
       REQUIRE(a[3] == 85);
       REQUIRE(a[4] == 75);
       REQUIRE(a.returnSize()==4);
   }

   SECTION("DDL:RemoveBack Test"){
       a.insertFront(75);
       a.insertFront(85);
       a.insertFront(95);
       a.insertFront(105);
       a.insertFront(115);
       a.removeBack();

       REQUIRE(a[4] == 85);
       REQUIRE(a[1] == 115);
       REQUIRE(a[2] == 105);
       REQUIRE(a[3] == 95);
       REQUIRE(a.returnSize()==4);
   }


   SECTION("DDL:InsertBack Test"){
       a.insertBack(120);
       a.insertBack(125);
       a.insertBack(130);
       REQUIRE(a[1] == 120);
       REQUIRE(a[2] == 125);
       REQUIRE(a[3] == 130);
    }

   SECTION("DDL:Insert at Position Test"){
       a.insertBack(120);
       a.insertBack(125);
       a.insertBack(130);
       a.insertAtIndex(1, 127);
       a.insertAtIndex(2, 120);
       REQUIRE(a[1] == 127);
       REQUIRE(a[2] == 120);
    }

   SECTION("DDL:Copy Constructor Test"){
       a.insertBack(120);
       a.insertBack(125);
       a.insertBack(130);
       a.insertBack(140);
       DoubleLinkedList <int> b(a);
       REQUIRE(b[1] == 120);
       REQUIRE(b.returnSize() == 4);
    }


   SECTION("DDL:Assignemnt operator Test"){
       a.insertBack(120);
       a.insertBack(125);
       a.insertBack(130);
       a.insertBack(140);
       DoubleLinkedList <int> d = a;
       REQUIRE(d[1] == 120);
       REQUIRE(d.returnSize() == 4);
   }

   SECTION("DDL:Return Iterator"){
       a.insertFront(120);
       a.insertFront(125);
       a.insertFront(130);
       a.insertFront(140);

       int i = a.returnIterator();
       REQUIRE(i == 140);
   }
   SECTION("DDL:Step Iterator"){
       a.insertFront(120);
       a.insertFront(125);
       a.insertFront(130);
       a.insertFront(140);
       a.stepIterator();
       int i = a.returnIterator();
       REQUIRE(i == 130);
   }
   SECTION("DDL:Reset Iterator"){
       a.insertFront(120);
       a.insertFront(125);
       a.insertFront(130);
       a.insertFront(140);
       a.stepIterator();
       int b = a.returnIterator();
       REQUIRE(b == 130);
       a.resetIterator();
       int i = a.returnIterator();
       REQUIRE(i == 140);
   }
   SECTION("DDL:Check if Iter Null"){
       a.insertFront(120);
       a.insertFront(125);
       a.insertFront(130);
       a.insertFront(140);
       a.stepIterator();
       int b = a.returnIterator();
       REQUIRE(b == 130);
       a.stepIterator();
       a.stepIterator();
       a.stepIterator();
       REQUIRE(a.iterNull() == true);
   }

   SECTION("AdjecencyList: ReturnList and Insert For"){
       AdjacencyList <string> p;
       string b[] = {"David", "Cheryl", "David"};
       string d[] = {"Brad", "Brad", "Cheryl"};
       for(int i =0; i<3; i++){
            p.insertFor(b[i], d[i]);
            p.insertFor(d[i], b[i]);
       }
       string x = p.returnList("David")[1];
       string y = p.returnList("Cheryl")[1];
       string z = p.returnList("Brad")[1];
       REQUIRE(x == "David");
       REQUIRE(y == "Cheryl");
       REQUIRE(z == "Brad");
       x = p.returnList("David")[2];
       y = p.returnList("Cheryl")[3];
       z = p.returnList("Brad")[2];
       REQUIRE(x == "Brad");
       REQUIRE(y == "David");
       REQUIRE(z == "David");
   }

   SECTION("AdjecencyList: Bracket Operator"){
       AdjacencyList <string> p;
       string b[] = {"David", "Cheryl", "David"};
       string d[] = {"Brad", "Brad", "Cheryl"};
       for(int i =0; i<3; i++){
            p.insertFor(b[i], d[i]);
            p.insertFor(d[i], b[i]);
       }
       string x = p[1][1];
       string y = p[2][1];
       string z = p[3][1];
       REQUIRE(x == "David");
       REQUIRE(y == "Brad");
       REQUIRE(z == "Cheryl");
   }

   SECTION("AdjecencyList: Size operator"){
       AdjacencyList <string> p;
       string b[] = {"David", "Cheryl", "David"};
       string d[] = {"Brad", "Brad", "Cheryl"};
       for(int i =0; i<3; i++){
            p.insertFor(b[i], d[i]);
            p.insertFor(d[i], b[i]);
       }
       REQUIRE(p.returnSize() == 3);
   }

   SECTION("Stack: Push Test and Size test"){
        Stack <string> holder;
        REQUIRE(holder.returnCount() == 0);
   }

   SECTION("Stack: Push Test and Size test"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       REQUIRE(holder.returnCount() == 3);
   }
   SECTION("Stack: Push Test and Return Top Test"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       REQUIRE(holder.returnTop() == "c");
   }
   SECTION("Stack: Pop test"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       string g = holder.pop();
       string l = holder.pop();
       REQUIRE(g == "c");
       REQUIRE(l == "b");
       REQUIRE(holder.returnCount() == 1);
   }

   SECTION("Stack: Pop test"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       string g = holder.pop();
       string l = holder.pop();
       REQUIRE(g == "c");
       REQUIRE(l == "b");
       REQUIRE(holder.returnCount() == 1);
   }

   SECTION("Stack: Search Stack"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       REQUIRE(holder.searchStack("a") == true);
       REQUIRE(holder.searchStack("d") == false);
   }

   SECTION("Stack: isEmpty"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       REQUIRE(holder.isEmpty() == false);
       string x;
       x = holder.pop();
       x = holder.pop();
       x = holder.pop();
       REQUIRE(holder.isEmpty() == true);
   }
   SECTION("Stack: isEmpty"){
       Stack <string> holder;
       holder.push("a");
       holder.push("b");
       holder.push("c");
       holder.clearStack();
       REQUIRE(holder.isEmpty() == true);
   }

}
