#include "promotedCarModelStack.h"
#include <stdexcept>
#include <list>
/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1)
   * @param model
   * @param price
   */
void PromotedCarModelStack::push(string model, int price) {
    //Creating pointer object
    PromotedModel* promotedModel = new PromotedModel(model, price);
    //Checks if the list is empty, if it is then it would add in the promotedModel to the back of both list.
    if (list.empty()) {
        list.push_back(*promotedModel);
        minMaxList.push_back(*promotedModel);
    } else {
        //If the price is less than or equal to the price being pushed,
        //then it will push the price to the back of the minMaxList.
        if (minMaxList.back().getPromotedPrice() <= price) {
            minMaxList.push_back(*promotedModel);
            //If the price is greater than or equal to the price being pushed,
            //then it will push the price to the front of the minMaxList.
        } else if (minMaxList.front().getPromotedPrice() >= price) {
            minMaxList.push_front(*promotedModel);
        }
        //After the arguments is done for the minMaxList, then it pushes the model and price to the end of list.
        list.push_back(*promotedModel);
    }
}
/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
    //This result variable is created to keep track of the popped model name and prices.
    PromotedModel result;
    //Throws logic error if the list is empty.
    if (list.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }
    else {
        //If the back of the list and the back of minMaxList is the same,
        //then it removes the back of the minMaxList.
        if (list.back().getPromotedPrice() == minMaxList.back().getPromotedPrice()) {
            minMaxList.pop_back();
        }
        //If the back of the list and the front of the minMaxList is the same,
        //then it removes the front of the minMaxList
        else if (list.back().getPromotedPrice() == minMaxList.front().getPromotedPrice()) {
            minMaxList.pop_front();
        }
    }
    //Keeps tracks of the elements at the back of List.
    result = list.back();
    //Removes the back of the list.
    list.pop_back();
    //Returns the elements that were removed.
    return result;
}
/**
   * @brief peek operation, peeking the latest promoted model at the top of the
stack (without popping)
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
    //Throws logic error if the list is empty.
    if (minMaxList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }
    else {
        //Returns the value of the top of the stack or the end of the list
        return list.back();
    }
}
/**
   * @brief getHighestPricedPromotedModel,
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
    //Throws logic error if the list is empty.
    if (minMaxList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }
    else {
        //Returns max value found from minMaxList
        return minMaxList.back();
    }
}
/**
   * @brief getLowestPricedPromotedModel,
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
    //Throws logic error if the list is empty.
    if (minMaxList.empty()) {
        throw logic_error("Promoted car model stack is empty");
    }
    else {
        //Returns the min value found from minMaxList
        return minMaxList.front();
    }
}
