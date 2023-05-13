#include "T3D/util/FileIO.hpp"
#include <fstream>

namespace t3d::util
{
    std::string GetStringFromFile(const char* path)
    {
        std::ifstream stream(path);
        std::string line, content;

        while(std::getline(stream, line))
        {
            content += (line + "\n");
        }
        return content;
    }
}
