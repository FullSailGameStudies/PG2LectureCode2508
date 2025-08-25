// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
        1.1) where is the file? file path
        1.2) what mode to open the file in?
        1.3) did it work? (don't assume it did)
    2) read/write to the file
    3) CLOSE the file. files are system resources
        OS will create a file HANDLE if it can open the file
        RULE: close the file ASAP



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::string fileName = "2508.csv";
    std::string path = "C:/temp/2508/";
    std::string finalPath = path + fileName;

    // fstream (input and output) logging 
    // ifstream (input), 
    // ofstream (output)
    // 
    // <fstream> header

    //attempts to open the file in output mode
    //will overwrite the file if it is there already
    //unless you open it to append to the end
    //steps 1.1 and 1.2
    //opens a text file
    std::ofstream outFile(finalPath);

    //step 1.3) did it work?
    if (outFile.is_open())
    {
        char delimiter = '?';
        //step 2) write to the file
        //look like using cout
        //use the << (insertion operator) to output data to the file
        outFile << "Batman rules. Aquaman smells." << delimiter << 5;
        outFile << delimiter << 13.7 << delimiter << "true" << delimiter << "The end.";
    }
    else
    {
        std::cout << finalPath << " could not be opened.\n";
    }

    //step 3) CLOSE the file
    outFile.close();

    //step 1) open the file
    std::ifstream inFile(finalPath);
    //step 1.3) did it work?
    if (inFile.is_open())
    {
        //step 2) read the file. Parse the incoming data.
        //use getline to read a line from the file
        std::string line;
        //reads until it finds a \n OR the end of the file
        std::getline(inFile, line);
        //parse the string for the pieces of data
        //use getline to get each piece of data
        std::stringstream lineStream(line);
        std::string data;
        //give it a different delimiter 
        //reads until it finds '?' OR the end of the stream
        std::getline(lineStream, data, '?');
        std::cout << data << "\n";


        try
        {
            std::getline(lineStream, data, '?');
            int iData = std::stoi(data);
            std::cout << iData << "\n";

            std::getline(lineStream, data, '?');
            double dData = std::stod(data);
            std::cout << dData << "\n";

            std::getline(lineStream, data, '?');
            bool bData = std::stoi(data);
            std::cout << bData << "\n";
        }
        //can have multiple catch blocks
        //the more SPECIFIC catch blocks come first
        catch (const std::exception& ex)
        { //handling the exception
            std::cout << "Exception thrown while reading the data.\n";
            std::cout << ex.what() << "\n";
        }
        std::getline(lineStream, data, '?');
        std::cout << data << "\n";
    }
    else
    {
        std::cout << finalPath << " could not be opened.\n";
    }

    //step 3) CLOSE the file
    inFile.close();

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}