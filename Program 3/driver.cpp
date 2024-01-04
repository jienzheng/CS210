#include "orgtree.h"
#include "orgtree.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */
/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void asserts(bool didPass, string message) {
        if (didPass) {
            cout << "Passed: " << message << endl;
        } else {
            cout << "FAILED: " << message << endl;
            // Halts execution, comment out to
            // continue testing other parts
// If you do comment this out, ignore the
// "All test cases passed!" printout
            exit(EXIT_FAILURE);
        }
}
//TODO
int main(int argc, char **argv) {
    /*
     * Construct the following organization chart for testing
     *                1
     *           /    \    \
     *           2    3    4
     *          / \  / \   \
     *          5 6  7 8   9
     *         /   \       \
     *         10  11      12
     */
    Employee *head = new Employee(1, vector<int>{2, 3, 4});
    Employee *e2 = head->getDirectReports().at(0);
    Employee *e3 = head->getDirectReports().at(1);
    Employee *e4 = head->getDirectReports().at(2);
    e2->addDirectReports(vector<int>{5, 6});
    e3->addDirectReports(vector<int>{7, 8});
    e4->addDirectReport(9);
    Employee *e5 = e2->getDirectReports().at(0);
    Employee *e6 = e2->getDirectReports().at(1);
    Employee *e9 = e4->getDirectReports().at(0);
    e5->addDirectReport(10);
    e6->addDirectReport(11);
    e9->addDirectReport(12);
    // Begin Testing
    // A few sample testing code are provided below

    // TODO Test all Orgtree functions
    //      according to the specifications in the comment section ABOVE each 
    //function signature.

    // IMPORTANT: You should also construct at least one different chart 
    // Also make sure to check edge cases, such as empty chart, or one employee 
    //chart.
    // Test isEmployeePresentInOrg function
    bool employeePresent = Orgtree::isEmployeePresentInOrg(head, 3);
    asserts(employeePresent, "ID 3 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, 6);
    asserts(employeePresent, "ID 6 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, 12);
    asserts(employeePresent, "ID 12 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, -2);
    asserts(employeePresent == false, "ID -2 Not present in tree");
    //TODO...
    // Test findEmployeeLevel function
    int employeeLevel = Orgtree::findEmployeeLevel(head, 4, 0);
    asserts(employeeLevel == 1, "Level of ID 4 returns " + to_string(employeeLevel)
                               + ", expected 1");
    employeeLevel = Orgtree::findEmployeeLevel(head, 5, 0);
    asserts(employeeLevel == 2, "Level of ID 5 returns " + to_string(employeeLevel)
                                + ", expected 2");
    employeeLevel = Orgtree::findEmployeeLevel(head, 10, 0);
    asserts(employeeLevel == 3, "Level of ID 10 returns " + to_string(employeeLevel)
                                 + ", expected 3");
    employeeLevel = Orgtree::findEmployeeLevel(head, 12, 0);
    asserts(employeeLevel == 3, "Level of ID 12 returns " + to_string(employeeLevel)
                                 + ", expected 3");
    employeeLevel = Orgtree::findEmployeeLevel(head, 20, 0);
    asserts(employeeLevel == -1, "Level of ID 20 returns " + to_string(employeeLevel)
                                 + ", expected -1");
    //TODO...
    // Test findClosestSharedManager function
    // Call the function with certain combination of the arguments
    // Assert / verify the returned Employee* has the expected Employee ID
    Employee* closestManager = Orgtree::findClosestSharedManager(head, 2, 4);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 2 and 4 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 1");
    closestManager = Orgtree::findClosestSharedManager(head, 5, 6);
    asserts(closestManager->getEmployeeID() == 2, "Closest shared manager ID between 5 and 6 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 2");
    closestManager = Orgtree::findClosestSharedManager(head, 10, 11);
    asserts(closestManager->getEmployeeID() == 2, "Closest shared manager ID between 10 and 11 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 2");
    closestManager = Orgtree::findClosestSharedManager(head, 10, 12);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 10 and 12 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 1");
    closestManager = Orgtree::findClosestSharedManager(head, 5, 9);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 5 and 9 returns " +
                                                   to_string(closestManager->getEmployeeID()) + ", expected 1");
    closestManager = Orgtree::findClosestSharedManager(head, 7, 8);
    asserts(closestManager->getEmployeeID() == 3, "Closest shared manager ID between 7 and 8 returns " +
                                                   to_string(closestManager->getEmployeeID()) + ", expected 3");
    closestManager = Orgtree::findClosestSharedManager(head, 10, 14);
    asserts(closestManager->getEmployeeID() == 10, "Closest shared manager ID between 10 and 14 returns " +
                                                   to_string(closestManager->getEmployeeID()) + ", expected 10");
    closestManager = Orgtree::findClosestSharedManager(head, 20, 16);
    asserts(closestManager == nullptr,
            "Closest shared manager ID between 20 and 16 returns Null, expected Null");

    //TODO...
    // Test findNumOfManagersBetween function
    int numManagers = Orgtree::findNumOfManagersBetween(head, 10, 11);
    asserts(numManagers == 3, "Managers between 10 and 11 returns " +
                             to_string(numManagers) + ", expected 3");
    // TODO numManagers = ...
    numManagers = Orgtree::findNumOfManagersBetween(head, 2, 3);
    asserts(numManagers == 1, "Managers between 2 and 3 returns " +
                              to_string(numManagers) + ", expected 1");
    numManagers = Orgtree::findNumOfManagersBetween(head, 10, 12);
    asserts(numManagers == 5, "Managers between 10 and 11 returns " +
                              to_string(numManagers) + ", expected 3");
    numManagers = Orgtree::findNumOfManagersBetween(head, 1, 11);
    asserts(numManagers == 2, "Managers between 1 and 11 returns " +
                              to_string(numManagers) + ", expected 2");
    // Test deleteOrgtree function
    // VERY IMPORTANT: Related to valgrind memory leaking detection testing,
    // You MUST call your deleteOrgtree function at the end of this driver testing 
    //code
    // to delete all the allocated memory for the tree. 
    Orgtree::deleteOrgtree(head);
    // Use the printed employee ID along the sequence of deletion to verify your 
    //implementation

    // Creating an empty tree.
    Employee *head1 = new Employee(NULL, vector<int>{NULL});

    employeePresent = Orgtree::isEmployeePresentInOrg(head1, 3);
    asserts(employeePresent == false, "ID 3 Not present in tree");

    employeeLevel = Orgtree::findEmployeeLevel(head1, 1, 0);
    asserts(employeeLevel == -1, "Level of ID 1 returns " + to_string(employeeLevel)
                                 + ", expected -1");

    closestManager = Orgtree::findClosestSharedManager(head1, 2, 3);
    asserts(closestManager == nullptr,
            "Closest shared manager ID between 2 and 3 returns Null, expected Null");

    numManagers = Orgtree::findNumOfManagersBetween(head1, 1, 11);
    asserts(numManagers == -1, "Managers between 1 and 11 returns" +
                              to_string(numManagers) + ", expected -1");
    Orgtree::deleteOrgtree(head1);

    // Creating a tree with one employee.
    Employee *head2 = new Employee(1, vector<int>{2});

    employeePresent = Orgtree::isEmployeePresentInOrg(head2, 2);
    asserts(employeePresent, "ID 2 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head2, 3);
    asserts(employeePresent == false, "ID 3 Not present in tree");

    employeeLevel = Orgtree::findEmployeeLevel(head2, 1, 0);
    asserts(employeeLevel == 0, "Level of ID 1 returns " + to_string(employeeLevel)
                                + ", expected 0");
    employeeLevel = Orgtree::findEmployeeLevel(head2, 3, 0);
    asserts(employeeLevel == -1, "Level of ID 3 returns " + to_string(employeeLevel)
                                 + ", expected -1");

    closestManager = Orgtree::findClosestSharedManager(head2, 4, 9);
    asserts(closestManager == nullptr,
            "Closest shared manager ID between 4 and 9 returns Null, expected Null");
    closestManager = Orgtree::findClosestSharedManager(head2, 1, 2);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 1 and 2 returns "
                    + to_string(closestManager->getEmployeeID()) + ", expected 1");

    numManagers = Orgtree::findNumOfManagersBetween(head2, 1, 2);
    asserts(numManagers == 0, "Managers between 1 and 2 returns " +
                              to_string(numManagers) + ", expected 1");
    numManagers = Orgtree::findNumOfManagersBetween(head2, 1, 11);
    asserts(numManagers == -1, "Managers between 1 and 11 returns " +
                               to_string(numManagers) + ", expected -1");

    Orgtree::deleteOrgtree(head2);

    // Creating a big tree

    /*
     * Construct the following organization chart for testing
     *                                  1
     *           /      /           /              \              \
     *           2      3           4               5              6
     *          / \    /          /   \          /    \             \
     *          7 8    9         10    11       12    13            14
     *         /   \    \       /  \     \      \       \          /  \
     *        15   16    17    18  19     20     21      22       23   24
     */
    Employee *head3 = new Employee(1, vector<int>{2, 3, 4, 5, 6});
    Employee *ed2 = head3->getDirectReports().at(0);
    Employee *ed3 = head3->getDirectReports().at(1);
    Employee *ed4 = head3->getDirectReports().at(2);
    Employee *ed5 = head3->getDirectReports().at(3);
    Employee *ed6 = head3->getDirectReports().at(4);
    ed2->addDirectReports(vector<int>{7, 8});
    ed3->addDirectReport(9);
    ed4->addDirectReports(vector<int>{10, 11});
    ed5->addDirectReports(vector<int>{12, 13});
    ed6->addDirectReport(14);
    Employee *ed7 = ed2->getDirectReports().at(0);
    Employee *ed8 = ed2->getDirectReports().at(1);
    Employee *ed9 = ed3->getDirectReports().at(0);
    Employee *ed10 = ed4->getDirectReports().at(0);
    Employee *ed11 = ed4->getDirectReports().at(1);
    Employee *ed12 = ed5->getDirectReports().at(0);
    Employee *ed13 = ed5->getDirectReports().at(1);
    Employee *ed14 = ed6->getDirectReports().at(0);
    ed7->addDirectReport(15);
    ed8->addDirectReport(16);
    ed9->addDirectReport(17);
    ed10->addDirectReports(vector<int>{18,19});
    ed11->addDirectReport(20);
    ed12->addDirectReport(21);
    ed13->addDirectReport(22);
    ed14->addDirectReports(vector<int>{23,24});

    employeePresent = Orgtree::isEmployeePresentInOrg(head, 18);
    asserts(employeePresent, "ID 34 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, 22);
    asserts(employeePresent, "ID 22 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, 12);
    asserts(employeePresent, "ID 12 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, -9);
    asserts(employeePresent == false, "ID -2 Not present in tree");

    employeeLevel = Orgtree::findEmployeeLevel(head, 4, 0);
    asserts(employeeLevel == 1, "Level of ID 4 returns " + to_string(employeeLevel)
                                + ", expected 1");
    employeeLevel = Orgtree::findEmployeeLevel(head, 13, 0);
    asserts(employeeLevel == 2, "Level of ID 13 returns " + to_string(employeeLevel)
                                + ", expected 2");
    employeeLevel = Orgtree::findEmployeeLevel(head, 24, 0);
    asserts(employeeLevel == 3, "Level of ID 24 returns " + to_string(employeeLevel)
                                + ", expected 3");
    employeeLevel = Orgtree::findEmployeeLevel(head, 16, 0);
    asserts(employeeLevel == 3, "Level of ID 16 returns " + to_string(employeeLevel)
                                + ", expected 3");
    employeeLevel = Orgtree::findEmployeeLevel(head, 38, 0);
    asserts(employeeLevel == -1, "Level of ID 38 returns " + to_string(employeeLevel)
                                 + ", expected -1");

    closestManager = Orgtree::findClosestSharedManager(head, 24, 11);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 24 and 11 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 1");
    closestManager = Orgtree::findClosestSharedManager(head, 17, 22);
    asserts(closestManager->getEmployeeID() == 1, "Closest shared manager ID between 17 and 22 returns " +
                                                  to_string(closestManager->getEmployeeID()) + ", expected 1");
    closestManager = Orgtree::findClosestSharedManager(head, 15, 8);
    asserts(closestManager->getEmployeeID() == 2, "Closest shared manager ID between 15 and 8 returns " +
                                                   to_string(closestManager->getEmployeeID()) + ", expected 2");
    closestManager = Orgtree::findClosestSharedManager(head, -1, 25);
    asserts(closestManager == nullptr,
            "Closest shared manager ID between -1 and 25 returns Null, expected Null");

    numManagers = Orgtree::findNumOfManagersBetween(head, 15, 14);
    asserts(numManagers == 4, "Managers between 15 and 14 returns " +
                              to_string(numManagers) + ", expected 4");
    numManagers = Orgtree::findNumOfManagersBetween(head, 8, 5);
    asserts(numManagers == 2, "Managers between 8 and 5 returns " +
                              to_string(numManagers) + ", expected 2");
    numManagers = Orgtree::findNumOfManagersBetween(head, 20, 18);
    asserts(numManagers == 3, "Managers between 20 and 18 returns " +
                              to_string(numManagers) + ", expected 3");

    Orgtree::deleteOrgtree(head3);

    // This part will be autograded as well as manually inspected for grading
    cout << endl << "All test cases passed!" << endl;
    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}
