#include "connectedcities.h"
#include "connectedcities.cpp"
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

    // Begin Testing
    // A few sample testing code are provided below

    /* Construct a graph for testing
        *    SD ---> DL <--------
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */
    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF",
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};
    vector<pair<string, string>> trainRoutes;
    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("SJ", "SK");
    trainRoutes.emplace_back("IV", "DL");

    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");
    vector<CityNode> cities =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1,
                                                                             trainRoutes);
//    cities returned from the above call are sorted according to
//    the ascending order of the city names and
//    the descending order of the size of reachableCities starting from those
//    cities

    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from"
                                                           " city HT can reach 7 cities");

    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from"
                                                           " city NH can reach 7 cities");

    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from"
                                                           " city SF can reach 7 cities");

    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from"
                                                           " city SJ can reach 7 cities");
    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from"
                                                           " city SK can reach 6 cities");

    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from"
                                                           " city JL can reach 4 cities");

    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from"
                                                           " city BV can reach 3 cities");

    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from"
                                                           " city LA can reach 3 cities");
    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from"
                                                           " city OD can reach 3 cities");
    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from"
                                                            " city BU can reach 1 city");
    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding
    //    required for assignment 4

    // Test Case 1
    vector<string> cities_2 {"SD", "LA", "IV", "SF",};
    vector<pair<string, string>> trainRoutes_2;
    vector<CityNode> cities2 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2,
                                                                             trainRoutes_2);
    asserts(cities2.at(0).getCity() == "IV", "First city should be IV");
    asserts(cities2.at(0).getReachableCities().size() == 1, "Train starting from"
                                                            " city IV can reach 1 cities");
    asserts(cities2.at(1).getCity() == "LA", "Second city should be LA");
    asserts(cities2.at(1).getReachableCities().size() == 1, "Train starting from"
                                                            " city LA can reach 1 cities");
    asserts(cities2.at(2).getCity() == "SD", "Third city should be SD");
    asserts(cities2.at(2).getReachableCities().size() == 1, "Train starting from"
                                                            " city SD can reach 1 cities");
    asserts(cities2.at(3).getCity() == "SF", "Fourth city should be SF");
    asserts(cities2.at(3).getReachableCities().size() == 1, "Train starting from"
                                                            " city SF can reach 1 cities");

    // Test Case 2
    vector<string> cities_3 {"HT", "NH", "SF", "JL", "OD", "SD", "DL",
                             "IV", "SK", "SJ", "LA", "BU", "BV"};
    vector<pair<string, string>> trainRoutes_3;
    trainRoutes_3.emplace_back("HT", "NH");
    trainRoutes_3.emplace_back("NH", "JL");
    trainRoutes_3.emplace_back("NH", "SF");
    trainRoutes_3.emplace_back("SF", "HT");
    trainRoutes_3.emplace_back("JL", "OD");
    trainRoutes_3.emplace_back("OD", "SD");
    trainRoutes_3.emplace_back("SD", "DL");
    trainRoutes_3.emplace_back("SJ", "SK");
    trainRoutes_3.emplace_back("SK", "IV");
    trainRoutes_3.emplace_back("SK", "LA");
    trainRoutes_3.emplace_back("IV", "DL");
    trainRoutes_3.emplace_back("LA", "BU");
    trainRoutes_3.emplace_back("LA", "BV");
    trainRoutes_3.emplace_back("BV", "LA");
    vector<CityNode> cities3 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3,
                                                                             trainRoutes_3);
    asserts(cities3.at(0).getCity() == "HT", "First city should be HT");
    asserts(cities3.at(0).getReachableCities().size() == 7, "Train starting from"
                                                            " city HT can reach 7 cities");
    asserts(cities3.at(1).getCity() == "NH", "Second city should be NH");
    asserts(cities3.at(1).getReachableCities().size() == 7, "Train starting from"
                                                            " city NH can reach 7 cities");
    asserts(cities3.at(3).getCity() == "SJ", "Fourth city should be SJ");
    asserts(cities3.at(3).getReachableCities().size() == 7, "Train starting from"
                                                            " city SJ can reach 7 cities");
    asserts(cities3.at(4).getCity() == "SK", "Fifth city should be SK");
    asserts(cities3.at(4).getReachableCities().size() == 6, "Train starting from"
                                                            "SK city can reach 6 cities");
    asserts(cities3.at(5).getCity() == "JL", "Sixth city should be JL");
    asserts(cities3.at(5).getReachableCities().size() == 4, "Train starting from"
                                                            " city JL can reach 4 cities");
    asserts(cities3.at(7).getCity() == "LA", "Seventh city should be LA");
    asserts(cities3.at(7).getReachableCities().size() == 3, "Train starting from"
                                                            " city LA can reach 3 cities");
    asserts(cities3.at(10).getCity() == "SD", "Eleventh city should be SD");
    asserts(cities3.at(10).getReachableCities().size() == 2, "Train starting from"
                                                             " city SD can reach 2 cities");
    asserts(cities3.at(11).getCity() == "BU", "Twelfth city should be BU");
    asserts(cities3.at(11).getReachableCities().size() == 1, "Train starting from"
                                                             " city BU can reach 1 cities");
    asserts(cities3.at(12).getCity() == "DL", "Thirteenth city should be DL");
    asserts(cities3.at(12).getReachableCities().size() == 1, "Train starting from"
                                                             " city DL can reach 1 cities");

