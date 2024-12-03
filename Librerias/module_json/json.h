#ifndef JSON_H
#define JSON_H

#include <string>
#include <variant>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

class Json {
public:
    using JsonValue = variant<
        string, 
        double, 
        bool, 
        nullptr_t, 
        vector<Json>, 
        map<string, Json>>;

private:
    JsonValue value;

public:
    // Constructores
    Json() : value(nullptr) {}
    Json(const string& str);
    Json(double num);
    Json(bool boolean);
    Json(nullptr_t nullVal);
    Json(const vector<Json>& array);
    Json(const map<string, Json>& obj);

    // Métodos para acceder a datos
    bool isString() const;
    bool isNumber() const;
    bool isBoolean() const;
    bool isNull() const;
    bool isArray() const;
    bool isObject() const;

    const string& asString() const;
    double asNumber() const;
    bool asBoolean() const;
    const vector<Json>& asArray() const;
    const map<string, Json>& asObject() const;

    // Métodos estáticos para parsear y serializar
    static Json parse(const string& jsonString);
    string serialize() const;
};

#endif
