//Name: David Schurer
//Class: CSS 342
//Assignment 3: Maze
#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// The maze constructor reads in from the maze text file using ifstream and creates
// a temp string which will store the string representation of the maze text file.
Maze::Maze(string mazeSimple) {
    
    ifstream mazeFile;
    mazeFile.open(mazeSimple);
    mazeFile >> columns;
    mazeFile >> rows;
    mazeFile >> exitRow;
    mazeFile >> exitColumn;
    
    // Read the maze into the 2D array
    string skipLine;
    getline(mazeFile, skipLine);

    char mazeValue;
    for (int i = 0; i < rows; i++) {

        string temp;
        getline(mazeFile, temp);
        
        for (int j = 0; j < columns; j++) {
            maze[i][j] = temp[j];
        }
    }
    mazeFile.close();

}

// getRows method allows the creature class to access the private data member rows.
int Maze::getRows() const {

    return rows;

}

// getColumns method allows the creature class to access the private data member columns.
int Maze::getColumns() const {
    return columns;
}

// getExitRow method allows the creature class to access the private data member exitRow.
int Maze::getExitRow() const {
    return exitRow;
}

// getExitColumn method allows the creature class to access the private data member exitColumn.
int Maze::getExitColumn() const {
    return exitColumn;
}

// Method to check if the row and column of the maze is an empty space.
bool Maze::IsClear(int row, int column) const {

    if(maze[row][column] == ' ') {
        return true;
    } else {
        return false;
    }

}

// Method to check if the row and column of the maze is a wall.
bool Maze::IsWall(int row, int column) const {

    if(maze[row][column] == 'x' || maze[row][column] == 'X') {
        return true;
    } else {
        return false;
    }

}

// Method to check if the row and column of the maze is part of the path to the exit.
bool Maze::IsPath(int row, int column) const {

    if(maze[row][column] == '*') {
        return true;
    } else {
        return false;
    }

}

// Method to check if the row and column of the maze has been visited by the creature.
bool Maze::IsVisited(int row, int column) const {

    if(maze[row][column] == '+') {
        return true;
    } else {
        return false;
    }

}

// Method to check if the row and column of the maze is the exit.
bool Maze::IsExit(int row, int column) const {

    if ((row == exitRow) && (column == exitColumn)) {
        return true;
    } else {
        return false;
    }

}

// Method to mark the specified row and column of the maze as part of the path to the exit.
void Maze::MarkAsPath(int row, int column) {

    maze[row][column] = '*';

}

// Method to mark the specified row and column of the maze that the creature has visited.
void Maze::MarkAsVisited(int row, int column) {

    maze[row][column] = '+';

}

// Method to mark the specified row and column of the maze as clear.
void Maze::MarkAsClear(int row, int column) {

    maze[row][column] = ' ';

}

// The Overloaded output operator is used to print out the columns, rows, exitRow, exitColumn, and the contents of the maze to the output screen.
ostream &operator<<(ostream &out, const Maze &maze) {

    out << maze.columns << " " << maze.rows << endl;
    out << maze.exitRow << " " << maze.exitColumn << endl;

    for (int i = 0; i < maze.rows; i++) {
        for (int j = 0; j < maze.columns; j++) {
            out << maze.maze[i][j];
        }
        out << "\n";
    }
    return out;

}
