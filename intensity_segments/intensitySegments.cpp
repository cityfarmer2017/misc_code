/**
 * Copyright [2024] <wangdc1111@gmail.com>
 * for a coding test.
 */
#include <iostream>
#include <limits>
#include "inc/IntensitySegments.hpp"

void IntensitySegments::toString(void) {
    auto isInProcess = false;
    std::cout << "[";
    for (const auto &p : segments) {
        if (isInProcess) {
            std::cout << ",";
        } else {
            isInProcess = true;
        }
        std::cout << "[" << p.first << "," << p.second << "]";
    }
    std::cout << "]\n";
}

void IntensitySegments::updateSegments(int from, int to, int amount, bool bSet) {
    if (from >= to) {
        std::cout << "'from' should be less than 'to', otherwise no update." << std::endl;
        return;
    }

    // if the container is currently empty, just insert the segment
    if (segments.empty()) {
        segments[from] = amount;
        segments[to] = 0;
        return;
    }

    // iterator to be used to iterating the container
    auto it = segments.begin();
    // record the intensity value of the previous segement point
    auto prevAmount = 0;
    for (const auto &p : segments) {
        if (from > p.first) {
            prevAmount = p.second;
            ++it;
        } else {
            break;
        }
    }

    // to check if it need to insert a new segement point
    auto insertFlg = false;
    if (it == segments.end() || from < it->first) {
        it = segments.insert(it, std::make_pair(from, 0));
        insertFlg = true;
    }

    // iterate the container to update the intensity values accordingly
    for (; it != segments.end() && to > it->first; ) {
        // if currently at the new inserted point, use the previous intensity, ortherwise use the current
        long long tempAmount = insertFlg ? prevAmount : it->second;
        // if this is setting operation, just replace the intensity with argument value, otherwise add it
        tempAmount = bSet ? amount : amount + tempAmount;
        insertFlg = false;

        // if the updated intensity value exceed the limits, just use the limit values
        if (tempAmount > std::numeric_limits<int>::max()) {
            it->second = std::numeric_limits<int>::max();
        } else if (tempAmount < std::numeric_limits<int>::min()) {
            it->second = std::numeric_limits<int>::min();
        } else {
            it->second = tempAmount;
        }

        // erase the leading segment if the intensity value is 0, or it's duplicated to its previous one
        // otherwise, iterate to next one
        if (((it == segments.begin()) && (it->second == 0)) || (it->second == std::prev(it)->second)) {
            it = segments.erase(it);
        } else {
            ++it;
        }
    }

    if (!segments.empty()) {
        // if now reach the end or the intensity of end point is less than the intensity of the current point
        // insert the end point with 0 intensity
        if (it == segments.end() || to < it->first) {
            it = segments.insert(it, std::make_pair(to, 0));
        }

        // erase any segment point with duplicated instensity value
        if (it->second == std::prev(it)->second) {
            it = segments.erase(it);
        }
    }
}
