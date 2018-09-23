#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "isaacvector.h"

using namespace std;

#define TEST true;

int runCatchTests(int agc, char* const argv[]){
    return Catch::Session().run();
}

void parseFile();

int main(int argc, char* argv[])
{
    if(strcmp (argv[1], "-t") == 0){
        Catch::Session().run();
    }
    else if(strcmp(argv[1],  "-r") == 0){

    }
    return 0;
}

parseFile(){

}
