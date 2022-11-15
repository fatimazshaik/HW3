//
// Created by Fatima Shaik on 10/9/22.
// .cpp file for PErson

#include "Person.h"
//Person Constructors:
Person::Person(std::string arg_name, GPS arg_home){
    this->name =arg_name;
    this->home = arg_home;
}

Person::Person(std::string arg_name){
    this->name =arg_name;
}

Person::Person(){
    this->name = "";
    this->home = GPS{};
    this->type = "";
}

//Sets Home Location of Person:
void Person::setHome(GPS arg_home){
    this->home = arg_home;
}

//Sets the current Location of the Person
void Person::setLocation(GPS arg_location, JvTime arg_time){
    this->location = arg_location;
    this->since_when = arg_time;
}

//Returns name of the person
std::string Person::getName(){
    return this->name;
}
std::string Person::getType(){
    return this->type;
}
GPS Person::getHome(){
    return this->home;
}
GPS Person::getLocation(){
    return this->location;
}

JvTime Person::getLocationTime(){
    return this-> since_when;
}

bool Person::isBlankPerson(){
    return (this->name == "");
}

//Dump Method
Json::Value //created empty lang
Person::dump2JSON
        (void)
{
    Json::Value result; //trigger constructor
    //empty json result
//
    if (name != "")
    {
    result["name"] = this->name;
    }

   if (this->type != "")
    {
       result["type"] = this->type;
    }

    Json::Value jv_result;  //empty JSON::Value

    jv_result = (this->home).dump2JSON();
    result["home"] = jv_result;

    jv_result = (this->location).dump2JSON();
    result["location"] = jv_result;

    jv_result = (this->since_when).dump2JSON();
    result["since_when"] = jv_result;

    return result;
}
bool Person::JSON2Object(Json::Value input){
    if ((input.isNull() == true) ||
        (input.isObject() != true))
    {
        return false;
    }

    if (((input["name"]).isNull() == true) ||
        ((input["name"]).isString() != true))
    {
        return false;
    }
    this->name = (input["name"]).asString();
    this->type = (input["type"]).asString();
    if (((input["home"]).isNull() == true) ||
        ((input["location"]).isNull() == true) ||
        ((input["home"]).isObject() != true) ||
        ((input["location"]).isObject() != true))
    {
        return false;
    }
    this->home.JSON2Object(input["home"]);
    this->location.JSON2Object(input["location"]);
    if (((input["since_when"]).isNull() == true) ||
        ((input["since_when"]).isObject() != true))
    {
        return false;
    }
    this->since_when.JSON2Object(input["since_when"]);
   return true;
}
