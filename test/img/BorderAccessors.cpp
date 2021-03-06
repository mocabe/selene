// This file is part of the `Selene` library.
// Copyright 2017-2018 Michael Hofmann (https://github.com/kmhofmann).
// Distributed under MIT license. See accompanying LICENSE file in the top-level directory.

#include <catch.hpp>

#include <selene/img/BorderAccessors.hpp>
#include <selene/img/Image.hpp>

#include <test/img/_TestImages.hpp>

using namespace sln::literals;


TEST_CASE("Image accessors", "[img]")
{
  const auto img = sln_test::make_3x3_test_image_8u1();

  SECTION("Within bounds")
  {
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(img, 0_idx, 0_idx) == 10);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, 0_idx, 0_idx) == 10);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, 0_idx, 0_idx) == 10);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(img, 2_idx, 1_idx) == 60);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, 2_idx, 1_idx) == 60);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, 2_idx, 1_idx) == 60);
  }

  SECTION("Out of bounds")
  {
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, -1_idx, 0_idx) == 0);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, -1_idx, 0_idx) == 10);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, 3_idx, 0_idx) == 0);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, 3_idx, 0_idx) == 30);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, -1_idx, 1_idx) == 0);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, -1_idx, 1_idx) == 40);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, -2_idx, 1_idx) == 0);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, -2_idx, 1_idx) == 40);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::ZeroPadding>::access(img, 1_idx, 3_idx) == 0);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Replicated>::access(img, 1_idx, 3_idx) == 80);
  }

  SECTION("Relative access")
  {
    const auto r_img = sln::relative_accessor(img, 1_idx, 1_idx);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, -1_idx, -1_idx) == 10);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 0_idx, -1_idx) == 20);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 1_idx, -1_idx) == 30);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, -1_idx, 0_idx) == 40);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 0_idx, 0_idx) == 50);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 1_idx, 0_idx) == 60);

    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, -1_idx, 1_idx) == 70);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 0_idx, 1_idx) == 80);
    REQUIRE(sln::ImageBorderAccessor<sln::BorderAccessMode::Unchecked>::access(r_img, 1_idx, 1_idx) == 90);
  }
}
