#ifndef AI_RECOMMENDER_H
#define AI_RECOMMENDER_H

#include <vector>
#include <string>

struct Seat {
    int id;
    std::string seatNumber;
    bool hasWindow;
    int distanceFromDoor;
    int occupiedNeighbors;
    std::string comfortZone;
    bool isAvailable;
};

struct CustomerPreferences {
    bool preferWindow;
    bool preferQuiet;
    bool preferNearDoor;
    std::string comfortPref;
    int tripDistance;
};

class AIRecommender {
public:
    static Seat recommendSeat(const std::vector<Seat>& availableSeats, 
                               const CustomerPreferences& prefs);
    static double calculateScore(const Seat& seat, const CustomerPreferences& prefs);
};

#endif
