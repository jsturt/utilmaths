project('utilmaths','cpp',default_options : ['cpp_std=c++20'])
src = ['tests.cpp','utilmaths.cpp']
inc = include_directories('include')
gtest_proj = subproject('gtest')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')
executable('test_utilmaths', sources : src , include_directories : inc, dependencies : gtest_main_dep)

