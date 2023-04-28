// Ruby Kaur
// CSS342
// April 19, 2023

#include "creature.h"

//CHANGE THIS
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  return Out;
}

Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

bool Creature::atExit(const Maze &Maze) const {
  if (Row == Maze.getExitRow() && Col == Maze.getExitColumn()) {
    return true;
  }
  return false;
}

string Creature::solve(Maze &Maze) {

  //path with direction thats being returned.
  string Path;

  //base case 
  //checks if creature is atExit already
  if (atExit(Maze)) {
    return "";
  }

  //North
  if (Maze.isClear(Row-1, Col)) {
    Path += goNorth(Maze); //returns whatever string to Path
    Maze.markAsPath(Row-1, Col); //the curr
    solve(Maze);
  } 

  //east
  if (Maze.isClear(Row, Col+1)) {
    Path += goEast(Maze); //returns whatever string to Path
    Maze.markAsPath(Row, Col+1); //the curr
    solve(Maze);
  } 


  //south
  if (Maze.isClear(Row+1, Col)) {
    Path += goSouth(Maze); //returns whatever string to Path
    Maze.markAsPath(Row+1, Col); //the curr
    solve(Maze);
  } 

  // west 
  if (Maze.isClear(Row, Col-1)) {
    Path += goWest(Maze); //returns whatever string to Path
    Maze.markAsPath(Row, Col-1); //the curr
    solve(Maze); //resurively
  }

  //backtracking
  Maze.markAsVisited(Row,Col);


  return Path; //returning the path will go thru the process again, 
  //you dont have to recursively call it. itll go thru the NESW process again 
}

string Creature::goNorth(Maze &Maze) {
  if (Row > 0 && Maze.isClear(Row - 1, Col)) {
    Maze.markAsPath(Row, Col);
    Maze.markAsVisited(Row, Col);
    --Row;
    return "N";
  }
  return "X";
}

string Creature::goWest(Maze &Maze) {
  if (Col > 0 && Maze.isClear(Row, Col - 1)) {
    Maze.markAsPath(Row, Col);
    Maze.markAsVisited(Row, Col);
    --Col;
    return "W";
  }
  return "X";
}

string Creature::goEast(Maze &Maze) {
  if (Col < Maze.Width - 1 && Maze.isClear(Row, Col + 1)) {
    Maze.markAsPath(Row, Col);
    Maze.markAsVisited(Row, Col);
    ++Col;
    return "E";
  }
  return "X";
}

string Creature::goSouth(Maze &Maze) {
  if (Row < Maze.Height - 1 && Maze.isClear(Row + 1, Col)) {
    Maze.markAsPath(Row, Col);
    Maze.markAsVisited(Row, Col);
    ++Row;
    return "S";
  }
  return "X";
}
