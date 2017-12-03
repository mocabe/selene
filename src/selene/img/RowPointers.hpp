// This file is part of the `Selene` library.
// Copyright 2017 Michael Hofmann (https://github.com/kmhofmann).
// Distributed under MIT license. See accompanying LICENSE file in the top-level directory.

#ifndef SELENE_IMG_ROW_POINTERS_HPP
#define SELENE_IMG_ROW_POINTERS_HPP

/// @file

#include <selene/img/Image.hpp>
#include <selene/img/ImageData.hpp>

#include <cstdint>
#include <memory>
#include <vector>

namespace selene {
namespace img {

using RowPointers = std::vector<std::uint8_t*>;  ///< Type representing a list of image row pointers
using ConstRowPointers = std::vector<const std::uint8_t*>;  ///< Type representing a list of constant image row pointers

template <typename T> RowPointers get_row_pointers(Image<T>& img);
template <typename T> ConstRowPointers get_row_pointers(const Image<T>& img);

RowPointers get_row_pointers(ImageData& img);
ConstRowPointers get_row_pointers(const ImageData& img);

// --------------
// Implementation

/** \brief Extracts a list of consecutive pointers to each image row from an `Image<T>` instance.
 *
 * @tparam T Image pixel type.
 * @param img An image to extract the row pointers from.
 * @return List of row pointers.
 */
template <typename T> RowPointers get_row_pointers(Image<T>& img)
{
  RowPointers row_pointers(img.height());

  for (Index y = 0; y < img.height(); ++y)
  {
    row_pointers[y] = img.byte_ptr(y);
  }

  return row_pointers;
}

/** \brief Extracts a list of consecutive (constant) pointers to each image row from an `Image<T>` instance.
 *
 * @tparam T Image pixel type.
 * @param img An image to extract the row pointers from.
 * @return List of row pointers.
 */
template <typename T> ConstRowPointers get_row_pointers(const Image<T>& img)
{
  ConstRowPointers row_pointers(img.height());

  for (Index y = 0; y < img.height(); ++y)
  {
    row_pointers[y] = img.byte_ptr(y);
  }

  return row_pointers;
}

/** \brief Extracts a list of consecutive pointers to each image row from an `ImageData` instance.
 *
 * @param img An image to extract the row pointers from.
 * @return List of row pointers.
 */
inline RowPointers get_row_pointers(ImageData& img)
{
  RowPointers row_pointers(img.height());

  for (Index y = 0; y < img.height(); ++y)
  {
    row_pointers[y] = img.byte_ptr(y);
  }

  return row_pointers;
}

/** \brief Extracts a list of consecutive (constant) pointers to each image row from an `ImageData` instance.
 *
 * @param img An image to extract the row pointers from.
 * @return List of row pointers.
 */
inline ConstRowPointers get_row_pointers(const ImageData& img)
{
  ConstRowPointers row_pointers(img.height());

  for (Index y = 0; y < img.height(); ++y)
  {
    row_pointers[y] = img.byte_ptr(y);
  }

  return row_pointers;
}


} // namespace img
} // namespace selene

#endif // SELENE_IMG_ROW_POINTERS_HPP
