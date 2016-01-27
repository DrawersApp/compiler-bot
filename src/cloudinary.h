//
// Created by Nishant Kumar Pathak on 31/01/16.
//

#ifndef ECHO_BOT_CLOUDINARY_H
#define ECHO_BOT_CLOUDINARY_H

#include <string>

using namespace std;
class Cloudinary {
public:
    inline static string generateFileUrl(string file) {
        return "https://res.cloudinary.com/nonety/raw/upload/" + file;
    }

    static string getCode(string file_name);
};


#endif //ECHO_BOT_CLOUDINARY_H
