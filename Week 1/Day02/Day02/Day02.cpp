#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

bool postFix(std::string hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

//print is not allowed to modify the const parameter
void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (auto& score : scores)
    {
        //score += 5;
        std::cout << index++ << ". " << score << "\n";
    }
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//when to use pass by reference?
// 1) for any type that is a class
// 2) when I need to update the variable in a different scope
// 3) when I want to improve performance

//BENEFITS:
//- prevents a copy (better performance)
//- allows a variable to be changed in a different scope
void PrintMe(int& num)
{
    std::cout << num;
}
int Update(int num)//copy 1
{
    num += 10;
    return num;//copy 2
}

enum Materials
{
    Wood = 10, Stone, Copper, Iron, Diamond
};
int main()
{
    //  type name;
    int n;// = 5;
    n = 5;
    n = Update(n);
    PrintMe(n);//creating an alias. num is an alias to n
    std::cout << n;
    //PrintMe(200);//200 is copied to num
    //copies are "expensive" b/c 
    // a new variable must be created and the value copied to it
    // 
    //a reference variable "points" to an existing variable
    // type& name = existingVariable;
    // name is now an ALIAS for another variable
    int& nRef = n;//nRef is now a new NAME for n. they are the same.
    nRef += 10;
    std::cout << n;//15
    int n2 = 10;
    nRef = n2;//copies n2 to nRef (n)
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.SetName("PG2-2508");
    std::cout << pg2.GetName() << "\n";
    pg2.GetGrades(grades);
    std::cout << "\n\nGrades...\n";
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }
    std::cout << "\n\n";

    const int upperLimit = 10;


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}