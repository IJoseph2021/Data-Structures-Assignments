#include "catch.hpp"
#include "doublelinkedlist.h"
#include "node.h"
//#include "stack.h"
#include "adjacencylist.h"

TEST_CASE("DoubleLinkedList and Stack and AdjacentList", "")
{
    DoubleLinkedList<int> a;

    SECTION("Constructor Test"){
        REQUIRE(a.returnSize() == 0);

    }


    SECTION("InsertFront Test"){
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

    SECTION("RemoveFront Test"){
        a.removeFront();
        REQUIRE(a.returnSize()==4);
    }

    SECTION("InsertBack Test"){
        a.insertBack(120);
        a.insertBack(125);
        a.insertBack(130);

        REQUIRE(a[6] == 120);
        REQUIRE(a[7] == 125);
        REQUIRE(a[8] == 130);

    }

    SECTION("Insert at Position Test"){
        a.insertAtIndex(6, 127);
        a.insertAtIndex(7, 135);
        //a.insertAtIndex(0, 0);
        REQUIRE(a[6] == 127);
        REQUIRE(a[7] == 135);



    }

}
