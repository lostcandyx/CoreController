#include "demo.h"

int main(int argc, char const *argv[])
{
    Plan *project = new Plan((char *)"project.txt");

    project->PrintAllLines();
}

/*
g++ -o demo ./src/demo.cpp -I ".\include\" -I ".\src\" -I ".\Quartic\"
*/