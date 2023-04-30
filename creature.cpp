// Ruby Kaur
// CSS 342

#include "creature.h"



//prints out the creatures location coordinates
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "(" << Creature.Row << "," << Creature.Col << ")" << endl;
  return Out;
}

//constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
  this->Row = Row;
  this->Col = Col;
}

//if its at the exit colum and row
// returns true, if not false
bool Creature::atExit(const Maze &Maze) const {
  if (Maze.getExitColumn() == Col && Maze.getExitRow() == Row) {
    return true;
  }
  return false;
}


//needs maze to solve, will return a string 
string Creature::solve(Maze &Maze) {

  // if creature spawns on wall, throws invalid argument
  if (!Maze.isClear(Row, Col)) {
    throw invalid_argument("Invalid Creature Location");
  }

  //path with direction thats being returned.
  string Path;  

  //base case 
  //checks if creature is atExit already
  if (atExit(Maze)) {
    Maze.markAsPath(Row,Col);
    return "";

  }
  Maze.markAsPath(Row,Col);  // Mark the current spot as part of the path


  // check all four directions
  // north
  if (Maze.isClear(Row-1, Col)) {  
    Path = goNorth(Maze);
    if (atExit(Maze)) {
      return Path;
    }
    Row++;  // Backtrack
  } 

  //east
  if (Maze.isClear(Row, Col+1)) {  
    Path = goEast(Maze); 
    if (atExit(Maze)) {
      return Path;
    }
    Col--; // Backtrack
  } 

  //south
  if (Maze.isClear(Row+1, Col)) {  
    Path = goSouth(Maze);
    if (atExit(Maze)) {
      return Path;
    }
    Row--; // Backtrack
  }   

  //west
  if (Maze.isClear(Row, Col-1)) {  
    Path = goWest(Maze);
    if (atExit(Maze)) {
      return Path;
    }
    Col++; // Backtrack 
  } 

  // if none of the paths lead to the exit
  // mark this spot as visited
  Maze.markAsVisited(Row, Col);
  return "";
}


string Creature::goNorth(Maze &Maze) {
  Row = Row -1;
  return "N" + solve(Maze); 
}

string Creature::goEast(Maze &Maze) {
  Col = Col + 1;
  return "E" + solve (Maze);
}

string Creature::goSouth(Maze &Maze) {
  Row = Row + 1; 
  return "S" + solve(Maze); 
}

string Creature::goWest(Maze &Maze) {
  Col = Col - 1;
  return "W" + solve(Maze);
}
