#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <tuple>

class SelectionOption {
private:
	std::string text;
public:
	SelectionOption() {
		text = "[Option]";
	}
	SelectionOption(std::string text) {
		this->text = text;
	}
	void setText(std::string text) {
		this->text = text;
	}
	std::string getText() {
		return text;
	}
};

class Selection {
private:
	std::vector<SelectionOption> options;

	std::string selectedOptionPrefix;
	std::string selectedOptionSuffix;

	std::string textColor;
	std::string selectedTextColor;
	std::string backgroundColor;
	std::string selectedBackgroundColor;

	std::string getTextColorCode(std::string colorName) {
		if (colorName == "black") {
			return "\033[30";
		}
		else if (colorName == "red") {
			return "\033[31";
		}
		else if (colorName == "green") {
			return "\033[32";
		}
		else if (colorName == "yellow") {
			return "\033[33";
		}
		else if (colorName == "blue") {
			return "\033[34";
		}
		else if (colorName == "magenta") {
			return "\033[35";
		}
		else if (colorName == "cyan") {
			return "\033[36";
		}
		else if (colorName == "white") {
			return "\033[37";
		}
		else if (colorName == "reset" || colorName == "default" || colorName == "normal" || colorName == "none") {
			return "\033[0";
		}
		else {
			return "";
		}
	}
	std::string getBackgroundColorCode(std::string colorName) {
		if (colorName == "black") {
			return ";40m";
		}
		else if (colorName == "red") {
			return ";41m";
		}
		else if (colorName == "green") {
			return ";42m";
		}
		else if (colorName == "yellow") {
			return ";43m";
		}
		else if (colorName == "blue") {
			return ";44m";
		}
		else if (colorName == "magenta") {
			return ";45m";
		}
		else if (colorName == "cyan") {
			return ";46m";
		}
		else if (colorName == "white") {
			return ";47m";
		}
		else if (colorName == "reset" || colorName == "default" || colorName == "normal" || colorName == "none") {
			return "m";
		}
		else {
			return "m";
		}
	}
	void printSelection(std::vector<SelectionOption> options, int selected, std::tuple<std::string, std::string> prefixSuffix, std::tuple<std::string, std::string, std::string, std::string> colors) {

		std::string textColor = getTextColorCode(std::get<0>(colors)); // text color code
		std::string selectedTextColor = getTextColorCode(std::get<1>(colors)); // selected text color code

		std::string backgroundColor = getBackgroundColorCode(std::get<2>(colors)); // background color code
		std::string selectedBackgroundColor = getBackgroundColorCode(std::get<3>(colors)); // selected background color code

		std::string colorText = textColor + backgroundColor; // color code for text (text color and background color)
		std::string colorSelectedText = selectedTextColor + selectedBackgroundColor; // color code for selected text (text color and background color)

		std::cout << colorText; // Set text color
		for (int counter = 0; counter < options.size(); counter++) {
			std::cout << "						";

			if (selected == counter) {
				std::cout << std::get<0>(prefixSuffix); // Selected character prefix 
				std::cout << colorSelectedText; // Set selected text color
			}
			else {
				for (int i = 0; i < std::get<0>(prefixSuffix).length(); i++) {
					std::cout << " ";
				}
			}
			std::cout << options[counter].getText(); // Print selection

			if (selected == counter) {
				std::cout << colorText; // Set text color
				std::cout << std::get<1>(prefixSuffix); // Selected character suffix
			}
			else {
				for (int i = 0; i < std::get<1>(prefixSuffix).length(); i++) { // Spaces after non selected options
					std::cout << " ";
				}
			}
			std::cout << "\n"; // Newline
		}

		std::cout << getTextColorCode("none") + getBackgroundColorCode("none"); // Reset text color and background color
	}

public:

	Selection() {
		options.push_back(SelectionOption("[Option 1]"));
		options.push_back(SelectionOption("[Option 2]"));
		options.push_back(SelectionOption("[Option 3]"));
		selectedOptionPrefix = ">> ";
		selectedOptionSuffix = " <<";
		textColor = "white";
		selectedTextColor = "red";
		backgroundColor = "none";
		selectedBackgroundColor = "none";
	}
	Selection(std::vector<SelectionOption> options) {
		this->options = options;
		selectedOptionPrefix = ">> ";
		selectedOptionSuffix = " <<";
		textColor = "white";
		selectedTextColor = "red";
		backgroundColor = "none";
		selectedBackgroundColor = "none";
	}
	Selection(std::vector<SelectionOption> options, std::string selectedOptionPrefix, std::string selectedOptionSuffix) {
		this->options = options;
		this->selectedOptionPrefix = selectedOptionPrefix;
		this->selectedOptionSuffix = selectedOptionSuffix;
		textColor = "white";
		selectedTextColor = "red";
		backgroundColor = "none";
		selectedBackgroundColor = "none";
	}
	Selection(std::vector<SelectionOption> options, std::string selectedOptionPrefix, std::string selectedOptionSuffix, std::string textColor, std::string selectedTextColor, std::string backgroundColor, std::string selectedBackgroundColor) {
		this->options = options;
		this->selectedOptionPrefix = selectedOptionPrefix;
		this->selectedOptionSuffix = selectedOptionSuffix;
		this->textColor = textColor;
		this->selectedTextColor = selectedTextColor;
		this->backgroundColor = backgroundColor;
		this->selectedBackgroundColor = selectedBackgroundColor;		
	}
	
