Feature: AI Seat Recommendation
  As a customer of Trinity Travels
  I want the system to recommend the best seat
  So that I have a comfortable journey

  Scenario: Recommend window seat for customer
    Given a customer prefers a window seat
    When the system searches available seats
    Then the system recommends a seat with window view
