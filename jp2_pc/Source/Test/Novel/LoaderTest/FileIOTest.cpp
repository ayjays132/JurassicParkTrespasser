#include "common.hpp"
#include "Lib/Groff/FileIO.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("CFileIO Destructor", "[CFileIO]")
{
        //Create several empty objects which are removed immediately
        //This shall happen without errors
        for (size_t i = 0; i < 5; i++) {
                CFileIO object;
        }
}
