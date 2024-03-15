# Проверка версии CMake
cmake_minimum_required(VERSION 3.28)

# Название проекта
project(cpp_labs)

# Установка переменной со списком исходников
set(SOURCE_EXE src/main.cpp)

# Расположение заголовочных файлов
include_directories(src/bool_vec/headers/)

# Создает исполняемый файл
add_executable(app src/main.cpp)

# Добавление подпроекта, указывается имя дирректории
add_subdirectory(src/bool_vec)

# Линковка программы с библиотекой
target_link_libraries(app bool_vec)