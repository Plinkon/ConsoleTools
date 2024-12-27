/**
 * @file example.cpp
 * @brief Demonstrates usage of the ConsoleTools library.
 */

#include <iostream>
#include <vector>
#include "includes/ConsoleTools.h"

int main() {
    // 1. Demonstrate colored text
    std::cout << ConsoleTools::Color::GREEN
        << "Welcome to the ConsoleTools demo!"
        << ConsoleTools::Color::RESET
        << std::endl;

    // 2. PauseConsole
    // This prompts the user with a message and waits for them to press Enter.
    ConsoleTools::PauseConsole("Press ENTER to show some spacing...");

    // 3. Spacing
    // This returns a string containing a specified number of newline characters.
    std::cout << "Here is some spacing below:"
        << ConsoleTools::Spacing(3)
        << "[End of spacing]"
        << std::endl;

    // 4. Header
    // Creates a header with repeated line characters, spacing characters, and colored text.
    std::string header = ConsoleTools::Header(
        "=",     // line character
        5,       // line character count
        "HEADER",// header text
        " ",     // spacing character
        ConsoleTools::Color::CYAN,        // line color
        ConsoleTools::Color::YELLOW,      // header text color
        ConsoleTools::Color::GREEN        // spacing character color
    );
    std::cout << header << std::endl;

    // 5. AdvancedHeader
    // Similar to Header, but supports different left/right line characters and colors.
    std::string advHeader = ConsoleTools::AdvancedHeader(
        "=",     // left line character
        3,       // left line count
        "-",     // right line character
        3,       // right line count
        "ADVANCED HEADER",
        " ",     // spacing character
        ConsoleTools::Color::LIGHT_BLUE,   // left line color
        ConsoleTools::Color::LIGHT_PURPLE, // right line color
        ConsoleTools::Color::GREEN,        // header text color
        ConsoleTools::Color::YELLOW,       // spacing character color
        true     // reset color on end?
    );
    std::cout << advHeader << std::endl;

    // 6. ProgressBar
    // Creates a simple progress bar with a filled portion, unfilled portion, optional percentage text.
    std::cout << "ProgressBar demonstration:" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "\r"
            << ConsoleTools::ProgressBar(i, 10, 20, ConsoleTools::Color::GREEN, true, ConsoleTools::Color::LIGHT_CYAN);
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl << "Done!\n";

    // 7. AdvancedProgressBar
    // Provides more customization such as prefix/suffix text, bracket color, etc.
    std::cout << "AdvancedProgressBar demonstration:" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "\r"
            << ConsoleTools::AdvancedProgressBar(
                i, 10, 20,                 // current, max, bar width
                "Loading",                 // prefix text
                "Complete",                // suffix text
                "#", "-",                  // fill char, unfilled char
                ConsoleTools::Color::GREEN,// fill color
                ConsoleTools::Color::GRAY, // unfilled color
                ConsoleTools::Color::WHITE,// text color
                ConsoleTools::Color::YELLOW, // prefix color
                ConsoleTools::Color::LIGHT_BLUE, // suffix color
                ConsoleTools::Color::RED,        // bracket color
                true,   // Show percentage
                true,   // Show brackets
                true    // Reset color on completion
            );
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl << "Done!\n";

    // 8. Error & Warning
    // Generate strings for errors and warnings in color.
    std::cout << ConsoleTools::Error("This is an error message!") << std::endl;
    std::cout << ConsoleTools::Warning("This is a warning message!") << std::endl;

    // 9. PrintTypingTextEffect
    // Prints text with a random delay between each character.
    std::cout << ConsoleTools::Color::LIGHT_PURPLE;
    ConsoleTools::PrintTypingTextEffect("Typing text effect demonstration...\n", 20, 80);
    std::cout << ConsoleTools::Color::RESET;

    // 10. Notification
    // A small text block with a border and optional inside character, type text, etc.
    std::string notification = ConsoleTools::Notification(
        "[",
        "!",
        "]",
        "INFO",
        "This is a notification message!",
        ConsoleTools::Color::LIGHT_CYAN,   // border color
        ConsoleTools::Color::GREEN,        // inside char color
        ConsoleTools::Color::WHITE         // notification text color
    );
    std::cout << notification << std::endl;

    // 11. PrintSpinner
    // Displays a spinner animation for a certain duration with a specified spin speed.
    std::cout << "Showing a spinner for 2 seconds..." << std::endl;
    ConsoleTools::PrintSpinner(2000, 150);

    // 12. PromptNumberedMenu
    // Asks the user to pick an option from a list. 
    std::vector<std::string> menuOptions = {
        "Option A",
        "Option B",
        "Option C"
    };
    std::cout << "Numbered Menu demonstration:\n";
    int choice = ConsoleTools::PromptNumberedMenu(
        menuOptions,
        ": ",
        "Please choose an option:",
        "Your choice: ",
        ConsoleTools::Color::WHITE,
        ConsoleTools::Color::LIGHT_BLUE,
        ConsoleTools::Color::GREEN,
        ConsoleTools::Color::YELLOW,
        ConsoleTools::Color::LIGHT_PURPLE,
        ConsoleTools::Color::LIGHT_RED
    );

    if (choice != -1) {
        std::cout << "You chose: " << menuOptions[choice] << std::endl;
    }
    else {
        std::cout << "No valid choice was made or an error occurred." << std::endl;
    }

    // Final pause
    ConsoleTools::PauseConsole("Press ENTER to end the demonstration...");
    return 0;
}
