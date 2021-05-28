# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)

project("NetSupport")

# Aggiungere l'origine all'eseguibile di questo progetto.

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
#add_library (NetSupport SHARED "NetSupport.h" "NetSupport.cpp")
# TODO: Aggiungere i test e, se necessario, installare le destinazioni.

add_executable (NetSupport "NetSupport.cpp" "NetSupport.h")
target_link_libraries(NetSupport LINK_PUBLIC ${Boost_LIBRARIES})
target_link_libraries(NetSupport LINK_PUBLIC Core)
target_include_directories(NetSupport PUBLIC Core)
