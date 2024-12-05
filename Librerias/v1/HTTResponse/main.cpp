#include <iostream>
#include "HttpResponse.h"


int main(){
    HttpResponse response;
    response.setStatusCode(200);
    response.setHeader("Content-Type", "text/html");
    response.setBody("<html><body><h1>Hi world</h1></body>");

    cout << response.toString() << endl;
}