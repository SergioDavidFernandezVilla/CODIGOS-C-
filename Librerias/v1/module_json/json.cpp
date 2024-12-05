#include "json.h"
#include <stdexcept>
#include <sstream>
#include <cstdio>

using namespace std;

// Constructores
Json::Json(const string& str) : value(str) {}
Json::Json(double num) : value(num) {}
Json::Json(bool boolean) : value(boolean) {}
Json::Json(nullptr_t nullVal) : value(nullVal) {}
Json::Json(const vector<Json> & array) : value(array) {}
Json::Json(const map<string, Json> & obj) : value(obj) {}

// Metodos para verificar tipos
bool Json::isString() const { return holds_alternative<string>(value); }
bool Json::isNumber() const { return holds_alternative<double>(value); }
bool Json::isBoolean() const { return holds_alternative<bool>(value); }
bool Json::isNull() const { return holds_alternative<nullptr_t>(value); }
bool Json::isArray() const { return holds_alternative<vector<Json>>(value); }
bool Json::isObject() const { return holds_alternative<map<string, Json>>(value); }

// Metodos para obtener valores


const string & Json::asString() const {
    if (!isString()) throw bad_variant_access(); 
    return get<string>(value);
    
}


double Json::asNumber() const {
    if (!isNumber()) throw bad_variant_access();
    return get<double>(value);
}

bool Json::asBoolean() const {
    if (std::holds_alternative<bool>(value)) {
        return std::get<bool>(value);
    }
    throw std::runtime_error("Json value is not a boolean");
}

const vector<Json> & Json::asArray() const {
    if (!isArray()) throw bad_variant_access();
    return get<vector<Json>>(value);
}

const map<string, Json> & Json::asObject() const {
    if (!isObject()) throw bad_variant_access();
    return get<map<string, Json>>(value);
}

// Metodos estaticos para parsear ( simplificado )
Json Json::parse(const string & JsonString){
    throw runtime_error("Parsear JSON no implementado.");
}

// Serializacion a string ( simplificado )
string Json::serialize() const {
    if (isString()) return "\"" + asString() + "\"";
    if (isNumber()) return to_string(asNumber());
    if (isBoolean()) return asBoolean() ? "true" : "false";
    if (isNull()) return "null";

    if (isArray()) {
        ostringstream oss;
        oss << "[";

        for (size_t i = 0; i < asArray().size(); i++)
        {
            if (i > 0) oss << ",";
            oss << asArray()[i].serialize();
        }

        oss << "]";
        return oss.str();
    }

    if (isObject()) {
        ostringstream oss;
        oss << "{";

        bool first = true;

        for (const auto& [key,value] : asObject()){
            if (!first) oss << ",";
            first = false;
            oss << "\"" << key << "\":" << value.serialize();
        }

        oss << "}";
        return oss.str();
    }

    throw runtime_error("Tipo desconocido en JSON::Serialize");
}