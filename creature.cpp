// Ruby Kaur
// CSS 342

#include "creature.h"

using namespace std;

ostream &operator<<(ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

// constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
  this->Row = Row;
  this->Col = Col;
}

// check if creature is at maze exit
// return true if at exit, false otherwise
bool Creature::atExit(const Maze &Maze) const {
  if (Row == Maze.getExitRow() && Col == Maze.getExitColumn()) {
    return true;
  }
  return false;
}

// solve maze recursively using depth first search
// param: Maze the maze object
// return a string representation of solution path
string Creature::solve(Maze &Maze) {
  string Path;

  // base case
  if (atExit(Maze)) {
    Maze.markAsPath(Row,Col);
    return "";
  } 

  Maze.markAsVisited(Row, Col);

  // TRY NORTH
  if (Maze.isClear(Row-1, Col)) {
    Path = goNorth(Maze) + solve(Maze);
    if (!Path.empty()) {
      Maze.markAsPath(Row,Col);
      return Path;
    }
    Maze.markAsVisited(Row, Col);
  } 

  // TRY EAST
  if (Maze.isClear(Row, Col+1)) {
    Path = goEast(Maze) + solve(Maze);
    if (!Path.empty()) {
      Maze.markAsPath(Row,Col);
      return Path;
    }  
    Maze.markAsVisited(Row, Col);
  }

  // TRY SOUTH
  if (Maze.isClear(Row+1, Col)) {
    Path = goSouth(Maze) + solve(Maze);
    if (!Path.empty()) {
      Maze.markAsPath(Row,Col);
      return Path;
    }
    Maze.markAsVisited(Row, Col);
  }

  // TRY WEST
  if (Maze.isClear(Row, Col-1)) {
    Path = goWest(Maze) + solve(Maze);
    if (!Path.empty()) {
      Maze.markAsPath(Row,Col);
      return Path;
    }
    Maze.markAsVisited(Row, Col);
  }

  Maze.markAsVisited(Row, Col);
  Maze.markAsPath(Row, Col);
  return "";
}

// move creature one cell to north and return direction
// param: Maze the maze object
// return: strign represenation of direction moved "N"
string Creature::goNorth(Maze &Maze) {
  Row--;
  return "N" + solve(Maze);
}

// move creature one cell to west and return direction
// param: Maze the maze object
// return: strign represenation of direction moved "W"
string Creature::goWest(Maze &Maze) {
  Col--;
  return "W" + solve(Maze);

}

// move creature one cell to east and return direction
// param: Maze the maze object
// return: strign represenation of direction moved "E"
string Creature::goEast(Maze &Maze) {
  Col++; 
  return "E" + solve(Maze);
}

// move creature one cell to south and return direction
// param: Maze the maze object
// return: strign represenation of direction moved "S"
string Creature::goSouth(Maze &Maze) {
  Row++;
  return "S" + solve(Maze);
} 
