#include <cucumber-cpp/defs.hpp>
#include <iostream>
#include "ai_recommender.h"

using cucumber::ScenarioScope;

struct BookingContext {
    std::vector<Seat> availableSeats;
    CustomerPreferences prefs;
    Seat recommendedSeat;
};

GIVEN("^a customer prefers a window seat$") {
    ScenarioScope<BookingContext> context;
    context->prefs.preferWindow = true;
    context->prefs.comfortPref = "front";
    
    // Create sample seats
    context->availableSeats = {
        {1, "A1", true, 1, 0, "front", true},
        {2, "A2", true, 1, 1, "front", true},
        {3, "B1", false, 3, 0, "middle", true},
        {4, "B2", false, 3, 1, "middle", true}
    };
}

WHEN("^the system searches available seats$") {
    ScenarioScope<BookingContext> context;
    context->recommendedSeat = AIRecommender::recommendSeat(
        context->availableSeats, 
        context->prefs
    );
    std::cout << "System searched available seats" << std::endl;
}

THEN("^the system recommends a seat with window view$") {
    ScenarioScope<BookingContext> context;
    if (context->recommendedSeat.hasWindow) {
        std::cout << "✓ Recommended: " << context->recommendedSeat.seatNumber 
                  << " (Window seat)" << std::endl;
        return;
    }
    throw std::runtime_error("Expected window seat recommendation!");
}
