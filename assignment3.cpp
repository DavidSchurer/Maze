//Name: David Schurer
//Class: CSS 342
//Assignment 3: Maze
#include "maze.h"
#include "creature.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

int main() {

    cout << "########## Testing A Creature Solving mazeSimple.txt ##########" << endl;
    cout << endl;

   Maze *testMaze = new Maze("mazeSimple.txt");
   Creature *testCreature = new Creature(1, 6);
   string mazeSolution = testCreature->Solve(*testMaze);
   cout << *testMaze;

   if (mazeSolution == "X") {
     cout << "The creature did not successfully reach the exit of the maze." << endl;
   } else {
     cout << "The creature successfully reached the exit of the maze!" << endl;
   }
   cout << "Path: " << mazeSolution << endl;

   delete testMaze;
   delete testCreature;


   cout << endl;
   cout << "########## Testing A Creature Solving mazeNoExit1.txt ##########" << endl;
   cout << endl;

   Maze *testMaze2 = new Maze("mazeNoExit1.txt");
   Creature *testCreature2 = new Creature(1, 1);
   string mazeSolution2 = testCreature2->Solve(*testMaze2);
   cout << *testMaze2;

   if (mazeSolution2 == "X") {
     cout << "The creature did not successfully reach the exit of the maze." << endl;
   } else {
     cout << "The creature successfully reached the exit of the maze!" << endl;
   }
   cout << "Path: " << mazeSolution2 << endl;

   delete testMaze2;
   delete testCreature2;
  
   cout << endl;
   cout << "########## Testing A Creature Solving maze.txt ##########" << endl;
   cout << endl;

   Maze *testMaze3 = new Maze("maze.txt");
   Creature *testCreature3 = new Creature(1, 5);
   string mazeSolution3 = testCreature3->Solve(*testMaze3);
   cout << *testMaze3;

   if (mazeSolution3 == "X") {
     cout << "The creature did not successfully reach the exit of the maze." << endl;
   } else {
     cout << "The creature successfully reached the exit of the maze!" << endl;
   }
   cout << "Path: " << mazeSolution3 << endl;

   delete testMaze3;
   delete testCreature3;

   cout << endl;
   cout << "########## Testing A Creature Solving maze0.txt ##########" << endl;
   cout << endl;

   Maze *testMaze4 = new Maze("maze0.txt");
   Creature *testCreature4 = new Creature(2, 7);
   string mazeSolution4 = testCreature4->Solve(*testMaze4);
   cout << *testMaze4;

   if (mazeSolution4 == "X") {
     cout << "The creature did not successfully reach the exit of the maze." << endl;
   } else {
     cout << "The creature successfully reached the exit of the maze!" << endl;
   }
   cout << "Path: " << mazeSolution4 << endl;

   delete testMaze4;
   delete testCreature4;

   return 0;
}
