#include "sortcar.h"

/**
 * @brief sort car inventory
 *
 * @param carInventory      input car inventory array
 * @param promotionOrder    car promotion order
 * @return vector<string>   sorted car inventory according to the car promotion
order
 *
 * Time complexity has to be linear: O(N), N is the size/length of the input car
inventory array
 * Space complexity has to be constant: O(1), hint: sorting can be done by mutating
 *                                      the input car inventory array.
 */
vector<string> SortCar::sortCarInventory(vector<string> carInventory,
                                         vector<string> promotionOrder) {
    // TODO: write your code here
    //A tracker that tracks whether a variable has been swapped at the beginning
    //A tracker that tracks whether a variable has been swapped at the end
    int trackerHead = 0, trackerTail = carInventory.size() - 1;
    //The starting and the ending elements of carInventory
    int start = 0, end = promotionOrder.size() - 1;
    //A temporary variable used for swapping
    string temp = "";

    //Iterates through the loop starting from the first element to the last element
    for (int i = 0; i < carInventory.size(); i++) {
        //Checks if the current element is the same as the promotion order
        if (carInventory.at(i) == promotionOrder.at(start)) {
            //Checks if the current tracker is the same as the promotion order
            if (carInventory.at(trackerHead) == promotionOrder.at(start)) {
                trackerHead++; //Increments the tracker variable
            }
            else {
                //Makes the temp variable assign to the element of where the tracker is at
                temp = carInventory.at(trackerHead);
                //Checks if the temp variable is not the same as the promotion order
                if (temp != promotionOrder.at(start)) {
                    //Swapping method
                    carInventory.at(trackerHead) = carInventory.at(i);
                    carInventory.at(i) = temp;
                    //Increments the tracker
                    trackerHead++;
                }
            }
        }
    }
    //Iterates through the loop starting from the last element to the first element
    for (int i = carInventory.size()-1 ; i >= 0; i--) {
        //Checks if the current element is the same as the promotion order
        if (carInventory.at(i) == promotionOrder.at(end)) {
            //Checks if the current tracker is the same as the promotion order
            if (carInventory.at(trackerTail) == promotionOrder.at(end)) {
                trackerTail--; //Decrements the tracker
            }
            else {
                //Makes the temp variable assign to the element of where the tracker is at
                temp = carInventory.at(trackerTail);
                //Checks if the temp variable is not the same as the promotion order
                if (temp != promotionOrder.at(end)) {
                    //Swapping method
                    carInventory.at(trackerTail) = carInventory.at(i);
                    carInventory.at(i) = temp;
                    //Decrements the tracker
                    trackerTail--;
                }
            }
        }
    }

    return carInventory;
}
