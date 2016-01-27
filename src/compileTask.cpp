//
// Created by Nishant Kumar Pathak on 31/01/16.
//



#include <string>
#include <iostream>
#include <rapidjson/stringbuffer.h>
#include "compileTask.h"
#include "cloudinary.h"
#include <sstream>
#include <curl/curl.h>
#include <restclient-cpp/restclient.h>

Document *CompileOperation::execute() {
    string code = Cloudinary::getCode(file);

    std::stringstream ss;
    CURL *curl = curl_easy_init();
    ss << "lang=" << language
       << "&source=" << curl_easy_escape(curl, code.c_str(), (int) code.length())
       << "&client_secret=" << client_secret;



    RestClient::response rsp = RestClient::post("http://api.hackerearth.com/code/run/", "text/plain", ss.str());

    cout << rsp.body << endl;
    rspDoc->Parse(rsp.body.c_str());
    return rspDoc;
}
