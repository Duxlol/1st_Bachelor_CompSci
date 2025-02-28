#include "DFA.h"
#include <utility> // for std::pair

using namespace std;

DFA::DFA() : startState(0) {
    acceptStates.insert(0);

    // Transitions for state 0
    transitionTable[make_pair(0, '0')] = 2;
    transitionTable[make_pair(0, '1')] = 1;

    // Transitions for state 1
    transitionTable[make_pair(1, '0')] = 3;
    transitionTable[make_pair(1, '1')] = 0;

    // Transitions for state 2
    transitionTable[make_pair(2, '0')] = 0;
    transitionTable[make_pair(2, '1')] = 3;

    // Transitions for state 3
    transitionTable[make_pair(3, '0')] = 1;
    transitionTable[make_pair(3, '1')] = 2;
}

bool DFA::accepts(const string &input) const {
    int currentState = startState;
    for (char c : input) {
        auto key = make_pair(currentState, c);
        auto it = transitionTable.find(key);
        if (it == transitionTable.end()) {
            return false;
        }
        currentState = it->second;
    }
    return acceptStates.count(currentState) > 0;
}