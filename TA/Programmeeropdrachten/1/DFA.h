#ifndef DFA_H
#define DFA_H

#include <string>
#include <map>
#include <unordered_set>

class DFA {
public:
    DFA();
    bool accepts(const std::string &input) const;

private:
    int startState;
    std::unordered_set<int> acceptStates;
    std::map<std::pair<int, char>, int> transitionTable;
};

#endif