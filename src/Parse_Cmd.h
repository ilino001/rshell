#ifndef PARSECMD_H
#define PARSECMD_H

#include <iostream>
#include <sstream> 
#include <vector> 
#include <string> 
#include <cstring> 

//using namespace std;

//uses all files 
#include "Base.h"
#include "Command.h" 
#include "Connector.h"
#include "Precedence.h"

class Parse_Cmd 
{ 
    public: 
        //constructor 
        Parse_Cmd() {};
        
        //constructor that painputes in stringstream 
            //to input each char that is being painputed in 
        Base* parse(std::stringstream &input, Base* v = 0)
        {
            
            std::string line;
            std::vector<std::string> command_list; //vector to store the commands by the user
           // int curr_status = -1; //keeps track of the status of the commands
            
            int Status = -1;
            
            Base* pre_counter = 0; 
            
            //as it is taking user input 
            while (input >> line) 
            {
                
                if (line.at(0) == '(')
                {
                    line = line.substr(1); 
                    int num_predence = 1;
                    char c;
                    bool inside_quotes = false;
                    
                    while ( (num_predence > 0) )
                    {
                        if (!(input.get(c)))
                        {
                            std::cout << "> ";
                            std::string tempString;
                            std::string space = " ";
                            getline(std::cin, tempString);
                           
                            tempString = space + tempString;
                            input.str(tempString);
                            input.clear();
                            c = input.get();
                        }
                        if (c == '"')
                        {
                            inside_quotes = !inside_quotes; //toggle quotes
                        }
                        else if (c == '(' && !inside_quotes)
                        {
                            num_predence++;
                        }
                        else if (c == ')' && !inside_quotes)
                        {
                            num_predence--;
                        }
                        
                        line += c;
                        
                    }
                    
                    
                    line = line.substr(0, line.size() - 1); 
                    std::stringstream output(line);
                    pre_counter = new Precedence(this->parse(output)); 
                }
                else 
                {
                    bool is_comment = false; 
                    for (unsigned i = 0; i < line.size(); ++i) 
                    {
                        if(line.at(i) == '#') 
                        {
                            line = line.substr(0, i); 
                            is_comment = true; 
                        }
                    }
                    if (is_comment) 
                    {
                        break; 
                    }
                }
                
                if (line.at(line.size() - 1) == ';') 
                {
                    Status = another;
                    command_list.push_back(line.substr(0, line.size() - 1)); 
                    break; 
                }
                
                // look for || in string line
                else if (strcmp(line.c_str(), "||") == 0) 
                {
                    Status = fails;
                    break; 
                }
                
                // look for && in string line
                else if (strcmp(line.c_str(), "&&") == 0) 
                {
                    Status = works;
                    break; 
                }
                else
                {
                    command_list.push_back(line);
                }

            } // end of while loop
            
            char** argvs = new char*[command_list.size() + 1];

            for (unsigned int i = 0; i < command_list.size(); ++ i) 
            {
                argvs[i] = new char[command_list.at(i).size() + 1]; 
                strcpy(argvs[i], command_list.at(i).c_str()); 
            }

            argvs[command_list.size()] = 0;
            
            
            Base* tempCmd = (pre_counter == 0) ? new Command(argvs) : pre_counter; //create new command with arguments
            

            if(v == 0) //no connector
            {
                v = tempCmd;
            }
            else
            {
                v->Right((tempCmd)); //place new command in tree if not first command
            }
            if(Status == -1) //base case return if there's no next connector
            {
                return v;
            }
            else
            {
            
                //recursively construct commands from the rest of the line
                Base* newCon = new Connector(Status);//Status);
              //  Base* newCon = new Connector((Status) Status);// Status;
                newCon->Left(v);
                v = newCon;
                return parse(input, v);
            }
            
            return parse(input, v);
        };

};
#endif 
