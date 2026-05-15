#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Seat {
    int id;
    string seatNumber;
    bool hasWindow;
    int distanceFromDoor;
    int occupiedNeighbors;
    string comfortZone;
    bool isAvailable;
};

struct CustomerPreferences {
    bool preferWindow;
    bool preferQuiet;
    bool preferNearDoor;
    string comfortPref;
    int tripDistance;
};

double calculateScore(const Seat& seat, const CustomerPreferences& prefs) {
    double score = 0.0;
    
    if (prefs.preferWindow && seat.hasWindow) score += 0.4;
    else if (!prefs.preferWindow && !seat.hasWindow) score += 0.2;
    
    double doorScore = 1.0 - (seat.distanceFromDoor / 10.0);
    score += doorScore * 0.2;
    
    double quietScore = 1.0 - (seat.occupiedNeighbors / 4.0);
    score += quietScore * 0.25;
    
    if (prefs.comfortPref == "front" && seat.comfortZone == "front") score += 0.15;
    else if (prefs.comfortPref == "middle" && seat.comfortZone == "middle") score += 0.15;
    else if (seat.comfortZone == "front") score += 0.1;
    else if (seat.comfortZone == "middle") score += 0.05;
    
    return score;
}

Seat recommendSeat(const vector<Seat>& seats, const CustomerPreferences& prefs) {
    double bestScore = -1;
    Seat bestSeat = seats[0];
    
    for (const auto& seat : seats) {
        if (!seat.isAvailable) continue;
        double score = calculateScore(seat, prefs);
        cout << "Seat " << seat.seatNumber << " score: " << score << endl;
        if (score > bestScore) {
            bestScore = score;
            bestSeat = seat;
        }
    }
    return bestSeat;
}

int main() {
    cout << "\n========================================" << endl;
    cout << "  Trinity Travels AI Seat Recommender" << endl;
    cout << "========================================\n" << endl;
    
    vector<Seat> seats = {
        {1, "A1", true, 1, 0, "front", true},
        {2, "A2", true, 1, 1, "front", true},
        {3, "B1", false, 3, 0, "middle", true},
        {4, "B2", false, 3, 1, "middle", true},
        {5, "C1", false, 6, 2, "back", true},
        {6, "C2", true, 6, 3, "back", true}
    };
    
    CustomerPreferences prefs;
    prefs.preferWindow = true;
    prefs.preferQuiet = true;
    prefs.preferNearDoor = false;
    prefs.comfortPref = "front";
    prefs.tripDistance = 150;
    
    cout << "CUSTOMER PREFERENCES:" << endl;
    cout << "  - Window seat: YES" << endl;
    cout << "  - Quiet area: YES" << endl;
    cout << "  - Comfort zone: front" << endl;
    cout << "\nAnalyzing seats...\n" << endl;
    
    Seat recommended = recommendSeat(seats, prefs);
    
    cout << "\n========================================" << endl;
    cout << "  AI RECOMMENDATION" << endl;
    cout << "========================================" << endl;
    cout << "  Seat Number:      " << recommended.seatNumber << endl;
    cout << "  Window seat:      " << (recommended.hasWindow ? "YES" : "NO") << endl;
    cout << "  Distance from door: " << recommended.distanceFromDoor << " meters" << endl;
    cout << "  Occupied neighbors: " << recommended.occupiedNeighbors << endl;
    cout << "  Comfort zone:     " << recommended.comfortZone << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}