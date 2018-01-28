

<?php



//create connection

$dbhost = "wossrobotics.ca";
$dbuser = "new_robot";
$dbpasswd = "aman#1999";
$dbname = "arduino_connection";

$conn = mysqli_connect($dbhost, $dbuser, $dbpasswd, $dbname) or die('Connect Error: ' . mysqli_connect_error());

// Create connection
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO serial_data (finger1, finger2, finger3, finger4, finger5)
VALUES (0,0,0,0,0)";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>