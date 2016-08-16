#include <iostream>
#include <cstdlib> 
#include <cstring>
#include "Prompt.h"
#include "Connector.h"
#include "Command.h"

using namespace std; 

int main() {
    
    char input[100]; 
    char * command;  
    cout << "Enter commands: "; 
    while (cin >> input) {
    
        command = strtok(input, ";||&&"); 
        cout << command << "\n"; 
    } 
    
   

    return 0; 
    
}
