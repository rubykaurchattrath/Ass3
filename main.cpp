// Ruby Kaur
// CSS 342

#include <iostream>
#include <cassert>


#include "creature.h"
#include "maze.h"

void test() {
    Maze M("maze.txt");
    Creature C(4, 4);
    string result = C.solve(M);
    cout << "Path: " << result << endl;
    cout << M << endl;
    assert(result == "EEENNNEEEEEESEESSSEEENNNNN");

    Maze M1("maze1.txt");
    Creature C1(1, 1);
    string result1 = C1.solve(M1);
    cout << "Path: " << result1 << endl;
    cout << M1 << endl;
    assert(result1 == "SSEEENNE");

    Maze M2("maze2.txt");
    Creature C2(1, 1);
    string result2 = C2.solve(M2);
    cout << "Path: " << result2 << endl;
    cout << M2 << endl;
    assert(result2 == "SSEEESESESESWWWSSEEEEEEEEEENNNEEEEEEEEEEEEEEE");

    Maze M3("maze3.txt");
    Creature C3(6, 32);
    string result3 = C3.solve(M3);
    cout << "Path: " << result3 << endl;
    cout << M3 << endl;
    assert(result3 == "NWNWNNNWSSSSWNNNNWWWWWWWWWWWSWSWNWSWNWSSWNNWNWSWNWSWWWWNN");
}

int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}
