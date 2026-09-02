#include <stdio.h>

int main() {
    /*
    Use evaluation function f(n) to rank nodes in the fringe and select the most promising one for 
    expansion.
    Use formula: f = g + h -> real cost from start to n + heuristic
    Psuedo code:
    Generate epty priority queue and call it OPEN,
    prioritized by f(n) value.
    generate empty collection of states and call it closed.
    Insert start state(s) into OPEN.
    remove state with smallest f(n) value from open. if removal fails because open is empty, search fails.
    If n is goal state, finish search.
    generate all successors to n.
    remove and free successors that are already in OPEn or CLOSED.
    Evaluate remaining successors and obtain f(n) values.
    Push remaining succesors onto OPEN.

    Puzzle problem!
    Calculate heuristic by:
    Number of misplaced tiles.
    OR
    sum of manhattan distances of all non-empty tiles
        Manhattan distance: number of squares (x and y) from
        current location to desired location.
    */
}