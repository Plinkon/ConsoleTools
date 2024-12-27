/**
 * @file ConsoleTools.cpp
 * @brief Implementation of the ConsoleTools library for various console functions such as
 * coloring text, creating headers, progress bars, notifications, etc.
 */

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <stdexcept>
#include <vector>
#include <limits>

namespace ConsoleTools {

    /**
     * @struct Color
     * @brief Stores static inline console color escape codes for easy access.
     */
    struct Color {
        // -- Standard colors --
        static inline constexpr const char* RED = "\033[31m";
        static inline constexpr const char* ORANGE = "\033[38;5;208m";
        static inline constexpr const char* YELLOW = "\033[33m";
        static inline constexpr const char* GREEN = "\033[32m";
        static inline constexpr const char* BLUE = "\033[34m";
        static inline constexpr const char* PURPLE = "\033[35m";
        static inline constexpr const char* CYAN = "\033[36m";

        // -- Normal colors --
        static inline constexpr const char* WHITE = "\033[37m";
        static inline constexpr const char* GRAY = "\033[90m";
        static inline constexpr const char* BLACK = "\033[30m";

        // -- Light colors --
        static inline constexpr const char* LIGHT_RED = "\033[91m";
        static inline constexpr const char* LIGHT_ORANGE = "\033[38;5;214m";
        static inline constexpr const char* LIGHT_YELLOW = "\033[93m";
        static inline constexpr const char* LIGHT_GREEN = "\033[92m";
        static inline constexpr const char* LIGHT_BLUE = "\033[94m";
        static inline constexpr const char* LIGHT_PURPLE = "\033[95m";
        static inline constexpr const char* LIGHT_CYAN = "\033[96m";

        // -- Reset --
        static inline constexpr const char* RESET = "\033[0m";

        // -- Custom Colors --
        // if you want to create your own custom color,
        // follow the format of [static inline constexpr const char* COLORNAME = "ANSI_CODE"]
    };

