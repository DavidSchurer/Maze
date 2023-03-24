//Name: David Schurer
//Class: CSS 342
//Assignment 3: Maze
#include "creature.h"
#include <iostream>
#include <string>
using namespace std;

// Creature class constructor initializes a creature object with a starting row and column position.
// The Creature class constructor also initializes the mazePath string as an empty string.
Creature::Creature(int row, int column) {
    currentRow = row;
    currentColumn = column;
    mazePath = "";
}

// The overloaded output operator for the creature will print its current row and column position for each move it takes 
// as it traverses through the maze.
ostream &operator<<(ostream &out, const Creature &creature) {
    out << "C(" << creature.currentRow << "," << creature.currentColumn << ")";
    return out;
}

// IsValidMove checks to see if the move that will be made by the creature is valid.
bool Creature::IsValidMove(int row, int column, Maze &maze) {

   // Outer if statement checks to see if the move made by the creature is within a valid row of the maze.
   if (row >= 0 && row <= maze.getRows() - 1) {
        // Inner if statement checks to see if the move made by the creature is within a valid column of the maze.
        if (column >= 0 && column <= maze.getColumns() - 1) {
            return true; 
        }
   }

    // If the move made by the creature is not within the borders of the maze, return false.
   return false;

}
 
// MoveNorth moves the creature one spot to the north in the maze.
bool Creature::MoveNorth(Maze &maze) {
    
    bool hasFoundExit = false;

    // Checks if the move to the north is within the bounds of the maze.
    if (IsValidMove(currentRow - 1, currentColumn, maze)) {

        // Checks if the move to the north is a clear spot in the maze and has not been visited.
        if ((maze.IsClear(currentRow - 1, currentColumn)) && (!maze.IsVisited(currentRow - 1, currentColumn))) {

            // The creature moves one spot to the north.
            currentRow -= 1;
            mazePath += "N";
            maze.MarkAsPath(currentRow, currentColumn);

        // If the creature is at the exit of the maze, set
        // hasFoundExit to true.
        if (maze.IsExit(currentRow, currentColumn)) { 

            hasFoundExit = true;

        } else { // If the creature hasn't found the exit to the maze, try the other directions.

            hasFoundExit = MoveNorth(maze) || MoveWest(maze) || MoveEast(maze);

            // If the exit hasn't been found after attempting to move to the other directions, the creature must backtrack.
            if (!hasFoundExit) {

                // The creature will move back to its previous position and the space it was just at 
                // will be marked as visited.
                currentRow += 1;
                mazePath.substr(0, mazePath.size() - 1);
                maze.MarkAsVisited(currentRow, currentColumn);

          }
        }
      }
    }
    return hasFoundExit;
}

// MoveEast moves the creature one spot to the east in the maze.
bool Creature::MoveEast(Maze &maze) {
    
    bool hasFoundExit = false;

        // Checks if the move to the east is within the bounds of the maze.
        if (IsValidMove(currentRow, currentColumn + 1, maze)) {

        // Checks if the move to the east is clear and has not been visited.
        if ((maze.IsClear(currentRow, currentColumn + 1)) && (!maze.IsVisited(currentRow, currentColumn + 1))) {

            // The creature moves one spot to the east.
            currentColumn += 1;
            mazePath += "E";
            maze.MarkAsPath(currentRow, currentColumn);

        // If the creature is at the exit of the maze, set
        // hasFoundExit to true.
        if (maze.IsExit(currentRow, currentColumn)) {

            hasFoundExit = true;

        } else { // If the creature hasn't found the exit to the maze, try the other directions.

            hasFoundExit = MoveEast(maze) || MoveNorth(maze) || MoveSouth(maze);

            if (!hasFoundExit) {

                // The creature will move back to its previous position and the space it was just at
                // will be marked as visited.
                currentColumn -= 1;
                mazePath.substr(0, mazePath.size() - 1);
                maze.MarkAsVisited(currentRow, currentColumn);

          }
        }
      }
    }
    return hasFoundExit;          
}

