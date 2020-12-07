cmake_minimum_required(VERSION 3.17)
project(Projektas_su_vektoriais)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

add_executable(Projektas_su_vektoriais main.cpp random.h random.cpp klausimai.h klausimai.cpp skaiciavimai.h skaiciavimai.cpp studentas.h pazymiai.h pazymiai.cpp studento_sukurimas.h studento_sukurimas.cpp rusiavimas.h rusiavimas.cpp isvedimas.h isvedimas.cpp nuskaityti_duomenys.h "nuskaityti duomenys.cpp" studentai.h studentai.cpp rusiavimas.cpp "studentai_faile.h" "studentai_faile.cpp")

