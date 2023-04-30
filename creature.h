// Ruby Kaur
// CSS 342

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  /**
  * Ostream operator to display creature's location coordinates
  * @param Out the output stream
  * @param Creature the creature to print
  * @return the output stream with the printed creature's location coordinates
  */
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row; // row of creature's current location
  int Col; // column of creature's current location

public:
  /**
  Constructor
  @param Row the row coordinate of the Creature's starting position
  @param Col the column coordinate of the Creature's starting position
  */
  Creature(int Row, int Col);

  /**
  Creature recursively tries to go north, east, south, &
  west from current position until it finds exit. 
  Marks the path that it takes.
  Backtracks when it reaches a dead end.
  @param Maze the Maze object that creature is trying to solve
  @return the path that creature takes to reach the exit
  */
  string solve(Maze &Maze);

  /**
  Checks if creature is at exit position in maze
  @param Maze the Maze object that creature is trying to solve
  @return true if creature is at the exit, false otherwise
  */
  bool atExit(const Maze &Maze) const;

  /**
  Moves creature north in maze 
  Marks current position as part of path
  @param Maze the Maze object that creature is trying to solve
  @return "N" to indicate that creature moved north
  */
  string goNorth(Maze &Maze);

  /**
  Moves creature south in maze 
  Marks current position as part of path
  @param Maze the Maze object that creature is trying to solve
  @return "S" to indicate that creature moved south
  */
  string goSouth(Maze &Maze);

  /**
  Moves creature east in maze 
  Marks current position as part of path
  @param Maze the Maze object that creature is trying to solve
  @return "E" to indicate that creature moved east
  */
  string goEast(Maze &Maze);

  /**
  Moves creature west in maze 
  Marks current position as part of path
  @param Maze the Maze object that creature is trying to solve
  @return "W" to indicate that creature moved west
  */
  string goWest(Maze &Maze);
};

#endif //ASS3_CREATURE_H
