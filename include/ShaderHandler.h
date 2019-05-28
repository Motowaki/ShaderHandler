#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

using std::cout;
using std::endl;
using std::string;

class ShaderHandler
{
    public:
        ShaderHandler();
        void loadFile(char*, string&);
        unsigned int loadShader(string&, unsigned int);
        void initShader(char*, char*);
        void useShader();
        void deleteShader();

        // setting uniforms
        void setBool(string, bool);
        void setInt(string, int);
        void setFloat(string, float);
        void setVec2(string, glm::vec2);
        void setVec3(string, glm::vec3);

        virtual ~ShaderHandler();
    protected:

    private:
        unsigned vs, fs, program;
};

#endif // SHADERHANDLER_H
