/**
 * main.cpp
 *
 * FERRER, Matt Brycen L.
 * ENGG 24 - F
 * Bit Manipulations
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// prints the bit representation of the 32-bit unsigned int x
void printBitRep(unsigned int x)
{
  unsigned int mask = 1 << 31;  // start with first bit

  while (mask)  // print one bit at a time
  {
    if (x & mask)
    {
      cout << "1 ";
    }
    else 
    {
      cout << "0 ";
    }
    mask >>= 1;  // shift selected bit by 1
  }
}

int main()
{
  // 32-bit unsigned int whose bits are to be manipulated
  unsigned int bit_manip = 0;
  string input = "";
  string command = "";

  // print opening lines
  cout << "Bit Manipulations - Commands: \n";
  cout << "on [bit list]\n";
  cout << "off [bit list]\n";
  cout << "toggle [bit list]\n";
  cout << "exit\n\n";

  while (true)  // program loop
  {
    bool is_valid_bitlist = true;
    int bit = 0;  // stores place of bit to be changed
    unsigned int bitmask = 0;

    // get input from user
    printBitRep(bit_manip);  // display bit representation
    cout << "\nEnter command: ";
    getline(cin, input);
  
    // parse command
    istringstream iss(input);
    iss >> command;  // parse first token in input = command

    if (command == "exit")  // exit command
    {
      cout << "Exiting program.\n";
      break;
    }

    // parse bit list
    while (iss >> bit)
    {
      if ((0 <= bit) && (bit <= 31))  // check if in valid range
      {
        bitmask = bitmask | (1 << bit);  // turn on bit
      }
      else
      {
        is_valid_bitlist = false;
        break;
      }
    }
    // check for invalid characters or bits out of range
    if ((!is_valid_bitlist) || (!iss.eof())) 
    {
      cout << "Invalid input. Please enter bits from 0 to 31.\n";
      continue;
    }

    // process command
    if (command == "on")  // on command
    {
      bit_manip = bit_manip | bitmask;  // OR
    }
    else
    {
      if (command == "off")  // off command
      {
        bit_manip = bit_manip & (~bitmask);  // AND with NOR
      }
      else
      {
        if (command == "toggle")  // toggle command
        {
          bit_manip = bit_manip ^ bitmask;  // XOR
        }
        else  // invalid command
        {
          cout << "Invalid command.\n";
        }
      }
    }
  }

  return 0;
}
