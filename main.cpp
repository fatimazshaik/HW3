//
// Created by Fatima Shaik on 10/9/22.
// main file which creates/prints all the Records

#include <iostream>
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"
#include "Thing.h"
#include "Record.h"
#include "ecs36b_JSON.cpp"
#include <fstream>

int main() {
    GPS LittleRedHouse = GPS ("Red's and her Mother's House", "Village", 0.0);
    Person LittleRedRidingHood = Person("Little Red Riding Hood", LittleRedHouse);
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    Thing Cap = Thing("Cap", "a head covering");
    Cap.setOwner(LittleRedRidingHood);
    //First Record: Little Red Ridding Hood wore the Cap.
    Record First = Record(Cap, LittleRedRidingHood, LittleRedHouse, *getNowJvTime());

    Thing Cake = Thing("Cake", "a sweet desert");
    Thing Wine = Thing("Wine", "a drink");
    Person Mother = Person("Mother", LittleRedHouse);
    LittleRedRidingHood.setLocation(LittleRedHouse, *getNowJvTime());
    Cake.setOwner(LittleRedRidingHood);
    Wine.setOwner(LittleRedRidingHood);
    //Second Record: Her mom gave her the cake and wine.
    Record Second = Record(Cake, Wine, LittleRedRidingHood, Mother, LittleRedHouse, *getNowJvTime());

    GPS meetingSpot = GPS ("entrance of the woods", "Woods");
    GPS wolfHome = GPS("Somewhere in woods", "Woods");
    Person Wolf = Person("Wolf", wolfHome);
    LittleRedRidingHood.setLocation(meetingSpot, *getNowJvTime());
    Wolf.setLocation(meetingSpot, *getNowJvTime());
    //Third Record: Little Red met the wolf at a particular spot in the wood
    Record Third = Record (LittleRedRidingHood, Wolf, meetingSpot, *getNowJvTime());

    GPS grandmotherHouse = GPS("Grandma's house", "end of Woods", "three large oak", 0.5);
    Person Grandma = Person("Grandma", grandmotherHouse);
    Grandma.setLocation(grandmotherHouse, *getNowJvTime());
    //Fourth Record: Grandma was at her own home right outside of the wood and there were three large oak trees nearby
    Record Fourth = Record(Grandma, grandmotherHouse, *getNowJvTime());

    //HW Three Stuff
    Json::Value first = First.dump2JSON();
    Json::Value second = Second.dump2JSON();
    Json::Value third = Third.dump2JSON();
    Json::Value fourth = Fourth.dump2JSON();
    myJSON2File("test1.txt", &first);
    myJSON2File("test2.txt", &second);
    myJSON2File("test3.txt", &third);
    myJSON2File("test4.txt", &fourth);
    //Create four new Json::Value objects
    Json::Value newFirst;
    Json::Value newSecond;
    Json::Value newThird;
    Json::Value newFourth;
    //Takes the content of file, converts them to JSON and stores them in the four
    //Json::Value objects that were previously created
    myFile2JSON("test1.txt", &newFirst);
    myFile2JSON("test2.txt", &newSecond);
    myFile2JSON("test3.txt", &newThird);
    myFile2JSON("test4.txt", &newFourth);
    //Create four blank record objects
    Record firstEvent;
    Record secondEvent;
    Record thirdEvent;
    Record fourthEvent;
    //Filling in the empty record objects
    firstEvent.JSON2Object(newFirst);
    secondEvent.JSON2Object(newSecond);
    thirdEvent.JSON2Object(newThird);
    fourthEvent.JSON2Object(newFourth);
    //Printing the JSON dump of the four new records
    std::cout << "First Record from file" << std::endl;
    std::cout << (firstEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Second Record from file" << std::endl;
    std::cout << (secondEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Third Record from file" << std::endl;
    std::cout << (thirdEvent.dump2JSON()).toStyledString() << std::endl;
    std::cout << "Fourth Record from file" << std::endl;
    std::cout << (fourthEvent.dump2JSON()).toStyledString() << std::endl;
}


