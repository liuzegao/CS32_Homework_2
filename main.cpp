//
//  main.cpp
//  CS_Homework_2
//
//  Created by Zegao Liu on 16/4/21.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#include <iostream>
#include <stack>
#include "Coord.h"
using namespace std;


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
{   Coord initialp(sr, sc);
    stack<Coord> temp;
    temp.push(initialp);
    maze[sr][sc] = 'H';
    
/*
    Push the starting coordinate (sr,sc) onto the coordinate stack and
    update maze[sr][sc] to indicate that the algorithm has encountered
    it (i.e., set maze[sr][sc] to have a value other than '.').
    While the stack is not empty,
    {   Pop the top coordinate off the stack. This gives you the current
        (r,c) location that your algorithm is exploring.
        If the current (r,c) coordinate is equal to the ending coordinate,
        then we've solved the maze so return true!
        Check each place you can move from the current cell as follows:
        If you can move NORTH and haven't encountered that cell yet,
        then push the coordinate (r-1,c) onto the stack and update
        maze[r-1][c] to indicate the algorithm has encountered it.
        If you can move EAST and haven't encountered that cell yet,
        then push the coordinate (r,c+1) onto the stack and update
        maze[r][c+1] to indicate the algorithm has encountered it.
        If you can move SOUTH and haven't encountered that cell yet,
        then push the coordinate (r+1,c) onto the stack and update
        maze[r+1][c] to indicate the algorithm has encountered it.
        If you can move WEST and haven't encountered that cell yet,
        then push the coordinate (r,c-1) onto the stack and update
        maze[r][c-1] to indicate the algorithm has encountered it.
    }
    There was no solution, so return false
*/

    while(!temp.empty())
    {
        
        int temp_r = temp.top().r();
        int temp_c = temp.top().c();
        temp.pop();
        
        if ( temp_r == er && temp_c == ec)
            return true;
        
        if (maze[temp_r-1][temp_c] == '.')
            {
                temp.push(Coord(temp_r-1,temp_c));
                maze[temp_r-1][temp_c] = 'H';
            }
        if (maze[temp_r][temp_c+1] == '.')
            {
                temp.push(Coord(temp_r,temp_c+1));
                maze[temp_r][temp_c+1] = 'H';
            }
        
        if (maze[temp_r+1][temp_c] == '.')
            {
                temp.push(Coord(temp_r+1,temp_c));
                maze[temp_r+1][temp_c] = 'H';
            }
        
        if (maze[temp_r][temp_c-1] == '.')
            {
                temp.push(Coord(temp_r,temp_c-1));
                maze[temp_r][temp_c-1] = 'H';
            }
    }
    return false;
}



int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','X','.','.','.','.','X','X','X'},
        { 'X','.','.','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    
    if (pathExists(maze, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}

