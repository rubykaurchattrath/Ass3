#include <iostream>

#include "creature.h"
#include "maze.h"
#include <cassert>

void test() {
    Maze M("maze.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    assert(C.solve(M) == "EEENNNEEEEEESEESSSEEENNNNN");

    // Test if program can backtrack
    Maze M1("maze1.txt");
    // cout << m << endl;
    Creature C1(4, 11);
    cout << "Path: " << C1.solve(M1) << endl;
    cout << M1 << endl;
    assert(C1.solve(M1) == "WWWWWNNNEESSSEEE");
   
    // Test if program can handle maze with no exit
    // Output should be empty
    Maze M2("maze2.txt");
    // cout << m << endl;
    Creature C2(1, 3);
    cout << "Path: " << C2.solve(M2) << endl;
    cout << M2 << endl;
    assert(C2.solve(M2).empty());

    Maze M3("maze3.txt");
    // cout << m << endl;
    Creature C3(3, 11);
    cout << "Path: " << C3.solve(M3) << endl;
    cout << M3 << endl;
    assert(C3.solve(M3).empty());

}

int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}
