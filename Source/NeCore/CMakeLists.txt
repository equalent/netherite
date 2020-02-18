SET (NeCore_SRCS

Public/NeDefines.h
Public/NeCore.h
Public/ini.h

Private/ini.c

Public/yaml.h
Private/yaml/api.c
Private/yaml/dumper.c
Private/yaml/emitter.c
Private/yaml/loader.c
Private/yaml/parser.c
Private/yaml/reader.c
Private/yaml/scanner.c
Private/yaml/writer.c
Private/yaml/yaml_private.h

${PROJECT_SOURCE_DIR}/.clang-format
)

add_library(NeCore SHARED ${NeCore_SRCS})
target_include_directories(NeCore PUBLIC Public)
target_compile_definitions(NeCore PRIVATE NE_BUILD_DLL_NE_CORE)