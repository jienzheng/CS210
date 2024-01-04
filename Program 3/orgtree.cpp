#include "orgtree.h"
/**
 * Check if an employee is present in an organization chart.
 *
 * @param  head the head / root Employee of the organization chart
 * @param  e_id the employee id being searched
 * @return      true or false
 * @see
 */
bool Orgtree::isEmployeePresentInOrg(Employee* head, int e_id) {
    // Write your recursive implementation here
    // Important: Your implementation MUST use the recursive approach
    // as required in the assignment 3 prompt to avoid penalties.
    // base case 1: empty organization chart
    // base case 2: if the employee is found, return true
    // search employee from each child of the head
    // return true if the employee is found in one of the child subtree
    // if not found, return false


    /*
     * Checks if the head is null, returns false.
     * Checks if the current value or the head to see if it is the same as the employee, returns true.
     * Else statement, loops through the tree, and checks if the boolean variable is true.
     * If it is true, then it means that the employee id is found within the true.
     * Otherwise, if the employee id is not found, then the employee is not in the org.
     */
    if (head == nullptr) {
        return false;
    }
    else if (head->getEmployeeID() == e_id) {
        return true;
    }
    else {
        for (int i = 0; i < head->getDirectReports().size(); ++i) {
            bool result = isEmployeePresentInOrg(head->getDirectReports().at(i), e_id);
            if (result) {
                return true;
            }
        }
        return false;
    }
}
/**
 * Find the level of an employee in an organization chart / tree.
 *
 * <p>
 * The head / root of the org chart has a level of 0, children of the head have
 * a level of head plus 1, and so on and so forth...
 *
 * <p>
 * Assumption: e_id is unique among all employee IDs
 *
 * @param  head      the head / root Employee of the organization chart
 * @param  e_id      the employee id being searched
 * @param  headLevel the level of the head employee of the organization
 * @return    level of the employee in the org chart
 *      returns Employee::NOT_FOUND if e_id is not present
 * @see
 */
int Orgtree::findEmployeeLevel(Employee* head, int e_id, int headLevel) {
    // Write your recursive implementation here.
    // Important: Your implementation MUST use the recursive approach
    // as required in the assignment 3 prompt to avoid penalties.
    // base case 1: empty organization chart
    // base case 2: the employee is found, returns the employee level
    // search employee from each child of the head
    // if not found


    /*
     * Checks if the head is null, if it is then returns employee is not found.
     * Checks if the employee id is the same as id to be checked returns the level.
     * Iterates through the tree and checks if the head level is not -1, then it returns
     * the recursive method with headlevel++, so that it knows to add 1 when it goes down a tree level.
     * Returns the tree level when the employee is found at the certain level.
     * Otherwise it will return Employee is not found.
     */
    if (head == nullptr) {
        return Employee::NOT_FOUND;
    }
    if (head->getEmployeeID() == e_id){
        return headLevel;
    }
    for (int i = 0; i < head->getDirectReports().size(); ++i) {
        if (findEmployeeLevel(head->getDirectReports().at(i), e_id, headLevel) != - 1) {
            return findEmployeeLevel(head->getDirectReports().at(i), e_id, ++headLevel);
        }
    }
    return Employee::NOT_FOUND;
}
/**
 * Find the closest shared manager of two employees e1 and e2.
 *
 * <p>
 * There are two possible organizational relationships between two employees in the
org chart:
 * case 1: e1 or e2 is a manager of the other employee;
 * case 2: e1 or e2 is not a manager of the other employee, they have at least one
shared manager
 *
 * Employee 1 is a manager of employee 2 if employee 1 is an ancestor of employee 2
in the organization chart
 *
 * <p>
 * Assumption: e1_id and e2_id are unique among all employee IDs
 *
 * @param  head  the head / root Employee of the organization chart
 * @param  e1_id id of employee 1 being searched
 * @param  e2_id id of employee 2 being searched
 * @return   closest shared manager in the org chart between employee e1 and
employee e2
   *           if head is nullptr, returns nullptr
   *           if neither e1 or e2 is present, returns empty employee
   *           if e1 is present and e2 is not, returns e1
   *           if e2 is present and e1 is not, returns e2
   *           if e1 and e2 both are present, returns their shared manager
   *              if e1 is a manager (ancestor) of e2, returns e1
   *              else if e2 is a manager (ancestor) of e1, returns e2
   *              else returns the shared manager of e1 and e2
 * @see
 */
