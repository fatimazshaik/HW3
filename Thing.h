//
// Created by Teni on 10/9/2022.
//

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include "Person.h"

#ifndef _THING_H_
#define _THING_H_

    class Thing {
    protected:
    private:
        std::string name;
        std::string description;
        Person owner;
    public:
        explicit Thing();
        explicit Thing(std::string arg_name, std::string arg_description);
        explicit Thing(Person arg_owner);
        bool isBlankThing();

        //Person owner;

        std::string getName();
        void setName(std::string newName);
        std::string getDescription();
        void setDescription(std::string newDescription);
        Person getOwner();
        void setOwner(Person newOwner);

        Json::Value dump2JSON();
        bool JSON2Object(Json::Value);
    };
#endif