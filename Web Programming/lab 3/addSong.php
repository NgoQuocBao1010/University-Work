<?php 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    else {
        echo 'Sucessfully connect to database!!';
    }

    $sql = "SELECT * FROM Reviews";
    $result = mysqli_query($conn, $sql);
    // $reviews = mysqli_fetch_all($result, MYSQLI_ASSOC);
    // print_r($reviews);

    while($row = mysqli_fetch_assoc($result)) {
        print_r($row);
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Them Bai Viet</title>
</head>
<body>
    
</body>
</html>