//
// Created by Teni on 10/9/2022.
//
#include "Thing.h"

Thing::Thing() {
    this->name = "";
    this->description = "";
}

Thing::Thing(std::string arg_name, std::string arg_description) {
    this->name = arg_name;
    this->description = arg_description;
}

Thing::Thing(Person arg_owner) {
    this->name = "";
    this->description = "";
    this->owner = arg_owner;
}

std::string Thing::getName() {
    return this->name;
}

void Thing::setName(std::string newName) {
    this->name = newName;
}

std::string Thing::getDescription() {
    return this->description;
}

void Thing::setDescription(std::string newDescription) {
    this->description =  newDescription;
}

Person Thing::getOwner() {
    return this->owner;
}

void Thing::setOwner(Person newOwner) {
    this->owner =  newOwner;
}
bool Thing::isBlankThing(){
    return (this->name == "");
}

Json::Value Thing::dump2JSON() {
    Json::Value result { };

    if (this->name != "")
    {
        result["name"] = this->name;
    }

    if (this->description != "")
    {
        result["description"] = this->description;
    }

    Json::Value jv_result;

    jv_result = (this->owner).dump2JSON();
    result["owner"] = jv_result;

    return result;
}

bool Thing::JSON2Object(Json::Value input){
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
    if (((input["description"]).isNull() == true) ||
        ((input["description"]).isString() != true))
    {
        return false;
    }
    this->description = (input["description"]).asString();
    if ((input["owner"].isNull() == true) ||
        (input["owner"].isObject() != true))
    {
        return false;
    }
    this->owner.JSON2Object(input["owner"]);
    return true;
}