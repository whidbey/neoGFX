// i_texture.hpp
/*
  neogfx C++ GUI Library
  Copyright (c) 2015 Leigh Johnston.  All Rights Reserved.
  
  This program is free software: you can redistribute it and / or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <neogfx/neogfx.hpp>
#include <neogfx/core/geometrical.hpp>

namespace neogfx
{
	class i_native_texture;

	enum class texture_type : uint32_t
	{
		Texture,
		SubTexture
	};

	enum class texture_sampling : uint32_t
	{
		Normal,
		NormalMipmap,
		Multisample
	};

	class i_sub_texture;
	class i_image;

	class i_texture
	{
	public:
		struct texture_empty : std::logic_error { texture_empty() : std::logic_error("neogfx::i_texture::texture_empty") {} };
		struct not_sub_texture : std::logic_error { not_sub_texture() : std::logic_error("neogfx::i_texture::not_sub_texture") {} };
	public:
		virtual ~i_texture() {}
	public:
		virtual texture_type type() const = 0;
		virtual const i_sub_texture& as_sub_texture() const = 0;
		virtual dimension dpi_scale_factor() const = 0;
		virtual texture_sampling sampling() const = 0;
		virtual bool is_empty() const = 0;
		virtual size extents() const = 0;
		virtual size storage_extents() const = 0;
		virtual void set_pixels(const rect& aRect, const void* aPixelData) = 0;
		virtual void set_pixels(const i_image& aImage) = 0;
	public:
		virtual std::shared_ptr<i_native_texture> native_texture() const = 0;
	};
}