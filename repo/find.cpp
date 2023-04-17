#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    // Define the four-byte string to search for
    char search_str[] = "bKqU";

    // Read 2000 random characters from a text file
    std::ifstream infile("random_chars.txt", std::ios::binary);
    infile.seekg(0, std::ios_base::end);
    int length = infile.tellg();
    infile.seekg(0, std::ios_base::beg);
    char* random_chars = new char[length];
    infile.read(random_chars, length);

    // Search for the first character of the four-byte string
    char* index = std::strstr(random_chars, search_str);

    // If the first character is found, continue searching for the remaining three characters
    while (index != NULL && index < random_chars + length - 3) {
        if (std::memcmp(index, search_str, 4) == 0) {
            // Found the four-byte string, output the position and exit the loop
            std::cout << "Found at position " << index - random_chars << std::endl;
            break;
        }
        else {
            // Continue searching for the next character position
            index = std::strstr(index + 1, search_str);
        }
    }

    if (index == NULL || index >= random_chars + length - 3) {
        // The four-byte string was not found
        std::cout << "Not found." << std::endl;
    }

    delete[] random_chars;
    return 0;
}