    /**
     * @brief Pauses the console until the user presses Enter.
     * @param message A message printed before waiting for user input.
     * @return void
     */
    void PauseConsole(const std::string& message) {
        std::cout << message << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /**
     * @brief Creates a string consisting of line-break characters.
     * @param NumberOfSpaces The number of newlines to append.
     * @return A string containing the specified number of newline characters.
     */
    std::string Spacing(int NumberOfSpaces) {
        std::string spacing;
        for (int i = 0; i < NumberOfSpaces; i++) {
            spacing.append("\n");
        }
        return spacing;
    }

    /**
     * @brief Creates a header string with repeated line characters, spacing characters, and colored text.
     * @param LineCharacter The character used to create the repeated line segments.
     * @param LineCharacterCount The number of times to repeat the line character on each side.
     * @param HeaderText The text that appears in the center of the header.
     * @param SpacingCharacter The character to insert between the line segments and the header text.
     * @param LineColor The color code for the repeated line segments.
     * @param HeaderTextColor The color code for the header text.
     * @param SpacingCharacterColor The color code for the spacing character.
     * @return The fully constructed header string.
     */
    std::string Header(const std::string& LineCharacter,
        int LineCharacterCount,
        const std::string& HeaderText,
        const std::string& SpacingCharacter,
        const std::string& LineColor,
        const std::string& HeaderTextColor,
        const std::string& SpacingCharacterColor)
    {
        std::string header;
        std::string lineSegment;

        // Create the repeated line segment
        for (int i = 0; i < LineCharacterCount; i++) {
            lineSegment.append(LineCharacter);
        }

        // Build the header
        header.append(LineColor);
        header.append(lineSegment);

        header.append(SpacingCharacterColor);
        header.append(SpacingCharacter);

        header.append(HeaderTextColor);
        header.append(HeaderText);

        header.append(SpacingCharacterColor);
        header.append(SpacingCharacter);

        header.append(LineColor);
        header.append(lineSegment);

        header.append(Color::RESET);

        return header;
    }

    /**
     * @brief Creates a header with two different line characters on the left and right, colored differently if desired.
     * @param LeftLineCharacter Character repeated on the left side of the header.
     * @param LeftLineCharacterCount Number of times to repeat the left line character.
     * @param RightLineCharacter Character repeated on the right side of the header.
     * @param RightLineCharacterCount Number of times to repeat the right line character.
     * @param HeaderText The text that appears in the center of the header.
     * @param SpacingCharacter The character to insert between the line segments and the header text.
     * @param LeftLineColor Color code for the left line segment.
     * @param RightLineColor Color code for the right line segment.
     * @param HeaderTextColor Color code for the header text.
     * @param SpacingCharacterColor Color code for the spacing character.
     * @param ResetColorOnEnd Whether to reset color codes at the end of the header.
     * @return The fully constructed advanced header string.
     */
    std::string AdvancedHeader(const std::string& LeftLineCharacter,
        int LeftLineCharacterCount,
        const std::string& RightLineCharacter,
        int RightLineCharacterCount,
        const std::string& HeaderText,
        const std::string& SpacingCharacter,
        const std::string& LeftLineColor,
        const std::string& RightLineColor,
        const std::string& HeaderTextColor,
        const std::string& SpacingCharacterColor,
        bool ResetColorOnEnd)
    {
        std::string header;
        std::string LlineSegment;
        std::string RlineSegment;

        // Create the repeated line segments
        for (int i = 0; i < LeftLineCharacterCount; i++) {
            LlineSegment.append(LeftLineCharacter);
        }
        for (int i = 0; i < RightLineCharacterCount; i++) {
            RlineSegment.append(RightLineCharacter);
        }

        // Build the header
        header.append(LeftLineColor);
        header.append(LlineSegment);

        header.append(SpacingCharacterColor);
        header.append(SpacingCharacter);

        header.append(HeaderTextColor);
        header.append(HeaderText);

        header.append(SpacingCharacterColor);
        header.append(SpacingCharacter);

        header.append(RightLineColor);
        header.append(RlineSegment);

        if (ResetColorOnEnd) {
            header.append(Color::RESET);
        }

        return header;
    }

    /**
     * @brief Creates a simple progress bar with a filled and unfilled portion, optionally showing a percentage.
     * @param CurrentProgress The current progress value (must be <= MaxProgress).
     * @param MaxProgress The maximum progress value.
     * @param BarWidth The total width of the progress bar in characters.
     * @param BarColor The color code for the filled portion of the bar.
     * @param ShowPercentage Whether to display the numeric percentage.
     * @param PercentageColor The color code for the percentage display.
     * @return The constructed progress bar string.
     */
    std::string ProgressBar(int CurrentProgress,
        int MaxProgress,
        int BarWidth,
        const std::string& BarColor,
        bool ShowPercentage,
        const std::string& PercentageColor)
    {
        // Clamp progress values to bounds
        if (CurrentProgress > MaxProgress) {
            CurrentProgress = MaxProgress;
        }
        if (CurrentProgress < 0) {
            CurrentProgress = 0;
        }

        // Calculate progress fraction
        double progress = static_cast<double>(CurrentProgress) / MaxProgress;
        int filledWidth = static_cast<int>(progress * BarWidth);
        int remainingWidth = BarWidth - filledWidth;

        // Build the bar
        std::string bar;
        bar.append(BarColor);

        // Filled portion
        for (int i = 0; i < filledWidth; i++) {
            bar.push_back('#');
        }
        // Unfilled portion
        for (int i = 0; i < remainingWidth; i++) {
            bar.push_back('-');
        }

        bar.append(Color::RESET);

        // Optionally show percentage
        if (ShowPercentage) {
            int percentage = static_cast<int>(progress * 100);
            bar.push_back(' ');
            bar.append(PercentageColor);
            bar.append(std::to_string(percentage));
            bar.push_back('%');
            bar.append(Color::RESET);
        }

        return bar;
    }

    /**
     * @brief Creates an advanced progress bar with optional brackets, prefix/suffix text, custom fill/unfill characters, and colors.
     * @param CurrentPercentage The current progress value.
     * @param MaxPercentage The maximum progress value.
     * @param BarWidth The total width of the progress bar in characters.
     * @param PrefixText A text that appears before the bar.
     * @param SuffixText A text that appears after the bar.
     * @param FillChar The character used to denote the filled portion of the bar.
     * @param UnfilledChar The character used to denote the unfilled portion of the bar.
     * @param FillColor The color code for the filled portion.
     * @param UnfilledColor The color code for the unfilled portion.
     * @param TextColor The color code for the percentage text.
     * @param PrefixColor The color code for the prefix text.
     * @param SuffixColor The color code for the suffix text.
     * @param BracketColor The color code for the brackets.
     * @param ShowPercentage Whether to display the numeric percentage next to the bar.
     * @param ShowBrackets Whether to display brackets around the bar.
     * @param ResetColorOnCompletion Whether to reset color codes after building the bar.
     * @return The constructed advanced progress bar string.
     */
    std::string AdvancedProgressBar(int CurrentPercentage,
        int MaxPercentage,
        int BarWidth,
        const std::string& PrefixText,
        const std::string& SuffixText,
        const std::string& FillChar,
        const std::string& UnfilledChar,
        const std::string& FillColor,
        const std::string& UnfilledColor,
        const std::string& TextColor,
        const std::string& PrefixColor,
        const std::string& SuffixColor,
        const std::string& BracketColor,
        bool ShowPercentage,
        bool ShowBrackets,
        bool ResetColorOnCompletion)
    {
        // Clamp current progress
        if (CurrentPercentage < 0) {
            CurrentPercentage = 0;
        }
        if (CurrentPercentage > MaxPercentage) {
            CurrentPercentage = MaxPercentage;
        }

        // Calculate progress fraction, avoid divide-by-zero
        double progress = (MaxPercentage != 0)
            ? static_cast<double>(CurrentPercentage) / MaxPercentage
            : 0.0;
        int filledWidth = static_cast<int>(progress * BarWidth);
        int remainingWidth = BarWidth - filledWidth;

        std::string result;

        // Prefix
        if (!PrefixText.empty()) {
            result.append(PrefixColor);
            result.append(PrefixText);
        }

        // Optional brackets
        if (ShowBrackets) {
            result.append(BracketColor);
            result.push_back('[');
        }

        // Filled portion
        result.append(FillColor);
        for (int i = 0; i < filledWidth; i++) {
            result.append(FillChar);
        }

        // Unfilled portion
        result.append(UnfilledColor);
        for (int i = 0; i < remainingWidth; i++) {
            result.append(UnfilledChar);
        }

        // Close brackets
        if (ShowBrackets) {
            result.append(BracketColor);
            result.push_back(']');
        }

        // Show percentage
        if (ShowPercentage) {
            int percentageValue = static_cast<int>(progress * 100);
            result.append(TextColor);
            result.append(" ");
            result.append(std::to_string(percentageValue));
            result.push_back('%');
        }

        // Suffix
        if (!SuffixText.empty()) {
            result.append(" ");
            result.append(SuffixColor);
            result.append(SuffixText);
        }

        if (ResetColorOnCompletion) {
            result.append(Color::RESET);
        }

        return result;
    }

    /**
     * @brief Creates an error message string in red color.
     * @param Message The error message to display.
     * @return A colored error string prefixed with "[ERROR]: ".
     */
    std::string Error(const std::string& Message) {
        std::string error;
        error.append(Color::LIGHT_RED);
        error.append("[ERROR]: ");
        error.append(Message);
        return error;
    }

    /**
     * @brief Creates a warning message string in yellow color.
     * @param Message The warning message to display.
     * @return A colored warning string prefixed with "[WARNING]: ".
     */
    std::string Warning(const std::string& Message) {
        std::string warning;
        warning.append(Color::LIGHT_YELLOW);
        warning.append("[WARNING]: ");
        warning.append(Message);
        return warning;
    }

    /**
     * @brief Prints text to the console with a random delay between each character to simulate a typing effect.
     * @param Text The text to print.
     * @param MinDelayMilliseconds The minimum delay between characters in milliseconds.
     * @param MaxDelayMilliseconds The maximum delay between characters in milliseconds.
     * @return void
     */
    void PrintTypingTextEffect(const std::string& Text,
        int MinDelayMilliseconds,
        int MaxDelayMilliseconds)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(MinDelayMilliseconds, MaxDelayMilliseconds);

        for (char c : Text) {
            int delay = dist(gen);
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }

    /**
     * @brief Creates a formatted notification string with a left border, an inside character, and a right border, along with some text.
     * @param LeftBorderCharacter The character or string used as the left border.
     * @param InsideCharacter The character or string used inside the border (often small).
     * @param RightBorderCharacter The character or string used as the right border.
     * @param NotificationTypeText A label or title for the notification (e.g., "INFO", "WARNING").
     * @param NotificationText The main notification text to display.
     * @param BorderCharacterColor Color code for the border characters.
     * @param InsideCharacterColor Color code for the inside character.
     * @param NotificationTextColor Color code for the notification text.
     * @return A formatted notification string with optional coloring.
     */
    std::string Notification(const std::string& LeftBorderCharacter,
        const std::string& InsideCharacter,
        const std::string& RightBorderCharacter,
        const std::string& NotificationTypeText,
        const std::string& NotificationText,
        const std::string& BorderCharacterColor,
        const std::string& InsideCharacterColor,
        const std::string NotificationTextColor)
    {
        std::string notification;
        notification.append(BorderCharacterColor);
        notification.append(LeftBorderCharacter);

        notification.append(InsideCharacterColor);
        notification.append(InsideCharacter);

        notification.append(BorderCharacterColor);
        notification.append(RightBorderCharacter);

        notification.append(InsideCharacterColor);
        notification.append(" " + NotificationTypeText);
        notification.append(": ");

        notification.append(NotificationTextColor);
        notification.append(NotificationText);

        notification.append(Color::RESET);

        return notification;
    }

    /**
     * @brief Prints a spinning animation in place for a specified duration, with a chosen spin speed.
     * @param SpinDurationMs The total duration of the spinner in milliseconds.
     * @param SpinSpeedMs The delay between spinner frames in milliseconds.
     * @return void
     */
    void PrintSpinner(int SpinDurationMs, int SpinSpeedMs) {
        const char* spinChars = "|/-\\";
        int spinIndex = 0;
        auto start = std::chrono::steady_clock::now();

        while (true) {
            // Print spinning char and flush.
            std::cout << "\r" << spinChars[spinIndex++] << std::flush;
            if (spinIndex == 4) {
                spinIndex = 0;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(SpinSpeedMs));
            auto now = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() >= SpinDurationMs) {
                break;
            }
        }

        // Clear the spinner character.
        std::cout << "\r " << std::endl;
    }