// Test Case 3
    vector<string> cities_4 {"JL", "OD", "SD", "DL", "AX", "SC", "PX",
                             "NY", "IV", "SK", "SJ", "LA", "BV", "BU"};
    vector<pair<string, string>> trainRoutes_4;
    trainRoutes_4.emplace_back("JL", "OD");
    trainRoutes_4.emplace_back("OD", "SD");
    trainRoutes_4.emplace_back("SD", "DL");
    trainRoutes_4.emplace_back("AX", "DL");
    trainRoutes_4.emplace_back("NY", "PX");
    trainRoutes_4.emplace_back("PX", "SC");
    trainRoutes_4.emplace_back("PX", "AX");
    trainRoutes_4.emplace_back("SC", "AX");
    trainRoutes_4.emplace_back("SJ", "SK");
    trainRoutes_4.emplace_back("SK", "IV");
    trainRoutes_4.emplace_back("SK", "LA");
    trainRoutes_4.emplace_back("LA", "BV");
    trainRoutes_4.emplace_back("LA", "BU");
    trainRoutes_4.emplace_back("BV", "LA");
    vector<CityNode> cities4 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_4,
                                                                             trainRoutes_4);
    asserts(cities4.at(0).getCity() == "SJ", "First city should be SJ");
    asserts(cities4.at(0).getReachableCities().size() == 6, "Train starting from"
                                                            " city SJ can reach 6 cities");
    asserts(cities4.at(1).getCity() == "NY", "Second city should be NY");
    asserts(cities4.at(1).getReachableCities().size() == 5, "Train starting from"
                                                            " city NY can reach 5 cities");
    asserts(cities4.at(4).getCity() == "PX", "Fifth city should be PX");
    asserts(cities4.at(4).getReachableCities().size() == 4, "Train starting from"
                                                            " city PX can reach 4 cities");
    asserts(cities4.at(6).getCity() == "LA", "Seventh city should be LA");
    asserts(cities4.at(6).getReachableCities().size() == 3, "Train starting from"
                                                            " city LA can reach 3 cities");
    asserts(cities4.at(7).getCity() == "OD", "Eighth city should be OD");
    asserts(cities4.at(7).getReachableCities().size() == 3, "Train starting from"
                                                            " city OD can reach 3 cities");
    asserts(cities4.at(10).getCity() == "SD", "Eleventh city should be SD");
    asserts(cities4.at(10).getReachableCities().size() == 2, "Train starting from"
                                                             " city SD can reach 2 cities");
    asserts(cities4.at(13).getCity() == "IV", "Fourteenth city should be IV");
    asserts(cities4.at(13).getReachableCities().size() == 1, "Train starting from"
                                                             " city IV can reach 1 cities");
