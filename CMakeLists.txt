#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.1) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (Project_E_2D)

# include the configuration file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake)

# we use the paths from the cmake GNUInstallDirs module as defaults
# you can override these if you like
# https://cmake.org/cmake/help/v3.0/module/GNUInstallDirs.html
include(GNUInstallDirs)

# force building sfml-window, if sfml-graphics module is built
if(SFML_BUILD_GRAPHICS AND NOT SFML_BUILD_WINDOW)
    message(WARNING "You're trying to build SFML's Graphics module without the Window module. Forcing building of the Window module as a dependency.")
    set(SFML_BUILD_WINDOW TRUE)
endif()

# Visual C++: remove warnings regarding SL security and algorithms on pointers
if(SFML_COMPILER_MSVC)
    # add an option to choose whether PDB debug symbols should be generated (defaults to true when possible)
    if(CMAKE_VERSION VERSION_LESS 3.1)
        sfml_set_option(SFML_GENERATE_PDB FALSE BOOL "True to generate PDB debug symbols, FALSE otherwise. Requires CMake 3.1.")
        if(SFML_GENERATE_PDB)
            message(FATAL_ERROR "Generation of PDB files (SFML_GENERATE_PDB) requires at least CMake 3.1.0")
        endif()
    else()
        sfml_set_option(SFML_GENERATE_PDB TRUE BOOL "True to generate PDB debug symbols, FALSE otherwise. Requires CMake 3.1.")
    endif()

    add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
endif()

# define SFML_OPENGL_ES if needed
if(SFML_OPENGL_ES)
    add_definitions(-DSFML_OPENGL_ES)
    add_definitions(-DGL_GLEXT_PROTOTYPES)
endif()

