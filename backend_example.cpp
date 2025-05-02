#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

// A mock database for simplicity.
std::map<std::string, std::string> mockDatabase{
    {"user:001", "Alice"},
    {"user:002", "Bob"},
    {"user:003", "Charlie"}
};

// Represents a simple user with an ID and a Name.
class User {
    std::string id;
    std::string name;

public:
    User(std::string userId, std::string userName) : id(std::move(userId)), name(std::move(userName)) {}

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }
};

// Simulate a backend service for managing users.
class UserService {
    // Here, we simulate a database call to fetch user data.
    std::string fetchUserNameFromDB(const std::string& userId) {
        if (mockDatabase.find(userId) == mockDatabase.end()) {
            throw std::invalid_argument("User not found.");
        }
        return mockDatabase[userId];
    }

public:
    // Retrieves a User object for a given user ID.
    User getUserById(const std::string& userId) {
        std::string userName = fetchUserNameFromDB(userId);
        return User(userId, userName);
    }
};

// Main function to run the application.
int main() {
    std::cout << "Backend with C++ demo";

    UserService userService;

    try {
        // Fetching users by ID.
        User user1 = userService.getUserById("user:001");
        User user2 = userService.getUserById("user:002");

        std::cout << "Fetched User 1 - ID: " << user1.getId() << ", Name: " << user1.getName() << std::endl;
        std::cout << "Fetched User 2 - ID: " << user2.getId() << ", Name: " << user2.getName() << std::endl;

        // Attempting to fetch a user that does not exist will throw an error.
        userService.getUserById("user:010");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}