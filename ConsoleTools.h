/**
 * @file ConsoleTools.h
 * @brief Header file for the ConsoleTools library.
 */

#ifndef CONSOLE_TOOLS_H
#define CONSOLE_TOOLS_H

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
        static inline constexpr const char* RED = "\033[31m";
        static inline constexpr const char* ORANGE = "\033[38;5;208m";
        static inline constexpr const char* YELLOW = "\033[33m";
        static inline constexpr const char* GREEN = "\033[32m";
        static inline constexpr const char* BLUE = "\033[34m";
        static inline constexpr const char* PURPLE = "\033[35m";
        static inline constexpr const char* CYAN = "\033[36m";

        static inline constexpr const char* WHITE = "\033[37m";
        static inline constexpr const char* GRAY = "\033[90m";
        static inline constexpr const char* BLACK = "\033[30m";

        static inline constexpr const char* LIGHT_RED = "\033[91m";
        static inline constexpr const char* LIGHT_ORANGE = "\033[38;5;214m";
        static inline constexpr const char* LIGHT_YELLOW = "\033[93m";
        static inline constexpr const char* LIGHT_GREEN = "\033[92m";
        static inline constexpr const char* LIGHT_BLUE = "\033[94m";
        static inline constexpr const char* LIGHT_PURPLE = "\033[95m";
        static inline constexpr const char* LIGHT_CYAN = "\033[96m";

        static inline constexpr const char* RESET = "\033[0m";
        
        // if you want to create your own custom color,
        // follow the format of [static inline constexpr const char* COLORNAME = "ANSI_CODE"]
    };

    // Function Declarations

    void PauseConsole(const std::string& message);
    std::string Spacing(int NumberOfSpaces);

    std::string Header(const std::string& LineCharacter,
        int LineCharacterCount,
        const std::string& HeaderText,
        const std::string& SpacingCharacter,
        const std::string& LineColor,
        const std::string& HeaderTextColor,
        const std::string& SpacingCharacterColor);

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
        bool ResetColorOnEnd);

    std::string ProgressBar(int CurrentProgress,
        int MaxProgress,
        int BarWidth,
        const std::string& BarColor,
        bool ShowPercentage,
        const std::string& PercentageColor);

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
        bool ResetColorOnCompletion);

    std::string Error(const std::string& Message);
    std::string Warning(const std::string& Message);

    void PrintTypingTextEffect(const std::string& Text,
        int MinDelayMilliseconds,
        int MaxDelayMilliseconds);

    std::string Notification(const std::string& LeftBorderCharacter,
        const std::string& InsideCharacter,
        const std::string& RightBorderCharacter,
        const std::string& NotificationTypeText,
        const std::string& NotificationText,
        const std::string& BorderCharacterColor,
        const std::string& InsideCharacterColor,
        const std::string NotificationTextColor);

    void PrintSpinner(int SpinDurationMs, int SpinSpeedMs);

    int PromptNumberedMenu(const std::vector<std::string> Options,
        const std::string SeperatorCharacter,
        const std::string& PromptMessage,
        const std::string InputQuestionText,
        const std::string MessageColor,
        const std::string NumberColor,
        const std::string SeperatorColor,
        const std::string OptionColor,
        const std::string InputQuestionColor,
        const std::string ErrorColor);

} // namespace ConsoleTools

#endif // CONSOLE_TOOLS_H