Employee* Orgtree::findClosestSharedManager(Employee* head, int e1_id, int e2_id) {
    // Write your recursive implementation here
    // Important: Your implementation MUST use the recursive approach
    // as required in the assignment 3 prompt to avoid penalties.
    // base case 1: empty organization chart
    // base case 2: either e1_id or e2_id is the same as the head / root
    // Recursively traverse through direct reports of the head to find
    // where e1 and e2 are
    /*
       For each recursive call (starting from the root), you need to handle three
  possible scenarios:
       1) if e1 is found in one subtree, and e2 is found from another subtree;
          the head at that recursive step would be the closest shared manager of e1
          and e2.
          you can use the returned pointer (being NOT NULL) from
          findClosestSharedManager
          to see if e1 or e2 is found from a subtree (one of the base cases).
       2) if either e1 or e2 is first found in one subtree (following one subtree),
          but the other employee is NOT found from any other subtree, then the found
          employee must either be the manager of the other employee, or the other
          employee
          is NOT in the org chart; in either case, the first found employee should be
          returned as the shared manager.
       3) if neither e1 or e2 is found in the org chart, return nullptr
    */


    /*
     * Vector result is created to save the employee id's found within the tree.
     * Employee value is used to save the value found from the recursive call.
     * Each iteration of the for loop, it goes through and check each child.
     * The base cases are used to find the employee within the tree.
     * Once the value is found, it is then returned to the "value".
     * Within the for loop, after the employee is saved, it checks if it is not null.
     * If it is null, then it will go to the next iteration to check if the employee is in a different subtree.
     * If value is not null, then that value is pushed back into the vector result.
     * Every time the iteration finishes looking at a subtree, if the vector size is 0,
     * then it will return a nullptr, but when vector size is 1. This means that there is
     * one employee found in this subtree, and it returns that employee value of where it was found.
     * If the vector is the size of two, then both the employees are found, which returns the parent of the two child.
     * When one child is found, but the other is not found, then it will return that child as the closest manager.
     * When neither child is found, it will return nullptr.
     */
    vector<Employee*> result;
    Employee* value;
    if (head == nullptr) {
        return nullptr;
    }
    if (head->getEmployeeID() == e1_id || head->getEmployeeID() == e2_id) {
        return head;
    }
    for (int i = 0; i < head->getDirectReports().size(); i++) {
        value = findClosestSharedManager(head->getDirectReports().at(i), e1_id, e2_id);
        if (value != nullptr) {
            result.push_back(value);
        }
    }
    if (result.size() == 2) {
        return head;
    }
    if (result.size() == 1) {
        return result.at(0);
    }
    if (result.empty()) {
        return nullptr;
    }
    return nullptr;
}
/**
 * Calculate the number of managers between employee e1 and employee e2.
 *
 * <p>
 * The number of managers between employee e1 and employee e2 can be calculated by:
 *  number of edges between employee 1 and closest shared manager +
 *  number of edges between employee 2 and closest shared manager - 1
 *
 * <p>
 * Assumption: e1_id and e2_id are unique among all employee IDs
 *
 * @param  head  the head / root Employee of the organization chart
 * @param  e1_id id of employee 1 being searched
 * @param  e2_id id of employee 2 being searched
 * @return   number of managers between employee e1 and employee e2
 *           returns Employee::NOT_FOUND if either e1 or e2 is not present in the
chart
 * @see
 */
int Orgtree::findNumOfManagersBetween(Employee* head, int e1_id, int e2_id) {

    // Write your implementation here. You do NOT need to use recursive approach
    // here.
    // Use the above functions wherever you need to implement this function.
    // Continue only if both employee nodes e1_id and e2_id are in the org chart tree
    // otherwise, return Employee::NOT_FOUND
    // The number of managers between employee e1 and employee e2 can be calculated
    // by:
    // number of edges between e1_id and closest shared manager +
    // number of edges between e2_id and closest shared manager - 1


    /*
     * This checks if both employee are present within the tree. If it is, it creates an employee variable called
     * sharedManager. This find the closest shared manager between the two employees.
     * The other two variable are called to find the edges/height of the tree. They use sharedManager as the
     * starting head node. When the height of the subtree is found, you return by adding the two edges
     * and subtracting one. Otherwise, if neither of the employees or one of the employees are found
     * then it will return that the employee is not found.
     */
    if (isEmployeePresentInOrg(head, e1_id) && isEmployeePresentInOrg(head, e2_id)) {
        Employee* sharedManager = findClosestSharedManager(head, e1_id, e2_id);
        int edges1 = findEmployeeLevel(sharedManager, e1_id, 0);
        int edges2 = findEmployeeLevel(sharedManager, e2_id, 0) - 1;
        return edges1 + edges2;
    }
    else {
        return Employee::NOT_FOUND;
    }
}
/** Recursively delete a tree
 *  The proper implementation of this function is also needed for
 *  passing the valgrind memory leaking test.
 *
 * <p>
 * Traversing from the head / root node, recursively deallocate
 * the memory of the descendants from the leaf node level.
 *
 * DO NOT worry about removing them from the vector directReports
 *
 * Use post order traversal:
 * Delete / deallocate the children recursively
 * Delete / deallocate the current node after deleting its children
 *     Before deleting the current node, print its employee ID and a new line
 *     This part will be autograded as well as manually inspected for grading
 *
 * For example, with the following org chart, the post order traversal
 * order would be 5 6 2 7 8 3 1, and the nodes should be deleted in that order
 *              1
 *           /    \
 *           2    3
 *          / \  / \
 *          5 6  7 8
 *
 * @param  head  the head / root Employee of the organization chart
 * @return   None
 *
 * @see
 */
void Orgtree::deleteOrgtree(Employee* head) {
    // Write your recursive implementation here
    // Important: Your implementation MUST use the recursive approach
    // as required in the assignment 3 prompt to avoid penalties.
    // base case: empty tree or organization chart
    // delete children recursively
    // print current node's employee ID and a new line
    // delete the current node after deleting its children


    /*
     * Base case is used to check if the tree is empty or not.
     * If it is not empty, it will go through the for loop,
     * that will look at each child, and it will print the employee id,
     * then it will delete the employee. This will yield the tree to be empty
     * after this recursion is done.
     */
    if (head == nullptr) {
        return;
    }
    else {
        for (int i = 0; i < head->getDirectReports().size(); ++i) {
            if (head->getDirectReports().at(i) != nullptr) {
                deleteOrgtree(head->getDirectReports().at(i));
            }
        }
        cout << head->getEmployeeID() << endl;
        delete head;
    }
}
