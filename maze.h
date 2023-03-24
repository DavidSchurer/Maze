//Name: David Schurer
//Class: CSS 342
//Assignment 3: Maze
#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <string>
using namespace std;

class Maze {

    public:

        // Maze constructor requiring a valid file name will initialize the maze object.
        explicit Maze(string mazeFile);

        // This overloaded output operator prints the maze to the output stream.
        friend ostream &operator<<(ostream &out, const Maze &maze);

        // The getRows and getColumns methods allow the creature class to access the private variables int rows and int columns
        // from the maze class.
        int getRows() const;
        int getColumns() const;

        // The getExitRow and getExitColumn methods allow the creature class to access the private variables int exitRow
        // and int exitColumn from the maze class.
        int getExitRow() const;
        int getExitColumn() const;

        // Methods to check if the specified row and column in the maze is either clear, a wall, a path, or visited.
        bool IsClear(int row, int column) const;
        bool IsWall(int row, int column) const;
        bool IsPath(int row, int column) const;
        bool IsVisited(int row, int column) const;
        
        // Method to check if the specified row and column in the maze is the exit.
        bool IsExit(int row, int column) const;

        // Marks the specific location as part of the path to the exit, is marked with an '*'.
        void MarkAsPath(int row, int column);

        // Marks the specific location that has already been visited with a '+'.
        void MarkAsVisited(int row, int column);

        // This method will mark the specific location in the maze as a clear spot that the creature can travel to.
        void MarkAsClear(int row, int column);

    private:

        // This is a 2D array of type char that will store the text representation of the array, it has a max size of 100x100
        char maze[100][100];

        // These integer variables store the rows and columns of the maze
        int rows;
        int columns;

        // These integer variables store the exit row and exit column of the maze
        int exitRow;
        int exitColumn;

};

#endif
