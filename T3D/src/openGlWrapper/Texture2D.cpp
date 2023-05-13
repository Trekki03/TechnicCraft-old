#include "T3D/openGlWrapper/Texture2D.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

using namespace std::string_literals;

namespace t3d::openGl
{
    Texture2D::Texture2D(const char *texturePath, GLenum inputFormat, GLenum internalFormat, GLenum sAxisWarpMode,
                         GLenum tAxisWarpMode, GLenum downscalingFilter, GLenum upscalingFilter, bool mipmap)
    {
        glGenTextures(1, &_objectID);
        Texture2D::Bind();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sAxisWarpMode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tAxisWarpMode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, downscalingFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, upscalingFilter);

        stbi_set_flip_vertically_on_load(true);

        // signed int because of stbi implementation
        int32_t width, height, nrChannels;
        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, inputFormat, GL_UNSIGNED_BYTE, data);
        }
        else
        {
            std::cerr << "Error reading Texture Image (" << texturePath << ")"  << std::endl;
            throw std::invalid_argument("Error reading Texture Image ("s + texturePath + ")"s);
        }

        if(mipmap)
        {
            Texture2D::GenerateMipmaps();
        }

        stbi_image_free(data);

        Texture2D::Unbind();
    }

    Texture2D::~Texture2D()
    {
        glDeleteTextures(1, &_objectID);
    }

    void Texture2D::GenerateMipmaps() const
    {
        Bind();
        glGenerateMipmap(GL_TEXTURE_2D);
        Unbind();
    }

    void Texture2D::SetTextureSlot(uint32_t textureSlot) const
    {
        glActiveTexture(GL_TEXTURE0 + textureSlot);
        Bind();
        Unbind();
    }
}