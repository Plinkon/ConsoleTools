
# ConsoleTools

### A Comprehensive Library for Console Quality Of Life Enhancements for C++

---

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Dependencies and Compatibility](#dependencies-and-compatibility)
4. [Getting Started](#getting-started)
 1. [Installation](#installation)
 2. [Integration](#integration)
5. [Library Overview](#library-overview)
 1. [Color Struct](#the-color-struct)
 2. [PauseConsole](#pauseconsole)
 3. [Spacing](#spacing)
 4. [Header & AdvancedHeader](#header--advancedheader)
 5. [ProgressBar & AdvancedProgressBar](#progressbar--advancedprogressbar)
 6. [Error & Warning](#error--warning)
 7. [PrintTypingTextEffect (typewriter effect)](#print-typing-text-effect-typewriter-effect)
 8. [Notification](#notification)
 9. [PrintSpinner](#printspinner)
 10. [PromptNumberedMenu](#promptnumberedmenu)
6. [Detailed Usage](#detailed-usage)
 1. [Color Formatting](#color-formatting)
 2. [Text and UI Elements](#text-and-ui-elements)
 3. [User Interaction](#user-interaction)
 4. [Examples](#examples)
7. [Advanced Topics](#advanced-topics)
 1. [ANSI Escape Codes Behavior](#ansi-escape-codes-behavior)
 2. [Potential Platform Issues](#potential-platform-issues)
8. [Contributing](#contributing)
9. [License](#license)

---

## Introduction

**ConsoleTools** is a lightweight, single-header (plus an implementation file) C++ library designed to improve and speed up basic console application development. Whether you’re building a command-line tool, a game, or a simple utility, ConsoleTools helps you create polished and user-friendly console experiences. ConsoleTools offers simple and easy-to-use, quality of life functions and features that make developing a nice console application easier and faster.

If you frequently create and develop console applications and want a way to speed up your development process, **ConsoleTools** is for you.

---

## Features

1. **Colorful Output**  
   \- Easily set text to **any color you want**, along with preset colors.  
   \- Includes *light* variants and *gray/black/white* colors.  
   \- Simplifies using ANSI escape codes, which also allows for easy customizability.

2. **Headers**  
   \- Create stylized headers and “advanced headers” with different characters, spacing, custom colors, and many other configurable settings.

3. **Progress Bars**  
   \- A simple progress bar `ProgressBar()` or a more customizable one, `AdvancedProgressBar()`.

4. **Interactive Elements**  
   \- Pausing for input with `PauseConsole()`.  
   \- Easily create highly-customizable numbered menus with input, and error handling using `PromptNumberedMenu()`.

5. **Effects and Animations**  
   \- Print a "typewriter" effect with adjustable speed with `PrintTypingTextEffect()`.  
   \- Print a spinning line animation for a set duration with `PrintSpinner()`.

6. **Notifications, Errors, Warnings**  
   \- Ready-made formatted text for errors, warnings, or highly customizable notifications.  


---

## Dependencies and Compatibility

- **Dependencies**: The library uses *only* standard C++ headers: `<iostream>`, `<string>`, `<thread>`, `<chrono>`, `<random>`, `<stdexcept>`, `<vector>`, `<limits>`.
- **C++ Version**: Compatible with C++17 and above.
- **Platform Compatibility**:  
	 - **Linux / macOS**: Works by default since these platforms generally support ANSI escape codes in the terminal.  
	 - **Windows**: Requires Windows 10 or later, or an ANSI-enabled terminal. Older Windows versions may need you to enable VT100/ANSI sequences or use third-party libraries (e.g., [ANSICON](https://github.com/adoxa/ansicon)) to see the colors properly.

---

## Getting Started

### Installation

1. Download/clone the **ConsoleTools** repository or copy `ConsoleTools.cpp` and `ConsoleTools.h` into your project.
2. Place both files in your source directory.

### Integration

1. Include the header:
   ```cpp
   #include "ConsoleTools.h" 
2. And that's it! You are now all good to go.
----------

## Library Overview

Below is a in-depth look at each function in the `ConsoleTools` library.

### The Color Struct

The `Color` struct contains static inline ANSI escape codes for coloring your console text. Here’s the list of available colors: *Please note that you can also add your own custom colors in the `ConsoleTools.cpp` file*

-   **Standard Colors**:  
    `Color::RED`
    `Color::ORANGE`
    `Color::YELLOW`
    `Color::GREEN`
    `Color::BLUE`
    `Color::PURPLE`
    `Color::CYAN`
-   **Normal Colors**:  
    `Color::WHITE`
    `Color::GRAY`
    `Color::BLACK`
-   **Light Colors**:  
    `Color::LIGHT_RED`
    `Color::LIGHT_ORANGE`
    `Color::LIGHT_YELLOW`
    `Color::LIGHT_GREEN`
    `Color::LIGHT_BLUE`
    `Color::LIGHT_PURPLE`
    `Color::LIGHT_CYAN`
-   **Reset**:  
    `Color::RESET` (resets any color or style to the console default)

### PauseConsole
```cpp
void PauseConsole(const std::string& message);
``` 

**Pauses the console** until the user presses `Enter`.  
- **message**: A prompt asking the user to press Enter.

### Spacing
```cpp
std::string Spacing(int NumberOfSpaces);
``` 

Generates a string with **`NumberOfSpaces`** line-breaks (`\n`).  
Useful for quickly inserting blank lines.

### Header & AdvancedHeader

```cpp
std::string Header(const std::string& LineCharacter,          // character or string that gets repeated in a line
                   int LineCharacterCount,                    // number of LineCharacters to use in line
                   const std::string& HeaderText,             // text to be used in the middle of the lines
                   const std::string& SpacingCharacter,       // character inbetween the lines and header text
                   const std::string& LineColor,              // color of the lines
                   const std::string& HeaderTextColor,        // color of the header text
                   const std::string& SpacingCharacterColor); // color of the spacing character
```
Creates a symmetrical header with repeated line characters on both sides of a centered text string.

```cpp
std::string AdvancedHeader(const std::string& LeftLineCharacter,   // character to be used in the left line
                           int LeftLineCharacterCount,             // number of characters for left line
                           const std::string& RightLineCharacter,  // character to be used in the right line
                           int RightLineCharacterCount,            // same as left but for right
                           const std::string& HeaderText,
                           const std::string& SpacingCharacter,
                           const std::string& LeftLineColor,       // line color for left
                           const std::string& RightLineColor,      // line color for right
                           const std::string& HeaderTextColor,
                           const std::string& SpacingCharacterColor,
                           bool ResetColorOnEnd);                  // true or false to decide wether to reset color at end of header 
```

Works similarly, but **Left** and **Right** line segments can differ, both in character and color.   

### ProgressBar & AdvancedProgressBar

```cpp
std::string ProgressBar(int CurrentProgress,
                        int MaxProgress,
                        int BarWidth,
                        const std::string& BarColor,
                        bool ShowPercentage,
                        const std::string& PercentageColor);
``` 

-   **`CurrentProgress`**: Current progress value (clamped to `0 .. MaxProgress`)
-   **`MaxProgress`**: The maximum progress value
-   **`BarWidth`**: Width of the bar in characters
-   **`BarColor`**: ANSI color code for the filled portion
-   **`ShowPercentage`**: `true` to display numeric `%`
-   **`PercentageColor`**: Color for the percentage text

```cpp
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
```

-   Extends `ProgressBar` with prefix/suffix text, custom fill/unfilled characters, bracket styling, etc.

### Error & Warning

```cpp
std::string Error(const std::string& Message);
std::string Warning(const std::string& Message);
```

Generate color-coded message strings with a prefix:  
`[ERROR]: your message` in red, or `[WARNING]: your message` in yellow.

### Print Typing Text Effect (typewriter effect)

```cpp
void PrintTypingTextEffect(const std::string& Text,
                           int MinDelayMilliseconds,
                           int MaxDelayMilliseconds);
```

Prints `Text` character-by-character with a random delay between `MinDelayMilliseconds` and `MaxDelayMilliseconds`, emulating typing.

### Notification

```cpp
std::string Notification(const std::string& LeftBorderCharacter,
                         const std::string& InsideCharacter,
                         const std::string& RightBorderCharacter,
                         const std::string& NotificationTypeText, // text before noti text, shown as "INFO" in example
                         const std::string& NotificationText,
                         const std::string& BorderCharacterColor,
                         const std::string& InsideCharacterColor,
                         const std::string NotificationTextColor);
```

Creates a formatted notification string like:

`[!] INFO: This is a notification message` 

All parts can be colored independently.

### PrintSpinner

```cpp
void PrintSpinner(int SpinDurationMs, int SpinSpeedMs);]
```

Prints a spinning line (`|`, `/`, `-`, `\`) in place for `SpinDurationMs` total, advancing frames every `SpinSpeedMs` milliseconds.

### PromptNumberedMenu

```cpp
int PromptNumberedMenu(const std::vector<std::string> Options,  // vector for menu options
                       const std::string SeperatorCharacter,    // character to seperate option number and option text
                       const std::string& PromptMessage,        // message shown above menu options
                       const std::string InputQuestionText,     // text shown after menu is drawn, before user input
                       const std::string MessageColor,          // prompt message color
                       const std::string NumberColor,           // option index number color
                       const std::string SeperatorColor,        // color for seperator character
                       const std::string OptionColor,           // option text color
                       const std::string InputQuestionColor,    // text color for input question
                       const std::string ErrorColor);           // text color for errors, gets reset after
```

-   Prints a list of options with numeric labels.
-   Waits for user to select one by entering its number.
-   Returns the **zero-based index** of the user’s choice, or `-1` on error/invalid input.

----------

## Detailed Usage

### Color Formatting

1.  **Inline usage**:
    
    ```cpp
    std::cout << ConsoleTools::Color::RED << "This is red." 
              << ConsoleTools::Color::RESET << std::endl;
     ```
    Always remember to reset with `ConsoleTools::Color::RESET`.
    
2.  **Using Color with Functions**:  
    Most `ConsoleTools` functions accept parameters for text color. For example:
    
    ```cpp
    std::string header = ConsoleTools::Header(
        "=", // line character
        5,   // number of times to print line character
        "HEADER", // header text
        " ", // spacing character
        ConsoleTools::Color::GREEN,
        ConsoleTools::Color::YELLOW,
        ConsoleTools::Color::CYAN);
        
    std::cout << header << std::endl;
    ```
    

### Text and UI Elements

-   **Headers**: Great for section headings or decorative banners in your CLI.
-   **Spacing**: Insert blank lines to group console sections without manually typing `\n\n`.

### User Interaction

-   **PromptNumberedMenu**:
    
    -   Present the user with multiple numbered options.
    -   Useful for basic text-based UIs without rewriting logic every time.
-   **PauseConsole**:
    
    -   Often used at the end of a program to prevent the console from closing immediately.

### Examples

1.  **Error and Warning**:
    
    ```cpp
    std::cout << ConsoleTools::Error("File not found!") << std::endl;
    std::cout << ConsoleTools::Warning("Disk space is almost full!") << std::endl;
    ```
    
2.  **Typing Effect**:
    
    ```cpp
    ConsoleTools::PrintTypingTextEffect("Hello, World!\n", 30, 120);
    ```
    
    Delays each character by a random time in the 30–120 ms range.
    
3.  **Spinner**:
    
    ```cpp
    std::cout << "Loading, please wait...\n";
    ConsoleTools::PrintSpinner(2000, 150);  // 2 seconds total, spin changes every 150 ms
    std::cout << "Loading complete!\n";
    ```
    
4.  **Advanced Progress Bar**:
    
    ```cpp
    for(int i = 0; i <= 100; i += 10) {
        std::cout << "\r" 
                  << ConsoleTools::AdvancedProgressBar(
                        i, 100, 20, 
                        "Downloading", "Complete",
                        "#", "-", 
                        ConsoleTools::Color::GREEN,
                        ConsoleTools::Color::GRAY,
                        ConsoleTools::Color::WHITE,
                        ConsoleTools::Color::YELLOW,
                        ConsoleTools::Color::LIGHT_BLUE,
                        ConsoleTools::Color::RED,
                        true,  // Show percentage
                        true,  // Show brackets
                        true   // Reset color on end
                   );
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << std::endl;
    ```
    

----------

## Advanced Topics

### ANSI Escape Codes Behavior

-   **Scrolling**: Once your output exceeds the visible console window size, scrolling will occur. This is normal.
-   **Clearing**: These functions do not provide an entire console clearing mechanism, though you could use something like `std::system("clear")` (Unix-like) or `std::system("cls")` (Windows).

### Potential Platform Issues

-   **Windows**: If your program is compiled for Windows 10 or above, ANSI codes should work if you have [VT Processing enabled](https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences).  
    - On older Windows or partial support environments, you might see gibberish like `\033[31m`.
    
-   **Remote Shells / Docker**: Some minimal shells or containers might not interpret ANSI sequences properly. Always test in your target environment.

----------

## Contributing

We welcome contributions of all kinds:

-   **Bug Reports**: Please open an issue with logs or a small test case.
-   **Enhancements**: If you have an idea for a new feature, open a pull request or an issue for discussion.
-   **Documentation**: Typos, clarifications, or expansions to this README are appreciated!

Steps to Contribute:

1.  Fork the repo.
2.  Create a new branch for your feature/bugfix.
3.  Commit and push your changes.
4.  Open a pull request describing what you changed and why.

----------

## License

You are free to use and modify ConsoleTools under the license included in this repository. For details, refer to the `LICENSE` file.

**Happy coding with ConsoleTools!**
