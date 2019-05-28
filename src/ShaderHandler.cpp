#include "ShaderHandler.h"

ShaderHandler::ShaderHandler()
{
    //ctor
}

ShaderHandler::~ShaderHandler()
{
    deleteShader();
}

void ShaderHandler::loadFile(char* fileName, string& str)
{
    char temp[1024];
    std::ifstream inFile(fileName);

    if(!inFile.is_open()){
        cout << "File couldn't open for some reason" << endl;
    }
    while(!inFile.eof()){
        inFile.getline(temp, 1024);
        str += temp;
        str += '\n';
    }
    cout << str << endl;
}

unsigned int ShaderHandler::loadShader(string& src, unsigned int mode)
{
    unsigned int id;
    const char* csrc;
    char error[1024];

    id = glCreateShader(mode);
    csrc = src.c_str();

    glShaderSource(id, 1, &csrc, NULL);
    glCompileShader(id);

    glGetShaderInfoLog(id, 1024, NULL, error);

    cout << "Compile Status \n" << error << endl;
    return id;
}

void ShaderHandler::initShader(char* vFileName, char* fFileName)
{
    string src;
    loadFile(vFileName, src);
    vs = loadShader(src, GL_VERTEX_SHADER);

    src = "";

    loadFile(fFileName, src);
    fs = loadShader(src, GL_FRAGMENT_SHADER);

    program = glCreateProgram();

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

}


void ShaderHandler::useShader()
{
    glUseProgram(program);
}


void ShaderHandler::deleteShader()
{
    glDetachShader(program,vs);
    glDetachShader(program,fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    glDeleteProgram(program);
}

void ShaderHandler::setBool(string name, bool val)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)val);
}

void ShaderHandler::setInt(string name, int val)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), val);
}

void ShaderHandler::setFloat(string name, float val)
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), val);
}

void ShaderHandler::setVec2(string name, glm::vec2 val)
{
    glUniform2fv(glGetUniformLocation(program, name.c_str()), 1, &val[0]);

}

void ShaderHandler::setVec3(string name, glm::vec3 val)
{
    glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &val[0]);

}

