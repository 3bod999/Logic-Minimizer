#include <iostream>
#include <string>
#include <kitty/kitty.hpp>

using namespace kitty;
using namespace std;

int main() {
    string expr; // Variable to store the user's input equation
    
    // Display instructions to the user
    cout << "Enter equation (use ! for NOT, & for AND, | for OR): \n>> ";
    cout << "Enter your equation (e.g., (a&b)|(a&!b)): " <<  endl;
    
    // Read the full line of text entered by the user
    getline(cin, expr);

    // 1. Define a Truth Table for up to 4 variables (a, b, c, d)
    // This creates a table with 16 possible combinations (2^4 = 16)
    static_truth_table<4> tt;

    // 2. Convert the string expression into the truth table
    // This function maps characters 'a','b','c','d' to variables 0,1,2,3
    create_from_formula(tt, expr, {"a", "b", "c", "d"});

    // 3. Minimize the logic using ISOP (Irredundant Sum of Products) algorithm
    // This removes unnecessary variables and simplifies the expression
    auto sop = isop(tt);

    cout << "\nSimplified result: ";
    
    // If the SOP is empty, it means the result is always 0 (False)
    if (sop.empty()) {
         cout << "0" << endl;
    } else {
        // Loop through each simplified term (called a 'cube')
        for (auto it = sop.begin(); it != sop.end(); ++it) {
            
            // Print '|' (OR) between different terms
            if (it != sop.begin()) cout << " | ";
            
            // Loop through the 4 variables to see which ones remain
            for (int i = 0; i < 4; ++i) {
                
                // Check if variable 'i' exists in the current simplified term
                if (it->get_mask(i)) {
                    
                    // If the variable is negative (0), print '~' before it
                    if (!it->get_bit(i)) cout << "~";
                    
                    // Convert index (0-3) to character ('a'-'d') and print it
                    cout << (char)('a' + i);
                }
            }
        }
        cout << endl; // Move to a new line
    }

    return 0; // End of the program
}
