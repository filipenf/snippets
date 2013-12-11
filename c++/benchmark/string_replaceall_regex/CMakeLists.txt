include_directories(
  ${PROJECT_SOURCE_DIR}/../hayai/src
)

add_executable(replace_regex
    replace_without_regex.cpp
    replace_with_regex.cpp
    main.cpp
)