    /**
     * @brief Prompts the user with a numbered menu of options and returns the user’s selection index (zero-based).
     * @param Options A vector of strings representing the menu options.
     * @param SeperatorCharacter The character (e.g. ':') separating the option index from the option text.
     * @param PromptMessage A message displayed before listing the options.
     * @param InputQuestionText A message asking the user to select an option.
     * @param MessageColor Color code for the prompt message.
     * @param NumberColor Color code for the numeric indices.
     * @param SeperatorColor Color code for the separator character.
     * @param OptionColor Color code for the option text.
     * @param InputQuestionColor Color code for the question text prompting user input.
     * @param ErrorColor Color code for any error messages (e.g., invalid input).
     * @return The zero-based index of the user’s chosen option. Returns -1 if an error occurs or if no options are provided.
     */
    int PromptNumberedMenu(const std::vector<std::string> Options,
        const std::string SeperatorCharacter,
        const std::string& PromptMessage,
        const std::string InputQuestionText,
        const std::string MessageColor,
        const std::string NumberColor,
        const std::string SeperatorColor,
        const std::string OptionColor,
        const std::string InputQuestionColor,
        const std::string ErrorColor)
    {
        if (Options.empty()) {
            std::cerr << "No menu options provided.\n";
            return -1;
        }

        std::cout << MessageColor << PromptMessage << "\n";

        // Print each option
        for (size_t i = 0; i < Options.size(); i++) {
            std::cout << NumberColor << i + 1
                << SeperatorColor << SeperatorCharacter
                << OptionColor << Options[i]
                << Color::RESET << std::endl;
        }

        // Ask for user input
        std::cout << InputQuestionColor << "\n" << InputQuestionText << NumberColor;

        std::string input;
        if (!std::getline(std::cin, input)) {
            // Input read error
            std::cout << ErrorColor;
            std::cerr << "Input error. Exiting.\n";
            std::cout << Color::RESET;
            return -1;
        }

        // Convert the user input to an integer
        try {
            int choice = std::stoi(input);
            if (choice < 1 || choice > static_cast<int>(Options.size())) {
                // Out-of-range choice
                std::cout << ErrorColor;
                std::cout << "Invalid choice. Please enter a number between 1 and "
                    << Options.size() << ".\n\n";
                std::cout << Color::RESET;
            }
            else {
                // Valid choice
                std::cout << Color::RESET;
                return choice - 1;
            }
        }
        catch (const std::invalid_argument&) {
            // Non-integer input
            std::cout << ErrorColor;
            std::cout << "Invalid input. Please enter a numeric value.\n\n";
            std::cout << Color::RESET;
        }
        catch (const std::out_of_range&) {
            // Very large number that cannot fit in int
            std::cout << ErrorColor;
            std::cout << "The number you entered is out of range. Please try again.\n\n";
            std::cout << Color::RESET;
        }

        // If we reach here, the input was invalid.
        std::cout << Color::RESET;
        return -1;
    }

} // namespace ConsoleTools