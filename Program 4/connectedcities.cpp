#include "connectedcities.h"
/**
 * <p>
 * Part A
 *
-----------------------------------------------------------------------------------
----
 * For each city in a city list, find the list of reachable cities starting from
the city
 * following the train routes, and sort the cities in the descending order based on
the
 * number of their reachable cities.
 *
 * Required specifications -
 *
 * Given a list of cities, and a list of one-way train routes from one city to
another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode
class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities
collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all
reachable
 *    cities starting from the city following the train routes and store those
reachable cities to
 *    the CityNode's reachableCities collection.
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.
 *
 *    Note: The train route can go from the starting city and stop at several
cities
 *          before reaching the destination city, all cities including the starting
city and
 *          the destination city along the path would be counted as reachable
cities from
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their
reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the
train can
 *    reach the greatest number of destination cities following the given one-way
routes.
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part
to find
 *    all reachable cities from a starting city given the train routes, using an
iterative
 *    approach would result in a 30% penalty to your assignment 4 grade.
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for
hints.
 *
 * Assumptions -
 * 1) Each city is represented by a unique two-letter code like "SD", "LA",
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example,
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to
 *    Los Angeles (LA).
 *
 * <p>
 * Part B
 *
-----------------------------------------------------------------------------------
----
 * Show the upper bound of the time complexity of this function would be O(c^2 + c
* r)
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 *
 *
-----------------------------------------------------------------------------------
----
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route
represented
 *                 by a pair of city codes; for example, route {"SD", "LA"} means
train
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }
 *                       refer to driver.cpp for more examples.
 *
 * @return       A list of CityNode in the descending order based on the number of
their
 *               reachable cities following the train routes

* @see
*/
vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(
        vector<string> cities,
        vector<pair<string, string>> trainRoutes) {
    // Write your implementation here.
    // Creation of map for storing the graph
    unordered_map<string, CityNode> cityGraph;
    // Creation of vector to return
    vector<CityNode> cityNodes;
    // Creation of vector to add reachableCities into CityNodes
    vector<string> reachableCities;
    // Checking vector
    set<string> visitedCities;

    // Comparison for stable_sort to sort the return vector by alphabetical order.
    auto sortByString = [] (CityNode a, CityNode b) {
        return (a.getCity() < b.getCity());
    };
    // Stable_sort command
    std::stable_sort(cities.begin(), cities.end(), sortByString);

    // Adds in the list of cities in vector of CityNode objects.
    for (auto & city : cities) {
        cityNodes.emplace_back(city);
    }
    // Compares the trainroutes first value to whichever city it is currently looking at.
    // Adds the each direct routes for each city into object vector.
    // Then it adds the cityNodes, and each individual cities into the unordered map.
    for (int i = 0; i < cities.size(); ++i) {
        for (auto & trainRoute : trainRoutes){
            if (trainRoute.first == cities.at(i)){
                cityNodes.at(i).addADirectRoutedCity(trainRoute.second);
            }
        }
        cityGraph.insert(make_pair(cities.at(i), cityNodes.at(i)));
    }
    // Calls the recursive function to get reachable cities making.
    // ReachableCities vector is saved, and it is used to populate the citygraph.
    // Have to clear the reachablecities and visitedcities at every iteration of every city in the graph.
    for (auto city : cityGraph) {
        reachableCities = depthFirstSearchReachableCities(cityGraph,cityGraph.at(city.first).getCity(),
                                                          reachableCities, visitedCities);
        cityGraph.at(city.first).setReachableCities(reachableCities);
        reachableCities.clear();
        visitedCities.clear();
    }
    // Gets the reachablecities from citygraph and adds it into the cityNodes vector.
    for (auto & city : cityNodes) {
        reachableCities = cityGraph.at(city.getCity()).getReachableCities();
        city.setReachableCities(reachableCities);
        reachableCities.clear();
    }
    // Comparison for stable_sort to sort the return vector by reachablecities size.
    auto sortByLength = [] (const CityNode &a, const CityNode &b) {
        return (a.getReachableCities().size() > b.getReachableCities().size());
    };
    // Sorts the vector cityNodes by the reachablecities size from descending order.
    std::stable_sort(cityNodes.begin(), cityNodes.end(), sortByLength);
    return cityNodes; // Returns vector of CityNodes
    // Follow the steps in the specification above to implement.
    // You may want to implement each step in the above specification in
    // a separate function.
    // Think what would be a good data structure to store the City Graph.
    // Each node/vertice represents a city and each has an adjacent list of cities
    // that can be reached directly from the city.
    // You can use a STL collection to store
    // the graph of city nodes, so that given a city code,
    // you can find the corresponding CityNode object instantaneously.
    // Think Which data structure would give you the best lookup ability
    // by using a key.
    //
    // Build the city Graph:
    // 1) create a city graph collection, and create CityNode object for
    // all cities passed in
    // 2) Use the one way trainRoutes to populate the directRoutedCities of
    // each CityNode. directedRoutedCities would be the adjacency list for
    // each CityNode.
    //
    // Hint for DFS:
    // You may want to use a separate function to implement the
    // recursive Depth-First-Search algorithm for finding all reachable cities
    // starting from a city using its direct routes to other cities, and their
    // connected cities, and so on and so forth until all cities along
    // reachable paths are traversed.
    // Use the general approach described in zyBook 20.6 Graphs: Depth-first search
    // Follow what Figure 20.6.1 presents
    // A suggested separate recursive function for the DFS part could be:
    // void depthFirstSearchReachableCities(
    //      cityGraph, // a collection of a STL collection type
    //      string startingCity,
    //      vector<string> &reachableCities, // list of cities to add reachable
    // cities along the recursive call
    //      set<string> &visitedCities); // list of cities to track if a city is
    // already visited along DFS search
    // what would be the base condition? --> the startingCity is already visited
    // Hint for sorting: descending order of number of reachable cities and
    //                   ascending alphabetical order of the city code as the
    // tiebreaker
    // you can leverage the std::sort()
    // one way to do the two-level of sorting here is to first sort the list
    // by City code in ascending order,
    // then sort by number of reachable cities in descending order.
    // vector<CityNode>() here is a placeholder, you need
    // to change it to
    // whichever the vector your logic comes up with and
    // return
}
vector<string> ConnectedCities::depthFirstSearchReachableCities (unordered_map<string, CityNode> cityGraph,
                                                                 string startingCity, vector<string> &reachableCities, set<string> &visitedCities) {
    // Base case 1: Checks if the graph is empty
    if (cityGraph.empty()) {
        return reachableCities;
    }
    // Checks if the current city is already in the VisitedCities vector
    for (auto visit : visitedCities) {
        if (visit == startingCity) {
            return reachableCities;
        }
    }
    // If the startingcity or currentcity is not in the Visitedcities,
    // Add the starting city to both the reachablecities and visitedcites vector.
    if (!visitedCities.count(startingCity)) {
        visitedCities.insert(startingCity);
        reachableCities.emplace_back(startingCity);
    }
    // Recursively calls the method to look through its children.
    // Returns the reachablecities vector at each recursive call.
    for (const string& directRouteCity : cityGraph.at(startingCity).getDirectRoutedCities()) {
        if (!cityGraph.at(startingCity).getDirectRoutedCities().empty()) {
            reachableCities = depthFirstSearchReachableCities(cityGraph, directRouteCity,
                                                              reachableCities, visitedCities);
        }
        else {
            return reachableCities;
        }
    }
    return reachableCities;
}
