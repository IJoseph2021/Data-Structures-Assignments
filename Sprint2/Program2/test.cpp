
#include "catch.hpp"
#include "isaacvector.h"

TEST_CASE("IsaacVector", "")
{
    IsaacVector <int> a(10);
    a.push_back(10);
    a.push_back(23);
    a.push_back(18);
    a.push_back(27);
    a.push_back(35);

    SECTION("Constructor"){
        REQUIRE(a[0] == 10);
        REQUIRE(a[1] == 23);
        REQUIRE(a[2] == 18);
        REQUIRE(a[3] == 27);
        REQUIRE(a[4] == 35);
        REQUIRE(a.returnSize() == 5);
        REQUIRE(a.returnCapactiy() == 10);
    }

    //SECTION("")
}
