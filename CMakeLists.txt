# Проверка версии CMake
cmake_minimum_required(VERSION 3.28)

# Название проекта
project(cpp_labs)

# Установка переменной со списком исходников
set(SOURCE_EXE src/main.cpp)

# Расположение заголовочных файлов
include_directories(src/file_system/headers/)

# Создает исполняемый файл
add_executable(app src/main.cpp)

# Добавление подпроекта, указывается имя дирректории
add_subdirectory(src/file_system)

# Линковка программы с библиотекой
target_link_libraries(app file_system)