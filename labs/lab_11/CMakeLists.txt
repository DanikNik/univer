project (database)

set (SOURCES database_raw.cpp lib.cpp)
set (HEADERS lib.h)

add_executable (database ${HEADERS} ${SOURCES})
