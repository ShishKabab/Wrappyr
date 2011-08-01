set(MODULE TRUE)

set( LLVM_USED_LIBS
  clangFrontend
  clangAST
  )

set( LLVM_LINK_COMPONENTS support mc)

add_clang_library(ExportHeader ExportHeader.cpp)

set_target_properties(ExportHeader
  PROPERTIES
  LINKER_LANGUAGE CXX
  PREFIX "")