// MoveSouth moves the creature one spot to the south in the maze.
bool Creature::MoveSouth(Maze &maze) {

    bool hasFoundExit = false;

    // Checks if the move to the south is within the bounds of the maze.
    if (IsValidMove(currentRow + 1, currentColumn, maze)) {

        // Checks if the move to the south is a clear spot in the maze and has not been visited.
        if ((maze.IsClear(currentRow + 1, currentColumn)) && (!maze.IsVisited(currentRow + 1, currentColumn))) {

            // The creature moves one spot to the south.
            currentRow += 1;
            mazePath += "S";
            maze.MarkAsPath(currentRow, currentColumn);

        // If the creature is at the exit of the maze, set
        // hasFoundExit to true.
        if (maze.IsExit(currentRow, currentColumn)) {

            hasFoundExit = true;

        } else { // If the creature hasn't found the exit to the maze, try the other directions.

            hasFoundExit = MoveSouth(maze) || MoveEast(maze) || MoveWest(maze);
            
            // If the exit hasn't been found after attempting to move to the other directions, the creature must backtrack.
            if (!hasFoundExit) {

                // The creature will move back to its previous position and the space it was just at
                // will be marked as visited.
                currentRow -= 1;
                mazePath.substr(0, mazePath.size() - 1);
                maze.MarkAsVisited(currentRow, currentColumn);

          }
        }
      }
    }  
    return hasFoundExit;
}

// MoveWest moves the creature one spot to the west in the maze.
bool Creature::MoveWest(Maze &maze) {

    bool hasFoundExit = false;

    // Checks if the move to the west is within the bounds of the maze.
    if (IsValidMove(currentRow, currentColumn -1, maze)) {

        // Checks if the move to the west is a clear spot in the maze and has not been visited.
        if ((maze.IsClear(currentRow, currentColumn - 1)) && (!maze.IsVisited(currentRow, currentColumn - 1))) {
            
            // The creature moves one spot to the west.
            currentColumn -= 1;
            mazePath += "W";
            maze.MarkAsPath(currentRow, currentColumn);
        
        // If the creature is at the exit of the maze, set
        // hasFoundExit to true.
        if (maze.IsExit(currentRow, currentColumn)) {

            hasFoundExit = true;

        } else { // If the creature hasn't found the exit to the maze, try the other directions.

            hasFoundExit = MoveWest(maze) || MoveNorth(maze) || MoveSouth(maze);

            // If the exit hasn't been found after attempting to move to the other directions, the creature must backtrack.
            if (!hasFoundExit) {

                // The creature will move back to its previous position and the space it was just at
                // will be marked as visited.
                currentColumn += 1;
                mazePath.substr(0, mazePath.size() - 1);
                maze.MarkAsVisited(currentRow, currentColumn);

          }
        }
      }
    }
    return hasFoundExit;
}

// The Solve method is the method that is used to solve the maze.
// It checks if the creature is at the exit of the maze, if it is not then
// it will call the MoveNorth, MoveEast, MoveSouth, and MoveWest methods to
// move the creature through the maze until it reaches the exit.
string Creature::Solve(Maze &maze) {

    // While the creature is not at the exit of the maze.
    if (!maze.IsExit(currentRow, currentColumn)) {

        // Check if the creature can move to the north, if true, call
        // the MoveNorth method.
        if (MoveNorth(maze)) {
            MoveNorth(maze);
        }

        // Check if the creature can move to the east, if true,
        // call the MoveEast method.
        if (MoveEast(maze)) {
            MoveEast(maze);
        }

        // Check if the creature can move to the south, if true,
        // call the MoveSouth method.
        if (MoveSouth(maze)) {
            MoveSouth(maze);
        }

        // Check if the creature can move to the west, if true,
        // call the MoveWest method.
        if (MoveWest(maze)) {
            MoveWest(maze);
        }
    }

    // If the creature was not able to reach the exit of the maze,
    // return "X".
    if (!maze.IsExit(currentRow, currentColumn)) {
        return "X";
    }

    // Return the string representation of the path the creature took to reach the exit of the maze.
    return mazePath;

}
