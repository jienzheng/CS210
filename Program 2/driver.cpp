/**
 * Runs the student code and provides 1 test case.
 * This case may not test everything and it is
 * always recommended that you implement your own
 * tests. Driver files will not necessarily be
 * provided for all projects.
 */
#include <stdlib.h>
#include <iostream>
#include "promotedCarModelStack.h"
#include "promotedCarModelStack.cpp"
using namespace std;
bool equalsIgnoreCase(const string& a, const string& b) {
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
void testHighestLowestPeek(string highestPricedModel,
                           int highestPrice,
                           string lowestPricedModel,
                           int lowestPrice,
                           string peekModel,
                           int peekModelPrice,
                           PromotedCarModelStack stack) {
    if (equalsIgnoreCase(stack.getHighestPricedPromotedModel().getModel(),
                         highestPricedModel)) {
        cout << "Stack highest priced model matches" << endl;
    } else {
        cout << "FAILED: Stack highest priced model does NOT match!" << endl;
        exit(EXIT_FAILURE);
    }
    if (stack.getHighestPricedPromotedModel().getPromotedPrice() == highestPrice) {
        cout << "Stack highest priced model's price matches" << endl;
    } else {
        cout << "FAILED: Stack highest priced model's price does NOT match!" <<
             endl;
        exit(EXIT_FAILURE);
    }
    if (equalsIgnoreCase(stack.getLowestPricedPromotedModel().getModel(),
                         lowestPricedModel)) {
        cout << "Stack lowest priced model matches" << endl;
    } else {
        cout << "FAILED: Stack lowest priced model does NOT match!" << endl;
        exit(EXIT_FAILURE);
    }
    if (stack.getLowestPricedPromotedModel().getPromotedPrice() == lowestPrice) {
        cout << "Stack lowest priced model's price matches" << endl;
    } else {
        cout << "FAILED: Stack lowest priced model's price does NOT match!" <<
             endl;
        exit(EXIT_FAILURE);
    }
    if (equalsIgnoreCase(stack.peek().getModel(), peekModel)) {
        cout << "Stack peek matches" << endl;
    } else {
        cout << "FAILED: Stack peek does NOT match!" << endl;
        exit(EXIT_FAILURE);
    }
    if (stack.peek().getPromotedPrice() == peekModelPrice) {
        cout << "Stack peek price matches" << endl;
    } else {
        cout << "FAILED: Stack peek price does NOT match" << endl;
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char **argv) {
    PromotedCarModelStack stack;
    cout << "Pushing m1 at 23,000" << endl;
    stack.push("m1", 13000);
    testHighestLowestPeek("m1", 13000,
                          "m1", 13000,
                          "m1", 13000, stack);
    cout << endl << "Pushing mj at 23,000" << endl;
    stack.push("mj", 14000);
    testHighestLowestPeek("mj", 14000,
                          "m1", 13000,
                          "mj", 14000, stack);
    cout << endl << "Pushing m4 at 23,000" << endl;
    stack.push("m4", 88000);
    testHighestLowestPeek("m4", 88000,
                          "m1", 13000,
                          "m4", 88000, stack);
    cout << endl << "Popping from stack" << endl;
    PromotedModel popped = stack.pop();
    if (equalsIgnoreCase(popped.getModel(), "m4")) {
        cout << "Popped model matches" << endl;
    } else {
        cout << "FAILED: Popped model does NOT match!" << endl;
        exit(EXIT_FAILURE);
    }
    if (popped.getPromotedPrice() == 88000) {
        cout << "Popped price matches" << endl;
    } else {
        cout << "Popped price does NOT match" << endl;
        exit(EXIT_FAILURE);
    }
    testHighestLowestPeek("mj", 14000,
                          "m1", 13000,
                          "mj", 14000, stack);
    cout << endl << "SUCCESS! All tests passed!" << endl;
    exit(EXIT_SUCCESS);
}
