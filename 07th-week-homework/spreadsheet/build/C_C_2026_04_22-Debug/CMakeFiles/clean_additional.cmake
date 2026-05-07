# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/spreadsheet_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/spreadsheet_autogen.dir/ParseCache.txt"
  "spreadsheet_autogen"
  )
endif()
