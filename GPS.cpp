//
// Created by Fatima Shaik on 10/9/22.
// .cpp for GPS

#include "GPS.h"
//GPS Constructors
GPS::GPS(){
    this->name = "";
    this->locatedIn = "";
    this->landmarks = "";
    this->leagues = 0;
}
GPS::GPS(std::string arg_name, std::string arg_locatedIn, std::string arg_landmarks, double arg_leagues){
    this->name = arg_name;
    this->locatedIn = arg_locatedIn;
    this->landmarks = arg_landmarks;
    this->leagues = arg_leagues;
}

GPS::GPS(std::string arg_name, std::string arg_locatedIn){
    this->name = arg_name;
    this->locatedIn = arg_locatedIn;
    this->leagues = 0.0;
}

GPS::GPS(std::string arg_name, std::string arg_landmarks, double arg_leagues){
    this->name = arg_name;
    this->landmarks = arg_landmarks;
    this->leagues = arg_leagues;
}

//returns name of location
std::string GPS::getName(){
    return this->name;
}
//returns where location is located (like if it's in the Woods or Village)
std::string GPS::getLocatedIn(){
    return this->locatedIn;
}
//returns the landmarks or surrounding items of the location
std::string GPS::getLandmarks(){
    return this->landmarks;
}
//returns how far the location is from the village (units are in leagues)
double GPS::getLeagues(){
    return this->leagues;
}
//returns contents of location in a JSON format
Json::Value GPS::dump2JSON
        () {
    Json::Value result;
    if (this->name  != "") {
        result["name"] = this->name;
    }

    if (this->locatedIn  != "") {
        result["locatedIn"] = this->locatedIn;
    }
    if (this->landmarks  != "") {
        result["landmarks"] = this->landmarks;
    }
    if (this->leagues != 0.0) {
        result["leagues"] = this->leagues;
    }
    return result;
}
bool GPS::JSON2Object(Json::Value input){
    this->name = (input["name"]).asString();
    this->locatedIn = (input["locatedIn"]).asString();
    this->landmarks = (input["landmarks"]).asString();
    this->leagues = (input["leagues"]).asDouble();
    return true;
}
