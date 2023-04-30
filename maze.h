// Ruby Kaur
// CSS 342

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  /**
  Output stream operator to display the maze.
  @param Out Output stream.
  @param Maze Maze object to display.
  @return The output stream.
  */
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  // max size of maze
  const static int MAX_SIZE = 100;
  // char array to store maze
  char Field[MAX_SIZE][MAX_SIZE];
  // width and height of maze
  int Width, Height;
  // row and column index of exit cell
  int ExitRow, ExitColumn; 

public:
  /**
  Maze constructor
  @param FileName Name of file containing maze to read
  */
  explicit Maze(const string &FileName);
  /*
  Check if cell at given coordinates is clear.
  @param Row Row index of cell.
  @param Col Column index of cell.
  @return True if the cell is clear, false otherwise.
  */
  bool isClear(int Row, int Col) const;
  /**
  Mark the cell at the given coordinates as part of the path.
  @param Row Row index of the cell.
  @param Col Column index of the cell.
  */
  void markAsPath(int Row, int Col);
  /**
  Mark the cell at given coordinates as visited.
  @param Row Row index of cell.
  @param Col Column index of cell.
  */
  void markAsVisited(int Row, int Col);
  /**
  Get the row index of the exit cell.
  @return The row index of the exit cell.
  */
  int getExitRow() const;
  /**
  Get the column index of the exit cell.
  @return The column index of the exit cell.
  */
  int getExitColumn() const;
};

#endif //ASS3_MAZE_H
