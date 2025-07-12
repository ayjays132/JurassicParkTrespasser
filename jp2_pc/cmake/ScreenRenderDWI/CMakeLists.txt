project(ScreenRenderDWI)

# Determine path to the jp2_pc directory. This allows configuring the project
# even when CMAKE_SOURCE_DIR does not point at jp2_pc directly.
get_filename_component(JP2_PC_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)

list(APPEND ScreenRenderDWI_Inc
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/AsmSupport.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawSubTriangle.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawTriangle.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBump.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/FastBumpEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBumpMath.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBumpTable.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/GouraudT.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCache.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCacheHelp.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCachePriv.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/ScanlineAsmMacros.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderAuxD3D.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderAuxD3DBatch.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderDWI.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/Walk.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/WalkEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCacheInterface.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCacheLRUItem.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/ColLookupT.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/Edge.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/IndexPerspectiveT.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/LineBumpMake.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/MapT.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/Scanline.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/TransparencyT.hpp
)

list(APPEND ScreenRenderDWI_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawSubTriangle.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawTriangle.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawTriangleEx.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBump.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBumpMath.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/FastBumpTable.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCache.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCacheHelp.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/RenderCachePriv.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderAuxD3D.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderAuxD3DBatch.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/ScreenRenderDWI.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/DrawSubTriangleFlat.inl
)

list(APPEND ScreenRenderDWI_P5_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleAlpha.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleBumpEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleBumpTblEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleTerrain.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleTerrainEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleTexEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleTexGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/DrawSubTriangleWater.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/FastBumpEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/IndexPerspectiveTEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/ScanlineAsmMacros.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P5/WalkEx.hpp
)

list(APPEND ScreenRenderDWI_P6_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleAlpha.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleBumpEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleBumpTblEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleTerrain.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleTerrainEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleTexEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleTexGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/DrawSubTriangleWater.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/FastBumpEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/IndexPerspectiveTEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/ScanlineAsmMacros.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/P6/WalkEx.hpp
)

list(APPEND ScreenRenderDWI_AMDK6_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleAlpha.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleBumpEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleBumpTblEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleTerrain.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleTerrainEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleTexEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleTexGourEx.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/DrawSubTriangleWater.inl
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/FastBumpEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/IndexPerspectiveTEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/ScanlineAsmMacros.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Renderer/Primitives/AMDK6/WalkEx.hpp
)

include_directories(
    ${JP2_PC_SOURCE_DIR}/Source
    ${JP2_PC_SOURCE_DIR}/Source/gblinc
)

add_common_options()


source_group("Primitives\\P5" FILES ${ScreenRenderDWI_P5_Src})
source_group("Primitives\\P6" FILES ${ScreenRenderDWI_P6_Src})
source_group("Primitives\\AMDK6" FILES ${ScreenRenderDWI_AMDK6_Src})

add_library(${PROJECT_NAME} STATIC 
    ${ScreenRenderDWI_Inc} 
    ${ScreenRenderDWI_Src}
    ${ScreenRenderDWI_P5_Src}
    ${ScreenRenderDWI_P6_Src}
    ${ScreenRenderDWI_AMDK6_Src} 
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Lib/Render)
