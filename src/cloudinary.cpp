//
// Created by Nishant Kumar Pathak on 31/01/16.
//

#include <string>
#include <restclient-cpp/restclient.h>
#include "cloudinary.h"

using namespace std;
string Cloudinary::getCode(string file_name) {
    string cloudinaryUrl = generateFileUrl(file_name);
    RestClient::response r = RestClient::get(cloudinaryUrl);

    return 200 == r.code ? r.body : nullptr;
}