# define an option for choosing between static and dynamic C runtime (Windows only)
if(SFML_OS_WINDOWS)
    sfml_set_option(SFML_USE_STATIC_STD_LIBS FALSE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

    # for VC++, we can apply it globally by modifying the compiler flags
    if(SFML_COMPILER_MSVC AND SFML_USE_STATIC_STD_LIBS)
        foreach(flag
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

# enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

if(SFML_OS_LINUX OR SFML_OS_FREEBSD OR SFML_OS_OPENBSD)
    set(SFML_INSTALL_PKGCONFIG_DEFAULT TRUE)
endif()

sfml_set_option(SFML_INSTALL_PKGCONFIG_FILES ${SFML_INSTALL_PKGCONFIG_DEFAULT} BOOL "TRUE to automatically install pkg-config files so other projects can find SFML")

if(SFML_INSTALL_PKGCONFIG_FILES)
    sfml_set_option(SFML_PKGCONFIG_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/${SFML_PKGCONFIG_DIR}" PATH "Install directory for SFML's pkg-config .pc files")

    foreach(sfml_module IN ITEMS all system window graphics audio network)
        CONFIGURE_FILE(
            "tools/pkg-config/sfml-${sfml_module}.pc.in"
            "tools/pkg-config/sfml-${sfml_module}.pc"
            @ONLY)
        INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/sfml-${sfml_module}.pc"
            DESTINATION "${SFML_PKGCONFIG_INSTALL_PREFIX}")
    endforeach()
endif()


# setup the install rules
if(NOT SFML_BUILD_FRAMEWORKS)
    install(DIRECTORY include
            DESTINATION .
            COMPONENT devel
            FILES_MATCHING PATTERN "*.hpp" PATTERN "*.inl")

    if(SFML_GENERATE_PDB)
        install(DIRECTORY ${PROJECT_BINARY_DIR}/lib
                DESTINATION .
                COMPONENT devel
                FILES_MATCHING PATTERN "*.pdb")
    endif()
else()
    # find only "root" headers
    file(GLOB SFML_HEADERS RELATIVE ${PROJECT_SOURCE_DIR} "include/SFML/*")

    # in fact we have to fool cmake to copy all the headers in subdirectories
    # to do that we have to add the "root" headers to the PUBLIC_HEADER
    # then we can run a post script to copy the remaining headers

    # we need a dummy file in order to compile the framework
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp
                       COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

    set(SFML_SOURCES ${SFML_HEADERS})
    list(APPEND SFML_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

    # create SFML.framework
    add_library(SFML ${SFML_SOURCES})

    # set the target flags to use the appropriate C++ standard library
    sfml_set_stdlib(SFML)

    # edit target properties
    set_target_properties(SFML PROPERTIES
                          FRAMEWORK TRUE
                          FRAMEWORK_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
                          MACOSX_FRAMEWORK_IDENTIFIER org.sfml-dev.SFML
                          MACOSX_FRAMEWORK_SHORT_VERSION_STRING ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
                          MACOSX_FRAMEWORK_BUNDLE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
                          PUBLIC_HEADER "${SFML_HEADERS}")

    # add the non-optional SFML headers
    add_custom_command(TARGET SFML POST_BUILD COMMAND cp -r
                       ${PROJECT_SOURCE_DIR}/include/SFML/Config.hpp
                       ${PROJECT_SOURCE_DIR}/include/SFML/OpenGL.hpp
                       ${PROJECT_SOURCE_DIR}/include/SFML/GpuPreference.hpp
                       ${PROJECT_SOURCE_DIR}/include/SFML/System.hpp
                       ${PROJECT_SOURCE_DIR}/include/SFML/Main.hpp
                       ${PROJECT_SOURCE_DIR}/include/SFML/System
                       $<TARGET_FILE_DIR:SFML>/Headers)

    # add window module headers if enabled
    if(SFML_BUILD_WINDOW)
        add_custom_command(TARGET SFML POST_BUILD COMMAND cp -r
                           ${PROJECT_SOURCE_DIR}/include/SFML/Window.hpp
                           ${PROJECT_SOURCE_DIR}/include/SFML/Window
                           $<TARGET_FILE_DIR:SFML>/Headers)
    endif()

    # add network module headers if enabled
    if(SFML_BUILD_NETWORK)
        add_custom_command(TARGET SFML POST_BUILD COMMAND cp -r
                           ${PROJECT_SOURCE_DIR}/include/SFML/Network.hpp
                           ${PROJECT_SOURCE_DIR}/include/SFML/Network
                           $<TARGET_FILE_DIR:SFML>/Headers)
    endif()

     # add graphics module headers if enabled
    if(SFML_BUILD_GRAPHICS)
        add_custom_command(TARGET SFML POST_BUILD COMMAND cp -r
                           ${PROJECT_SOURCE_DIR}/include/SFML/Graphics.hpp
                           ${PROJECT_SOURCE_DIR}/include/SFML/Graphics
                           $<TARGET_FILE_DIR:SFML>/Headers)
    endif()

     # add audio module headers if enabled
    if(SFML_BUILD_AUDIO)
        add_custom_command(TARGET SFML POST_BUILD COMMAND cp -r
                           ${PROJECT_SOURCE_DIR}/include/SFML/Audio.hpp
                           ${PROJECT_SOURCE_DIR}/include/SFML/Audio
                           $<TARGET_FILE_DIR:SFML>/Headers)
    endif()

    # adapt install directory to allow distributing dylibs/frameworks in user's frameworks/application bundle
    # NOTE: it's not required to link against SFML.framework
    set_target_properties(SFML PROPERTIES INSTALL_NAME_DIR "@rpath")
    if(NOT CMAKE_SKIP_BUILD_RPATH)
        if (CMAKE_VERSION VERSION_LESS 3.9)
            set_target_properties(${target} PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
        else()
            set_target_properties(${target} PROPERTIES BUILD_WITH_INSTALL_NAME_DIR TRUE)
        endif()
    endif()

    # install rule
    install(TARGETS SFML
            FRAMEWORK DESTINATION "."
            COMPONENT devel)
endif()

# install 3rd-party libraries and tools
if(SFML_OS_WINDOWS)

    if(NOT SFML_USE_SYSTEM_DEPS)
        # install the binaries of SFML dependencies
        if(ARCH_32BITS)
            install(DIRECTORY extlibs/bin/x86/ DESTINATION ${CMAKE_INSTALL_BINDIR})
            if(SFML_COMPILER_MSVC AND SFML_MSVC_VERSION LESS 14)
                install(DIRECTORY extlibs/libs-msvc/x86/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            elseif(SFML_COMPILER_MSVC)
                install(DIRECTORY extlibs/libs-msvc-universal/x86/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            else()
                install(DIRECTORY extlibs/libs-mingw/x86/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            endif()
        elseif(ARCH_64BITS)
            install(DIRECTORY extlibs/bin/x64/ DESTINATION ${CMAKE_INSTALL_BINDIR})
            if(SFML_COMPILER_MSVC AND SFML_MSVC_VERSION LESS 14)
                install(DIRECTORY extlibs/libs-msvc/x64/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            elseif(SFML_COMPILER_MSVC)
                install(DIRECTORY extlibs/libs-msvc-universal/x64/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            else()
                install(DIRECTORY extlibs/libs-mingw/x64/ DESTINATION ${CMAKE_INSTALL_LIBDIR})
            endif()
        endif()
    endif()

elseif(SFML_OS_MACOSX)
    # install extlibs dependencies only when used
    if(SFML_BUILD_GRAPHICS)
        if(FREETYPE_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/freetype.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/freetype.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()
    endif()

    if(SFML_BUILD_AUDIO)
        if(FLAC_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/FLAC.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/FLAC.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()

        if(OGG_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/ogg.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/ogg.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()

        if(VORBIS_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/vorbis.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/vorbis.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()

        if(VORBISENC_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/vorbisenc.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/vorbisenc.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()

        if(VORBISFILE_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/vorbisfile.framework")
            install(DIRECTORY extlibs/libs-osx/Frameworks/vorbisfile.framework DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()

        if(OPENAL_LIBRARY STREQUAL "${SFML_SOURCE_DIR}/extlibs/libs-osx/Frameworks/OpenAL.framework")
            install(DIRECTORY "${OPENAL_LIBRARY}" DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endif()
    endif()

    # install the Xcode templates if requested
    if(SFML_INSTALL_XCODE_TEMPLATES)
        # configure the templates plist files
        foreach(TEMPLATE "SFML Compiler" "SFML App")
            configure_file(
                        "tools/xcode/templates/SFML/${TEMPLATE}.xctemplate/TemplateInfo.plist.in"
                        "${CMAKE_CURRENT_BINARY_DIR}/tools/xcode/templates/SFML/${TEMPLATE}.xctemplate/TemplateInfo.plist"
                        @ONLY)
        endforeach()
        install(DIRECTORY "tools/xcode/templates/SFML" "${CMAKE_CURRENT_BINARY_DIR}/tools/xcode/templates/SFML"
                DESTINATION /Library/Developer/Xcode/Templates
                PATTERN "*.in" EXCLUDE
                PATTERN ".DS_Store" EXCLUDE)
    endif()

elseif(SFML_OS_IOS)

    # fix CMake install rules broken for iOS (see http://public.kitware.com/Bug/view.php?id=12506)
    install(DIRECTORY "${CMAKE_BINARY_DIR}/lib/\$ENV{CONFIGURATION}/" DESTINATION ${CMAKE_INSTALL_LIBDIR})

    if(NOT SFML_USE_SYSTEM_DEPS)
        # since the iOS libraries are built as static, we must install the SFML dependencies
        # too so that the end user can easily link them to its final application
        if(SFML_BUILD_GRAPHICS)
            install(FILES extlibs/libs-ios/libfreetype.a DESTINATION lib)
        endif()

        if(SFML_BUILD_AUDIO)
            install(FILES extlibs/libs-ios/libflac.a
                          extlibs/libs-ios/libvorbis.a
                          extlibs/libs-ios/libogg.a
                          DESTINATION lib)
        endif()
    endif()

elseif(SFML_OS_ANDROID)

    if(NOT SFML_USE_SYSTEM_DEPS)
        # install extlibs
        install(DIRECTORY extlibs/libs-android/${CMAKE_ANDROID_ARCH_ABI} DESTINATION extlibs/lib)
        install(FILES extlibs/Android.mk DESTINATION extlibs)
    endif()

    # install Android.mk so the NDK knows how to set up SFML
    install(FILES src/SFML/Android.mk DESTINATION .)

endif()

sfml_export_targets()

#set include files
include_directories("${CMAKE_CURRENT_LIST_DIR}/SFML/include")

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 11)

#set source files
set (SOURCE_FILES main.cpp)

#look for SFML and add it
set(SFML_USE_STATIC_STD_LIBS TRUE)
set (SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML")

find_package (SFML REQUIRED audio network graphics window system)

include_directories(${SFML_INCLUDE_DIR})

#we add the executable of the program
add_executable (Project_E_2D ${SOURCE_FILES})
target_link_libraries(Project_E_2D ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
target_link_libraries(Project_E_2D sfml-audio sfml-network sfml-graphics sfml-window sfml-system   )
