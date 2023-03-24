//Name: David Schurer
//Class: CSS 342
//Assignment 3: Maze
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
#include "maze.h"
using namespace std;

class Creature {

    public:
    
        // The constructor for the creature class initializes a creature object with a starting row and column position
        Creature(int row, int column);

        // The solve method returns a string representation of the steps to reach the exit of the maze.
        // The string consists of the directions N for North, E for East, W for West, and, S for South.
        // If the creature can't reach the exit, this method returns "X".
        string Solve(Maze &maze);
        
        // The overloaded output operator prints the current location of the creature: C(row, column)
        friend ostream &operator<<(ostream &out, const Creature &creature);

        // These methods move the creature 1 position north, east, west, or south and return true if the creature
        // is able to make that move or false if it is not.
        bool MoveNorth(Maze &maze);
        bool MoveEast(Maze &maze);
        bool MoveWest(Maze &maze);
        bool MoveSouth(Maze &maze);
        
    private:

        // The private variables currentRow and currentColumn store the creature's current row and column position.
        int currentRow;
        int currentColumn;

        // The string variable mazePath will be used to store the string representation of the path the
        // creature took to traverse to the exit of the maze (Example: NNEESW) N = North, E = East, W = West, S = South
        string mazePath;

        // IsValidMove returns true if the creature can move to the specified location or false if it cannot, it
        // checks that if the move is within the bounds of the maze
        bool IsValidMove(int row, int column, Maze &maze);

};

#endif
