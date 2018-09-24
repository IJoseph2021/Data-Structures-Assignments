
#include "catch.hpp"
#include "isaacvector.h"

TEST_CASE("IsaacVector", "")
{
    IsaacVector <int> a(10);
    IsaacVector <int> b(15);
    IsaacVector <int> c(100);
    a.push_back(10);
    a.push_back(23);
    a.push_back(18);
    a.push_back(27);
    a.push_back(35);

    SECTION("Constructor"){
        REQUIRE(a.returnSize() == 5);
        REQUIRE(a.returnCapactiy() == 10);
        REQUIRE(b.returnSize() == 0);
        REQUIRE(b.returnCapactiy() == 15);
        REQUIRE(c.returnSize() == 0);
        REQUIRE(c.returnCapactiy() == 100);
    }


    SECTION("Overloaded Brackets"){
        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 23);
        REQUIRE(a[2] == 18);
        REQUIRE(a[3] == 27);
        REQUIRE(a[4] == 35);
    }

    SECTION("Push Back"){
        a.push_back(75);
        a.push_back(85);
        a.push_back(95);
        a.push_back(105);
        a.push_back(115);
        a.push_back(125);

        REQUIRE(a[5] == 75);
        REQUIRE(a[6] == 85);
        REQUIRE(a[7] == 95);
        REQUIRE(a[8] == 105);
        REQUIRE(a[9] == 115);
        REQUIRE(a[10] == 125);
        REQUIRE(a.returnSize() == 11);
        REQUIRE(a.returnCapactiy() == 20);
    }

    SECTION("Overloaded Assignment Operator"){
        c = a;
        b = a;
        REQUIRE(a[0] == c[0]);
        REQUIRE(a[1] == c[1]);
        REQUIRE(a[2] == c[2]);
        REQUIRE(a[3] == c[3]);
        REQUIRE(a[4] == c[4]);

        REQUIRE(a[0] == b[0]);
        REQUIRE(a[1] == b[1]);
        REQUIRE(a[2] == b[2]);
        REQUIRE(a[3] == b[3]);
        REQUIRE(a[4] == b[4]);
    }

    SECTION("Copy Constructor"){
        IsaacVector <int> e = a;
        REQUIRE(a[0] == e[0]);
        REQUIRE(a[1] == e[1]);
        REQUIRE(a[2] == e[2]);
        REQUIRE(a[3] == e[3]);
        REQUIRE(a[4] == e[4]);


    }

}
