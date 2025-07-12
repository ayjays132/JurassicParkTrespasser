project(Std)

# Resolve jp2_pc directory for out-of-tree configuration.
get_filename_component(JP2_PC_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)

list(APPEND Std_Inc
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Array.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Array2.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/ArrayAllocator.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/ArrayIO.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/BlockAllocator.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/BlockArray.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/buildver.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/CircularList.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/common.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/CRC.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Hash.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/InitSys.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/LocalArray.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Mem.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/MemLimits.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/PrivSelf.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Ptr.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Random.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/RangeVar.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Set.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Sort.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/SparseArray.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/StdLibEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/StringEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/TreeList.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/UAssert.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/UDefs.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/UTypes.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/Warnings.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/version.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/VerBones.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/3DX.hpp
)

list(APPEND Std_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Hash.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/InitSys.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Mem.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Ptr.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/Random.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Std/StringEx.cpp
)

include_directories(
    ${JP2_PC_SOURCE_DIR}/Source
    ${JP2_PC_SOURCE_DIR}/Source/gblinc
)

add_common_options()

add_library(${PROJECT_NAME} STATIC ${Std_Inc} ${Std_Src} )

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Lib/Util)