// Test Case 4
    vector<string> cities_5 {"SD"};
    vector<pair<string, string>> trainRoutes_5;
    vector<CityNode> cities5 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_5,
                                                                             trainRoutes_5);
    asserts(cities5.at(0).getCity() == "SD", "First city should be SD");
    asserts(cities5.at(0).getReachableCities().size() == 1, "Train starting from"
                                                            " city SD can reach 1 cities");
// Test Case 5
    vector<string> cities_6 {"NY", "LA", "BU", "SD", "PX", "AX",
                             "JL", "SJ", "BV", "IV", "SF", "SC"};
    vector<pair<string, string>> trainRoutes_6;
    trainRoutes_6.emplace_back("NY", "LA");
    trainRoutes_6.emplace_back("LA", "SD");
    trainRoutes_6.emplace_back("SD", "BU");
    trainRoutes_6.emplace_back("BU", "NY");
    trainRoutes_6.emplace_back("SD", "JL");
    trainRoutes_6.emplace_back("SD", "IV");
    trainRoutes_6.emplace_back("BU", "PX");
    trainRoutes_6.emplace_back("PX", "AX");
    trainRoutes_6.emplace_back("PX", "JL");
    trainRoutes_6.emplace_back("JL", "SJ");
    trainRoutes_6.emplace_back("IV", "BV");
    trainRoutes_6.emplace_back("IV", "SF");
    trainRoutes_6.emplace_back("SF", "SC");
    trainRoutes_6.emplace_back("SF", "SJ");
    vector<CityNode> cities6 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_6,
                                                                             trainRoutes_6);
    asserts(cities6.at(0).getCity() == "BU", "First city should be BU");
    asserts(cities6.at(0).getReachableCities().size() == 12, "Train starting from"
                                                             " city BU can reach 12 cities");
    asserts(cities6.at(3).getCity() == "SD", "Fourth city should be SD");
    asserts(cities6.at(3).getReachableCities().size() == 12, "Train starting from"
                                                             " city SD can reach 12 cities");
    asserts(cities6.at(4).getCity() == "IV", "Fifth city should be IV");
    asserts(cities6.at(4).getReachableCities().size() == 5, "Train starting from"
                                                            " city IV can reach 5 cities");
    asserts(cities6.at(5).getCity() == "PX", "Sixth city should be PX");
    asserts(cities6.at(5).getReachableCities().size() == 4, "Train starting from"
                                                            " city PX can reach 4 cities");
    asserts(cities6.at(6).getCity() == "SF", "Seventh city should be SF");
    asserts(cities6.at(6).getReachableCities().size() == 3, "Train starting from"
                                                            " city SF can reach 3 cities");
    asserts(cities6.at(7).getCity() == "JL", "Eighth city should be JL");
    asserts(cities6.at(7).getReachableCities().size() == 2, "Train starting from"
                                                            " city JL can reach 2 cities");
    asserts(cities6.at(9).getCity() == "BV", "Tenth city should be BV");
    asserts(cities6.at(9).getReachableCities().size() == 1, "Train starting from"
                                                            " city BV can reach 1 cities");
    // Test Case 6
    vector<string> cities_7 {};
    vector<pair<string, string>> trainRoutes_7;
    vector<CityNode> cities7 =
            ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_7,
                                                                             trainRoutes_7);
    asserts(cities7.size() == 0, "Graph is empty. There are no cities");

    // IMPORTANT: You should construct at least one different city graph similar to
    //    the one above
    //
    // Also make sure to construct graphs for testing the edge cases,
    // such as empty graph (NO node), one node graph, two nodes graph, etc.
    cout << endl << "All test cases passed!" << endl;
    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}
