
#include <string>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

class HttpResponse {

    private:
    int statusCode;
    string statusMessage;
    map<string, string> headers;
    string body;

    string getStatusMessage(int code) const {
        switch(code) {
            case 200 : return "OK";
            case 201 : return "Created";
            case 204 : return "No content";
            case 400 : return "Bad Request";
            case 401 : return "UnAuthorized";
            case 403 : return "Forbidden";
            case 404 : return "Not Found";
            case 500 : return "Internal Server Error";
            case 502 : return "Bad Gateway";
            case 503 : return "Service UnaVailable";

            default : return "Unknown Status";
        }
    }

    public:
    HttpResponse() : statusCode(200), statusMessage("OK") {}

    void setStatusCode(int code){
        statusCode = code;
        statusMessage = getStatusMessage(code);
    }

    void setHeader(const string & key, const string & value) {
        headers[key] = value;
    }

    void setBody(const string & content){
        body = content;
        setHeader("Content-Length", to_string(content.size()));
    }

    string toString() const {
        ostringstream response;
        response << "HTTP/1.1 " << statusCode << " " << statusMessage << "\r\n";

        for(const auto & header : headers){
            response << header.first << ": " << header.second << "\r\n";
        }

        response << "\r\n" << body;
        return response.str();
    }

};