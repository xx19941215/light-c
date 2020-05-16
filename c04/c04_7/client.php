<?php

$file = $argv[1];

$filename = __DIR__ . "/" . $file;

$service_port = 8989;
$address = 'localhost';
$now = microtime(true);

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
} else {
    // echo "OK. \n";
}

// echo "Attempting to connect to '$address' on port '$service_port'...";
$result = socket_connect($socket, $address, $service_port);
if($result === false) {
    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($socket)) . "\n";
} else {
    // echo "OK \n";
}
$in = "$filename\n";
$out = "";
// echo "sending http head request ...";
socket_write($socket, $in, strlen($in));
// echo  "OK\n";

// echo "Reading response:\n\n";
// while ($out = socket_read($socket, 8192)) {
//     echo $out;
// }
// echo "closeing socket..";
socket_close($socket);
// echo "ok .\n\n";
$finished = microtime(true);

$elapsed = $finished - $now;
echo "Elapsed $elapsed.\n\n";