	/// <summary>
	/// Set default text color (black, red, green, yellow, blue, magenta, cyan, white, reset|default|none|normal).
	/// </summary>
	/// <param name="String color"></param>
	void setTextColor(std::string color) {
		textColor = color;
	}
	/// <summary>
	/// Set selected text color (black, red, green, yellow, blue, magenta, cyan, white, reset|default|none|normal).
	/// </summary>
	/// <param name="String color"></param>
	void setSelectedTextColor(std::string color) {
		selectedTextColor = color;
	}
	/// <summary>
	/// Set default background color (black, red, green, yellow, blue, magenta, cyan, white, reset|default|none|normal).
	/// </summary>
	/// <param name="String color"></param>
	void setBackgroundColor(std::string color) {
		backgroundColor = color;
	}
	/// <summary>
	/// Set selected background color (black, red, green, yellow, blue, magenta, cyan, white, reset|default|none|normal).
	/// </summary>
	/// <param name="String color"></param>
	void setSelectedBackgroundColor(std::string color) {
		selectedBackgroundColor = color;
	}
	/// <summary>
	/// Set all colors (black, red, green, yellow, blue, magenta, cyan, white, reset|default|none|normal).
	/// </summary>
	/// <param name="String color"></param>
	void setColors(std::string textColor, std::string selectedTextColor, std::string backgroundColor, std::string selectedBackgroundColor) {
		this->textColor = textColor;
		this->selectedTextColor = selectedTextColor;
		this->backgroundColor = backgroundColor;
		this->selectedBackgroundColor = selectedBackgroundColor;
	}

	/// <summary>
	/// Set options.
	/// </summary>
	/// <param name="vector<SelectionOption> options"></param>
	void setOptions(std::vector<SelectionOption> options) {
		this->options = options;
	}
	/// <summary>
	/// Add one option to options vector.
	/// </summary>
	/// <param name="SelectionOption option"></param>
	void addOption(SelectionOption option) {
		options.push_back(option);
	}
	/// <summary>
	/// Remove option with int index.
	/// </summary>
	/// <param name="Int index"></param>
	void removeOption(int index) {
		options.erase(options.begin() + index);
	}
	/// <summary>
	/// Remove option with string text.
	/// </summary>
	/// <param name="String text"></param>
	void removeOption(std::string text) {
		for (int i = 0; i < options.size(); i++) {
			if (options[i].getText() == text) {
				options.erase(options.begin() + i);
				break;
			}
		}
	}
	/// <summary>
	/// Returns options as vector.
	/// </summary>
	/// <returns>Vector options</returns>	
	std::vector<SelectionOption> getOptions() {
		return options;
	}

	/// <summary>
	/// Set prefix and suffix of selected option.
	/// </summary>
	/// <param name="String prefix
	/// String suffix"></param>
	void setPrefixSuffix(std::string prefix, std::string suffix) {
		selectedOptionPrefix = prefix;
		selectedOptionSuffix = suffix;
	}
	/// <summary>
	/// Set prefix of selected option.
	/// </summary>
	/// <param name="String prefix"></param
	void setSelectedPrefix(std::string selectedOptionPrefix) {
		this->selectedOptionPrefix = selectedOptionPrefix;
	}
	/// <summary>
	/// Set suffix of selected option.
	/// </summary>
	/// <param name="String suffix"></param
	void setSelectedSuffix(std::string selectedOptionSuffix) {
		this->selectedOptionSuffix = selectedOptionSuffix;
	}

	/// <summary>
	/// Start selection.
	/// </summary>
	int Start() {
		int selected = 0; // Selected option
		char userInput = '\0'; // User input
		bool hasToPrint = false; // If true, the selection will be reprinted
		
		std::tuple<std::string, std::string> prefixSuffix = std::make_tuple(selectedOptionPrefix, selectedOptionSuffix); // Prefix and suffix of selected option
		std::tuple<std::string, std::string, std::string, std::string> colors = std::make_tuple(textColor, selectedTextColor, backgroundColor, selectedBackgroundColor); // Text and background colors and selected option
		
		printSelection(options, selected, prefixSuffix, colors); // Prints the selection
		
		do {
			if (_kbhit) { // If user pressed a key
				userInput = _getch(); // Get pressed key
				hasToPrint = false;

				if (userInput == 13 || userInput ==  32) { // If user pressed enter or spacebar
					hasToPrint = true;
					return selected;
				}
				else if (userInput == 'w' || userInput == 72) { // If user pressed up
					if (selected > 0) { // If selected is not the first option
						hasToPrint = true; // Print the selection
						selected--; // Decrease selected by 1
					}
				}
				else if (userInput == 's' || userInput == 80) { // If user pressed down
					if (selected < options.size() - 1) { // If selected is not the last option
						hasToPrint = true; // Print the selection
						selected++; // Increase selected by 1
					}
				}
				else { // If user pressed any other key
					hasToPrint = false; // Don't print the selection
				}

				if (hasToPrint) {
					std::cout << "\x1B[2J\x1B[H"; // "Clear" the screen
					printSelection(options, selected, prefixSuffix, colors); // Print the selection
				}

			}
		} while (userInput != 13 && userInput != 32); // If user pressed enter or spacebar

	}
};

