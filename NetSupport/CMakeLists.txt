# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)
if(NOT DEFINED ${LOCAL_RUN})
	set(LOCAL_RUN true)
project("Structural.Net")
endif() 

# Aggiungere l'origine all'eseguibile di questo progetto.
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options  )

if(${Boost_FOUND})
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
endif()

if(${LOCAL_RUN})
	ADD_EXECUTABLE(Structural.Net "NetSupport.h" "NetSupport.cpp")
else()
	add_library (Structural.Net SHARED "NetSupport.h" "NetSupport.cpp")
	target_link_libraries(Structural.Net LINK_PUBLIC Core)
# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
endif()
target_link_libraries(Structural.Net LINK_PUBLIC ${Boost_LIBRARIES})

target_include_directories(Structural.Net PUBLIC Core)
