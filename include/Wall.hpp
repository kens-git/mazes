#pragma once

#include <string>

using std::string;

class Wall {
    public:
        Wall() { }
        Wall(string wallString) { mWallString = wallString; }
        string getWallString() { return mWallString; }

    private:
        string mWallString;
};
