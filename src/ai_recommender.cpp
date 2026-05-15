#include "ai_recommender.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

Seat AIRecommender::recommendSeat(const std::vector<Seat>& availableSeats,
                                   const CustomerPreferences& prefs) {
    if (availableSeats.empty()) {
        throw std::runtime_error("No available seats");
    }
    
    double bestScore = -1.0;
    Seat bestSeat = availableSeats[0];
    
    for (const Seat& seat : availableSeats) {
        if (!seat.isAvailable) continue;
        
        double score = calculateScore(seat, prefs);
        if (score > bestScore) {
            bestScore = score;
            bestSeat = seat;
        }
    }
    return bestSeat;
}

double AIRecommender::calculateScore(const Seat& seat, const CustomerPreferences& prefs) {
    double score = 0.0;
    
    // Window preference (40%)
    if (prefs.preferWindow && seat.hasWindow) score += 0.4;
    else if (!prefs.preferWindow && !seat.hasWindow) score += 0.2;
    
    // Door proximity (20%)
    double doorScore = 1.0 - (seat.distanceFromDoor / 10.0);
    score += doorScore * 0.2;
    
    // Quiet (neighbors) (25%)
    double quietScore = 1.0 - (seat.occupiedNeighbors / 4.0);
    score += quietScore * 0.25;
    
    // Comfort zone (15%)
    if (prefs.comfortPref == "front" && seat.comfortZone == "front") score += 0.15;
    else if (prefs.comfortPref == "middle" && seat.comfortZone == "middle") score += 0.15;
    else if (seat.comfortZone == "front") score += 0.1;
    else if (seat.comfortZone == "middle") score += 0.05;
    
    return score;
}
