#include <iostream>
#include "json.h"

int main() {
    Json obj = Json(std::map<std::string, Json>{
        {"name", Json("John Doe")},
        {"is_student", Json(false)}
    });

    std::cout << obj.serialize() << std::endl;

    return 0;
}