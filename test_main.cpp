#include "src/ai_recommender.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  Trinity Travels AI Seat Recommender" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    // Create sample seats
    std::vector<Seat> availableSeats = {
        {1, "A1", true, 1, 0, "front", true},
        {2, "A2", true, 1, 1, "front", true},
        {3, "B1", false, 3, 0, "middle", true},
        {4, "B2", false, 3, 1, "middle", true},
        {5, "C1", false, 6, 2, "back", true},
        {6, "C2", true, 6, 3, "back", true}
    };
    
    // Set customer preferences
    CustomerPreferences prefs;
    prefs.preferWindow = true;
    prefs.preferQuiet = true;
    prefs.preferNearDoor = false;
    prefs.comfortPref = "front";
    prefs.tripDistance = 150;
    
    std::cout << "CUSTOMER PREFERENCES:" << std::endl;
    std::cout << "  - Window seat: " << (prefs.preferWindow ? "YES" : "NO") << std::endl;
    std::cout << "  - Quiet area: " << (prefs.preferQuiet ? "YES" : "NO") << std::endl;
    std::cout << "  - Near door: " << (prefs.preferNearDoor ? "YES" : "NO") << std::endl;
    std::cout << "  - Comfort zone: " << prefs.comfortPref << std::endl;
    std::cout << "  - Trip distance: " << prefs.tripDistance << " km" << std::endl;
    std::cout << "\nAVAILABLE SEATS:" << std::endl;
    std::cout << "  Seat | Window | DoorDist | Neighbors | Zone" << std::endl;
    std::cout << "  -----|--------|----------|-----------|------" << std::endl;
    for (const auto& s : availableSeats) {
        std::cout << "  " << s.seatNumber << "   | " 
                  << (s.hasWindow ? "YES   " : "NO    ") << " | "
                  << s.distanceFromDoor << "m       | "
                  << s.occupiedNeighbors << "         | "
                  << s.comfortZone << std::endl;
    }
    
    std::cout << "\n--- AI ANALYZING SEATS ---" << std::endl;
    Seat recommended = AIRecommender::recommendSeat(availableSeats, prefs);
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  AI RECOMMENDATION" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "  Seat Number:      " << recommended.seatNumber << std::endl;
    std::cout << "  Window seat:      " << (recommended.hasWindow ? "YES" : "NO") << std::endl;
    std::cout << "  Distance from door: " << recommended.distanceFromDoor << " meters" << std::endl;
    std::cout << "  Occupied neighbors: " << recommended.occupiedNeighbors << std::endl;
    std::cout << "  Comfort zone:     " << recommended.comfortZone << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}