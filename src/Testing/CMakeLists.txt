# - Build sub-script for the MPAGSCipher library unit tests

# Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# First Catch-based test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch PRIVATE Catch)
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar PRIVATE Catch MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Test ProcessCommandLine
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine PRIVATE Catch MPAGSCipher)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)

# Test CaesarCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher PRIVATE Catch MPAGSCipher)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)

# Test PlayfairCipher
add_executable(testPlayfairCipher testPlayfairCipher.cpp)
target_link_libraries(testPlayfairCipher PRIVATE Catch MPAGSCipher)
add_test(NAME test-playfaircipher COMMAND testPlayfairCipher)

# Test VigenereCipher
add_executable(testVigenereCipher testVigenereCipher.cpp)
target_link_libraries(testVigenereCipher PRIVATE Catch MPAGSCipher)
add_test(NAME test-vigenerecipher COMMAND testVigenereCipher)

# Test Ciphers
add_executable(testCipher testCiphers.cpp)
target_link_libraries(testCipher PRIVATE Catch MPAGSCipher)
add_test(NAME test-cipher COMMAND testCipher)
