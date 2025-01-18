#!/bin/bash

# Start the server in the background
# valgrind --track-fds=yes --leak-check=full ../server &
PATH_FILE=.
HOST=127.0.0.3
PORT=1234

PAYLOAD=$(head -c 10000 < /dev/urandom | tr -d '\000')

sleep 2

# Test a simple GET request
echo -e "GET / HTTP/1.1\r\nHost: $HOST\r\n\r\n" | nc  $HOST $PORT > $PATH_FILE/result/test1.txt
echo -e "Test 1 : \n"
diff $PATH_FILE/result/test1.txt $PATH_FILE/nginx_result/test1.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's implementation for the root PATH_FILE)

# Test a malformed request
echo -e "BADREQUEST / HTTP/1.1\r\nHost: $HOST\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test2.txt
echo -e "Test 2 : \n"
diff $PATH_FILE/result/test2.txt $PATH_FILE/nginx_result/test2.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 400 Bad Request (or appropriate error response based on your server's error handling)

# Test a large payload
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nContent-Length: 10000\r\n\r\n$(head -c 10000 < /dev/urandom | tr -d '\000')" | nc   $HOST $PORT > $PATH_FILE/result/test3.txt
echo -e "Test 3 : \n"
diff $PATH_FILE/result/test3.txt $PATH_FILE/nginx_result/test3.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of large payloads)

# Test a request with a long URL
echo -e "GET /$(head -c 1000 < /dev/urandom | tr -dc 'a-zA-Z0-9' | tr -d '\000') HTTP/1.1\r\nHost: $HOST\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test4.txt
echo -e "Test 4 : \n"
diff $PATH_FILE/result/test4.txt $PATH_FILE/nginx_result/test4.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 414 Request-URI Too Long (or appropriate response based on your server's handling of long URLs)

# Test a request with special characters in the URL
echo -e "GET /test?param1=value1&param2=value2 HTTP/1.1\r\nHost: $HOST\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test5.txt
echo -e "Test 5 : \n"
diff $PATH_FILE/result/test5.txt $PATH_FILE/nginx_result/test5.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of query parameters)

# Test a request with headers
echo -e "GET / HTTP/1.1\r\nHost: $HOST\r\nUser-Agent: TestAgent\r\nAccept: */*\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test6.txt
echo -e "Test 6 : \n"
diff $PATH_FILE/result/test6.txt $PATH_FILE/nginx_result/test6.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of headers)

# Test a request with a different HTTP method
echo -e "PUT / HTTP/1.1\r\nHost: $HOST\r\nContent-Length: 0\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test7.txt
echo -e "Test 7 : \n"
diff $PATH_FILE/result/test7.txt $PATH_FILE/nginx_result/test7.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 405 Method Not Allowed (or appropriate response based on your server's handling of unsupported methods)

# Test a request with a non-existent resource
echo -e "GET /nonexistent HTTP/1.1\r\nHost: $HOST\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test8.txt
echo -e "Test 8 : \n"
diff $PATH_FILE/result/test8.txt $PATH_FILE/nginx_result/test8.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 404 Not Found (or appropriate response based on your server's handling of non-existent resources)

# Test a request with a valid resource but unsupported media type
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nContent-Type: application/unsupported\r\nContent-Length: 0\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test9.txt
echo -e "Test 9 : \n"
diff $PATH_FILE/result/test9.txt $PATH_FILE/nginx_result/test9.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 415 Unsupported Media Type (or appropriate response based on your server's handling of unsupported media types)

# Test a request with a valid resource but missing Host header
echo -e "GET / HTTP/1.1\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test10.txt
echo -e "Test 10 : \n"
diff $PATH_FILE/result/test10.txt $PATH_FILE/nginx_result/test10.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 400 Bad Request (or appropriate response based on your server's handling of missing required headers)

# Test a request with a valid resource but invalid HTTP version
echo -e "GET / HTTP/1.0\r\nHost: $HOST\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test11.txt
echo -e "Test 11 : \n"
diff $PATH_FILE/result/test11.txt $PATH_FILE/nginx_result/test11.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 505 HTTP Version Not Supported (or appropriate response based on your server's handling of unsupported HTTP versions)

# Test a request with a valid resource and a large number of headers
echo -e "GET / HTTP/1.1\r\nHost: $HOST\r\n$(for i in {1..100}; do echo -e "Header$i: value$i\r\n"; done)\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test12.txt
echo -e "Test 12 : \n"
diff $PATH_FILE/result/test12.txt $PATH_FILE/nginx_result/test12.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of many headers)

# Test a request with a valid resource and a very large header value
echo -e "GET / HTTP/1.1\r\nHost: $HOST\r\nX-Large-Header: $(head -c 10000 < /dev/urandom | tr -dc 'a-zA-Z0-9' | tr -d '\000')\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test13.txt
echo -e "Test 13 : \n"
diff $PATH_FILE/result/test13.txt $PATH_FILE/nginx_result/test13.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of large header values)

# Test a request with a valid resource and a chunked transfer encoding
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nTransfer-Encoding: chunked\r\n\r\n4\r\ndata\r\n0\r\n\r\n" | nc   $HOST $PORT > $PATH_FILE/result/test14.txt
echo -e "Test 14 : \n"
diff $PATH_FILE/result/test14.txt $PATH_FILE/nginx_result/test14.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of chunked transfer encoding)

# Test a request with a valid resource and a very large body
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nContent-Length: 1000000\r\n\r\n$(head -c 1000000 < /dev/urandom | tr -d '\000')" | nc   $HOST $PORT > $PATH_FILE/result/test15.txt
echo -e "Test 15 : \n"
diff $PATH_FILE/result/test15.txt $PATH_FILE/nginx_result/test15.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of very large bodies)

# Test a request with a valid resource and a very small body
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nContent-Length: 1\r\n\r\na" | nc   $HOST $PORT > $PATH_FILE/result/test16.txt
echo -e "Test 16 : \n"
diff $PATH_FILE/result/test16.txt $PATH_FILE/nginx_result/test16.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of very small bodies)

# Test a request with a valid resource and a body with special characters
echo -e "POST / HTTP/1.1\r\nHost: $HOST\r\nContent-Length: 10\r\n\r\n!@#$%^&*()" | nc   $HOST $PORT  > $PATH_FILE/result/test17.txt
echo -e "Test 17 : \n"
diff $PATH_FILE/result/test17.txt $PATH_FILE/nginx_result/test17.txt
echo -e "\n----------------------------------------\n"
# Expected response: HTTP/1.1 200 OK (or appropriate response based on your server's handling of bodies with special characters)
