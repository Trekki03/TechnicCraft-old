#ifndef TECHNICCRAFT_TEXTURE2D_HPP
#define TECHNICCRAFT_TEXTURE2D_HPP

#include "Texture.hpp"
#include "glad/glad.h"

namespace T3D::OpenGl
{
    /**
     * A wrapper class for a OpenGL texture object.
     */
    class Texture2D : public Texture
    {
    public:
        /**
         * Reads a texture from a file path and creates an OpenGl texture from it.
         * @param texturePath Path of the file which contains the image used for the texture.
         * @param inputFormat Format in which the image is available on disk (e.g. GL_RGB or GL_RGBA)
         * @param internalFormat Format in which the image should be internally saved (e.g. GL_RGB or GL_RGBA)
         * @param sAxisWarpMode The warp mode of the texture on its s-axis (also named x-axis, in 2d cartesian coordinate system)
         * @param tAxisWarpMode The warp mode of the texture on its t-axis (also named y-axis, in 2d cartesian coordinate system)
         * @param downscalingFilter The texture downscaling function that should be used (e.g. GL_NEAREST)
         * @param upscalingFilter The texture upscaling function that should be used (e.g. GL_NEAREST)
         * @param mipmap Defines, if mipmaps should be generated or not. If set to false, mipmaps can be generated later with GenerateMipmaps().
         *
         * <b>Usage Example</b>
         * @code Texture2D texture("res/textures/TextureAtlas.jpg", GL_RGB, GL_RGB, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR, false) @endcode
         */
        Texture2D(const char *texturePath, GLenum inputFormat, int internalFormat, int sAxisWarpMode, int tAxisWarpMode, int downscalingFilter, int upscalingFilter, bool mipmap);

        /**
         * Deletes the OpenGl texture
         */
        ~Texture2D();

        /**
         * @copydoc T3D::OpenGl::Texture::GenerateMipmaps()
         */
        void GenerateMipmaps() const override;

        /**
         * @copydoc T3D::OpenGl::Texture::SetTextureSlot()
         */
        void SetTextureSlot(uint32_t textureSlot) const override;

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Bind()
         */
        void Bind() const override;

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Unbind()
         */
        void Unbind() const override;
    };
}
#endif //TECHNICCRAFT_TEXTURE2D_HPP
