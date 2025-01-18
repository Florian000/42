#!/bin/bash

# Start the server in the background
SERVER=server
EXEC="valgrind -q --leak-check=full --show-leak-kinds=all ./$SERVER"
# Test invalid configuration files
echo "Testing invalid configuration files..."

# Test invalid configuration files
echo "Testing invalid configuration files..."

# Test invalid1.conf
echo -e "\033[34mTesting invalid1.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid1.conf
# Expected response: Error message indicating missing Host field
echo -e "\n----------------------------------------"

# Test invalid2.conf
echo -e "\033[34mTesting invalid2.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid2.conf
# Expected response: Error message indicating invalid port value
echo -e "\n----------------------------------------"

# Test invalid3.conf
echo -e "\033[34mTesting invalid3.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid3.conf
# Expected response: Error message indicating syntax error
echo -e "\n----------------------------------------"

# Test invalid4.conf
echo -e "\033[34mTesting invalid4.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid4.conf
# Expected response: Error message indicating duplicate Host field
echo -e "\n----------------------------------------"

# Test invalid5.conf
echo -e "\033[34mTesting invalid5.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid5.conf
# Expected response: Error message indicating unknown field
echo -e "\n----------------------------------------"

# Test invalid6.conf
echo -e "\033[34mTesting invalid6.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid6.conf
# Expected response: Error message indicating missing Match field
echo -e "\n----------------------------------------"

# Test invalid7.conf
echo -e "\033[34mTesting invalid7.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid7.conf
# Expected response: Error message indicating invalid Listing value
echo -e "\n----------------------------------------"

# Test invalid8.conf
echo -e "\033[34mTesting invalid8.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid8.conf
# Expected response: Error message indicating missing server block
echo -e "\n----------------------------------------"

# Test invalid9.conf
echo -e "\033[34mTesting invalid9.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid9.conf
# Expected response: Error message indicating invalid client-max-body-size value
echo -e "\n----------------------------------------"

# Test invalid10.conf
echo -e "\033[34mTesting invalid10.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid10.conf
# Expected response: Error message indicating invalid Listing value
echo -e "\n----------------------------------------"

# Test invalid11.conf
echo -e "\033[34mTesting invalid11.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid11.conf
# Expected response: Error message indicating invalid Allowed method
echo -e "\n----------------------------------------"

# Test invalid12.conf
echo -e "\033[34mTesting invalid12.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid12.conf
# Expected response: Error message indicating missing route block
echo -e "\n----------------------------------------"

# Test invalid13.conf
echo -e "\033[34mTesting invalid13.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid13.conf
# Expected response: Error message indicating invalid Location value
echo -e "\n----------------------------------------"

# Test invalid14.conf
echo -e "\033[34mTesting invalid14.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid14.conf
# Expected response: Error message indicating invalid Return value
echo -e "\n----------------------------------------"

# Test invalid15.conf
echo -e "\033[34mTesting invalid15.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid15.conf
# Expected response: Error message indicating missing Name field
echo -e "\n----------------------------------------"

# Test invalid16.conf
echo -e "\033[34mTesting invalid16.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid16.conf
# Expected response: Error message indicating invalid Client-max-body-size value
echo -e "\n----------------------------------------"

# Test invalid17.conf
echo -e "\033[34mTesting invalid17.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid17.conf
# Expected response: Error message indicating missing route block
echo -e "\n----------------------------------------"

# Test invalid18.conf
echo -e "\033[34mTesting invalid18.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid18.conf
# Expected response: Error message indicating invalid Allowed method
echo -e "\n----------------------------------------"

# Test invalid19.conf
echo -e "\033[34mTesting invalid19.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid19.conf
# Expected response: Error message indicating invalid Forbidden method
echo -e "\n----------------------------------------"

# Test invalid20.conf
echo -e "\033[34mTesting invalid20.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid20.conf
# Expected response: Error message indicating missing Location field
echo -e "\n----------------------------------------"

# Test invalid21.conf
echo -e "\033[34mTesting invalid21.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid21.conf
# Expected response: Error message indicating invalid Return value
echo -e "\n----------------------------------------"

# Test invalid22.conf
echo -e "\033[34mTesting invalid22.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid22.conf
# Expected response: Error message indicating invalid Match value
echo -e "\n----------------------------------------"

# Test invalid23.conf
echo -e "\033[34mTesting invalid23.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid23.conf
# Expected response: Error message indicating invalid Listing value
echo -e "\n----------------------------------------"

# Test invalid24.conf
echo -e "\033[34mTesting invalid24.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid24.conf
# Expected response: Error message indicating missing end braces
echo -e "\n----------------------------------------"

# Test invalid25.conf
echo -e "\033[34mTesting invalid25.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid25.conf
# Expected response: Error message indicating invalid character in Host field
echo -e "\n----------------------------------------"

# Test invalid26.conf
echo -e "\033[34mTesting invalid26.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid26.conf
# Expected response: Error message indicating missing Port field
echo -e "\n----------------------------------------"

# Test invalid27.conf
echo -e "\033[34mTesting invalid27.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid27.conf
# Expected response: Error message indicating invalid character in Port field
echo -e "\n----------------------------------------"

# Test invalid28.conf
echo -e "\033[34mTesting invalid28.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid28.conf
# Expected response: Error message indicating missing Client-max-body-size field
echo -e "\n----------------------------------------"

# Test invalid29.conf
echo -e "\033[34mTesting invalid29.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid29.conf
# Expected response: Error message indicating invalid character in Client-max-body-size field
echo -e "\n----------------------------------------"

# Test invalid30.conf
echo -e "\033[34mTesting invalid30.conf\033[0m"
$EXEC ./tester/parsing_tester/invalid30.conf
# Expected response: Error message indicating missing Allowed field
echo -e "\n----------------------------------------"
