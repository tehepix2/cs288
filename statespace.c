#include <stdio.h>

int main() {

    // state space search
    // solving problems by searching
    // the process of looking for the sequence of actions that reaches the goal.

    /*
    start state: the beginning, where we start
    actions: the choices available -> to go from one state to another
    transition model: what is the result of performing a given action in a given state?
    goal state: the end, the result desired
    solution: a sequence of actions that turn a start state to a goal state
    path cost: total cost of a sequence of actions
    optimal solution: the sequence of actions that have the lowest path cost (a problem could have multiple solutions)

    Factors for a puzzle problem:
    start: initial position of tiles
    actions: movement of empty tile
    transition model: where the blank tile went
    goal state: sorted puzzle

    basic idea:
    start from start state
    try different possible actions, and obtain new states
    try different possible actions on new states, and obtain even more new states
    keep trying until goal state is found
    check what actions were made to change the start state into the goal state

    so searching is pretty much just the process of trying different actions and checking new states

    so how do we make the search algorithm?

    the set of new states is called the fringe.
        - a data structure, usually implemented as a list, and each state is a node on the list
    fringe = start state
    while the fringe is not empty:
        choose the first state and remove it from the fringe
        check the state: if the node contains the goal state, return the solution.
        expand the state: for each possible action, generate a successor (new?) state.
        add successor states into the fringe at the appropriate locations.
    each node looks like this:

        node1            node2
    |data    ptr| -> |data  ptr|-> etc

    data contains a state of the puzzle and ptr points to the next move.
    conceptually, this is just the traversal of a tree.
    */
    return 0;
}