/* Benyamain Yacoob
Intro to Programming I
11-10-21
Project #2 */  
  
#include <iostream>
  
using namespace std;

int main () 
{
  
  // Declaration of variables
  const int ARRAY_SIZE = 8;  // Array size declarator
  const int MAX_PASSWORD_ATTEMPTS = 5;    // User has only five attempts to type in a valid password
  const int MIN_PASSWORD_LENGTH = 6;  // Minimum digit requirement to meet a valid password
  const int MAX_PASSWORD_LENGTH = 8;  // Maximum digit requirement to meet a valid password
  const int MAX_PAIR_REPEATED_DIGITS = 1; // Only 1 pair of digit can be repeated
  int arrayPassword[ARRAY_SIZE], trials = 0;
  bool passwordIsInvalid = true;
    
  // User prompt that asks for a password input; DISPLAYS message
  cout << "Thank you for choosing Amazon!\n\nFor your package security purposes\n";
  
  while (passwordIsInvalid && trials < MAX_PASSWORD_ATTEMPTS)
    {
        trials++;   // Each time that user fails to meet validity
      
        // Declaration inside of the while loop in order to reset after each iteration
        int length = 0, repeatedDigit = 0, oddVal = 0, password = 0,temp1 = 0, temp2 = 0;
     
        cout << "Please enter a valid password: ";
        cin >> password;    // INPUT
      
        temp1 = password;    // Store as a temporary variable because iteration forces a reset
        temp2 = password;   // Variable to be used when echoing output
        
        // Finds length of array
        while (temp1)
        {
            temp1 /= 10; // Finding number of entered digits
	        length++;	 
        }
	    // Meets password limit requirements
	    if (length >= MIN_PASSWORD_LENGTH && length <= MAX_PASSWORD_LENGTH && trials < MAX_PASSWORD_ATTEMPTS)
        {
            for (int i = length - 1; i >= 0; i--)
            {
	           arrayPassword[i] = password % 10;    // Stores values into array
	           password /= 10;  // Updates the password size
            }	
            for (int i = 0; i < length; i++)
            {
                if (arrayPassword[i] % 2 != 0)  // Algorithm that determines if some stored array value is odd
                    oddVal++;
                
                // Algorithm that determines if there is more than one pair of a digit being repeated
                if (arrayPassword[i] == arrayPassword[i + 1])
                    repeatedDigit++;
            }
            if (repeatedDigit > 1)
            {	     
                cout << "\n" << temp2 << " has more than 1 pair of repeated digits.\n";
                passwordIsInvalid = true;   // Violates the repeated digit requirement
                continue;
            }
            else if (repeatedDigit < 1)
            {
                cout << "\n" << temp2 << " has less than 1 pair of repeated digits.\n";
                passwordIsInvalid = true;
                continue;
            }
            else if (oddVal == 0)
            {
                passwordIsInvalid = true;
                cout << "\n" << temp2 << " has no odd values.\n";
                continue;
            }
        }    
        // Runs if entered digits meet odd & repeated digits requirement
        if (oddVal > 0 && repeatedDigit == MAX_PAIR_REPEATED_DIGITS)
        {   
            passwordIsInvalid = false;
            cout << "\nYour password " << temp2 << " is valid.";
        }
        else if (trials > MAX_PASSWORD_ATTEMPTS)
            break;
           
        else if (length > MAX_PASSWORD_LENGTH)	// Tells user password is invalid if more than 8 digits
        {
            cout << temp2 << " has a password size that is greater than 8.\n";
	  
            passwordIsInvalid = true;
            continue;
        }
        else if (length < MIN_PASSWORD_LENGTH)	// Tells user password is invalid if less than 6 digits
        {
            cout << temp2 << " has a password size that is less than 6.\n";
	  
            passwordIsInvalid = true;
            continue;
        }
    }
  if (trials == MAX_PASSWORD_ATTEMPTS)  // User has reached maximum attempts to enter
    cout << "\nToo many trials. Please come back another time.";
    
  // OUTPUT
  cout << "\nHave a great day!";
    
    return 0;
}
