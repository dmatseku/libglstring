cmake_minimum_required(VERSION 3.14)
project(glstring C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

link_libraries(matrix)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

add_library (glstring includes/lgs.h init/string_init.c other/other.c
        string_create/string_create.c t_symbol/symbol_new.c t_symbol/symbol_addend.c
        t_symbol/symbol_free_lst.c string_create_image/string_create_image.c string_create_image/create_symbols_list.c
        string_create/string_create_vao.c string_create/vao_module.c t_string/string_add.c
        t_string/string_delete_one.c draw_strings/draw_strings.c init/standart_shaders.c draw_strings/string_draw_standart_function.c t_string/string_get_elem.c string_update_info/string_update_vbo_all.c string_update_info/string_update_vbo_index.c string_update_info/string_update_vbo.c string_update_info/string_update.c string_update_info/string_update_index.c)