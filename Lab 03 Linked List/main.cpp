//
//  main.cpp
//  Lab 03 Linked List
//
//  Created by C/R
//


#include <iostream>
#include <fstream>
#include "LinkedListInterface.h"
#include "LinkedList.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, const char * argv[])
{
    VS_MEM_CHECK;
    //Checking for correct number of arguments
    if (argc < 3)
    {
       std::cerr << "Please provide the name of input and output files, thanks\n";
       return 1;
    }
    
    //Checking if input file opens
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Failure to open input file: " << argv[1] << std::endl;
        return 2;
    }
    
    //Checking if output file opens
    std::ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        std::cerr << "Failure to open output file: " << argv[1] << std::endl;
        return 3;
    }
    
    LinkedList<std::string> linkedList;

    linkedList.clear();

    std::string command = " ";
    for (std::string line; getline(in, line);)
     {
         std::istringstream iss(line);
         try
         {
             //getting the command
             iss >> command;
             out << command;
             if (command == "Clear")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         linkedList.clear();
                        if (linkedList.empty())
                         {
                             out << " OK";
                         }
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Size")
             {
                 out << " " << linkedList.size();
             }
             else if (command == "Empty")
             {
                 if (linkedList.empty())
                 {
                     out << " true";
                 }
                 else
                 {
                     out << " false";
                 }
             }
             else if (command == "PrintList")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         out << "  " << linkedList;
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Delete")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         std::string temp = linkedList.front();
                         linkedList.pop_front();
                         if (linkedList.front() != temp) out << " OK";
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "First")
             {
                 try
                    {
                        if (linkedList.empty())
                        {
                            throw std::string(" Empty!");
                        }
                        else
                        {
                            out << " " << linkedList.front();
                        }
                } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
        }
             else if (command == "Insert")
             {
                 std::string value = " ";
                 while (iss >> value)
                 {
                     out << " " << value;
                     linkedList.push_front(value);
                 }
             }
             else if (command == "Remove")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         std::string value = " ";
                         iss >> value;
                         out << " " << value;
                         linkedList.remove(value);
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Reverse")
             {
                 try
                 {
                     linkedList.reverse();
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         out << " OK";
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else {
                 throw std::string(line);
             }
         }  catch(std::string errorString)
             {
                 out << "**Error: " << line << std::endl;
             }
         out << std::endl;
     }
    return 0;
}
