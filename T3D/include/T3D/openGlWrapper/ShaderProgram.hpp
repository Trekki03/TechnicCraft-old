#ifndef TECHNICCRAFT_SHADERPROGRAM_HPP
#define TECHNICCRAFT_SHADERPROGRAM_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "OpenGlObject.hpp"

namespace T3D::OpenGl
{
    class ShaderProgram : public OpenGlObject
    {
    public:
        ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
        ~ShaderProgram();

        inline void Bind() const
        {
            glUseProgram(_objectID);
        }

        inline void Unbind() const
        {
            glUseProgram(0);
        }

        void SetUniform1f(const char* location, float data) const;
        void SetUniform2f(const char* location, glm::vec2 data) const;
        void SetUniform3f(const char* location, glm::vec3 data) const;
        void SetUniform4f(const char* location, glm::vec4 data) const;

        void SetUniform1i(const char* location, int32_t data) const;
        void SetUniform2i(const char* location, glm::ivec2 data) const;
        void SetUniform3i(const char* location, glm::ivec3 data) const;
        void SetUniform4i(const char* location, glm::ivec4 data) const;

        void SetUniform1ui(const char* location, uint32_t data) const;
        void SetUniform2ui(const char* location, glm::uvec2 data) const;
        void SetUniform3ui(const char* location, glm::uvec3 data) const;
        void SetUniform4ui(const char* location, glm::uvec4 data) const;

        void SetUniformMatrix2f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix3f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix4f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix2x3f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix3x2f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix2x4f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix4x2f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix3x4f(const char* location, bool transpose, const float* data) const;
        void SetUniformMatrix4x3f(const char* location, bool transpose, const float* data) const;


    private:
        static void SetShaderSource(uint32_t shaderID, const char* shaderSrcString) ;
        static void CompileShader(uint32_t shaderID) ;
        void AttachShader(uint32_t shaderID) const;
        void LinkShader() const;
        static void DeleteShader(uint32_t shaderID) ;

        int32_t GetUniformLocation(const char* location) const;
    };
}
#endif //TECHNICCRAFT_SHADERPROGRAM_HPP
