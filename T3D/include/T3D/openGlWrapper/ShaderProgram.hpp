#ifndef TECHNICCRAFT_SHADERPROGRAM_HPP
#define TECHNICCRAFT_SHADERPROGRAM_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "OpenGlObject.hpp"

namespace t3d::openGl
{
    /**
     * A wrapper class for a OpenGL shader program object.
     */
    class ShaderProgram : public OpenGlObject
    {
    public:
        /**
         * Creates an shader program with the shader sourcecode (vertex and fragment) from two source files.
         * @param vertexShaderPath
         * @param fragmentShaderPath
         */
        ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);

        /**
         * Deletes the OpenGl program
         */
        ~ShaderProgram();

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Bind()
         */
        inline void Bind() const override
        {
            glUseProgram(_objectID);
        }

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Unbind()
         */
        inline void Unbind() const override
        {
            glUseProgram(0);
        }

        /**
         * Sets data for an one float uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform1f(const char* location, float data) const;

        /**
         * Sets data for a two float uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform2f(const char* location, glm::vec2 data) const;

        /**
         * Sets data for a three float uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform3f(const char* location, glm::vec3 data) const;

        /**
         * Sets data for a four float uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform4f(const char* location, glm::vec4 data) const;

        /**
         * Sets data for an one int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform1i(const char* location, int32_t data) const;

        /**
         * Sets data for a two int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform2i(const char* location, glm::ivec2 data) const;

        /**
         * Sets data for a three int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform3i(const char* location, glm::ivec3 data) const;

        /**
         * Sets data for a four int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform4i(const char* location, glm::ivec4 data) const;

        /**
         * Sets data for an one unsigned int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform1ui(const char* location, uint32_t data) const;

        /**
         * Sets data for a two unsigned int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform2ui(const char* location, glm::uvec2 data) const;

        /**
         * Sets data for a three unsigned int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform3ui(const char* location, glm::uvec3 data) const;

        /**
         * Sets data for a four unsigned int uniform
         * @param location uniform "name"
         * @param data data to be set
         */
        void SetUniform4ui(const char* location, glm::uvec4 data) const;

        /**
         * Sets data for a two by two float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix2f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a three by three float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix3f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a four by four float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix4f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a two by three float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix2x3f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a three by two float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix3x2f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a two by four float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix2x4f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a four by two float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix4x2f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a three by four float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix3x4f(const char* location, bool transpose, const float* data) const;

        /**
         * Sets data for a four by three float matrix uniform
         * @param location uniform "name"
         * @param transpose defines if the matrix should be transposed while loading it into the uniform
         * @param data data to be set
         */
        void SetUniformMatrix4x3f(const char* location, bool transpose, const float* data) const;


    private:
        /**
         * @internal
         * Sets the source for an opengl shader object
         * @param shaderID opengl internal shader id
         * @param shaderSrcString
         */
        static void SetShaderSource(uint32_t shaderID, const char* shaderSrcString) ;

        /**
         * @internal
         * compiles an opengl shader
         * @param shaderID opengl internal shader id
         */
        static void CompileShader(uint32_t shaderID);

        /**
         * @internal
         * Attaches an opengl shader to the shader program
         * @param shaderID opengl internal shader id
         */
        void AttachShader(uint32_t shaderID) const;

        /**
         * @internal
         * links the program with the  in T3D::OpenGl::ShaderProgram::AttachShader() attached shaders
         */
        void LinkShader() const;

        /**
         * Deletes an opengl shader
         * @param shaderID opengl internal shader id
         */
        static void DeleteShader(uint32_t shaderID);

        /**
         * Gets the location of an uniform by its name
         * @param location name of the uniform
         * @return int containing location information
         */
        int32_t GetUniformLocation(const char* location) const;
    };
}
#endif //TECHNICCRAFT_SHADERPROGRAM_HPP
